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
        k: i32,
        p: [(i32,i32); n],
    };
    let mut ma=0;
    for i in 1..=100 {
        for j in 1..=100 {
            let mut cnt=0;
            for l in 0..n {
                if i<=p[l].0 && p[l].0<=i+k && j<=p[l].1 && p[l].1<=j+k {
                    cnt+=1;
                }
            }
            ma=ma.max(cnt);
        }
    }
    println!("{}",ma);
}
