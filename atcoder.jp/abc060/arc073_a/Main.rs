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
        t: isize,
        v: [isize; n],
    };
    let mut ans = 0;
    let mut x = t;
    for i in 1..n {
        if x >= v[i] {
            ans+=v[i]-v[i-1];
        } else {
            ans+=x-v[i-1];
        }
        x=t+v[i];
    }
    println!("{}",ans+t);
}


