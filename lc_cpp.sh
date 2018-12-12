#!/bin/bash
# $1 -> problem number

#leetcode show $1 -gx -l cpp -o $1

for i in {1..956}; do leetcode show $i -gx -l cpp; done
