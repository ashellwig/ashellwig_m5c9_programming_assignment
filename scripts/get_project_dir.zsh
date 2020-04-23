#!/usr/bin/env zsh

# Global Options and Variables
## Options
set -o errexit -o pipefail -o noclobber -o nounset
## Variables
declare -L get_project_dir_path
get_project_dir_path="\
    $(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"

unset get_project_dir_path
unset errexit
unset pipefail
unset noclobber
unset nounset
