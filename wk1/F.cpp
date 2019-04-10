#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
using namespace std;

typedef long long int64;
int main(){
	int n,m;
	cin >> n, cin >> m;
	int a,b;
	vector<int64> ret;
	set<int> col,row;
	for(int i = 0; i < m; i++){
		cin >> a, cin >> b;
		row.insert(a),col.insert(b); 
		int64 cnt_col = (int64)col.size(), cnt_row = (int64)row.size(), ans = (int64)n*n;
		ans -= (n*cnt_row + n*cnt_col - cnt_col*cnt_row);
		ret.push_back(ans);
	}
	for(int i = 0; i < m; i++)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}