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
    string s;
    cin >> s;
    ll idx=0;
    while(q--) {
        ll t,x;
        cin >> t >> x;
        if(t==1) {
            idx+=x;
        } else {
            x--;
            cout << s[(x-idx+n*500500)%n] << endl;
        }
    }
    return 0;
}