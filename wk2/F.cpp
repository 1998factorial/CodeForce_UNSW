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

typedef long long int64;

int n,m,k;
int64 a[200001];

int main(){
	cin >> n, cin >> m, cin >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int64 ret = 0;
	ret = (m/(k+1))*a[n-2] + (m % (k+1))*a[n-1] + (m/(k+1))*k*a[n-1];
	cout << ret << endl;
	return 0;
}