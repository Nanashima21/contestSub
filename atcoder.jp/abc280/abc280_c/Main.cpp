#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    int ans=(int)s.size()+1;
    rep(i,(int)s.size()) {
        if(s[i]!=t[i]) ans=min(i+1,ans);
    }
    if(ans==-1) ans=(int)s.size()+1;
    cout << ans << endl;
    return 0;
}