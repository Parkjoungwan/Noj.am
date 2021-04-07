#!/bin/bash

# Add changes to git
git add .

#Commit changes.
msg="upload 'date'[0"
if [$# -eq 1]
	then msg="$1"
fi
git commit -m "$msg"

# Push source
git push origin master
