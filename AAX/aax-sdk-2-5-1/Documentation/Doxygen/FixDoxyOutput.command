#!/bin/sh
# 
# Copyright 2023 Avid Technology, Inc.
# 
# CONFIDENTIAL: this document contains confidential information of Avid. Do
# not disclose to any third party. Use of the information contained in this
# document is subject to an Avid SDK license.

DIR="$( cd "$( dirname "$0" )" && pwd )"

# Fix paths that incorrectly point to dot directory
perl -e 's#\/Volumes.*?\/dot\/#\.\/#g;' -pi $(find ${DIR}/output -type f)

# Put dot images into 'centered' class
perl -e 's#\<img(.*?)src\=\"dot_#\<img class="centered"\1src\=\"dot_#g;' -pi $(find ${DIR}/output/html/*.html -type f)
