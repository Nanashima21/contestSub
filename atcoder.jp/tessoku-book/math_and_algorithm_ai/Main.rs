use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        p: [(usize,usize); q],
    };
    let mut tot=vec![0; n+1];
    for i in 0..n {
        tot[i+1]=tot[i]+a[i];
    }
    let mut ans=Vec::with_capacity(q);
    for (l,r) in p {
        ans.push(tot[r]-tot[l-1]);
    } 
    println!("{}",ans.iter().join("\n"));
}
