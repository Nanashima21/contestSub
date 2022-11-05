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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    set<ll> se;
    map<ll,ll> mp;
    queue<ll> q;
    ll gc=a[0];
    rep(i,n) gc=gcd(gc,a[i]);
    q.push(gc);
    se.insert(gc);
    mp[gc]=0;
    while(!q.empty()) {
        ll cv=q.front();
        q.pop();
        if(cv*2<=1e10&&se.find(cv*2)==se.end()) {
            se.insert(cv*2);
            mp[cv*2]=mp[cv]+1;
            q.push(cv*2);
        }
        if(cv*3<=1e10&&se.find(cv*3)==se.end()) {
            se.insert(cv*3);
            mp[cv*3]=mp[cv]+1;
            q.push(cv*3);
        }
    }
    bool flag=true;
    rep(i,n) if(se.find(a[i])==se.end()) flag=false;
    if(!flag) cout << -1 << endl;
    else {
        ll tot=0;
        rep(i,n) tot+=mp[a[i]];
        cout << tot << endl;
    }
    return 0;
}