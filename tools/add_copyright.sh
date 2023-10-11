#!/usr/bin/env bash

set -e
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ROOT_DIR="${SCRIPT_DIR}/../"

LICENSE_FILE="${SCRIPT_DIR}/MPL2_short.txt"

LICENSE_LEN=`wc -l "${LICENSE_FILE}" | cut -f1 -d ' '`

for x in $*; do  
    head -$LICENSE_LEN $x | diff "${LICENSE_FILE}" - || ( ( cat "${LICENSE_FILE}"; echo; cat $x) > /tmp/copyright_file;  
    mv /tmp/copyright_file $x )  
done
