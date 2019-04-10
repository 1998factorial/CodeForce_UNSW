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
	int a,b,c;
	cin >> a, cin >> b, cin >> c;
	int h = max(a,max(b,c));
	int l = min(a,min(b,c));
	int d = 1 << 29;
	for(int i = l; i <= h; i++){
		int dis = abs(i - a) + abs(i - b) + abs(i - c);
		if(dis < d)
			d = dis;
	}
	cout << d << endl;
	return 0;
}