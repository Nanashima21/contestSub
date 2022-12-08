#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x; string s;
    cin >> n >> x >> s;
    int cnt=0;
    for(char c:s) {
        if(c=='U') {
            if(cnt>0) cnt--;
            else x/=2;
        } else if(c=='L') {
            if(x*2>1e18) cnt++;
            else x=x*2;
        } else {
            if(x*2+1>1e18) cnt++;
            else x=x*2+1;
        }
    }
    cout << x << endl;
    return 0;
}