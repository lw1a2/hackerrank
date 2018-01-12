#!/bin/bash

./main < input/input00.txt > /tmp/output00.txt
diff /tmp/output00.txt output/output00.txt

./main < input/input01.txt > /tmp/output01.txt
diff /tmp/output01.txt output/output01.txt

