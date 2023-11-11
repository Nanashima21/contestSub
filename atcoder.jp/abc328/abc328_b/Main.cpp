#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int cnt=0;
    rep(i,n) {
        for(int j=1;j<=d[i];j++) {
            string str;
            str+=to_string(i+1);
            str+=to_string(j);
            set<char> se;
            for(char c:str) se.insert(c);
            if((int)se.size()==1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}