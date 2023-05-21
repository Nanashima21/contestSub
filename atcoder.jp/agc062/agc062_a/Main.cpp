#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

void f(string s) {
    string str=s;
    while((int)str.size()>1) {
        string sa,sb;
        rep(i,(int)str.size()-1) {
            if(str[i]=='A') sa+=str[i+1];
            else sb+=str[i+1];
        }
        str=sa+sb;
    }
    cout << s << " " << str << endl;
}

vector<pair<char,int>> runlength(string s) {
    int x=s.size();
    vector<pair<char,int>> res;
    char pre=s[0];
    int cnt=1;
    for(int i=1;i<x;i++) {
        if(pre!=s[i]) {
            res.push_back({pre,cnt});
            pre=s[i]; cnt=1;
        } else cnt++;
    }
    res.push_back({pre,cnt});
    return res;
    //auto rl=runlength(s)
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        auto rl=runlength(s);
        if((int)rl.size()==1) cout << rl[0].first << '\n';
        else if((int)rl.size()==2&&rl[0].first=='A'&&rl[1].first=='B') cout << "B\n";
        else cout << "A\n";  
    }

    /*
    ll n;
    cin >> n;
    for(int i=0;i<(1<<n);i++) {
        string s;
        rep(j,n) {
            if(i&1<<j) s+='A';
            else s+='B';
        }
        f(s);
    }*/
    return 0;
}