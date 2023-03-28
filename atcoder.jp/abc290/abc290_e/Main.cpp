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
    vector<vector<ll>> p(n+1,vector<ll> ());
    rep(i,n) {
        int a;
        cin >> a;
        p[a].push_back(i+1);
    }
    ll ans=0;
    rep(i,n+1) ans+=(n+1-i)*(i/2);
    rep(i,n+1) {
        ll l=0,r=(int)p[i].size()-1;
        while(l<r) {
            if(p[i][l]<n+1-p[i][r]) {
                ans-=(r-l)*p[i][l];
                l++;
            } else {
                ans-=(r-l)*(n+1-p[i][r]);
                r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}