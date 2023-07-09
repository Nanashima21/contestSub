#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<ll> v3(1,3);

ll f(ll n) {
    ll ret=0;
    rep(i,(int)v3.size()) ret+=n/v3[i];
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(v3.back()<=1e18) {
        v3.push_back(v3.back()*3);
    }
    while(t--) {
        ll n,k;
        cin >> n >> k;
        ll l=n-2*f(n);
        bool flag=false;
        if(l<=k&&k<=n&&k%2==l%2) flag=true;
        cout << (flag ? "Yes" : "No") << endl; 
    }
    return 0;
}