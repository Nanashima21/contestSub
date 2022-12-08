#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

char c[]={'S','W'};

int main() {
    int n; string s;
    cin >> n >> s;
    string ans="-1";
    rep(i,2) rep(j,2) {
        string str;
        str+=c[i];
        str+=c[j];
        for(int l=1;l<n;l++) {
            if(str[l]=='S') {
                if(s[l]=='o') {
                    str+=str[l-1];
                } else {
                    if(str[l-1]=='S') str+='W';
                    else str+='S';
                }
            } else {
                if(s[l]!='o') {
                    str+=str[l-1];
                } else {
                    if(str[l-1]=='S') str+='W';
                    else str+='S';
                }
            }
        }
        if(str[0]!=str.back()) continue;
        if(s[0]=='o') {
            if(str[0]=='S'&&str[n-1]!=str[1]) continue;
            if(str[0]=='W'&&str[n-1]==str[1]) continue;
        } else {
            if(str[0]=='W'&&str[n-1]!=str[1]) continue;
            if(str[0]=='S'&&str[n-1]==str[1]) continue;
        }
        ans=str;
    }   
    cout << ans.substr(0,n) << endl;
    return 0;
}