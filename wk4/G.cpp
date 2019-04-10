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
	}
	for(int i = 0; i < q; i++)cout << ret[i] << '\n';
    return 0;
}