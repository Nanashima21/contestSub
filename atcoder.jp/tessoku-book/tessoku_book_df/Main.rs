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

//#[fastout]
fn main() {
    input! {
        n: usize,
        _h: usize,
        _w: usize,
        p: [(Usize1,Usize1); n],
    };
    let mut nim = 0;
    for &(a,b) in p.iter() {
        nim^=a;
        nim^=b;
    }
    println!("{}",if nim == 0 {"Second"} else {"First"});
}