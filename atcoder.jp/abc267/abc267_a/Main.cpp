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
    int ans=0;
    if(s[0]=='M') ans=5; 
    if(s[0]=='T'&&s[1]=='u') ans=4;
    if(s[0]=='W') ans=3;
    if(s[0]=='T'&&s[1]=='h') ans=2;
    if(s[0]=='F') ans=1;
    cout << ans << endl;
    return 0;
}