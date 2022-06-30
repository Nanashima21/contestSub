#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll a,b,k;
    cin >> a >> b >> k;
    set<ll> se;
    for(int i=a;i<a+k;i++) if(i<=b) se.insert(i);
    for(int i=b;i>b-k;i--) if(i>=a) se.insert(i);
    for(auto u:se) cout << u << endl;
    return 0;
}