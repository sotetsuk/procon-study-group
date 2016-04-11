#!/bin/bash
cat src/Template.java > src/Main.java
VAR=$(pwd)
echo $VAR/src/Main.Java
find "$VAR/src/Main.java" -type f | xargs sed -i.bak "s/Template/Main/g"
find "$VAR/src/Main.java" -type f | xargs sed -i.bak "s/FastReader2/FastReader/g"
rm -rf $VAR/src/*.bak