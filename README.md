# Simple Website Traffic Data Management

## About
This program helps you manage site information such as:
-*URL*
-*Number of visitors*
-*Page views*
-*Bandwidth usage*
-*Squarespace and Google Analytics Integrations*

## Before You Compile - Getting Curl and APIs Set Up
- Download `curl` via curl.se and set PATH - system variables for `curl/bin`, `curl/lib`, and `curl/include`.

- Set up Squarespace and Google Analytics APIs to gain access to your API keys. Edit files ending in `...api.cpp` with those keys - but **DO NOT** add or push those keys to your main file directory. Store them on your local directory for personal use.

## Compiling
- Compile all `.cpp` files with: `g++ -I ./ *.cpp -o (name_of_out_your_file)`

- To use `curl` command, use: `g++ -I/path/to/curl/include -L/path/to/curl/lib -lcurl *.cpp -o (name_of_out_your_file)`

- Then, run the output file (`(name_of_out_your_file).exe`) on Windows.

## Note
INCOMPLETE - WILL GIVE ERRORS.

Currently only supports **MANUAL** edits to the `traffic_data` text file.
