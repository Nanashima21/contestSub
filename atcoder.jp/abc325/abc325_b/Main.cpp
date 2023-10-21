#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(24,0);
    rep(i,n) {
        ll w,x;
        cin >> w >> x;
        for(int i=9;i<18;i++) v[(x+i)%24]+=w;
    }
    cout << *max_element(all(v)) << endl;
    return 0;
}