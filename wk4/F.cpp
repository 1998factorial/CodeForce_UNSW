#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
using namespace std;


int g[1005][1005];
int n,m;
int row[1005][1005],col[1005][1005];
//row[i][j] = i th row sum [0...j-1]
//col[i][j] = i th col sum [0...j-1]
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
		}
	}
	for(int j = 0; j < n; j++){
		row[j][0] = g[j][0];
		for(int i = 1; i < m; i++){
			row[j][i] = g[j][i] + row[j][i-1];
		}	
	}
	for(int i = 0; i < m; i++){
		col[i][0] = g[0][i];
		for(int j = 1; j < n; j++){
			col[i][j] = col[i][j-1] + g[j][i];
		}
	}
	int ret = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!g[i][j]){
				//check 4 dir
				if(row[i][j] > 0)ret++;
				if(row[i][m-1]-row[i][j] > 0)ret++;
				if(col[j][i] > 0)ret++;
				if(col[j][n-1]-col[j][i] > 0)ret++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}