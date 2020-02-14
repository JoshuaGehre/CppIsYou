#!/bin/bash

set -e -u

for i in Levels/Level_* ; do
  if [ -d "$i" ]; then
    cp "Scripts/Move.sh" "${i}/Move.sh"
    cp "Scripts/Restart.sh" "${i}/Restart.sh"
  fi
done