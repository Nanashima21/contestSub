use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
        x: [[usize; 4]; n],
    };
    let mut ans=vec![vec![0; w+1]; h+1];
    for v in x {
        ans[v[0]-1][v[1]-1]+=1;
        ans[v[0]-1][v[3]]-=1;
        ans[v[2]][v[1]-1]-=1;
        ans[v[2]][v[3]]+=1;
    }
    for i in 0..h {
        for j in 1..w {
            ans[i][j]+=ans[i][j-1];
        }
    }
    for i in 0..w {
        for j in 1..h {
            ans[j][i]+=ans[j-1][i];
        }
    }
    println!("{}",ans.iter().take(h).map(|a| a.iter().take(w).join(" ")).join("\n"));
}
