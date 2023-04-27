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
    vector<vector<char>> ans(n,vector<char> (n,'.'));
    int cur=0;
    rep(i,n) {
        rep(j,3) {
            ans[i][cur]='#';
            cur++;
            cur%=n;
        }
    }
    if(n%3!=0) {
        swap(ans[0],ans[n/3-1]);
        swap(ans[n-1],ans[n-n/3]);
    } 
    rep(i,n) {
        rep(j,n) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}