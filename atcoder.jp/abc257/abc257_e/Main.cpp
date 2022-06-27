#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> c(9);
    rep(i,9) cin >> c[i];
    vector<vector<ll>> dp(n,vector<ll> (9,INF));
    rep(i,9) dp[0][i]=c[i];
    for(int i=1;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                dp[i][j]=min(dp[i][j],dp[i-1][j]+c[k]);
            }
        }
    }
    string ans;
    ll mi=0;
    for(int i=n-1;i>=0;i--) {
        bool flag=false;
        rep(j,9) if(dp[i][j]<=n) flag=true;
        if(!flag) continue;
        int k=i;
        while(k>=0) {
            if(k==i) {
                for(int j=8;j>=0;j--) {
                    if(dp[i][j]<=n) {
                        mi=dp[i][j];
                        ans+=char(j+'1');
                        break;
                    }
                }
            } else {
                int l=ans.back()-'1';
                for(int j=8;j>=0;j--) {
                    if(dp[k][j]+c[l]==dp[k+1][l]) {
                        ans+=char(j+'1');
                        break;
                    }
                }
            }
            k--;
        }
        break;
    }
    if(ans[0]!=ans.back()) {
        int l=ans[0]-'1',r=ans.back()-'1';
        int idx=1;
        while(idx<(int)ans.size()) {
            for(int i=l;i>=0;i--) {
                if(mi+(c[i]-c[r])<=n) {
                    mi+=c[i]-c[r];
                    ans[idx++]=char(i+'1');
                    l=i;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}