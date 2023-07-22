#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    set<char> s;
    int n; string str;
    cin >> n >> str;
    rep(i,n) {
        s.insert(str[i]);
        if((int)s.size()==3) {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}