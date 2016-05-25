#!/bin/bash

counter=0

while [ $counter -le 25 ]
do
	testdominion
	$counter++
done
