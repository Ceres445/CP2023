#!/bin/bash

cp tester.py $1 

cd $1
if (python3 tester.py ); then
    exit 0
else
    exit 1
fi
