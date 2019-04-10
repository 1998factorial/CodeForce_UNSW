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
	int a, b, c;
	cin >> a, cin >> b, cin >> c;
	int i = 1;
	for(;i <= a && 2*i <= b && 4*i <= c; i++){

	}
	i--;
	cout << i + 2*i + 4*i << endl;
	return 0;
}
