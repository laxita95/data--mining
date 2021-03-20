#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;


void read_record(int k,int n,long double* rv) 
{ 
  
    // File pointer 
    fstream fin; 
  
    // Open an existing file 
    fin.open("/home/sonalkumar/Desktop/test/eigenvec1.csv", ios::in);
    //fin1.open("/home/sonalkumar/Desktop/test/clusterOP.csv", ios::in);
    
    vector<string> row;
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
        while (getline(s, word, ' ')) { 
  
            // add all the column data 
            // of a row to a vector 
            row.push_back(word); 
        } 
       
  	if (count < k)
  	{
  	long double max;
  	for(int m=0;m<n;m++)
  	{
  	if(m == 0)
  	max = std::stold(row[m]);
  	if(max < std::stold(row[m]))
  	max = std::stold(row[m]);
  	}
 
  	//for(auto x: row) if (max < x) max = x;
  	if(count == 0)
  	{
  	for(int r=0; r<n;r++){
  	 rv[r]=(std::stold(row[r])/max);}
 	}
 	else{
 	for(int r=0; r<n;r++){
 	rv[r]=rv[r]+(std::stold(row[r])/max);}
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

	long double rv[k];
	
	read_record(k,n,rv);
	
	for(auto x: rv) cout << x << " ";
	return 0;
	}
