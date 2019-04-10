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
int a[105];
//0 !a&!b, 1 !a&b, 2 a&!b, 3 a&b
int dp[105][3];
int INF = 1 << 30;
//dp[i][0] = minimal day to rest if rest on day i
//dp[i][1] = minimal day to rest if do sport on day i
//dp[i][2] = minimal day to rest if do comp on day i
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++){
		dp[i][0] = dp[i][1] = dp[i][2] = INF;
		if(a[i] == 0){}//have to rest
		else if(a[i] == 1){//comp
			for(int j = 0; j < 3; j++)
				if(dp[i][2] > dp[i-1][j] && j != 2)
					dp[i][2] = dp[i-1][j];
		}
		else if(a[i] == 2){//gym
			for(int j = 0; j < 3; j++)
				if(dp[i][1] > dp[i-1][j] && j != 1)
					dp[i][1] = dp[i-1][j];
		}
		else{//sport/comp
			for(int j = 0; j < 3; j++){
				if(dp[i][1] > dp[i-1][j] && j != 1)
					dp[i][1] = dp[i-1][j];
				if(dp[i][2] > dp[i-1][j] && j != 2)
					dp[i][2] = dp[i-1][j];
			}
		}
		for(int j = 0; j < 3; j++){
			if(dp[i][0] > dp[i-1][j]){
				dp[i][0] = dp[i-1][j] + 1;
			}
		}
	}
	cout << min(dp[n][0],min(dp[n][1],dp[n][2])) << endl;
	return 0;
}