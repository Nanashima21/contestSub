#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,p;
    cin >> n >> m >> p;
    ll cnt=0;
    while(m<=n) {
        m+=p;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}