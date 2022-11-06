use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [usize; n],
    };
    let mut b=a.clone();
    b.sort();
    b.dedup();
    let mut ans=Vec::with_capacity(n);
    for i in &a {
        ans.push(b.binary_search(&i).unwrap()+1);
    }
    println!("{}",ans.iter().join(" "));
}