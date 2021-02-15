#!/bin/sh
for i in {1,2,4,8,16,32,64,128,256,512,1024,2048}
do ./tlb -n $i -l 1000000 > out$i.txt;
done
cat out1.txt out2.txt out4.txt out8.txt out16.txt out32.txt out64.txt out128.txt out256.txt out512.txt out1024.txt out2048.txt > out_1.txt
echo "done"
