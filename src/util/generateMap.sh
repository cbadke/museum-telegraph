#!/bin/bash
make

generated_file="../tapper/mappings.c"
filename="alphabet.txt"

regex='(.) (.*)'

echo '' > $generated_file
echo '//This file was generated using ../utils/generateMap.sh and ../utils/dotDashToInt.c' >> $generated_file
echo '//to change the morse code mappings update alphabet.txt and regenerate this file.' >> $generated_file
echo '#include "mappings.h"' >> $generated_file
echo "" >> $generated_file
echo "const int MAPPER_LENGTH = $(wc -l < $filename);" >> $generated_file
echo "Mapping morseMappings[] = {" >> $generated_file
while read -r line
do
  if [[ $line =~ $regex ]];
  then
    char=${BASH_REMATCH[1]}
    pattern=${BASH_REMATCH[2]}
    num=$(./dotDashToInt "$pattern")
    echo "  {\"$char\", $num}," >> $generated_file
  fi;
done < "$filename"

echo "};" >> $generated_file
