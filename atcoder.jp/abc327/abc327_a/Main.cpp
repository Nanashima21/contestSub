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
    string s;
    cin >> s;
    bool flag=false;
    rep(i,n) {
        if(s[i]=='a') {
            if(i&&s[i-1]=='b') flag=true;
            if(i+1<n&&s[i+1]=='b') flag=true;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}