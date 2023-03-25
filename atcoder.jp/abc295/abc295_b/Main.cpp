#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int r,c;
    cin >> r >> c;
    vector<string> s(r);
    rep(i,r) cin >> s[i];
    rep(i,r) {
        rep(j,c) {
            if(s[i][j]=='.') continue;
            if(s[i][j]=='#') continue;
            int n=s[i][j]-'0';
            rep(x,r) rep(y,c) {
                if('1'<=s[x][y]&&s[x][y]<='9') continue;
                if(abs(i-x)+abs(j-y)<=n) s[x][y]='.';
            }
        }
    }
    rep(i,r) {
        rep(j,c) {
            if('1'<=s[i][j]&&s[i][j]<='9') cout << '.';
            else cout << s[i][j];
        }
        cout << endl;;
    }
    return 0;
}