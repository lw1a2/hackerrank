#!/bin/bash

./main < input/input00.txt > /tmp/output.txt
diff /tmp/output.txt output/output00.txt

./main < input/input02.txt > /tmp/output.txt
diff /tmp/output.txt output/output02.txt

./main < input/input12.txt > /tmp/output.txt
diff /tmp/output.txt output/output12.txt

./main < input/input14.txt > /tmp/output.txt
diff /tmp/output.txt output/output14.txt

./main < input/input15.txt > /tmp/output.txt
diff /tmp/output.txt output/output15.txt

