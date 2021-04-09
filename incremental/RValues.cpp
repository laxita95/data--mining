#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include<cmath>
//#include"represent.h"
#include<fstream>

using namespace std;


void read_record(int k,int n,double* rv) 
{ 
  
    // File pointer 
    fstream fin; 
  
    // Open an existing file 
    fin.open("/home/sonalkumar/Desktop/test/AggriInc7/eigenvec1.csv", ios::in);
    //fin1.open("/home/sonalkumar/Desktop/test/clusterOP.csv", ios::in);
    
    vector<double> row;
    string line, word, temp;  
    
    int count = 0;
  
    while (fin >> temp) { 
  
        row.clear(); 
  
        // read an entire row and 
        // store it in a string variable 'line' 
        getline(fin, line); 
  
        // used for breaking words 
        stringstream s(line); 
  
        // read every column data of a row and 
        // store it in a string variable, 'word' 
        while (getline(s, word, '	')) { 
  
            // add all the column data 
            // of a row to a vector 
            
            //cout << std::stold(word);
            row.push_back(std::stod(word)); 
        } 
       
  	if (count < k)
  	{
  	double max;
  	for(int m=0;m<n;m++)
  	{
  	if(m == 0)
  	max = row[m];
  	if(max < row[m])
  	max = row[m];
  	}
 
  	//for(auto x: row) if (max < x) max = x;
  	if(count == 0)
  	{
  	for(int r=0; r<n;r++){
  	 rv[r] = pow((row[r] / max),2);}
 	}
 	else{
 	for(int r=0; r<n;r++){
 	rv[r] = rv[r] + pow((row[r] / max),2);}
 	}
        // convert string to integer for comparision 
        //roll2 = stoi(row[0]); 
  
        }
        count = count +1;
        
    }
}

int main() {
	int k,n;

	cout << "Enter No. of Current Clusters:";
	cin >> k;

	cout << "Enter No. of data points:";
	cin >> n;

	double rv[n];
	
	read_record(k,n,rv);
	
	for(auto x: rv) cout << x << " ";
	
	ofstream myRfile;
    	myRfile.open("/home/sonalkumar/Desktop/test/AggriInc7/RepVal.csv");
    	for(auto rr: rv) myRfile << rr << " ";
    	//myEfile << clusters;
    	myRfile.close();
    	
	return 0;
	}
