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
    ll cnt=0;
    rep(i,(int)s.size()) {
        if(s[i]=='0') {
            if(i==(int)s.size()-1) cnt++;
            else if(s[i+1]=='0') {
                cnt++;
                i++;
            } else cnt++;
        } else cnt++;
    }
    cout << cnt << endl;
    return 0;
}