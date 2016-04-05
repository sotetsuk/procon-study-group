#!/bin/bash
cat src/Template.java > src/Main.java
VAR=$(pwd)
echo $VAR/src/Main.Java
find "$VAR/src/ALDS1_1_D.java" -type f | xargs sed -i.bak "s/Template/ALDS1_1_D/g"
find "$VAR/src/ALDS1_1_D.java" -type f | xargs sed -i.bak "s/FastReader2/FastReader/g"
rm -rf $VAR/src/*.bak