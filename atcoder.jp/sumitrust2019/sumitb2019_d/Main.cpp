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
    vector<vector<bool>> l(n,vector<bool> (10));
    l[0][s[0]-'0']=true;
    for(int i=1;i<n;i++) {
        rep(j,10) l[i][j]=l[i-1][j];
        l[i][s[i]-'0']=true;
    } 
    vector<vector<bool>> r(n,vector<bool> (10));
    r[n-1][s[n-1]-'0']=true;
    for(int i=n-2;i>=0;i--) {
        rep(j,10) r[i][j]=r[i+1][j];
        r[i][s[i]-'0']=true;
    } 
    set<string> se;
    for(int i=1;i<n-1;i++) {
        rep(j,10) rep(k,10) {
            if(l[i-1][j]&&r[i+1][k]) {
                string str;
                str+=char(j+'0');
                str+=s[i];
                str+=char(k+'0');
                se.insert(str);
            }
        }
    }
    cout << (int)se.size() << endl;
    return 0;
}