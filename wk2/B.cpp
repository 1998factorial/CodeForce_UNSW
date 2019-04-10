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

string a[3];
//A > B  B > C A > C
//A > B, B > C, B > A
int main(){
	for(int i = 0; i < 3; i++){
		cin >> a[i];
		if(a[i][1] == '<'){
			swap(a[i][0],a[i][2]);
			a[i][1] = '>';
		}
	}
	sort(a,a+3);	
	vector<int> p[3];
	for(int i = 0; i < 3; i++){
		int x = a[i][0]-'A',y = a[i][2]-'A';
		p[x].push_back(y);
	}
	string ans = "";
	for(int i = 0; i < 3; i++){
		if(p[i].size() == 0){
			ans += i+'A';
			break;
		}
	}
	for(int i = 0; i < 3; i++){
		if(p[i].size() == 1){
			ans += i+'A';
			break;
		}
	}
	for(int i = 0; i < 3; i++){
		if(p[i].size() == 2){
			ans += i+'A';
			break;
		}
	}
	if(ans.size() == 3)cout << ans << endl;
	else cout << "Impossible" << endl;
	return 0;
}

