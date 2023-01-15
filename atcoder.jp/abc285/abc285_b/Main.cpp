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
    rep(i,n-1) {
        int cnt=0;
        rep(j,n-i-1) {
            if(s[j]==s[i+j+1]) {
                break;
            } else cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}