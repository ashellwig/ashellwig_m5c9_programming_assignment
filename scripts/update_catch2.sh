#!/bin/bash

## Set Script Options
set -o errexit
set -o pipefail
set -o nounset

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

if [[ -d "${project_source_DIR}/include/catch2" ]]; then
  rm -r "${project_source_DIR}/include/catch2"
fi

cmake '-Bbuild' '-H.' "-DCMAKE_INSTALL_PREFIX=${project_source_DIR}" '-DBUILD_TESTING=OFF' '-DCATCH_BUILD_EXAMPLES=OFF' '-DCATCH_BUILD_TESTING=OFF' '-DCATCH_INSTALL_DOCS=OFF' '-DCATCH_INSTALL_HELPERS=on'
cmake --build build/ --target install

if [[ -d "${project_source_DIR}/cmake/Catch2" ]]; then
  rm -r "${project_source_DIR}/cmake/Catch2/"
fi

mkdir "${project_source_DIR}/cmake/Catch2"

mv "${project_source_DIR}"/lib/cmake/Catch2/* "${project_source_DIR}"/cmake/Catch2

rm -rf "${project_source_DIR}/lib"
rm -rf "${project_source_DIR}/share"

cd "${prev_DIR}"

# Delete temp dir
rm -rf "${temp_DIR}"

# Unset script options
set -u errexit
set -u pipefail
set -u noclobber
set -u nounset

exit 0
