#Name: Tho Nguyen
#Email ID: tnn7yc
#File name:
#Date: 11/1/18
#!/bin/bash
clang++ counter.cpp
echo "Enter the exponent for counter.cpp:"
read e
if [[ ${e} == "quit" ]]; then
    echo "Exit averagetime.sh"
    exit 0
fi
SUM=0
for i in {1..5} ; do
    echo "Running iteration $i..."
    RUNNING_TIME=`./a.out ${e} | tail -1`
    echo "time taken: ${RUNNING_TIME} ms"
    SUM=$((SUM + RUNNING_TIME))
done
echo "5 iterations took ${SUM} ms"
AVERAGE=$((SUM / 5))
echo "Average time was ${AVERAGE} ms"
