#!/bin/bash

SUCC="SUCCESS"
FAIL="FAIL"
format="%-20s %-15s %-15s %-15s %s\n"
source=`pwd`
printf "%-20s %-15s %-15s %-15s %s\n" "CHAMPION NAME" "DEFIN(lost)" "INDIR(lost)" "ERROR(sum)" "RESULT"
printf "============================================================================\n"
for champion in $source/tests/champion_cor/*
do
    name_champ=`echo $champion | cut -d'/' -f8`
    valgrind --log-file=tests/log.txt $1 $champion > /dev/null 2>&1
    defin=`echo $(grep -E 'definitely' tests/log.txt) | cut -d' ' -f4`
    indir=`echo $(grep -E 'indirectly' tests/log.txt) | cut -d' ' -f4`
    ERROR=`echo $(grep -E 'ERROR SUMMARY' tests/log.txt) | cut -d' ' -f4`
    if [[ "$defin" == "0" && "$indir" == "0" && "$ERROR" == "0" ]]
    then
        printf "%-24s %-15s %-15s %-10s \e[92m%s\e[m" $name_champ $defin $indir $ERROR $SUCC
    else
        printf "%-24s %-15s %-15s %-10s \e[91m%s\e[m" $name_champ $defin $indir $ERROR $FAIL
    fi
    printf "\n"
done
