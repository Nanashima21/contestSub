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
        m: usize,
        s: [Chars; n],
        t: [Chars; m],
    };
    for i in 0..n-m+1 {
        for j in 0..n-m+1 {
            let mut flag = true;
            for x in 0..m {
                for y in 0..m {
                    if s[x+i][y+j] != t[x][y] {
                        flag = false;
                    } 
                }
            }
            if flag {
                println!("Yes");
                return
            }
        }
    }
    println!("No");
}


