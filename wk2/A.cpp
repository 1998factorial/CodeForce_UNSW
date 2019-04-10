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
double l;
double a[1005];

int main(){
	cin >> n, cin >> l;
	memset(a,0.0,sizeof(a));
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	double ret = max(2*a[0],2*(l-a[n-1]));
	for(int i = 1; i < n; i++){
		ret = max(ret,(a[i]-a[i-1]));
	}
	printf("%f\n",ret/2);
	return 0;
}