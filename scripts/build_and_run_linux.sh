#!/bin/bash

declare +x build_and_run_linux_DIR
build_and_run_linux_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"

# shellcheck source=SCRIPTDIR/lib/lib.sh
. "${build_and_run_linux_DIR}/lib/lib.sh"

declare +x project_DIR
project_DIR='/home/ahellwig/Documents/School/CSC160/Module-5/Programming-Assignments/ashellwig_m5c9_programming_assignment'

declare +x generator_type
generator_type='Unix Makefiles'

declare +x +i verbose
verbose=0

declare +x input_data
input_data="${project_DIR}/data/Ch9Ex2/Ch9Ex2Data.txt"
declare +x output_data
output_data="${project_DIR}/data/Ch9Ex2Out.txt"

# --- PARSE ARGS ---
while getopts ":vf:o:" opt; do
  case $opt in
    f)
      input_data="$OPTARG"
      ;;
    o)
      output_data="$OPTARG"
      ;;
    v)
      verbose=1
      ;;
    \?)
      __log_msg -e -m "Invalid option: -$OPTARG" >&2
      ;;
    :)
      __log_msg -e -m "Option -$OPTARG requires an argument" >&2
      ;;
  esac
done

cd "${project_DIR}" || err_dir_not_found "${project_DIR}"

# --- SETUP PROJECT ---
if [[ -d "${project_DIR}/build" ]]; then
  if [[ "$verbose" ]]; then
    __log_msg -i -m "Removing directory: ${project_DIR}/build"
  fi
  rm -rf "${project_DIR}/build"

  if [[ "$verbose" ]]; then
    __log_msg -i -m "Creating directory: ${project_DIR}/build"
  fi
  mkdir -p "${project_DIR}/build"
else
  if [[ "$verbose" ]]; then
    __log_msg -i -m "Creating directory: ${project_DIR}/build"
  fi
  mkdir -p "${project_DIR}/build"
fi

# --- BUILD PROJECT ---
if [[ "$verbose" ]]; then
  __log_msg -i -m "Moving to build directory: ${project_DIR}/build"
fi
cd "${project_DIR}/build" \
  || __log_msg -e -m "Unable to find: ${project_DIR}/build"

if [[ "$verbose" ]]; then
  __log_msg -i -m 'Configuring project...'
fi
cmake .. -G "${generator_type}"

if [[ "$verbose" ]]; then
  __log_msg -i -m 'Building project...'
fi
cmake --build . --target ashellwig_m5c9_programming_assignment

# --- EXECUTE SOLUTION ---
if [[ "$verbose" ]]; then
  __log_msg -i -m 'Executing solution...'
  __log_msg -i -m "Using input data file: ${input_data}"
  __log_msg -i -m "Using output data file: ${output_data}"
fi
./ashellwig_m5c9_programming_assignment --output="${output_data}"
cat "${output_data}"

# --- CLEANUP ---
cd "${project_DIR}" || err_dir_not_found "${project_DIR}"

unset build_and_run_linux_DIR
unset project_DIR
unset err_dir_not_found
unset verbose
