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
        k: isize,
        a: [isize; n],
    };
    let mut totl = vec![];
    let mut totr = vec![];
    for i in 0..1<<(n/2) {
        let mut sum=0;
        for j in 0..n/2 {
            if i>>j & 1 == 1 {
                sum+=a[j];
            }
        }
        totl.push(sum);
    }
    for i in 0..1<<(n-n/2) {
        let mut sum=0;
        for j in 0..(n-n/2) {
            if i>>j & 1 == 1 {
                sum+=a[j+n/2];
            }
        }
        totr.push(sum);
    }
    totl.sort();
    totr.sort();
    let mut flag = false;
    for &li in totl.iter() {
        if let Ok(_) = totr.binary_search(&(k-li)) {
            flag=true;
        }
    }
    println!("{}",if flag {"Yes"} else {"No"});
}

