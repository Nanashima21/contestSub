//use itertools::Itertools;
use proconio::input;
//use superslice::Ext;

fn main() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
        b: [usize; n],
        c: [usize; n],
        d: [usize; n],
    };
    let mut hs1 = std::collections::HashSet::new();
    let mut hs2 = std::collections::HashSet::new();
    for i in &a {
        for j in &b {
            hs1.insert(i+j);
        }
    }
    for i in &c {
        for j in &d {
            hs2.insert(i+j);
        }
    }
    let mut flag=false;
    for i in hs1 {
        if hs2.contains(&(k-i)) {
            flag=true;
        }
    }
    println!("{}",if flag { "Yes" } else { "No" });
}