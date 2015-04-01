#!/bin/bash
./build_sdks.sh "@$" || exit 1
./set_sdks.sh "$@" || exit 1
./build_mako.sh "@$" || exit 1
