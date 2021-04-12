NOTE :- The instruction regarding incremental algorithm is inside Incremental folder.

******************Static Algorithm*******************

Operating System: Ubantu20, Dataset Link: http://cs.joensuu.fi/sipu/datasets/

**************Execute following commands in linex terminal in same order.***************

INSTALL g++|Eigen|libboost|numpy|matploib

$sudo apt-get install g++-9

$sudo apt-get install libeigen3-dev

$sudo apt-get install libboost-dev

$sudo apt-get install libboost-all-dev 

$sudo apt-get install python3-numpy

$sudo apt-get install python3-pip

$sudo pip3 install matplotlib

-----
create ln(link) for eigen (Eigen & unsupported)

check the location of eigen on the system to create link. check the parent dir (example: /usr/include/eigen3 || /usr/local/include/eigen3) ####a
$locate eigen ## check parent dir

$cd /usr/include

$sudo ln -sf eigen3/Eigen Eigen

$sudo ln -sf eigen3/unsupported unsuppored

----
COMPILE AND RUN PROGRAM
create object files from cpp with g++-9

$cd <proj_folder>

$g++-9 -c SpectralClustering.cpp -Wall -std=c++0x -lboost_program_options

$g++-9 -c spectral.cpp -Wall -std=c++0x -lboost_program_options

$g++-9 -c visualization.cpp -Wall -std=c++0x -lboost_program_options

----
use object file to create executable file(s)

$g++-9 -o dtm SpectralClustering.o spectral.o -Wall -std=c++0x -lboost_program_options

$g++-9 -o visualization visualization.o -Wall -std=c++0x -lboost_program_options

----
run executables to generates final output

$./dtm --cluster 3 --neighbors 4 < data.txt | ./visualization | python3


