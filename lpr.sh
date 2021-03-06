#!/bin/sh

EXPECTED_ARGS=1
E_BADARGS=1
SUCCESS=0

if [ $# -ne $EXPECTED_ARGS ]
then
    echo "Usage: ./lpr <input.img>"
    exit $E_BADARGS
fi

rm -f output.txt
#./0_locateLP/locateLP $1 > /dev/null 2>&1
./1_text_isolation/txtiso.out $1 > /dev/null 2>&1
./2_character_segmentation/charsegm.out final.png > /dev/null 2>&1
rm final.png
./3_ocr/ocr.out letter*.png
rm letter*.png

echo "-------------------------------"
echo "Greek License Plate: "
cat output.txt | grep '[A-Z0-9]' | perl -p -e 's/[^A-Z0-9]+//g'
printf "\n"
echo "-------------------------------"

rm output.txt

exit $SUCCESS
