#!/bin/bash

cmake . || exit 1
make -j all || exit 1
ctest --output-on-failure
