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
        a: usize,
        b: usize,
    };
    let MOD=1_000_000_007;
    println!("{}",modpow(a,b,MOD));
}

fn modpow(mut n: usize,mut r: usize,MOD: usize) -> usize {
    let mut num=1;
    while r>0 {
        if r&1==1 {
            num=num*n%MOD;
        }
        n=n*n%MOD;
        r/=2;
    }
    return num;
}