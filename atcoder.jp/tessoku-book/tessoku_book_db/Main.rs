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
        a: usize,
        b: usize,
    };
    println!("{}",modpow(a,b));
}

fn modpow(mut n: usize, mut r: usize) -> usize {
    let mut num = 1;
    while r > 0 {
        if r&1 == 1 {
            num=num*n%MOD;
        }
        n=n*n%MOD;
        r/=2;
    }
    num
}