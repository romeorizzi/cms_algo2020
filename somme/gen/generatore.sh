#!/bin/bash

NUM="$1"
shift

if [ "z$NUM" == "z0" ] ; then
	cat << EOF
6
11 -4 52 -7 -2 -20
EOF
	exit 0
fi

case "$NUM" in
	1) ./gen/somme-gen.py "$@"
	;;
	2) ./gen/somme-gen02.py "$@"
	;;
esac

