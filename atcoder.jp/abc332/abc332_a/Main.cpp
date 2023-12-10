#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,s,k;
    cin >> n >> s >> k;
    ll tot=0;
    rep(i,n) {
        ll p,q;
        cin >> p >> q;
        tot+=p*q;
    }
    if(tot<s) tot+=k;
    cout << tot << endl;
    return 0;
}