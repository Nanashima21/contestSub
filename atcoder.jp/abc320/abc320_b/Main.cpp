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
    int n=(int)s.size();
    ll ma=0;
    rep(i,n) {
        string str;
        for(int j=i;j<n;j++) {
            str+=s[j];
            string rstr=str;
            reverse(all(rstr));
            if(rstr==str) ma=max(ma,(ll)str.size());
        }
    }
    cout << ma << endl;
    return 0;
}