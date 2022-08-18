#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,q; string s;
    cin >> n >> s >> q;
    int cnt=0;
    rep(i,q) {
        int t,a,b;
        cin >> t >> a >> b;
        a--; b--;
        if(cnt%2==0) {
            if(t==1) swap(s[a],s[b]);
            else cnt++;
        } else {
            if(t==1) swap(s[(a+n)%(2*n)],s[(b+n)%(2*n)]);
            else cnt++;
        }
    }
    if(cnt%2==0) cout << s << endl;
    else cout << s.substr(n) << s.substr(0,n) << endl; 
    return 0;
}