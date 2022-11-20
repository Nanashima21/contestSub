#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int M,N; //Nは構築するグラフの頂点数
double eps;
vector<ll> num;
vector<vector<vector<int>>> pred;
int pd_loop=750;
vector<string> graph_str;

void make_graph(int M) {
    N=M;
    ll div=2;
    for(int i=0;i<M;i++) {
        string str;
        vector<int> cnt(N);
        for(int j=0;j<N;j++) {
            for(int k=j+1;k<N;k++) {
                if(i<N/div) {
                    if(j<i) {
                        cnt[j]++;
                        cnt[k]++;
                        str+='1';
                    } else {
                        if(i%2==1) {
                            if(j<=N/2) str+='0';
                            else if(cnt[j]<N&&cnt[k]<N) {
                                cnt[j]++;
                                cnt[k]++;
                                str+='1';
                            } else str+='0';
                        } else str+='0';
                    }
                } else {
                    if(j<i) {
                        if(cnt[j]<i&&cnt[k]<i) {
                            cnt[j]++;
                            cnt[k]++;
                            str+='1';
                        } else str+='0'; 
                    } else {
                        if(i%2==1) {
                            if(j==i+1||j==i+2) str+='0';
                            else if(cnt[j]<N-i&&cnt[k]<N-i) {
                                cnt[j]++;
                                cnt[k]++;
                                str+='1';
                            } else str+='0';
                        } else str+='0';
                    }
                }
            }
        }/*
        cout << endl;
        rep(j,(int)cnt.size()) {
            if(j) cout << " ";
            cout << cnt[j];
        } cout << endl;*/
        graph_str.push_back(str);
    }
}

void make_graph0(int M) {
    vector<int> vec(4,0);
    for(int i=4;i<=100;i++) vec.push_back(i*(i-1)/2+1);
    int it=lower_bound(all(vec),M)-vec.begin();
    N=it;
    for(int i=0;i<M;i++) {
        string str;
        for(int j=0;j<N*(N-1)/2;j++) {
            if(j<i) str+='1';
            else str+='0';
        }
        graph_str.push_back(str);
    }
}

void predict(int M) {
    pred.resize(M,vector<vector<int>> (pd_loop,vector<int> ()));
    for(int i=0;i<M;i++) {
        for(int l=0;l<pd_loop;l++) {
            vector<int> cnt(N,0);
            int idx=0;
            for(int j=0;j<N;j++) {
                for(int k=j+1;k<N;k++) {
                    int num=graph_str[i][idx++]-'0';
                    if(rand()%100<eps*100.0) num=1-num;
                    cnt[j]+=num;
                    cnt[k]+=num;
                }
            }
            sort(all(cnt));
            pred[i][l]=cnt;
        }
    }
}

void query() {
    rep(k,100) {
        string in_str;
        cin >> in_str;
        vector<int> cnt(N,0);
        int idx=0;
        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                if(in_str[idx++]=='1') {
                    cnt[i]++;
                    cnt[j]++;
                }
            }
        }
        sort(all(cnt));
        ll out_num=-1,min_score=INF;
        for(int i=0;i<M;i++) {
            ll score=0;
            for(int j=0;j<pd_loop;j++) {
                for(int l=0;l<N;l++) {
                    score+=abs(pred[i][j][l]-cnt[l]);
                }
            }
            if(min_score>score) {
                min_score=score;
                out_num=i;
            } 
        }
        cout << out_num << "\n";
    }
}

int main() {
    cin >> M >> eps;
    if(eps==0.0) make_graph0(M);
    else make_graph(M);
    predict(M);
    cout << N << endl;
    for(string str:graph_str) cout << str << endl;
    query();
    return 0;
}