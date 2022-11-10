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
        x: [usize; n],
    };
    let mut y=x.clone();
    y.sort();
    let mid=y[n/2];
    for i in 0..n {
        if x[i]>=mid {
            println!("{}",y[n/2-1]);
        } else {
            println!("{}",mid);
        }
    }
}
