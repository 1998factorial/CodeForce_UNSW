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
int n;
int64 a[100001];
int main(){
	cin >> n;
	memset(a,0,sizeof(a));
	int64 mx = 0,sum = 0;
	for(int i = 0; i < n; i++)cin >> a[i],sum += a[i],mx = max(mx,a[i]);
	if(sum % (n-1) != 0) sum = sum/(n-1) + 1;
	else sum = sum/(n-1);
	cout << max(mx,sum) << endl;
	return 0;
}