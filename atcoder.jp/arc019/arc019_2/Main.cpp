#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    int x=(int)s.size();
    string ns=s.substr(0,x/2);
    string rs=s.substr(x/2+(x%2==1),x-x/2);
    reverse(all(rs));
    int dif=0;
    rep(i,x/2) if(ns[i]!=rs[i]) dif++;
    int ans=0;
    rep(i,x/2) {
        if(dif!=1) {
            ans+=50;
        } else {
            if(ns[i]==rs[i]) ans+=50;
            else ans+=48;
        }
    }
    if(x%2==1&&dif!=0) ans+=25;
    cout << ans << endl;
    return 0;
}