#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll a,b,n;
    cin >> a >> b >> n;
    ll x=min(b-1,n);
    cout << floor(a*x/b)-a*floor(x/b) << endl;
    return 0;
}