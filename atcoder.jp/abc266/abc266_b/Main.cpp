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
    const ll mod=998244353;
    while(true) {
        if(0<=n&&n<mod) break;
        n+=mod;
        n%=mod; 
    }
    cout << n << endl;
    return 0;
}