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
    bool flag=true;
    string str;
    for(char c:s) if(c!='A') str+=c;
    if(str!="KIHBR") flag=false;
    rep(i,(int)s.size()) {
        if(s[i]=='A') {
            if(i==0||i==(int)s.size()-1) continue;
            if(s[i-1]=='H'&&s[i+1]=='B') continue;
            if(s[i-1]=='B'&&s[i+1]=='R') continue;
            flag=false;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}