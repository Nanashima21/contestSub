#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    bool flag=false;
    rep(i,n) {
        string s;
        cin >> s;
        if(s=="and") flag=true;
        if(s=="not") flag=true;
        if(s=="that") flag=true;
        if(s=="the") flag=true;
        if(s=="you") flag=true;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}