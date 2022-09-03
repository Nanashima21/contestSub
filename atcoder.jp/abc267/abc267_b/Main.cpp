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
    bool flag=false;
    vector<bool> check(7,true);
    if(s[6]=='0') check[0]=false;
    if(s[3]=='0') check[1]=false;
    if(s[1]=='0'&&s[7]=='0') check[2]=false;
    if(s[0]=='0'&&s[4]=='0') check[3]=false;
    if(s[2]=='0'&&s[8]=='0') check[4]=false;
    if(s[5]=='0') check[5]=false;
    if(s[9]=='0') check[6]=false;
    for(int i=1;i<6;i++) {
        bool f1=false,f2=false;
        if(!check[i]) {
            for(int j=0;j<i;j++) if(check[j]) f1=true;
            for(int j=i+1;j<7;j++) if(check[j]) f2=true;
        }
        if(f1&&f2) flag=true;
    }
    if(s[0]=='1') flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}