#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    ll h,w,k;
    cin >> h >> w >> k;
    k--;
    vector<vector<ll>> dp(h+1,vector<ll> (w,0));
    dp[0][0]=1;
    for(int i=1;i<=h;i++) {
        for(int bit=0;bit<(1<<(w-1));bit++) {
            vector<bool> vec; 
            rep(j,w-1) vec.push_back(bit>>j&1);
            bool flag=true;
            rep(j,w-2) if(vec[j]&&vec[j+1]) flag=false;
            if(!flag) continue;
            rep(j,w-1) if(vec[j]) {
                dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=mod;
                dp[i][j+1]+=dp[i-1][j];
                dp[i][j+1]%=mod; 
            }
            
            if((int)vec.size()==0||!vec[0]) dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;
            if(w>1&&!vec[w-2]) dp[i][w-1]=(dp[i][w-1]+dp[i-1][w-1])%mod;
            for(int j=1;j<w-1;j++) if(!vec[j-1]&&!vec[j]) {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            } 
        } 
    }
    cout << dp[h][k] << endl;
    return 0;
}