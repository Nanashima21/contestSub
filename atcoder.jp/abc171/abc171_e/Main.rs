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
        a: [i64; n],
    };
    let mut all=0i64;
    for i in 0..n {
        all^=a[i];
    }
    let mut ans=Vec::with_capacity(n);
    for i in 0..n {
        ans.push(all^a[i]);
    }
    println!("{}",ans.iter().join(" "));
}
