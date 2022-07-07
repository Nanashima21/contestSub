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
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    ll lc=lcm(n,m);
    bool flag=true;
    map<ll,char> v;
    map<ll,bool> mp;
    for(ll i=0;i<n;i++) {
        v[i*(lc/n)]=s[i];
        mp[i*(lc/n)]=true;
    }
    for(ll i=0;i<m;i++) {
        if(mp[i*(lc/m)]&&v[i*(lc/m)]!=t[i]) flag=false;
    }
    if(flag) cout << lc << endl;
    else cout << -1 << endl;
    return 0;
}