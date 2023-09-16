#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll a,b;
    cin >> a >> b;
    ll c=1,d=1;
    rep(i,a) c*=b;
    rep(i,b) d*=a;
    cout << c+d << endl;
    return 0;
}