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
    ll ma=0;
    rep(i,n) rep(j,n) {
        for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++) {
            ll num=s[i][j]-'0';
            if(dx==0&&dy==0) continue;
            int cx=i,cy=j;
            rep(r,n-1) {
                cx=(cx+dx+n)%n,cy=(cy+dy+n)%n;
                num*=10;
                num+=s[cx][cy]-'0';
            }
            ma=max(ma,num);
        }
    }
    cout << ma << endl;
    return 0;
}