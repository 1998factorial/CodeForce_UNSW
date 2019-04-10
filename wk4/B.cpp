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
#include <unordered_map>
#include <complex>
using namespace std;
typedef pair<int,int> ii;
//bool g[400][400];
int dp[500];
int n;
int main(){
	cin >> n;
	int cnt = 1;
	unordered_map<string,int> mp;
	memset(dp,0,sizeof(dp));
	vector<ii> a;
	for(int i = 1; i <= n; i++){
		string t, name1 = "", name2 = "";
		cin >> name1 >> t >> name2;
		transform(name1.begin(),name1.end(),name1.begin(),::tolower);
		transform(name2.begin(),name2.end(),name2.begin(),::tolower);
		if(mp.count(name1) == 0)mp[name1] = cnt, cnt++;
		if(mp.count(name2) == 0)mp[name2] = cnt, cnt++;
		a.push_back(make_pair(mp[name1],mp[name2]));
		//(i,j) -> (i repost j)
	}
	sort(a.begin(),a.end());
	dp[a[0].second] = 1;
	dp[a[0].first] = dp[a[0].second] + 1;
	int ret = 2;
	for(int i = 1; i < n; i++){
		int x = a[i].first, y = a[i].second; //x repost y
		dp[x] = max(dp[x],dp[y]+1);
		ret = max(dp[x],ret);
	}
	cout << ret << endl;
	return 0;
}