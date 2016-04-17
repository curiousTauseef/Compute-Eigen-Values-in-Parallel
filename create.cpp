#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

#include "omp.h"

using namespace std;

int main(){
	int N;
	cin >> N;

	vector<vector<double> > mat(N, vector<double> (N));

	//creating file
	stringstream ss;
	ss << N;
	string s;
	ss >> s;
	s = s+".txt";
	cout << s << endl;
	ofstream mfile (s.c_str());

	#pragma omp parallel for private(i, j)
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i > j){
				mat[i][j] = mat[j][i];
			}
			else{
				mat[i][j] = rand()%100000 + 1;
			}
			//cout << mat[i][j] << "    " ;
		}
		//cout << endl;
	}
	

	return 0;
}