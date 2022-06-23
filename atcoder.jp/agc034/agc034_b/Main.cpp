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
    int x=s.size();
    ll ans=0;
    for(int i=0;i<x-2;i++) {
        string str=s.substr(i,3);
        if(str=="ABC") {
            int j=i,k=i;
            ll cnta=0,cntbc=0;
            while(j>=0&&s[j]=='A') {
                cnta++;
                j--;
            }
            while(k+2<x&&s[k+1]=='B'&&s[k+2]=='C') {
                cntbc++;
                k+=2;
            }
            ans+=cnta*cntbc;
            while(cnta--) s[k--]='A';
            s[k]='B';
        }
    }
    cout << ans << endl;
    return 0;
}