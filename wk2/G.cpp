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
int n,m,k;
int b[100005];
vector<int> diff;
bool used[100005];


static bool cmp(int a, int b){
	return diff[a] > diff[b];
}

int main(){
	cin >> n, cin >> m, cin >> k;
	memset(b,0,sizeof(b));
	memset(used,false,sizeof(used));
	diff.clear();
	for(int i = 0; i < n; i++)cin >> b[i];	
	int cost = b[n-1] - b[0] + 1; //total
	for(int i = 1; i < n; i++){
		diff.push_back(b[i] - b[i-1]);
	}
	sort(diff.begin(),diff.end());
	int p = diff.size();
	for(int i = p-1; i > p-k; i--){
		cost -= diff[i] - 1;
	}
	cout << cost << endl;
	return 0;
}



