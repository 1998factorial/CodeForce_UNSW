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
int a[505];

int main(){
	cin >> n, cin >> k;
	memset(a,0,sizeof(a));
	for(int i = 0; i < n; i++)cin >> a[i];
	int ret = 0;
	for(int i = 0; i < n-1; i++){
		if(a[i]+a[i+1] < k){
			ret += k - a[i] - a[i+1]; 
			a[i+1] = k - a[i];
		}
	}
	cout << ret << endl;
	for(int i = 0; i < n-1; i++)cout << a[i] << " ";
	cout << a[n-1] << endl;
    return 0;
}