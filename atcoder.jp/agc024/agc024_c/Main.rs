#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: isize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut flag = true;
    for i in 0..n {
        if a[i] > i {
            flag = false;
        } 
        if i > 0 && a[i] > a[i-1]+1 {
            flag = false;
        }
    }
    if !flag {
        println!("-1");
    } else {
        let mut ans = 0;
        for i in (0..n).rev() {
            if i == n-1 {
                ans += a[i];
            } else {
                if a[i]+1 == a[i+1] {
                    continue;
                } else {
                    ans += a[i];
                }
            }
        }
        println!("{}",ans);
    } 
}

