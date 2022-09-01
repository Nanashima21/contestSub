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
    string a,b,c;
    cin >> a >> b >> c;
    int ans=0;
    rep(i,n) {
        set<char> se;
        se.insert(a[i]);
        se.insert(b[i]);
        se.insert(c[i]);
        ans+=(int)se.size()-1;
    }
    cout << ans << endl;
    return 0;
}