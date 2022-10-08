#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> flag(n,vector<bool> (n,false));
    rep(i,m) {
        int k;
        cin >> k;
        vector<int> a(k);
        rep(j,k) {
            cin >> a[j];
            a[j]--;
        }
        rep(j,k) rep(l,k) {
            flag[a[j]][a[l]]=true;
            flag[a[l]][a[j]]=true;
        }
    }
    bool check=true;
    rep(i,n) rep(j,n) if(!flag[i][j]) check=false;
    cout << (check ? "Yes" : "No") << endl;
    return 0;
}