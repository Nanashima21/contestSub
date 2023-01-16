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
        n: f64,
    };
    let mut l=0.0;
    let mut r=100_100_f64;
    while r-l > 0.0001 {
        let mid=(l+r)/2.0;
        let tot=mid*mid*mid+mid;
        if tot >= n {
            r=mid;
        } else {
            l=mid;
        }
    }
    println!("{}",l);
}

