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
	int x,y,s;
	cin >> x, cin >> y, cin >> s;
	int dis = abs(x) + abs(y);
	if(s - dis >= 0 && (s - dis) % 2 == 0)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}