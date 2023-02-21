#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll n,k;
vector<ll> a;

ll get_minus(ll x) {
    vector<ll> mi,pl;
    rep(i,n) {
        if(a[i]<0) mi.push_back(a[i]);
        if(a[i]>0) pl.push_back(a[i]);
    }
    ll ret=0,pidx=0;
    rep(midx,(int)mi.size()) {
        while(pidx<(int)pl.size() && x<mi[midx]*pl[pidx]) pidx++;
        ret+=pl.size()-pidx;
    }
    return ret;
}

ll zero() {
    ll z=0;
    rep(i,n) if(a[i]==0) z++;
    return z*(n-z)+z*(z-1)/2; 
}

ll get_plus(ll x) {
    vector<ll> mi,pl;
    rep(i,n) if(a[i]>0) pl.push_back(a[i]);
    rep(i,n) if(a[n-i-1]<0) mi.push_back(a[n-i-1]); 
    ll ret=0;
    ll r=(int)mi.size()-1;
    rep(l,(int)mi.size()) {
        while(l<r && x<mi[l]*mi[r]) r--;
        ret+=max(0LL,r-l);
    }
    r=(int)pl.size()-1;
    rep(l,(int)pl.size()) {
        while(l<r && x<pl[l]*pl[r]) r--;
        ret+=max(0LL,r-l);
    }
    return ret;
}

ll cnt(ll x) {
    ll ret=get_minus(min(x,-1LL));
    if(x>=0) ret+=zero();
    if(x>0) ret+=get_plus(x);
    return ret;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll l=-INF,r=INF;
    while(r-l>1) {
        ll mid=(l+r)/2;
        if(k<=cnt(mid)) r=mid;
        else l=mid;
    }
    cout << r << endl;
    return 0;
}