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
        p: [(Usize1,i64); n],
    };
    let mut dp=vec![vec![0; n]; n];
    for i in (0..n-1).rev() {
        for l in 0..n-i {
            let r=l+i;
            let mut s1=0;
            let mut s2=0;
            if l>=1 && l<=p[l-1].0 && p[l-1].0<=r {
                s1=p[l-1].1;
            }
            if r+1<n && l<=p[r+1].0 && p[r+1].0<=r {
                s2=p[r+1].1;
            }
            if l==0 {
                dp[l][r]=dp[l][r+1]+s2;
            } else if r==n-1 {
                dp[l][r]=dp[l-1][r]+s1;
            } else {
                dp[l][r]=std::cmp::max(dp[l-1][r]+s1,dp[l][r+1]+s2);
            }
        } 
    }
    println!("{}",(0..n).fold(0i64, |v,i| v.max(*dp[i].iter().max().unwrap())));
}