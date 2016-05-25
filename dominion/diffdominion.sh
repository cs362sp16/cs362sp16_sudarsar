#!/bin/bash

if [ "$#" -ne 3 ]; then
	echo "Illegal number of parameters"
	echo "diffdominion.sh <abs path of your directory> <abs path of other directory> <seed>"
	exit
fi

loc1=$1
loc2=$2
seed=$3

make clean
make all

cd $loc2
make clean
make all

cd -

output1="file1.out"
output2="file2.out"
domc="dominion.c"
testdom="testdominion"

$loc1$testdom $seed > $loc1$output1
$loc2$testdom $seed > $loc1$output2

diff $loc1$output1 $loc1$output2 > dominionDifferences.diff
gcov $loc1$domc >> dominionDifferences.diff
gcov $loc2$domc >> dominionDifferences.diff

if [ ! -s dominionDifferences.diff ]
then
	echo "TEST PASSED"
else
	echo "TEST FAILED"
fi


