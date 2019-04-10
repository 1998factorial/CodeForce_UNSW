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

typedef long long ll;
//dp1 = take b[i]
//dp2 = dont take b[i]
int n;
int main(){
    cin >> n;
    if(!n)return 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(),a.end()); //sort
    int cnt = 1;
    int b[100001];
    memset(b,0,sizeof(b));
    b[0] = a[0];
    map<int,int> mp; //mp[i] = # i in a
    mp[a[0]]++;
    for(int i = 1; i < n; i++){
        mp[a[i]]++;
        if(a[i] != a[i-1]){
            b[cnt] = a[i];
            cnt++;
        }
    }
    //get into blocks
    ll dp1 = (ll)b[0]*mp[b[0]],dp2 = 0;
    for(int i = 1; i < cnt; i++){
        if(b[i] == b[i-1] + 1){//either take b[i] or b[i-1]
            ll take = dp1, dont = dp2;
            dp1 = dont + (ll)mp[b[i]]*b[i];
            dp2 = max(take,dont);
        }
        else{//can take both b[i] and b[i-1]
            ll take = dp1, dont = dp2;
            dp1 = max(take,dont) + (ll)mp[b[i]]*b[i];
            dp2 = max(take,dont);
        }
    }
    cout << max(dp1,dp2) << endl;
    return 0;
}