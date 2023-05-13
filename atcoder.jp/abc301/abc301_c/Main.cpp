#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    vector<int> cnt(26,0);
    int cnts=0,cntt=0;
    rep(i,(int)s.size()) {
        if(s[i]!='@') cnt[s[i]-'a']++;
        else cnts++;
        if(t[i]!='@') cnt[t[i]-'a']--;
        else cntt++;
    }
    bool check=true;
    string at="atcoder";
    rep(i,26) {
        bool flag=false;
        for(char c:at) if(c-'a'==i) flag=true;
        if(cnt[i]!=0&&!flag) check=false;
        if(cnt[i]!=0&&flag) {
            if(cnt[i]>0) cntt-=cnt[i];
            if(cnt[i]<0) cnts+=cnt[i];
        }  
    }
    if(cnts<0||cntt<0) check=false;
    if(cnts!=cntt) check=false;
    cout << (check ? "Yes" : "No") << endl;
    return 0;
}