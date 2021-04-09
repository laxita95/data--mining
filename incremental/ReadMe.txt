Step to run proposed Incremental Algorithm

Step 1: Execute the static part by following the steps given in Readme.txt of static Algorithm. After execution three document will be generated clusterOP.csv (Cluster Label), eigenvec1.csv (Eigen vectors), and eigenval.csv (Eigen Values).

Step 2: Now, following commands to compile, generate executable file and run "RValues.cpp" : "g++ -c RValues.cpp", "g++ -o RV RValues.cpp", and "./RV" respectively. After execution "RepVal.csv" file will be generated. RapVal.csv contains representative value of each data point of data set.

Step 3: Transpose the column of "eigenval.csv" and remane as "EV.csv". Now compile, generate executable file and run "Increment.cpp" with following command: "g++ -c Increment.cpp", "g++ -o INC Increment.cpp", and "./INC" respectively. 

Step 4: While running "Increment.cpp", the programe will ask to input the Optimal number of Cluster. Please select best value among the printed option based on their Eigengap.

[ Please automate the program to perform Optimal number of Operations ans save the output in a file. In the next iteration include all newly added points in your data set and compare the results of itteration one with the result of static part of itteration two.]

Important Note: 
1. Please change the path provided in program accordingly.  
2. If you incounter "core Dump", please cheak whether the program is reading input file or not.
3. To use "visualization.cpp", allow your program to print cluster label and data points after execution and append executable file of Visualization.cpp with executable file of program i.e. "./ProgramExecutableFile | visual". Here visual is executable file of Visualization.cpp.
	 
