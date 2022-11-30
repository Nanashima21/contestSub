#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    string ans;
    if(a==b) {
        if(n%(a+1)==0) ans="Aoki";
        else ans="Takahashi";
    } else if(a>b) ans="Takahashi";
    else {
        if(n<=a) ans="Takahashi";
        else ans="Aoki";
    }
    cout << ans << endl;
    return 0;
}