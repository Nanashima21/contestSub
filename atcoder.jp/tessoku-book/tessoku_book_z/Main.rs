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
        n: usize,
        q: [usize; n],
    };
    let mut ans=Vec::with_capacity(n);
    for i in 0..n {
        ans.push(if isprime(q[i]) { "Yes" } else { "No" });
    }
    println!("{}",ans.iter().join("\n"));
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
    return true;
}