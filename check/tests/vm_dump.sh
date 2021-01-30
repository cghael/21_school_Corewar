#!/bin/bash

count=0
while [ 1 ]
do
    count=$(($count + 1))
    $1 -d $count $3 $4 $5 > out_subj | $2 -d $count $3 $4 $5 > out_main
    output=$(diff out_subj out_main)
    winner1=$(grep 'Contestant' out_subj)
    winner2=$(grep 'Contestant' out_main)
    if [ "$output" != "" ]
    then
        echo "$output"
        printf "\e[91mFAIL\e[0m\n"
        break
    fi
    if [ "$winner1" != "" ]
    then
        if [ "$winner1" == "$winner2" ]
        then
            printf "\n> Winner $1 : $winner1\n"
            printf "> Winner $2 : $winner2\n"
            printf "\e[92mSUCCESS\e[0m\n"
        else
            printf "\n> Winner $1 : $winner1\n"
            printf "< Winner $2 : $winner2\n"
            printf "\e[91mFAIL\e[0m\n"
        fi
        break
    fi
    printf " \e[93mCYCLE #$count\e[0m\r"
done