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

int n,k;
int s[100001];

int main(){
	cin >> n, cin >> k;
	for(int i = 0; i < n; i++)cin >> s[i];
	int i = n-1;
	int ret = -1; 
	for(; i >= 0 && (i+1) < k*2; i--,k--){
		ret = max(s[i],ret);
	}
	int j = 0;
	while(i >= j){
		if(i == j){
			ret = max(ret,s[i]);
		}
		else{
			ret = max(ret,s[i]+s[j]);
		}
		i--,j++;
	}
	cout << ret << endl;
	return 0;
}