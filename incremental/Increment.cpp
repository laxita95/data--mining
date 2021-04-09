#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<tuple>

using namespace std;
//void Rvecsort();

int CD; //Current number of datapoints
int Clusts; //Number of clusters

int FlagDel=0; //Indicate new data is deleted.

struct Interval {				//Interval sorting 
	double start,mid,end;
}; 

bool compareInterval(Interval i1, Interval i2)
{
	return(i1.start < i2.start);
}

//vvvvvvvvvvvvvvvvvvvvvvvvvvvv//EV

vector<double> EV(CD); //Current Eigen values

void feedEV(){

    // File pointer 
    fstream fin; 
  
    // Open an existing file 
    fin.open("/home/sonalkumar/Desktop/test/AggriInc7/EV.csv", ios::in);
    //cout << "CheakP1";
    
    //vector<double> row;
    
    string line, word, temp;  
    
        EV.clear();
 
        getline(fin, line); 
  
        // used for breaking words 
        stringstream s(line); 
         
        while (getline(s, word, ' ')) { 
  
            //cout << std::stold(word);
            EV.push_back(std::stod(word)); 
        } 
        cout<<"EigenValues are: \n";
        for(auto x: EV) cout << x << ",";
        cout << "\n";
}
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//End

//vvvvvvvvvvvvvvvvvvvvvvvvvvvvv // Rvec


vector<vector<double>> Rvec(3, vector<double> (CD));
vector<Interval> Rvecc(CD);


void feedRvec(){
// File pointer 
    fstream fin_r; 
  
    // Open an existing file 
    fin_r.open("/home/sonalkumar/Desktop/test/AggriInc7/RepVal.csv", ios::in);
    //cout << "CheakP2";
    
    string line_r, word_r;  
    
    int count = 0;
  
    // Feeding Representative value in Rvec
        Rvec[0].clear(); 
  
        // read an entire row and store it in a string variable 'line' 
        getline(fin_r, line_r); 
  
        // used for breaking words 
        stringstream s_r(line_r); 
  	
        // read every column data of a row and store it in a string variable, 'word' 
        while (getline(s_r, word_r, ' ')) { 
  	     //count = count +1;
  	     //cout << count;
            // add all the column data of a row to a vector 
            if(word_r == "nan"){
            	Rvec[0].push_back(0);}
            else{
            //cout << std::stold(word);
            Rvec[0].push_back(std::stold(word_r));}
        } 
        cout << "Representative Points: \n";
        for(int i=0;i<CD;i++){
        cout << Rvec[0][i] << ",";
        //for(auto x: Rvec[0]) cout << x << " ";
       }
        cout << "\n";
        
        //Feeding Cluster label in Rvec
     	
  	fstream fin_c;
  	string line_c, word_c; 
  	fin_c.open("/home/sonalkumar/Desktop/test/AggriInc7/clusterOP.csv", ios::in);
    	//cout << "CheakP3";
        Rvec[2].clear(); 
  
        getline(fin_c, line_c); 
  
        // used for breaking words 
        stringstream s_c(line_c); 
  
        while (getline(s_c, word_c, ' ')) { 
  
            //cout << std::stod(word_c);
            Rvec[2].push_back(std::stod(word_c));
        } 
        cout << "Cluster Lebel: \n";
	for(auto x: Rvec[2]) cout << x << ",";
        cout << "\n";
        
        for (int inx=0;inx<CD;inx++) // feeding data point number to Rvec
    	{
    		Rvec[1].push_back(inx+1);
    	}
    	cout << "Data Point Number: \n";
    	for(auto x: Rvec[1]) cout << x << ",";
        cout << "\n";
        
}

//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//end

//vvvvvvvvvvvvvvvvvvvvvvvvvvvvv // Dvec
vector<vector<double>> Dvec(2, vector<double> (CD));

