#!/usr/bin/env bash

## Options
set -o errexit -o pipefail -o noclobber -o nounset

## Variables
declare prev_DIR
prev_DIR="${PWD}"

declare update_catch2_DIR
update_catch2_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"

declare project_source_DIR
project_source_DIR="$(dirname "${update_catch2_DIR}")"

declare temp_DIR
temp_DIR="$(dirname "${project_source_DIR}")/tmp"

cd "${project_source_DIR}"

if [[ ! -d "${temp_DIR}" ]]; then
  mkdir -p "${temp_DIR}"
else
  rm -rf "${temp_DIR}"
  mkdir -p "${temp_DIR}"
fi

cd "${temp_DIR}"

git clone 'https://github.com/catchorg/Catch2.git' "${temp_DIR}/catch2"
cd "${temp_DIR}/catch2"
cmake '-Bbuild' '-H.' "-DCMAKE_INSTALL_PREFIX=${project_source_DIR}/out/cmake" '-DBUILD_TESTING=OFF'
cmake --build 

cd "${prev_DIR}"
rm -rf "${temp_DIR}"

exit 0
