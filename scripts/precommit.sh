#!/bin/bash
set -e
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )

pushd "$parent_path" > /dev/null

source ./venv/bin/activate

echo "> Updating assets..."
ls .. -l | grep -P '\d{4}-' --only-matching | sed 's/-//g' | ./generate_grid.py -n 3000 -o ../assets/grid.png -r 2
echo "> ✅ Grid generated."
git add ../assets/grid.png

popd > /dev/null
