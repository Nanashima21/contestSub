#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    vector<char> stk;
    rep(i,(int)s.size()) {
        if((int)stk.size()>=2) {
            char x=stk.back();
            char y=stk[(int)stk.size()-2];
            // cout << y << x << s[i] << endl;
            if(y=='A'&&x=='B'&&s[i]=='C') {
                stk.pop_back();
                stk.pop_back();
                continue;
            } 
        } 
        stk.push_back(s[i]);
    }   
    for(char c:stk) cout << c;
    cout << endl;
    return 0;
}