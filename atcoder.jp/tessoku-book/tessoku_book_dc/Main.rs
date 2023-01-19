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
    println!("{}",comb(a+b-2,a-1));
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

fn comb(n: usize,r: usize) -> usize {
    let mut x=1;
    let mut y=1;
    for i in 0..r {
        x=x*(n-i)%MOD;
    }
    for i in 1..=r {
        y=y*i%MOD;
    }
    x*modpow(y,MOD-2)%MOD
}