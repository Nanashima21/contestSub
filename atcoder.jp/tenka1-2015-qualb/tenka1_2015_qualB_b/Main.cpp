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
    int cnt=0;
    rep(i,(int)s.size()) {
        if(s[i]==':'&&cnt==1) {
            cout << "dict" << endl;
            return 0;
        } 
        else if(s[i]==','&&cnt==1) {
            cout << "set" << endl;
            return 0;
        }
        else if(s[i]=='{') cnt++;
        else if(s[i]=='}') cnt--;
    }
    if((int)s.size()==2) cout << "dict" << endl;
    else cout << "set" << endl;
    return 0;
}