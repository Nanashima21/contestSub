#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll a,b;
    cin >> a >> b;
    ll cnt=0;
    while(a!=b) {
        if(a==0||b==0) break;
        if(a>b) {
            ll x=a/b;
            a=a-x*b;
            cnt+=x;
        } else if(a<b) {
            ll x=b/a;
            b=b-x*a;
            cnt+=x;
        }
    }
    cout << max(cnt-1,0LL) << endl;
    return 0;
}