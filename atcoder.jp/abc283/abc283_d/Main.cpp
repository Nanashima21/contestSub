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
    vector<vector<int>> v(26,vector<int> ());
    ll cnt=0;
    bool flag=true;
    rep(i,(int)s.size()) {
        if(s[i]=='(') cnt++;
        else if(s[i]==')') {
            rep(j,26) {
                int num=0;
                while((int)v[j].size()!=0&&v[j].back()==cnt) {
                    v[j].pop_back();
                    num++;
                }
                if(num>=2) flag=false;
            }
            cnt--;
        } else {
            if((int)v[s[i]-'a'].size()!=0&&v[s[i]-'a'].back()<cnt) flag=false;
            v[s[i]-'a'].push_back(cnt);
        }
    } 
    rep(j,26) {
        int num=0;
        while((int)v[j].size()!=0&&v[j].back()==cnt) {
            v[j].pop_back();
            num++;
        }
        if(num>=2) flag=false;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}