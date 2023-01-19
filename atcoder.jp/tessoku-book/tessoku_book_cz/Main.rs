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
        a: usize,
        b: usize,
    };
    println!("{}",lcm(a,b));
}

fn gcd(x: usize, y: usize) -> usize {
    if y==0 {
        return x;
    }
    gcd(y,x%y)
}

fn lcm(x: usize, y: usize) -> usize {
    x*y/gcd(x,y)
}