void feedDvec()
{
//int count=0;
double a,b;
//int flag=0;
std::ifstream infile("/home/sonalkumar/Desktop/test/AggriInc7/aggri.txt");
while(infile >> a >> b){

//cout << typeid(a).name();
//cout << "\n";
Dvec[0].push_back(a);
Dvec[1].push_back(b);

}
cout<<"Data Points: \n";
//for(auto x: Dvec[0]) cout << x << " ";
//cout << "\n";
for(int d=0;d<CD;d++){
	cout<< "("<<Dvec[0][d] << "," << Dvec[1][d]<<")";}

//for(auto x: Dvec[1]) cout << x << " ";
//cout << "\n";
}
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//end

void Rvecsort(){
 	//cout <<"here";
	for(int pv=0; pv<CD; pv++)
	{
		//cout<<"In Loop";
		Interval I={Rvec[0][pv],Rvec[1][pv],Rvec[2][pv]};
		Rvecc.insert(Rvecc.begin(),I);
	}
	
	std::sort(Rvecc.begin(),Rvecc.end(),compareInterval);
	//for(auto x: Rvecc) cout << x.start << " " << x.mid << " " << x.end << "\n"; //printing Rvecc
	return;
}

int OptimalK( )	// Finding Optimal Cluster Number
{
	long double max;
	long double temp,ptemp;//flag;
	vector<long double> Egap(CD-1);
	
	ofstream myRfile;
    	//myRfile.open("/home/sonalkumar/Desktop/test/AggriInc/Eigengap.csv");
    	cout<<"In Func\n";
	//for(int i=0; i<(CD-1); i++)
	//{
		//cout<<"In 1st for Loop"<<i<<"\n";
		//temp = abs(EV[i] - EV[i+1]);
		//Egap.push_back(temp);
		
    		//myRfile << temp << " ";
	//}
	//myRfile.close();
	
	long double Avg=EV[0];
	vector<int> Kopt(CD);
	Kopt.clear();
	for(int j=1; j<CD; j++)
	{
		//cout<< "In 2nd for loop"<<i<<"\n";
		ptemp = abs(EV[j] - EV[j-1]);
	
		if((EV[j-1]-Avg) < ptemp)
		{
			Kopt.push_back(j);
			cout << ptemp << ",";
		}
	
		Avg = ((Avg * j) + EV[j])/(j+1);
	}
	cout<<"\n";
	for(auto x:Kopt) cout<<x<<",";
	cout << "\n";
	
	int kk;
	cout<<"Enter valid Optimal Cluster Number among above options: \n";
	cin>>kk;
	//cout << "Max Value: " << max << "\n";
	//if(Kopt[0]!=1)
	//return Kopt[0];
	//else
	return kk;
}


int GenerateCluster(double x, double y, int Cl)
{
	double AMdist,Avgd,temp;// Avg Minimum distance from clusters
	int AC; //Assined cluster
	int DpointNumber;
	//cout<<"cp1\n";
	for(int c=1;c<(Clusts+1);c++)
	{
		//cout<<"In for loop"<< c <<"\n";
		int k=0,p=0; // k (no. of rep points), p(no. of data points)
		double dist=0,xx,yy; //sum of distance from data points of clusters
		
		cout<<"\nRepresentative points of Cluster " <<c<< " are: \n";
		while(k!=Cl and p!=CD)
		{
			//cout<<"In while loop " << p << "\n";
			//cout << Rvecc[p].end << "," <<Rvecc[p].mid << "\n";
			if(Rvecc[p].end == c) //Define Rvec as 2D vector of Representative value point number, and cluster label
			{
				DpointNumber = Rvecc[p].mid - 1;
				int dp = (int)DpointNumber;
				//cout << dp << "\n";
				//cout << Dvec[dp][0] << "," << Dvec[dp][1]<< "\n";
				xx = Dvec[0][dp];
				yy = Dvec[1][dp];
				
				cout << "("<< xx << "," << yy <<")"<< ",";
				//xx=34;
				//yy=23;
				
				temp = (x-xx)*(x-xx) + (y-yy)*(y-yy); // Define Dvec as 2D to store x and y value of new data points
				//cout<< "temp= " << temp << "\n";
				dist = dist + sqrt(temp);
				k = k+1;
			}
			p = p+1;
			
		}
		//cout<< "Total Dist= " << dist << "\n";
		Avgd = dist/Cl;
		//cout<< "Total Avg Dist= " << Avgd << "\n";
 			
		if(c == 1){
		AMdist = Avgd;
		AC = c;}
		if(AMdist > Avgd){
		AMdist = Avgd;
		AC = c;
		}
		cout<<"\n";
	}
	cout<< "Avg Min Dist= " << AMdist << "\n";
	return AC;
}

