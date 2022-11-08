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
        mut a: [usize; n],
    };
    let mut cnt =vec![0; 101];
    for i in 0..n {
        cnt[a[i]]+=1;
    }
    let mut tot: i64=0;
    for i in 1..=100 {
        tot+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6; 
    }
    println!("{}",tot);
}
