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
const ll mod = 1e9+7; 
ll dp[2005][2005]; //dp[i][j] = # of good seq with length i ending with j
//n,k<=2000
//bool d[2005][2005]; //t <=> i | j
vector<int> d[2005];

int n,k;
int main(){
	cin >> n, cin >> k;
	ll ret = 0;
	for(int i = 0; i < 2005; i++)d[i].clear();
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(i % j == 0)d[i].push_back(j);
		}
	}
	for(int i = 1; i <= n; i++)dp[1][i] = 1;
	for(int len = 2; len <= k; len++){
		for(int i = 1; i <= n; i++){
			int m = d[i].size();
			for(int j = 0; j < m; j++){
				dp[len][i] = (dp[len-1][d[i][j]] + dp[len][i]) % mod;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		ret = (ret + dp[k][i]) % mod;
	cout << ret << endl;
    return 0;
}