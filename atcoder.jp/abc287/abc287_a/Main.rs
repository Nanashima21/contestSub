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
        s: [Chars; n],
    };
    let mut cnt1 = 0;
    let mut cnt2 = 0;
    for i in 0..n {
        if s[i][0] == 'F' {
            cnt1+=1;
        } else {
            cnt2+=1;
        }
    }
    println!("{}",if cnt1>cnt2 {"Yes"} else {"No"});
}


