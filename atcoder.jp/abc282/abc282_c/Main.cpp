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
    int cnt=0;
    rep(i,n) {
        if(s[i]=='"') cnt++;
        if(s[i]==','&&cnt%2==0) s[i]='.';
    }
    cout << s << endl;
    return 0;
}