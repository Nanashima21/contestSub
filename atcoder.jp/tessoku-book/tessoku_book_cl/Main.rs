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
        k: isize,
        a: [isize; n],
    };
    let mut b = vec![0; n+1];
    for i in 1..=n {
        b[i]=b[i-1]+a[i-1];
    }
    let mut ans = 0;
    for i in 0..n {
        let r=b.upper_bound(&(b[i]+k))-1;
        ans+=r-i;
    }
    println!("{}",ans);
}

