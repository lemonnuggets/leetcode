#!/bin/bash

source ./venv/bin/activate

ls .. -l | grep -P '\d{4}-' --only-matching | sed 's/-//g' | ./generate_grid.py -n 3000 -o ../assets/grid.png -r 2
git add ../assets/grid.png

echo "> Grid generated."