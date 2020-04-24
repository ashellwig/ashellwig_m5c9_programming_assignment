#!/bin/bash

################################################################################
# Print messages to STDERR.
################################################################################
function eprintlog() {
  echo "[$(date +'%Y-%m-%dT%H:%M:%S%z')]: $*" >&2
}

################################################################################
# Gets the path of the currently file this function is called in.
# Returns:
#   Path of the currently file this function is called in as a string.
################################################################################
function __script_src_dir__() {
  cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd
}
