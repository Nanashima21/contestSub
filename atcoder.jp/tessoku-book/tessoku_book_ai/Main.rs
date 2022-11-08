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
        a: [usize; n],
    };
    let mut dp=vec![vec![0; n]; n];
    let mut flag=vec![false; n];
    flag[n-1]=true;
    for i in 0..n {
        dp[i][i]=a[i];
    }
    for i in (0..n-1).rev() {
        flag[i]=!flag[i+1];
    }
    for len in 1..n {
        for l in 0..n {
            let r=l+len;
            if r>=n {
                break;
            }
            if flag[len] {
                dp[l][r]=std::cmp::max(dp[l+1][r],dp[l][r-1]);
            } else {
                dp[l][r]=std::cmp::min(dp[l+1][r],dp[l][r-1]);
            }
        }
    }
    println!("{}",dp[0][n-1]);
}
