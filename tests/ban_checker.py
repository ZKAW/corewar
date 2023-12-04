import os
import re
import argparse

colors = {
    'RESET': '\033[0m',
    'RED': '\033[31m',
    'ORANGE': '\033[33m',
    'BLUE': '\033[34m',
    'GREEN': '\033[32m',
}

func_calls_reg = r'(?<!\w)(?!if|for|while|switch|return|sizeof|typedef|struct|enum|union|goto|const|static|volatile|extern)(\w+)\s*\(.+?\)'
defined_funcs_reg = r'\w+\s+\**\s*\w+\([^;]+?\)\s*\{'
defined_header_funcs_reg = r'\w+\s+\**\s*\w+\([^;]+?\)\s*;'

parser = argparse.ArgumentParser(description='Find undeclared functions in C source files.')
parser.add_argument('root_directories', help='Root directory to search for C source files')
parser.add_argument('-a', '--authorized_functions', help='Comma-separated list of authorized functions')
parser.add_argument('-nC', '--no-color', action='store_true', help='Disable color output')
parser.add_argument('-gA', '--github-actions', action='store_true', help='Enable GitHub Actions output')
args = parser.parse_args()

authorized_functions = set(args.authorized_functions.replace(' ', '').split(',')) if args.authorized_functions else set()

if args.no_color:
    for color in colors:
        colors[color] = ''

def get_in_comment_lines(file_content):
    in_comment = False
    lines = []
    for i, line in enumerate(file_content.splitlines()):
        if '/*' in line:
            in_comment = True
        if '*/' in line:
            in_comment = False
        if in_comment:
            lines.append(i)
        if '//' in line:
            lines.append(i)
    return lines

def parse_dir(dir, pattern, file_extension='.c'):
    out = []
    for root, dirs, files in os.walk(dir):
        for file in files:
            if file.endswith(file_extension):
                # Open the file and read its contents into a string variable
                filepath = os.path.join(root, file)
                with open(filepath, 'r', encoding='latin1') as f:
                    content = f.read()
                # Search for function declarations using the regular expression pattern
                for m in re.finditer(pattern, content):
                    name = m.group().split('(')[0]
                    name = name.split(' ')[-1].replace('*', '')
                    if name.isspace():
                        continue
                    # Move line counting inside the loop
                    line_nb = content[:m.start()].count('\n') + 1

                    comment_lines = get_in_comment_lines(content)
                    if line_nb - 1 in comment_lines:
                        continue
                    out.append({'file': filepath, 'name': name, 'line': line_nb})
    return out


def get_defined_functions(dir):
    header_defined_functions = parse_dir(dir, defined_header_funcs_reg, '.h')
    defined_functions = parse_dir(dir, defined_funcs_reg)
    return [dict(t) for t in {tuple(d.items()) for d in header_defined_functions + defined_functions}]

def get_function_calls(dir):
    return parse_dir(dir, func_calls_reg)

def get_undefined_functions(defined_functions, function_calls):
    out = []
    for function_call in function_calls:
        if function_call['name'] not in [f['name'] for f in defined_functions]:
            out.append(function_call)
    return out

def get_banned_functions(dir, authorized_functions):
    defined_functions = get_defined_functions(dir)
    function_calls = get_function_calls(dir)
    undefined_functions = get_undefined_functions(defined_functions, function_calls)

    banned_functions = {}
    for function in undefined_functions:
        if function['name'] not in authorized_functions:
            banned_functions.setdefault(function['name'], []).append({'file': function['file'], 'line': function['line']})

    return banned_functions

def display_normal(banned_functions):
    num_functions = len(banned_functions)
    for i, function in enumerate(banned_functions):
        print(f'{colors["RED"]}Banned function: {colors["ORANGE"]}{function}{colors["RESET"]}')
        for j, file in enumerate(banned_functions[function]):
            print(f'File location: {colors["BLUE"]}{file["file"]}:{file["line"]}{colors["RESET"]}')
        if i < num_functions - 1:
            print()
    return (bool(len(banned_functions)))

def display_git_actions(banned_functions):
    for i, function in enumerate(banned_functions):
        for j, file in enumerate(banned_functions[function]):
            print(f'::error file={file["file"]},line={file["line"]},title=Banned function::{function}')
    return (bool(len(banned_functions)))

banned_functions = get_banned_functions(args.root_directories, authorized_functions)

if args.github_actions:
    exit(display_git_actions(banned_functions))
else:
    ret = display_normal(banned_functions)
    if ret == False:
        print(f'{colors["GREEN"]}No banned functions found{colors["RESET"]}')
    exit(ret)
