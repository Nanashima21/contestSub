#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q; string s;
    cin >> n >> s >> q;
    int type=0;
    map<int,char> mp;
    while(q--) {
        int t,x; char c;
        cin >> t >> x >> c;
        if(t==1) {
            x--;
            s[x]=c;
            mp[x]=c;
        } else if(t==2) {
            mp.clear();
            type=1;
        } else {
            mp.clear();
            type=2;
        }
    }
    string str=s;
    if(type==1) rep(i,n) str[i]=tolower(s[i]);
    if(type==2) rep(i,n) str[i]=toupper(s[i]);
    for(auto u:mp) str[u.first]=u.second;
    cout << str << endl;
    return 0;
}