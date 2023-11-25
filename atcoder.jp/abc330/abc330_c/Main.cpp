#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll d;
    cin >> d;
    vector<ll> v;
    for(ll i=0;i*i<=4e12;i++) {
        v.push_back(i*i);
    }
    ll ans=INF;
    for(auto u:v) {
        ll z=u-d;
        if(z<0) {
            int it=lower_bound(all(v),-z)-v.begin();
            for(int i=max(0,it-2);i<=min((int)v.size()-1,it+1);i++) {
                ans=min(ans,abs(z+v[i]));
            }
        } else ans=min(ans,abs(z));
    }
    cout << ans << endl;
    return 0;
}