tuple<int,int> FindCluster(double p,double q,vector<vector<double>> Nv)
{
		int flag=0,CC=0,Ind;
		for(int m=0;m<Dvec[0].size();m++)
		{
			if(Dvec[0][m] == p and Dvec[1][m] == q)
			{
				CC = Rvec[2][m];
				flag = 1;
			}
		}
		
		if(flag ==0)
		{
			for(int m=0;m<Nv[0].size();m++)
			{
			if(Nv[0][m] == p and Nv[1][m] == q)
			{
				CC = Nv[2][m];
				FlagDel=FlagDel+1;
				Ind=m;
				//cout << FlagDel<<"\n";
				break;
			}
			}
		}
		return make_tuple(CC,Ind);
}

int DuplicateCheak(double p,double q,vector<vector<double>> Nv)
{
		int flag=0,CC=0,Ind;
		for(int m=0;m<Dvec[0].size();m++)
		{
			if(Dvec[0][m] == p and Dvec[1][m] == q)
			{
				flag = 1;
			}
		}
		
		if(flag == 0)
		{
			for(int m=0;m<Nv[0].size();m++)
			{
			if(Nv[0][m] == p and Nv[1][m] == q)
			{
				flag=1;
				break;
			}
			}
		}
		return flag;
		}

int main()
{
	cout << "\nEnter current no. of data points: ";
	cin >> CD;
	
	cout << "\nEnter current no. of Clusters: ";
	cin >> Clusts;
	
	feedEV();
	feedRvec();
	//double Dvec[2][CD];
	feedDvec();
	
	Rvecsort();
	
	int OptimalNum,TempNum=0,TempDel=0,tmp;
	double x,y;
	//long double EV[CD];//Array of Eigen values
	int K = OptimalK();	//Finding optimal cluster number
	
	vector<vector<double>> Nvec(3, vector<double> (K)); //vector to store New Data Points
	vector<vector<double>> Ovec(3, vector<double> (CD)); //Vector to store deleted Data Points 
	
	cout << "\nOptimal Number of Cluster is: " << K;
	cout <<"\n";
	
	OptimalNum = CD/K;
	cout << "\nOptimal Number of data point to be added in one phase is: " << OptimalNum;
	cout << "\n";
	
	//cout<<FlagDel<<"\n";
	
	while(1)
	{
		cout << "\nEnter \n1:Add a data point,\n 2: Current number of added number,\n 3:Print New Data Points,\n 4:Delete a point,\n 5: Current number of data point deleted,\n 6:Print Deleted data points,\n 7:Exit\n";
		cin >> tmp;
		switch(tmp)
		{
			case 1:if (TempNum < OptimalNum) { cout <<"\nEnter first value of data point:\n";
			cin >> x;
			cout <<"\nEnter second value of data point:\n";
			cin >> y;
			if(!DuplicateCheak(x,y,Nvec)){
			int cl = GenerateCluster(x, y, K);
			//cout << cl << "\n";
			
			if(FlagDel!=0){
				cout<<"Inside FlagDel Not Zero\n";
				for(int n=0;n<Nvec[0].size();n++)
				{
					if(Nvec[0][n]==0)
					{
						Nvec[0][n]=x;
						Nvec[1][n]=y;
						Nvec[2][n]=cl;  
						break;
					}
				}
				FlagDel=FlagDel-1;
				cout<<FlagDel<<"\n";
			}
			else{
			Nvec[0][TempNum]=x;
			Nvec[1][TempNum]=y;
			Nvec[2][TempNum]=cl;
			}
			
			TempNum = TempNum + 1;
			cout<<"\nNew data point "<< x << ","<< y << " cluster level is " << cl;
			cout << "\n";
			}
			else
				cout<<"\nDuplicate Point Alert!! Please provide some other input.\n";
			}
			else
			{ 
				cout << "\nNumber of data points to be added exceeded the Optimal number of data points. Please perform static clustering by including newly added data points\n";
				
				ofstream myIfile;
    				myIfile.open("/home/sonalkumar/Desktop/test/AggriInc7/NewData.csv");
    				for(auto N1: Nvec[0]) myIfile << N1 << " ";
    				for(auto N2: Nvec[1]) myIfile << N2 << " ";
    				for(auto N3: Nvec[3]) myIfile << N3 << " ";
    				//myEfile << clusters;
    				myIfile.close();
			}
			break;
			
			case 2: cout << "\nNumber of data points added in this phase is: "<<TempNum<<"\n";
			break;
			
			case 3:cout << "\nNew Data points with cluster Noumber: \n";
			for(int m=0;m<Nvec.size();m++)
			{
				for(int n=0;n<Nvec[m].size();n++)
				{
					cout<<Nvec[m][n]<<" ";
				}
			cout<<endl;
			}
			break;
			
			case 4: double p,q;
			int CurrClust,Index;
			if (TempDel < OptimalNum)
			{
			cout<<"\nEnter first value of the data to be deleted:\n";
			cin>> p;
			cout<<"\nEnter second value of the data to be deleted:\n";
			cin>> q;
			tie(CurrClust,Index)=FindCluster(p,q,Nvec);
			
			cout<<"("<<CurrClust<<","<<Index<<")"<<"\n";
			
			if(CurrClust==0)
			{ cout << "\nData Not Found.\n";}
			else{
			cout <<"\nThe cluster no. of Data point to be deleted i.e. ("<<p<<","<<q<<") is " <<CurrClust<<"\n";
			
			Ovec[0][TempDel]=p;
			Ovec[1][TempDel]=q;
			Ovec[2][TempDel]=CurrClust;
			
			if(FlagDel ==0){
			TempDel=TempDel+1;} //TempDel increases only if data deleted from existing data set
			
			if(FlagDel !=0)	//Removing data point from new data point added
			{	
				Nvec[0][Index]=0;
				Nvec[1][Index]=0;
				Nvec[2][Index]=0;
				TempNum = TempNum-1;
			}
			}
			}
			
			else{
				cout<<"\nNumber of data points to be deleted exceeded the Optimal number of data points. Please perform static clustering by Removing deleted data points\n";
				
				ofstream myOfile;
    				myOfile.open("/home/sonalkumar/Desktop/test/AggriInc7/DelData.csv");
    				for(auto O1: Ovec[0]) myOfile << O1 << " ";
    				for(auto O2: Ovec[1]) myOfile << O2 << " ";
    				for(auto O3: Ovec[2]) myOfile << O3 << " ";
    				myOfile.close();
			}
			break;
			
			case 5: cout << "\nNumber of data points added in this phase is: "<<TempDel<<"\n";
			break;
			
			case 6:cout << "\nDeleted Data points with cluster Noumber: \n";
			for(int m=0;m<Ovec.size();m++)
			{
				for(int n=0;n<Ovec[m].size();n++)
				{
					cout<<Ovec[m][n]<<" ";
				}
			cout<<endl;
			}
			break;
			
			case 7: exit(0);
		}
	}
	return 0;
	
}
