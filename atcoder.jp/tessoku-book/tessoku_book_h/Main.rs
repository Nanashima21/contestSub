use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        x: [[usize; w]; h],
        q: usize,
        query: [[usize; 4]; q],
    };
    let mut tot=vec![vec![0; w+1]; h+1];
    for i in 1..=h {
        for j in 1..=w {
            tot[i][j]=x[i-1][j-1]+tot[i-1][j]+tot[i][j-1]-tot[i-1][j-1];
        }
    }
    let mut ans=Vec::with_capacity(q);
    for v in query {
        ans.push(tot[v[0]-1][v[1]-1]+tot[v[2]][v[3]]-tot[v[0]-1][v[3]]-tot[v[2]][v[1]-1]);
    }
    println!("{}",ans.iter().join("\n"));
}
