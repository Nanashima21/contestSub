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
    println!("{}",gcd(a,b));
}

fn gcd(x: usize,y: usize) -> usize {
    if y==0 {
        return x;
    }
    return gcd(y,x%y);
}