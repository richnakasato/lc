#!/bin/bash -x
# $1 -> problem number

leetcode show $1 -gx -l python3 -o $1

#for i in {1..956}; do leetcode show $i -gx -l python3; done
