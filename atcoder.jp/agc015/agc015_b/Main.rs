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
        s: Chars,
    };
    let mut cnt=0;
    let x=s.len();
    for i in 0..s.len() {
        match s[i] {
            'U' => cnt+=x-i-1+i*2,
            'D' => cnt+=(x-i-1)*2+i,
            _ => panic!(),
        };
    }
    println!("{}",cnt);
}
