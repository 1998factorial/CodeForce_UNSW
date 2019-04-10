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
int A[6000];
int main(){
	int n;
	cin >> n;
	memset(A,0,sizeof(A));
	for(int i = 1; i <= n; i++)cin >> A[i];
	for(int i = 1; i <= n; i++){
		int a = i, b = A[i], c = A[b], d = A[c];
		if(i != b && i != c && b != c && a == d){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}