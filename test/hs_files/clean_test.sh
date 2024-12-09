#!/bin/bash

# Define red color for warning message
RED='\033[1;31m'
RESET='\033[0m'

# Warning message
echo -e "${RED}🛑 Warning: Are you sure you want to delete test stats? (y/n)${RESET}"

# Read user input
read -r confirm

# Check if the user confirmed
if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
    echo -e "Deleting test stats log file..."
    rm -f test/test_outputs/summary.log
    rm -f test/test_outputs/command_output.log
    rm -f test/test_outputs/generated_numbers.log
    echo -e "test stats have been deleted."
else
    echo -e "Operation cancelled. No files were deleted."
fi