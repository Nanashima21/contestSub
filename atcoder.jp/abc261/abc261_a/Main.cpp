#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<int> v(110,0);
    rep(i,2) {
        int l,r;
        cin >> l >> r;
        for(int i=l;i<r;i++) v[i]++;
    }
    int cnt=0;
    for(int i=0;i<110;i++) if(v[i]==2) cnt++;
    cout << cnt << endl;
    return 0;
}