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
ll dp1[105][105]; 
//dp[i][j] = # ways to write i as (1 <= xi <= k), given last number is j
ll dp2[105][105];
//dp[i][j] = # ways to write i as (1 <= xi < d), given last number is j
int n,k,d;
int main(){
	cin >> n >> k >> d;
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	for(int i = 1; i <= k; i++)dp1[i][i] = 1;
	for(int i = 1; i <= k && i < d; i++)dp2[i][i] = 1;
	for(int i = 1; i <= n; i++){	
		for(int j = 1; j <= k && j <= i; j++){
			for(int p = 1; p <= k && p <= i-j; p++){
				dp1[i][j] = (dp1[i][j] + dp1[i-j][p] + mod) % mod;
			}
		}
	}
	for(int i = 1; i <= n; i++){	
		for(int j = 1; j < d && j <= i; j++){
			for(int p = 1; p < d && p <= i-j; p++){
				dp2[i][j] = (dp2[i][j] + dp2[i-j][p] + mod) % mod;
			}
		}
	}
	ll ret = 0, total = 0;
	for(int i = 1; i <= k; i++)
		total = (total + dp1[n][i] + mod) % mod;
	for(int i = 1; i < d; i++)
		ret = (ret + dp2[n][i] + mod) % mod;
	cout << (total - ret + mod) % mod << endl;
	return 0;
}