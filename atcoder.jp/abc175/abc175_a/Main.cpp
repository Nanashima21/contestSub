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
    int ans=1;
    if(s[0]==s[1]&&s[1]==s[2]&&s[0]=='R') ans=3;
    else if(s[0]==s[1]&&s[0]=='R') ans=2;
    else if(s[1]==s[2]&&s[2]=='R') ans=2;
    else if(s[0]==s[1]&&s[1]==s[2]&&s[0]=='S') ans=0;
    cout << ans << endl;
    return 0;
}