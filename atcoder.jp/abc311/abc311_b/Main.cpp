#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,d;
    cin >> n >> d;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans=0,cnt=0;
    rep(j,d) {
        bool flag=true;
        rep(i,n) {
            if(s[i][j]=='x') flag=false;
        }
        if(flag) cnt++;
        else cnt=0;
        ans=max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}