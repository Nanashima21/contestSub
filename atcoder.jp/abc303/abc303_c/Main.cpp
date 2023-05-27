#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int,int> > se;
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        se.insert(make_pair(x,y));
    } 
    int cx=0,cy=0;
    rep(i,n) {
        if(s[i]=='R') cx++;
        if(s[i]=='L') cx--;
        if(s[i]=='U') cy++;
        if(s[i]=='D') cy--;
        h--;
        if(h<0) {
            cout << "No" << endl;
            return 0;
        }
        if(se.find(make_pair(cx,cy))!=se.end()) {
            if(h<k) {
                h=k;
                se.erase(make_pair(cx,cy));
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}