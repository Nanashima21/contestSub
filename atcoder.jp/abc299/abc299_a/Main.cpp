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
    int x=-1,y=-1,z=-1;
    rep(i,n) {
        if(s[i]=='|') {
            if(x==-1) x=i;
            else y=i;
        } 
        if(s[i]=='*') z=i;
    }
    cout << (x<z&&z<y ? "in" : "out") << endl;
    return 0;
}