#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m; string s,t;
    cin >> n >> m >> s >> t;
    int q=100;
    while(q--) {
        for(int i=0;i<n-m+1;i++) {
            bool flag=true;
            rep(j,m) {
                if(s[i+j]=='#') continue;
                if(s[i+j]!=t[j]) flag=false;
            }
            if(flag) {
                rep(j,m) s[i+j]='#';
            }
        }
        reverse(all(s));
        reverse(all(t));
        for(int i=0;i<n-m+1;i++) {
            bool flag=true;
            rep(j,m) {
                if(s[i+j]=='#') continue;
                if(s[i+j]!=t[j]) flag=false;
            }
            if(flag) {
                rep(j,m) s[i+j]='#';
            }
        }
    }
    string st;
    rep(i,n) st+='#';
    cout << ((st==s) ? "Yes" : "No") << endl;
    return 0;
}