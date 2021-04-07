#!/bin/bash

echo -ed "\033starting upload...\033[0m"

# Add changes to git
git add .

#Commit changes.
msg="upload 'date'"
if [$# -eq 1]
	then msg="$1"
fi
git commit -m "$msg"

# Push source
git push origin master
