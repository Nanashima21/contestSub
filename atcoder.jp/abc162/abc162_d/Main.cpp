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
    ll r=0,g=0,b=0;
    for(char c:s) {
        if(c=='R') r++;
        if(c=='G') g++;
        if(c=='B') b++;
    }
    ll all=r*g*b;
    for(int i=1;i<n-1;i++) {
        for(int j=1;;j++) {
            if(i-j<0||i+j>=n) break;
            if(s[i]!=s[i+j]&&s[i]!=s[i-j]&&s[i-j]!=s[i+j]) all--;
        }
    }
    cout << all << endl;
    return 0;
}