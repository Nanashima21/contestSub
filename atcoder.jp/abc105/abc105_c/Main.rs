#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        mut n: isize,
    }
    if n == 0 {
        println!("0");
        return;
    }
    let mut dq = VecDeque::new();
    while n != 0 {
        match ((n%4)+4)%4 {
            0 => {
                dq.push_back(0);
                dq.push_back(0);
            },
            1 => {
                dq.push_back(1);
                dq.push_back(0);
            },
            2 => {
                dq.push_back(0);
                dq.push_back(1);
            },
            _ => {
                dq.push_back(1);
                dq.push_back(1);
            },
        }
        if n > 0 {
            n = (n+2)/4;
        } else {
            n = (n-1)/4;
        }
    }
    while dq.back().unwrap() == &0 {
        dq.pop_back();
    }
    while let Some(x) = dq.pop_back() {
        print!("{}",x);
    }
    println!();
}