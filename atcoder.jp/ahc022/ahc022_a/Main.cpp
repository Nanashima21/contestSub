#include <bits/stdc++.h>
using namespace std;
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;
typedef pair<ll,ll> pl;

// clock-wise
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

struct Pos {
    int y, x;
};

struct Judge {
    int measure_cnt;

    void set_temperature(const vector<vector<int> >& temperature) {
        measure_cnt = 0;
        for (const vector<int>& row : temperature) {
            for (int i = 0; i < (int)row.size(); i++) {
                cout << row[i] << (i == (int)row.size() - 1 ? "\n" : " ");
            }
        }
        cout.flush();
    }

    int measure(int i, int y, int x, int &tot, int &cnt) {
        cnt++; 
        if (measure_cnt == 10000) return 0;
        cout << i << " " << y << " " << x << endl; 
        int v;
        cin >> v;
        if (v == -1) {
            cerr << "something went wrong. i=" << i << " y=" << y << " x=" << x << endl;
            exit(1);
        }
        tot += v;
        measure_cnt++;
        return v;
    }

    void answer(const vector<int>& estimate) {
        cout << "-1 -1 -1" << endl;
        int cnt = 0;
        for (int e : estimate) {
            cout << "# " << cnt++ << endl;
            cout << e << endl;
        }
    }
};

