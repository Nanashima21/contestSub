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
        k: usize,
        s: Chars,
    };
    let mut cnt = 0;
    for i in 0..n {
        if s[i] == '1' {
            cnt+=1;
        }
    } 
    println!("{}",if cnt%2 == k%2 {"Yes"} else {"No"});
}