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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
  	ll tot=0;
    rep(i,n) tot+=a[i]-1;
    cout << tot << endl;
    return 0;
}