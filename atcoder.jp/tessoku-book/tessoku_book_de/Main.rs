#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

//#[fastout]
fn main() {
    input! {
        n: usize,
        k: usize,
        a: [usize; k],
    };
    let max = 100_100;
    let mut dp = vec![false; max];
    for i in 0..k {
        dp[a[i]]=true;
    }
    for i in 0..max {
        for j in 0..k {
            if i+a[j] < max {
                dp[i+a[j]]|=!dp[i];
            }
        }
    }
    println!("{}",if dp[n] {"First"} else {"Second"});
}
