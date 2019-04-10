#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
using namespace std;


int main(){
	string a;
	cin >> a;
	int n = a.size(), ret = 0;
	int cur = 0;
	for(int i = 0; i < n; i++){
		int x = a[i]-'a';
		int y = 26 - x + cur;
		int z = 26 - cur + x;
		int p = abs(cur - x);
		ret += min(p,min(y,z));
		cur = x;
	}
	cout << ret << endl;
	return 0;
}