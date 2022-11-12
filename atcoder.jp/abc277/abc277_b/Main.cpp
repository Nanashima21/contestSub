#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

char x[]={'H','D','C','S'};
char y[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

int main() {
    int n;
    cin >> n;
    map<string,int> mp;
    bool flag=true;
    rep(i,n) {
        string s;
        cin >> s;
        bool f1=false;
        bool f2=false;
        rep(j,4) if(s[0]==x[j]) f1=true;
        rep(j,13) if(s[1]==y[j]) f2=true;
        if(!f1) flag=false;
        if(!f2) flag=false; 
        mp[s]++;
        if(mp[s]!=1) flag=false;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}