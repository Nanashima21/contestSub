#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s;
    cin >> n >> s;
    rep(i,n-1) {
        if(s[i]=='n'&&s[i+1]=='a') {
            cout << s[i] << "y";
        } else cout << s[i];
    }
    cout << s.back() << endl;
    return 0;
}