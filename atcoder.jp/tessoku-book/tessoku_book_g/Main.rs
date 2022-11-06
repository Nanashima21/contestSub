use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        d: usize,
        n: usize,
        p: [(usize,usize); n],
    };
    let mut tot=vec![0; d+1];
    for (l,r) in p {
        tot[l-1]+=1;
        tot[r]-=1;
    }
    for i in 1..=d {
        tot[i]+=tot[i-1];
    }
    println!("{}",tot.iter().take(d).join("\n"));
}
