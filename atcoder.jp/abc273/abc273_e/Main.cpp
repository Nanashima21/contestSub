#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

struct node {
    ll val,par;
    node(ll _v,ll _p) : val(_v), par(_p) {};
};

int main() {
    int q;
    cin >> q;
    vector<node> g;
    int cv=0;
    g.push_back(node(-1,0));
    map<ll,ll> mp;
    rep(i,q) {
        string s;
        cin >> s;
        if(s[0]=='D') {
            cv=g[cv].par;
        } else {
            ll x;
            cin >> x;
            if(s[0]=='A') {
                g.push_back(node(x,cv));
                cv=(int)g.size()-1;
            } else if(s[0]=='S') {
                mp[x]=cv;
            } else if(s[0]=='L') {
                cv=mp[x];
            }
        }
        if(i) cout << " ";
        cout << g[cv].val;
    }
    cout << endl;
    return 0;
}