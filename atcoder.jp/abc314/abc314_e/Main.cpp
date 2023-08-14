#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> c(n),p(n);
    vector<vector<ll>> s(n,vector<ll> ());
    rep(i,n) {
        cin >> c[i] >> p[i];
        ll sum=0;
        rep(j,p[i]) {
            ll a;
            cin >> a;
            s[i].push_back(a);
            sum+=a;
        }
    }
    vector<double> dp(m+1,INF);
    dp[0]=0.0;
    for(int i=1;i<=m;i++) {
        rep(j,n) {
            int cnt=0;
            double sum=0.0;
            rep(k,p[j]) {
                if(s[j][k]==0) cnt++;
                else sum+=dp[max(0LL,i-s[j][k])]/(1.0*p[j]);
            }
            dp[i]=min(dp[i],(sum+c[j])*p[j]/(1.0*p[j]-cnt));
        }
    } 
    printf("%.10f\n",dp[m]); 
    return 0;
}