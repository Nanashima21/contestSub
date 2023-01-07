#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

bool isprime(ll x) {
    if(x<2) return 0;
    else if(x==2) return 1;
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}

ll _sqrt(ll x) {
    ll l=1,r=1e10;
    while(r-l>1) {
        ll mid=(l+r)/2;
        ll y=mid*mid;
        if(y==x) return mid;
        else if(y>x) r=mid; 
        else l=mid;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    vector<ll> p;
    for(ll i=2;i<=3e6;i++) {
        if(isprime(i)) p.push_back(i);
    }
    while(t--) {
        ll n;
        cin >> n;
        for(auto u:p) {
            if(n%(u*u)==0) {
                cout << u << " " << n/(u*u) << endl;
                break;
            }
            if(n%u==0) {
                cout << _sqrt(n/u) << " " << u << endl;
                break;
            }
        }
    }
    return 0;
}