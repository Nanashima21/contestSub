#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [usize; n],
    };
    let mut flag=false;
    for i in 0..n {
        for j in i+1..n {
            for k in j+1..n {
                if a[i]+a[j]+a[k] == 1000 {
                    flag=true;
                }
            }
        }
    }
    println!("{}",if flag {"Yes"} else {"No"});
}

