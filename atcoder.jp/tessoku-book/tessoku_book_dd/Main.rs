#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
    };
    let x = n/3;
    let y = n/5;
    let z = n/7;
    let xy = n/15;
    let yz = n/35;
    let zx = n/21;
    let xyz = n/105;
    println!("{}",x+y+z-xy-yz-zx+xyz); 
}