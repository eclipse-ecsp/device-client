@echo off
SETLOCAL EnableDelayedExpansion

echo 'Cleaning previously created files in parent module'
del .\DEPENDENCIES

echo 'Running dash tool for all dependencies license compliance'
CALL java -jar ./eclipse-dash/dash.jar ./eclipse-dash/dc.deps -summary DEPENDENCIES

echo DEPENDENCIES file created.