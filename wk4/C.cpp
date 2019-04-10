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

double dp[100001]; //dp[i] = prob ending at city i start from city 1
double dis[100001]; //dis[i] = distance from city 1 to city i
vector<int> v[100001]; //graph
vector<int> end_points; //possible ending cities
int N; 

void DFS(int cur, int pre){
	int cnt = 0, m = v[cur].size();
	dis[cur] = dis[pre] + 1.0;
	for(int j = 0; j < m; j++){
		if(v[cur][j] != pre){
			cnt++;
			DFS(v[cur][j],cur);
		}
	}
	if(!cnt)end_points.push_back(cur);
}

void DFS2(int cur, int pre, int c){
	dp[cur] = dp[pre] * 1.0/(double)c;
	int cnt = 0, m = v[cur].size();
	for(int i = 0; i < m; i++){
		if(v[cur][i] != pre)cnt++;
	}
	for(int i = 0; i < m; i++){
		if(v[cur][i] != pre)
			DFS2(v[cur][i],cur,cnt);
	}
}

int main(){
	cin >> N;
	memset(dp,0.0,sizeof(dp));
	memset(dis,0.0,sizeof(dis));
	for(int i = 1; i <= N; i++)v[i].clear();
	end_points.clear();
	for(int i = 1; i < N; i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dis[0] = -1.0;
	DFS(1,0); //find all distance & end possible end points
	dp[0] = 1.0;
	DFS2(1,0,1);
	double ret = 0.0;
	int m = end_points.size();
	for(int i = 0; i < m; i++)
		ret += dp[end_points[i]] * dis[end_points[i]]; //prob * dist
	printf("%f\n",ret);
	return 0;
}
