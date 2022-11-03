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
    vector<ll> v(5);
    ll mi=INF;
    rep(i,5) {
        cin >> v[i];
        mi=min(mi,v[i]);
    }
    if(mi>=n) cout << 5 << endl;
    else cout << n/mi+(n%mi!=0)+4 << endl;
    return 0;
}