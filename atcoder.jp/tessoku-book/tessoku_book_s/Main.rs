#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        x: usize,
        p: [(usize,i64); n],
    };
    let mut dp=vec![0i64; x+1];
    for (a,b) in p {
        for i in (0..=x).rev() {
            if i+a<=x {
                dp[i+a]=dp[i+a].max(dp[i]+b);
            }
        }
    }
    println!("{}",dp.iter().max().unwrap());
}