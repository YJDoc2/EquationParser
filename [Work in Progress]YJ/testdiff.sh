#!/bin/bash
touch diff.txt
touch temp1.txt
touch temp2.txt

ls . >>temp1.txt
ls ../Mark\ II >>temp2.txt
echo '>>>>>>>POLY>>>>' >> diff.txt
diff temp1.txt temp2.txt >> diff.txt
rm ./temp1.txt ./temp2.txt
echo '>>>>END>>>' >> diff.txt

