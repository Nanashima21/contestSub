#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
    input! {
        n: usize,
        a: usize,
        b: usize,
    };
    let mut dp=vec![false; n+1];
    for i in 0..=n {
        if i+a<=n {
            dp[i+a]|=!dp[i];
        } 
        if i+b<=n {
            dp[i+b]|=!dp[i];
        }
    }
    println!("{}",if dp[n] { "First" } else { "Second" });
}
