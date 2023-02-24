#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans=0;
    rep(k,n) {
        bool flag=true;
        rep(i,n) rep(j,n) {
            if(s[(i+k)%n][j]!=s[(j+k)%n][i]) flag=false;
        }
        if(flag) ans++;
    }
    cout << ans*n << endl;
    return 0;
}