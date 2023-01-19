#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        mut p: [(isize,isize); n],
    };
    for i in 0..n {
        p[i].1 = -p[i].1;
    }
    p.sort();
    let mut dp = vec![INF; n];
    let mut ans = 0;
    for &(_x,y) in p.iter() {
        let idx = dp.lower_bound(&(-y));
        dp[idx] = -y;
        ans=ans.max(idx+1);
    }
    println!("{}",ans);
}
