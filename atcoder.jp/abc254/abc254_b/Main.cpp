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
    vector<vector<ll>> v(n,vector<ll> ());
    v[0].push_back(1);
    for(int i=1;i<n;i++) {
        rep(j,i+1) {
            if(j==0) v[i].push_back(1);
            else if(j==i) v[i].push_back(1);
            else v[i].push_back(v[i-1][j-1]+v[i-1][j]); 
        }
    }
    rep(i,n) {
        rep(j,(int)v[i].size()) {
            if(j) cout << " ";
            cout << v[i][j];
        } cout << endl;
    }
    return 0;
}