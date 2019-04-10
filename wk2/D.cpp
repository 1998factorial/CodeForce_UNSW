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
int k,n;
int main(){
	cin >> n, cin >> k;
	int total = 240 - k;
	int ret = 0;
	for(int i = 1; i <= n && total >= 0; i++){
		total -= 5*i;
		ret++;
	}
	if(total < 0)ret--;
	cout << ret << endl;
	return 0;
}