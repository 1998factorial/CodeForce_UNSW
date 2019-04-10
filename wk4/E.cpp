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

int n;
int a[100005];
int dp[100005];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	int ret = 0;
	for(int i = 1; i < n; i++){
		if(a[i] > a[i-1])dp[i] = dp[i-1] + 1;
		else dp[i] = 1;
		ret = max(dp[i],ret);
	}
	for(int i = 1; i < n; i++){
		int j = i - dp[i] + 1;
		if(j > 0){
			if(i == j)
				ret = max(ret,dp[j-1]+1);
			if(j == 1)
				ret = max(ret,dp[i]+1);
			else{
				if(a[j+1]-1 > a[j-1] || a[j-2]+1 < a[j])
					ret = max(ret,dp[i]+dp[j-1]);
			}
		}
	}
	cout << ret << endl;
	return 0;
}