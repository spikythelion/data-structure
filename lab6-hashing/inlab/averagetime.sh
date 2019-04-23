#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: inlab6.pdf
#Date: 10/23/18
#!/bin/bash 
make
echo "What is your dictionary file?"
read dictFile
#echo ${dictFile}
echo "What is your grid file?"
read gridFile
#echo ${gridFile}
RUNNING_TIME1=`./a.out "${dictFile}" "${gridFile}" | tail -1`
RUNNING_TIME2=`./a.out "${dictFile}" "${gridFile}" | tail -1`
RUNNING_TIME3=`./a.out "${dictFile}" "${gridFile}" | tail -1`
RUNNING_TIME4=`./a.out "${dictFile}" "${gridFile}" | tail -1`
RUNNING_TIME5=`./a.out "${dictFile}" "${gridFile}" | tail -1`
RUNNING_TIME=$((RUNNING_TIME1 + RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNNING_TIME5))
AVERAGE=$((RUNNING_TIME / 5))
echo "Average running time is ${AVERAGE} miliseconds"
make clean										       
