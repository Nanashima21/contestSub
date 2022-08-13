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
    string str="atcoder";
    int cnt=0;
    rep(i,7) {
        rep(j,7) {
            if(str[i]==s[j]) {
                if(i>=j) break;
                int idx=j; 
                while(str[i]!=s[i]) {
                    swap(s[idx],s[idx-1]);
                    idx--;
                    cnt++;
                }
            }
        }
    } 
    cout << cnt << endl;
    return 0;
}