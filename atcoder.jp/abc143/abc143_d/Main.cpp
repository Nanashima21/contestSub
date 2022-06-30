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
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    sort(all(l));
    ll ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ll x=abs(l[i]-l[j]),y=l[i]+l[j];
            int it1=upper_bound(all(l),x)-l.begin();
            int it2=lower_bound(all(l),y)-l.begin();
            ll tot=it2-it1;
            if(x<l[i]&&l[i]<y) tot--;
            if(x<l[j]&&l[j]<y) tot--;
            ans+=tot;
        }
    }
    cout << ans/3 << endl;
    return 0;
}