#!/bin/bash

./main < input/input00.txt > /tmp/output00.txt
diff /tmp/output00.txt output/output00.txt

./main < input/input31.txt > /tmp/output31.txt
diff /tmp/output31.txt output/output31.txt

