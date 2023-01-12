#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        k: usize,
    };
    let mut v=Vec::new();
    let max=10_000_000_000_i64;
    for i in 1..10 {
        let mut dq=VecDeque::new();
        dq.push_back(i);
        while let Some(num)=dq.pop_front() {
            v.push(num);
            let d=num%10;
            for j in d-1..=d+1 {
                if j==-1 || j==10 {
                    continue;
                }
                let y=num*10+j;
                if y<max {
                    dq.push_back(y);
                }
            }
        }
    }
    v.sort();
    println!("{}",v[k-1]);
}