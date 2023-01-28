#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    int x=(int)s.size();
    int y=(int)t.size();
    string str=s.substr(x-y);
    int cnt=0;
    rep(i,y) {
        if(str[i]=='?'||t[i]=='?'||str[i]==t[i]) continue;
        cnt++;
    }
    cout << (cnt==0 ? "Yes" : "No") << '\n';
    rep(i,y) {
        if(t[i]=='?') {
            cout << (cnt==0 ? "Yes" : "No") << '\n';
            continue;
        }
        if(s[i]=='?') {
            if(str[i]=='?') {
                cout << (cnt==0 ? "Yes" : "No") << '\n';
            } else {
                if(str[i]!=t[i]) cnt--;
                cout << (cnt==0 ? "Yes" : "No") << '\n';
            }
            continue;
        }
        if(str[i]=='?') {
            if(s[i]!=t[i]) cnt++;
            cout << (cnt==0 ? "Yes" : "No") << '\n';
            continue;
        }
        if(str[i]==t[i]&&s[i]!=t[i]) cnt++;
        if(str[i]!=t[i]&&s[i]==t[i]) cnt--;
        cout << (cnt==0 ? "Yes" : "No") << '\n';
    }
    return 0;
}