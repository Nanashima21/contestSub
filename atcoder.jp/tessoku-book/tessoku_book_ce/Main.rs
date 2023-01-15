#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [usize; n],
        q: usize,
        p: [(usize,usize); q],
    };
    let mut tot=vec![0; n+1];
    for i in 0..n {
        tot[i+1]+=tot[i]+a[i];
    }
    for &(l,r) in p.iter() {
        let ans;
        if r-l+1 == (tot[r]-tot[l-1])*2 {
            ans="draw";
        } else if r-l+1 < (tot[r]-tot[l-1])*2 {
            ans="win";
        } else {
            ans="lose";
        }
        println!("{}",ans);
    }
}

