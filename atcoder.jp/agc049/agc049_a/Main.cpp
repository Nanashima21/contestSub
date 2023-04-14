#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<bool>> g(n,vector<bool> (n,false));
    rep(i,n) rep(j,n) g[i][j]=s[i][j]-'0';
    rep(k,n) rep(i,n) rep(j,n) g[i][j]=g[i][j]|(g[i][k]&g[k][j]);
    double ans=0.0;
    rep(i,n) {
        int cnt=1;
        rep(j,n) if(i!=j&&g[j][i]) cnt++;
        ans+=1.0/cnt;
    }
    printf("%.10f\n",ans);
    return 0;
}