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
//0000000 -> 1111111
int n,k,cnt;
int ret[1005];
int main(){
	cin >> n, cin >> k;
	int r = n % (2*k+1);
	cnt = 0;
	if(r == 0){
		for(int i = k+1; i <= n; i += 2*k+1){
			ret[cnt++] = i;
		}
	}
	else if(r <= k+1 && r != 0){
		ret[cnt++] = 1;
		for(int i = k+2; i <= n; i += 2*k+1){
			if(i + k <= n)ret[cnt++] = i+k;
			else ret[cnt++] = n;
		}
	}
	else{
		ret[cnt++] = r-k;
		for(int i = r+1; i <= n; i += 2*k+1){
			if(i + k < n)ret[cnt++] = i+k;
		}
	}
	cout << cnt << '\n';
	for(int i = 0; i < cnt; i++)cout << ret[i] << " ";
	cout << '\n';
    return 0;
}