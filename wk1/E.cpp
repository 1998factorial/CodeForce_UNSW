#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int A[10005];

int main(){
	while(1){
		cin >> N;
		if(N == 0)break;
		memset(A,0,sizeof(A));
		for(int i = 0; i < N; i++)cin >> A[i];
		int dp = 0, ret = 0;
		for(int i = 0; i < N; i++){
			if(dp < 0)dp = A[i];
			else dp += A[i];
			ret = max(ret,dp);
		}
		if(dp > 0)cout << "The maximum winning streak is " << ret << "." <<endl;
		else cout << "Losing streak." << endl;
	}
	return 0;
}