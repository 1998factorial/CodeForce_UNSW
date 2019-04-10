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
typedef long long ll;
int n;
int c[100001];
ll INF = 1LL << 60;

int main(){
	cin >> n;
	vector<string> a;
	memset(c,0,sizeof(c));
	for(int i = 0; i < n; i++)cin >> c[i];
	for(int i = 0; i < n; i++){
		string t;
		cin >> t, a.push_back(t);
	}
	ll ret = 0,dp1 = (ll)c[0], dp2 = 0; 
	int i = 1;
	for(; i < n; i++){
		string x0 = a[i], x1 = a[i], y0 = a[i-1], y1 = a[i-1];
		reverse(x1.begin(),x1.end()),reverse(y1.begin(),y1.end());
		ll dp1_i = INF, dp2_i = INF;
		if(x1 >= y0)dp1_i = min(dp1_i,dp2);
		if(x1 >= y1)dp1_i = min(dp1_i,dp1);
		if(x0 >= y0)dp2_i = min(dp2_i,dp2);
		if(x0 >= y1)dp2_i = min(dp2_i,dp1);
		dp1 = dp1_i,dp2 = dp2_i;
		if(dp1 == INF && dp2 == INF)break;
		dp1 += (ll)c[i];
	}
	if(i == n)cout << min(dp1,dp2) << endl;
	else cout << -1 << '\n';
    return 0;
}