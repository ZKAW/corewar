#!/bin/bash

# This script is used to test the corewar program.
# It will run the program with the given command line arguments
# and compare the output of both binaries.

shell_dir=$(dirname $0)
my_bin=$shell_dir/../corewar/corewar
model_bin=$shell_dir/bin/corewar_subject
tests_file_name=tests_list
tests_file=$shell_dir/$tests_file_name
rand_nb=$(shuf -i 1-100000 -n 1)
tmp_dir=/tmp/corewar.$rand_nb
result=""


if [ ! -f $my_bin ]; then
    echo -e "\e[31mError:\e[0m $my_bin not found"
    exit 1
fi

if [ ! -f $model_bin ]; then
    echo -e "\e[31mError:\e[0m $model_bin not found"
    exit 1
fi

if [ ! -f $tests_file ]; then
    echo -e "\e[31mError:\e[0m $tests_file not found"
    exit 1
fi

rm -rf /tmp/corewar.*

test_nb=0
failed_tests=0

while IFS= read -r test || [ -n "$test" ]; do
    test_nb=$((test_nb+1))

    if [[ $test == *'?' ]]; then
        echo -e "[\e[95mSTATUS\e[0m] \c"
    else
        echo -e "[\e[34mOUTPUT\e[0m] \c"
    fi
    echo -n "Test $test_nb "
    echo -e "(\e[34m$tests_file_name:$test_nb\e[0m): \c "
    test_line=${test%\?} # Remove "?" at the end of the line, if present
    mkdir -p $tmp_dir/$test_nb
    my_output=$tmp_dir/$test_nb/my.out
    model_output=$tmp_dir/$test_nb/model.out
    $my_bin $test_line > $my_output 2>&1
    my_return_code=$?
    if [ $my_return_code -eq 1 ]; then
        my_return_code=84
    fi
    echo "Program exited with return code: $my_return_code" >> $my_output
    $model_bin $test_line > $model_output 2>&1
    model_return_code=$?
    if [ $model_return_code -eq 1 ]; then
        model_return_code=84
    fi
    echo "Program exited with return code: $model_return_code" >> $model_output


    # if there's a "-L" in command line argument of tester.sh
    # then we only keep the last two lines of output
    if [ "$1" == "-L" ]; then
        tail -n 2 $my_output > $my_output.tmp
        mv $my_output.tmp $my_output
        tail -n 2 $model_output > $model_output.tmp
        mv $model_output.tmp $model_output
    fi

    if [[ $test == *'?' ]]; then
        if [ $my_return_code -eq $model_return_code ]; then
            rm -rf $tmp_dir/$test_nb
            echo -e "\e[32mOK\e[0m"
            # echo -e "\e[32mOK - Check output in $tmp_dir/$test_nb/\e[0m"
        else
            # echo -e "\e[31mKO\e[0m \c"
            echo -e "\e[31mKO - Check output in $tmp_dir/$test_nb/\e[0m \c"
            failed_tests=$((failed_tests+1))
            diff_output=$(diff $my_output $model_output)
            # count lines of diff output
            diff_lines=$(echo "$diff_output" | wc -l)
            echo -e "(\e[31m$diff_lines\e[0m lines)"
            echo "$diff_output" > $tmp_dir/$test_nb/diff.out
        fi
    else
        diff_output=$(diff $my_output $model_output)
        echo "$diff_output" > $tmp_dir/$test_nb/diff.out
        if [ "$diff_output" != "" ]; then
            # echo -e "\e[31mKO\e[0m \c"
            echo -e "\e[31mKO - Check output in $tmp_dir/$test_nb/\e[0m \c"
            failed_tests=$((failed_tests+1))
            diff_lines=$(echo "$diff_output" | wc -l)
            echo -e "(\e[31m$diff_lines\e[0m lines)"
        else
            rm -rf $tmp_dir/$test_nb
            echo -e "\e[32mOK\e[0m"
            # echo -e "\e[32mOK - Check output in $tmp_dir/$test_nb/\e[0m"
        fi
    fi
done < "$tests_file"

# Print test results
echo -e "\nTests results:"
if [ $failed_tests -eq 0 ]; then
    echo -e "\e[32mAll tests passed\e[0m"
    exit 0
else
    echo -e "\e[31m$failed_tests\e[0m/\e[31m$test_nb\e[0m tests failed"
    exit 1
fi
