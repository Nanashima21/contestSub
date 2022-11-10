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
        c: usize,
        k: usize,
        mut t: [usize; n],
    };
    t.sort();
    let mut ans=1;
    let mut cnt=1;
    let mut lst=t[0];
    for i in 1..n {
        if t[i]<=lst+k && cnt<c {
            cnt+=1;
        } else {
            lst=t[i];
            cnt=1;
            ans+=1;
        }
    }
    println!("{}",ans);
}
