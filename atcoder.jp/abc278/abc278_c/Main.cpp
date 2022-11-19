#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    set<pl> se;
    while(q--) {
        ll t,a,b;
        cin >> t >> a >> b;
        a--; b--;
        if(t==1) {
            se.insert({a,b});
        } else if(t==2) {
            se.erase({a,b});
        } else {
            bool flag=true;
            if(se.find({a,b})==se.end()) flag=false;
            if(se.find({b,a})==se.end()) flag=false;
            cout << (flag ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}