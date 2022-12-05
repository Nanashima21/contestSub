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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans=0;
    if(n==1) {
        if(s[0][0]=='.') ans=1;
    } else {
        rep(i,n-1) for(int j=n-1;j>=0;j--) {
            if(s[i][j]=='.') {
                for(int k=j;k<n;k++) s[i+1][k]='o';
                ans++;
                break;
            }
        }
        rep(i,n) if(s[n-1][i]=='.') {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}