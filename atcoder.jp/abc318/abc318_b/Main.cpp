#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> cnt(101,vector<int> (101,0));
    rep(i,n) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j=a;j<b;j++) {
            for(int k=c;k<d;k++) {
                cnt[j][k]++;
            }
        }
    }
    ll ans=0; 
    rep(i,101) rep(j,101) if(cnt[i][j]!=0) ans++;
    cout << ans << endl;
    return 0;
}