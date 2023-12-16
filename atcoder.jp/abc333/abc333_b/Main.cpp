#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    string str="ABCDE";
    int s1=0,s2=0;
    int t1=0,t2=0;
    rep(i,5) {
        if(s[0]==str[i]) s1=i;
        if(s[1]==str[i]) s2=i;
        if(t[0]==str[i]) t1=i;
        if(t[1]==str[i]) t2=i;
    }
    bool flag=false;
    // cout << s1 << ' ' << s2 << " " << t1 << " " << t2 << endl;
    if(abs(s1-s2)==4&&abs(t1-t2)==1) flag=true;
    if(abs(s1-s2)==1&&abs(t1-t2)==4) flag=true;
    if(abs(s1-s2)==1&&abs(t1-t2)==1) flag=true;
    if(2<=abs(s1-s2)&&abs(s1-s2)<=3&&2<=abs(t1-t2)&&abs(t1-t2)<=3) flag=true;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}