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
        mut a: i64,
        mut b: i64,
        mut w: i64,
    };
    w*=1000;
    let mut ma=0i64;
    let mut mi=1_000_000i64;
    for i in 1..10_000_000 {
        if a*i<=w && w<=b*i {
            ma=ma.max(i);
            mi=mi.min(i);
        }
    }
    if ma==0 {
        println!("UNSATISFIABLE");
    } else {
        println!("{} {}",mi,ma);
    }
}
