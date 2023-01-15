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
        t: usize,
        n: usize,
        p: [(usize,usize); n],
    };
    let mut tot = vec![0; t+1];
    for &(l,r) in p.iter() {
        tot[l]+=1;
        tot[r]-=1;
    }
    for i in 0..t {
        if i!=0 {
            tot[i]+=tot[i-1];
        }
        println!("{}",tot[i]);
    }
}

