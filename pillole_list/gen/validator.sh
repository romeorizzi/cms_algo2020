#!/bin/bash
MAXN=13

read N < "$1"

if ! ((N > 0 && N <= MAXN)); then
    exit 1;
fi