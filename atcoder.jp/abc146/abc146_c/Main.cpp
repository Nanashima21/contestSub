#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll a,b,x;
    cin >> a >> b >> x;
    for(ll i=20;i>=1;i--) {
        ll y=x-b*i;
        if(y<=0) continue;
        ll z=y/a;
        if(i<=(int)to_string(z).size()) {
            if(z>1e9) z=1e9;
            else if(i!=(int)to_string(z).size()) z=pow(10,i)-1;
            cout << z << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}