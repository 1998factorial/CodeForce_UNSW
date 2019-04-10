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
const int maxn = 1e5+7;
int dp1[maxn],dp2[maxn],a[maxn]; 
//dp1[i] = length of increasing ending at i
//dp2[i] = length of increasing starting at i
int main()
{
    int n;
    scanf("%d",&n);a[0]=1e9+7,a[n+1]=1e9+7;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n==1)return puts("1"),0;
    if(n==2)return puts("2"),0;
    int ans=0;
    for(int i=1;i<=n;i++){
        dp1[i] = 1;
        if(a[i]>a[i-1])dp1[i]=dp1[i-1]+1;
        ans = max(ans,dp1[i]);
    }
    for(int i=n;i>=1;i--){
        dp2[i]=1;
        if(a[i]<a[i+1])dp2[i]=dp2[i+1]+1;
        ans=max(ans,dp2[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i-1]<a[i+1]-1)
            ans=max(ans,dp1[i-1]+dp2[i+1]+1);
    }
    for(int i=2;i<=n;i++)ans=max(ans,dp2[i]+1); //might miss case
    for(int i=1;i<n;i++)ans=max(ans,dp1[i]+1); 
    cout<<ans<<endl;
}