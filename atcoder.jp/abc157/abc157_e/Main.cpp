#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s;
    cin >> n >> s;
    vector<set<int>> v(26);
    rep(i,n) v[s[i]-'a'].insert(i);
    rep(i,26) v[i].insert(n+1);
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int i; char c;
            cin >> i >> c;
            i--;
            v[s[i]-'a'].erase(i);
            v[c-'a'].insert(i);
            s[i]=c;
        } else {
            int l,r;
            cin >> l >> r;
            l--; r--;
            int cnt=0;
            rep(i,26) {
                auto itl=v[i].lower_bound(l);
                auto itr=v[i].upper_bound(r);
                if(itl!=itr) cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}