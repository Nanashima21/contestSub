#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        t: [usize; n],
        a: [usize; n],
    }
    let mut ans = 1;
    let max = t[n-1].max(a[0]);
    for i in 0..n {
        if max != t[i].max(a[i]) {
            ans = 0;
        }
    }
    let mut flag = false;
    for i in 0..n {
        if max == t[i] && t[i] == a[i] {
            flag = true;
        }
    }
    if !flag {
        ans = 0;
    }
    for i in 1..(n-1) {
        if t[i] > t[i-1] || a[i] > a[i+1] {
            continue;
        }
        if t[i] == a[i] {
            ans *= t[i]; 
        } else {
            ans *= t[i].min(a[i]);
        }
        ans %= MOD;
    }
    println!("{}",ans);
}
