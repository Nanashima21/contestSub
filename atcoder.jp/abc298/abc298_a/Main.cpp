#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s;
    cin >> n >> s;
    int x=0,y=0;
    rep(i,n) {
        if(s[i]=='o') x++;
        if(s[i]=='x') y++;
    }
    if(y!=0) cout << "No" << endl;
    else if(x>0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}