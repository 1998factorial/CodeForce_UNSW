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
int n,q;
int main(){
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++)cin >> x[i];
	cin >> q;
	sort(x.begin(),x.end());
	vector<int> ret;
	for(int i = 0; i < q; i++){
		int m;
		cin >> m;
		ret.push_back(upper_bound(x.begin(),x.end(),m)-x.begin());
		/*
		error with this binary search
		int k = -1;
		for(int b = n/2; b >= 1; b /= 2){
			while(b + k < n && x[b + k] <= m[i])k += b;
		}
		if(k == -1)ret.push_back(0);
		else ret.push_back(k+1);
		*/
	}
	for(int i = 0; i < q; i++)cout << ret[i] << '\n';
    return 0;
}