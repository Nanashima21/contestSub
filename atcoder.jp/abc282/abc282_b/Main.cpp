#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int cnt=0;
    rep(i,n) for(int j=i+1;j<n;j++) {
        bool flag=true;
        rep(k,m) if(s[i][k]=='x'&&s[j][k]=='x') flag=false;
        if(flag) cnt++;
    }
    cout << cnt << endl;
    return 0;
}