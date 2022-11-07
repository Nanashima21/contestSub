#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [Usize1; n-1],
        b: [Usize1; n-1],
    };
    let mut dp: Vec<i64>=vec![-1_000_000_000; n];
    dp[0]=0;
    for i in 0..n-1 {
        dp[a[i]]=dp[a[i]].max(dp[i]+100);
        dp[b[i]]=dp[b[i]].max(dp[i]+150);
    }
    println!("{}",dp[n-1]);
}