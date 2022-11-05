#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    rep(i,(int)s.size()) {
        if(s[(int)s.size()-i-1]=='a') {
            cout << s.size()-i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}