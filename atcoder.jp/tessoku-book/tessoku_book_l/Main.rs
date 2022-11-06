//use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
    };
    let mut l=0;
    let mut r=1_000_000_001;
    while l+1<r {
        let mid=(l+r)/2;
        let mut tot=0;
        for i in &a {
            tot+=mid/i;
        }
        if k>tot {
            l=mid;
        } else {
            r=mid;
        }
    }
    println!("{}",r);
}