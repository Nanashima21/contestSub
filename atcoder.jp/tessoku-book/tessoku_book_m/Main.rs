//use itertools::Itertools;
use proconio::input;
use superslice::Ext;

fn main() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
    };
    let mut ans: usize=0;
    for i in 0..n {
        let it=a.lower_bound(&(a[i]+k+1));
        ans+=it-i-1;
    }
    println!("{}",ans);
}