#!/usr/bin/env bash

set -e
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ROOT_DIR="${SCRIPT_DIR}/../"

find "${ROOT_DIR}" -type f -regex ".*\.[ch]\(pp\)?$" -not -path "./build/*" -print0 | xargs -0 "${SCRIPT_DIR}/add_copyright.sh"
