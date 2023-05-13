#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans;
    rep(i,n-1) {
        if(a[i]<a[i+1]) {
            for(int j=a[i];j<a[i+1];j++) ans.push_back(j);
        } else {
            for(int j=a[i];j>a[i+1];j--) ans.push_back(j);
        }
    }
    ans.push_back(a.back());
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}