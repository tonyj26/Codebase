#!/bin/bash
# A simple copy script

cp $1 $2

# Verify it worked

echo Details for $2
ls -lh $2
