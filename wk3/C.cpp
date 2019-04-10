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
int n,k;
int a[200000];
int main(){
	cin >> n, cin >> k;
	ll sum = 0;
	memset(a,0,sizeof(a));
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < k; i++)sum += a[i];
	int ret = 1, m = sum;
	for(int i = 1; i <= n-k; i++){
		if(m > sum-a[i-1]+a[i+k-1]){
			ret = i+1;
			m = sum-a[i-1]+a[i+k-1];
		}
		sum = sum-a[i-1]+a[i+k-1];
	}
	cout << ret << endl;
    return 0;
}