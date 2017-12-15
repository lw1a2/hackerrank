#!/bin/bash

./main < input/input00.txt > /tmp/output00.txt
diff /tmp/output00.txt output/output00.txt

./main < input/input10.txt > /tmp/output10.txt
diff /tmp/output10.txt output/output10.txt

./main < input/input11.txt > /tmp/output11.txt
diff /tmp/output11.txt output/output11.txt

./main < input/input2.txt > /tmp/output2.txt
diff /tmp/output2.txt output/output2.txt

./main < input/input12.txt > /tmp/output12.txt
diff /tmp/output12.txt output/output12.txt

