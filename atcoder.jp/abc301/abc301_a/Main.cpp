#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s;
    cin >> n >> s;
    vector<int> cnt(2,0);
    for(char c:s) {
        if(c=='T') {
            cnt[0]++;
            if(cnt[0]==(n+1)/2) {
                cout << c << endl;
                return 0;
            }
        } else {
            cnt[1]++;
            if(cnt[1]==(n+1)/2) {
                cout << c << endl;
                return 0;
            }
        }
    }
    return 0;
}