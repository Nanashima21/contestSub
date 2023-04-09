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
        x: usize,
        y: usize,
        a: [usize; n],
    };
    let mut grundy = vec![];
    for &ai in a.iter() {
        grundy.push(ai%(x+y)/x);
    }
    let mut xor_sum = 0;
    for &gi in grundy.iter() {
        xor_sum^=gi;
    } 
    println!("{}",if xor_sum == 0 {"Second"} else {"First"});
}