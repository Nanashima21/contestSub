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
    vector<int> c(n);
    vector<vector<bool>> f(n,vector<bool> (38));
    rep(i,n) {
        cin >> c[i];
        rep(j,c[i]) {
            int a;
            cin >> a;
            f[i][a]=true;
        }
    }
    int x;
    cin >> x;
    int mi=100;
    rep(i,n) if(f[i][x]) mi=min(mi,c[i]);
    vector<int> ans;
    rep(i,n) if(f[i][x]&&mi==c[i]) ans.push_back(i+1);
    cout << (int)ans.size() << endl;
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl; 
    return 0;
}