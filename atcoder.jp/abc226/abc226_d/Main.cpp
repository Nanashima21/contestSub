#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll gcd(ll x,ll y){
    if(y==0) return x;
    else return gcd(y,x%y);
}

ll lcm(ll x,ll y){
    return ll(x/gcd(x,y))*y;
}

int main() {
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    set<pl> v;
    rep(i,n) for(int j=i+1;j<n;j++) {
        ll xi=x[i],yi=y[i];
        ll xj=x[j],yj=y[j];
        if(xi==xj) v.insert({0,INF}); 
        else if(yi==yj) v.insert({INF,0});
        else {
            ll a=yj-yi;
            ll b=xj-xi;
            v.insert({a/gcd(a,b),b/gcd(a,b)});
        }
    }
    cout << (ll)v.size()*2 << endl;
    return 0;
}