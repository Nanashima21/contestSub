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
    int n=(int)s.size();
    s=" "+s;
    bool flag=true;
    if(s[1]=='0'||s[n-1]=='0') flag=false;
    if(s[n]=='1') flag=false;
    for(int i=1;i<n;i++) if(s[i]!=s[n-i]) flag=false;
    if(!flag) {
        cout << -1 << endl;
        return 0;
    }
    s[n]='1';
    queue<int> q;
    for(int i=1;i<=n;i++) if(s[i]=='1') q.push(i);
    for(int i=1;i<n;i++) {
        if(i==q.front()) q.pop();
        cout << i << " " << q.front() << endl;
    }
    return 0;
}