struct Solver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;
    vector<vector<int> > grid;

    Solver(int L, int N, int S, const vector<Pos>& landing_pos) : 
        L(L), N(N), S(S), landing_pos(landing_pos), judge() {
        grid.resize(N, vector<int> (N, 0));
        for (int i = 0; i < N; i++) {
            grid[landing_pos[i].y][landing_pos[i].x] = 1;
        }
    }

    void solve() {
        const vector<vector<int> > temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    vector<vector<int> > create_temperature() {
        vector<vector<int> > temperature(L, vector<int>(L, 0));
        if (S > 4) temperature[L/2][L/2] = min(1000, 6*S+1);
        else {
            vector<vector<bool> > flag(L, vector<bool> (L, false));

            queue<pair<int, int> > que;
            que.push(make_pair(L/2, L/2));
            flag[L/2][L/2] = true;

            int num = 0;
            if (grid[L/2][L/2]) num++;

            while (!que.empty()) {
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = (cy + dy[i] + L) % L;
                    int nx = (cx + dx[i] + L) % L;
                    if (flag[ny][nx]) continue;
                    flag[ny][nx] = true;
                    temperature[ny][nx] = num * (2 * S + 1);
                    if (grid[ny][nx]) num++;
                    que.push(make_pair(ny, nx));
                }
            }

            while (true) { 
                vector<vector<int> > pre_temperature = temperature;

                for (int y = 0; y < L; y++) {
                    for (int x = 0; x < L; x++) {
                        if (grid[y][x]) continue;
                        int tot = 0;
                        for (int i = 0; i < 4; i++) {
                            int ny = (y + dy[i] + L) % L;
                            int nx = (x + dx[i] + L) % L;
                            tot += temperature[ny][nx];
                        }
                        temperature[y][x] = tot / 4;
                    }
                }

                if(pre_temperature == temperature) break;
            }
        }

        return temperature;
    }

    vector<int> predict(const vector<vector<int> >& temperature) {
        vector<vector<int> > predict_ave(N, vector<int>(N, 0));
        vector<vector<int> > predict_cnt(N, vector<int>(N, 0));
        vector<int> estimate(N, -1);
        vector<bool> isestimated(N, false);

        if (S <= 4) {

            vector<int> restimate(N, -1);
            vector<vector<int> > measure_res(N, vector<int>());
            queue<int> que;
            for (int i_in = 0; i_in < N; i_in++) que.push(i_in);

            while (!que.empty()) {
                int i_in = que.front();
                que.pop();

                int tot = 0, cnt = 0;
                int loop_cnt = 3;
                while (loop_cnt--) measure_res[i_in].push_back(judge.measure(i_in, 0, 0, tot, cnt));

                int i_in_num = (int)measure_res[i_in].size();
                int ret = accumulate(measure_res[i_in].begin(), measure_res[i_in].end(), 0);
                ret /= i_in_num;

                for (int i_out = 0; i_out < N; i_out++) {
                    if (isestimated[i_out]) continue;
                    int temp = temperature[landing_pos[i_out].y][landing_pos[i_out].x];
                    if (max(0, temp - S) <= ret && ret <= min(1000, temp + S)) {
                        estimate[i_in] = i_out;
                        restimate[i_out] = i_in;
                        isestimated[i_out] = true;
                        break;
                    }
                }  

                if (i_in_num == 9) {
                    que.push(i_in);
                    continue;
                }

                if (estimate[i_in] == -1) {
                    for (int i_out = 0; i_out < N; i_out++) {
                        int temp = temperature[landing_pos[i_out].y][landing_pos[i_out].x];
                        if (max(0, temp - S) <= ret && ret <= min(1000, temp + S)) {
                            estimate[i_in] = i_out;
                            que.push(i_in);
                            que.push(restimate[i_out]);
                            restimate[i_out] = i_in;
                            isestimated[i_out] = true;
                            break;
                        }
                    }  
                }
            }

        } else {
            
            int loop_cnt = S <= 484 ? 100 : 5;
            while (loop_cnt--) {
            if (judge.measure_cnt == 10000) break;
            
            for (int i_in = 0; i_in < N; i_in++) {
                if (judge.measure_cnt == 10000) break;

                for (int i_out = 0; i_out < N; i_out++) {
                    if (judge.measure_cnt == 10000) break;

                    if (isestimated[i_out]) continue;
                    int ey = L/2 - landing_pos[i_out].y;
                    int ex = L/2 - landing_pos[i_out].x;
                    int tot = 0, cnt = 0;
                    if (S <= 100) {
                        if (judge.measure(i_in, ey, ex, tot, cnt) > 4*S) {
                            estimate[i_in] = i_out;
                            isestimated[i_out] = true;
                            break;
                        }
                    } else if (S <= 144) {
                        if (judge.measure(i_in, ey, ex, tot, cnt) > 3*S &&
                            judge.measure(i_in, ey, ex, tot, cnt) > 3*S) {
                            estimate[i_in] = i_out;
                            isestimated[i_out] = true;
                            break;
                        }
                    } else if (S <= 225) {
                        if (judge.measure(i_in, ey, ex, tot, cnt) > 2*S && 
                            judge.measure(i_in, ey, ex, tot, cnt) > 2*S && 
                            judge.measure(i_in, ey, ex, tot, cnt) > 2*S ) {
                            estimate[i_in] = i_out;
                            isestimated[i_out] = true;
                            break;
                        } 
                    } else if (S <= 529) {
                        if (judge.measure(i_in, ey, ex, tot, cnt) > S && 
                            judge.measure(i_in, ey, ex, tot, cnt) > S && 
                            judge.measure(i_in, ey, ex, tot, cnt) > S &&
                            judge.measure(i_in, ey, ex, tot, cnt) > S &&
                            judge.measure(i_in, ey, ex, tot, cnt) > S ) {
                            estimate[i_in] = i_out;
                            isestimated[i_out] = true;
                            break;
                        } 
                    } else {
                        if (judge.measure(i_in, ey, ex, tot, cnt) > 6*S/10 && 
                            judge.measure(i_in, ey, ex, tot, cnt) > 6*S/10 && 
                            judge.measure(i_in, ey, ex, tot, cnt) > 6*S/10) {
                            if (judge.measure(i_in, ey, ex, tot, cnt) > 7*S/10 &&
                                judge.measure(i_in, ey, ex, tot, cnt) > 7*S/10 &&
                                judge.measure(i_in, ey, ex, tot, cnt) > 7*S/10 ) {
                                estimate[i_in] = i_out;
                                isestimated[i_out] = true;
                                break;
                            }
                        } 
                    } 

                    predict_ave[i_in][i_out] += tot;
                    predict_cnt[i_in][i_out] += cnt;
                } 
            }

            }

            for (int i_in = 0; i_in < N; i_in++) {
                if (estimate[i_in] != -1) continue;

                int ma = 0, idx = 0;
                for (int i_out = 0; i_out < N; i_out++) {
                    if (isestimated[i_out]) continue;
                    if (predict_cnt[i_in][i_out]) predict_ave[i_in][i_out] /= predict_cnt[i_in][i_out];
                    if (ma < predict_ave[i_in][i_out]) {
                        ma = predict_ave[i_in][i_out];
                        idx = i_out;
                    }
                }
                estimate[i_in] = idx;
            }
        }

        return estimate;
    }
};

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<Pos> landing_pos(N);
    for (int i = 0; i < N; i++) cin >> landing_pos[i].y >> landing_pos[i].x;
    Solver solver(L, N, S, landing_pos);
    solver.solve();
}
