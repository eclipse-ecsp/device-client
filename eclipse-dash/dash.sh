#!/bin/bash

echo 'Cleaning previously created files in parent module'
rm -f ./DEPENDENCIES

echo 'Running dash tool for all dependencies license compliance'
chmod +x $PWD/eclipse-dash/dash.jar $PWD/eclipse-dash/dc.deps
java -jar $PWD/eclipse-dash/dash.jar $PWD/eclipse-dash/dc.deps -summary $PWD/DEPENDENCIES
chmod +x $PWD/DEPENDENCIES
echo "DEPENDENCIES file created."

echo 'Checking for failed dependencies'
if  grep -q "restricted" "$PWD/DEPENDENCIES"; then
    echo "Some restricted dependencies found."
#   exit 1
else
    echo "All dependencies are compliant."
fi
