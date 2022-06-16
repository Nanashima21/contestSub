#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(ll x) {
    if(x%4==0) return x;
    else if(x%4==1) return 1;
    else if(x%4==2) return x+1;
    else return 0;
}

int main() {
    ll a,b;
    cin >> a >> b;
    ll l=f(max(0LL,a-1)),r=f(b);
    cout << (l^r) << endl;
    return 0;
}