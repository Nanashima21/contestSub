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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b;
    rep(i,n) {
        b.push_back(0);
        rep(j,(int)b.size()) {
            b[j]+=a[i];
        } 
    }
    int cnt=0;
    rep(i,(int)b.size()) if(b[i]>3) cnt++;
    cout << cnt << endl;
    return 0;
}