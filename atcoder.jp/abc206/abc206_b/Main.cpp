#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    ll tot=0;
    for(ll i=1;;i++) {
        tot+=i;
        if(tot>=n) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}