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
        q: usize,
        a: [Usize1; n],
    };
    let mut dp=vec![vec![0; n]; 60];
    for i in 0..n {
        dp[0][i]=a[i];
    }
    for i in 1..60 {
        for j in 0..n {
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    let mut ans=Vec::with_capacity(q);
    for _ in 0..q {
        input! { mut x: Usize1, y: i64 };
        for i in 0..60 {
            if (y>>i&1)==1 {
                x=dp[i][x];
            }
        }
        ans.push(x+1);
    }
    println!("{}",ans.iter().join("\n"));
}
