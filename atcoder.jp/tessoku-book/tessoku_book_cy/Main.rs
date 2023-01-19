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
    };
    for i in 2..=n {
        if isprime(i) {
            println!("{}",i);
        }
    }
}

fn isprime(x: usize) -> bool {
    if x<2 {
        return false;
    } else if x==2 {
        return true;
    } 
    if x%2==0 {
        return false;
    } 
    let mut i=3;
    while i*i<=x {
        if x%i==0 {
            return false;
        }
        i+=2;
    }
    true
}
