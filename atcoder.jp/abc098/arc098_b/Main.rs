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
        n: usize,
        a: [isize; n],
    }
    let mut ans = 0;
    let mut cnt = vec![0; 20];
    let mut l = 0;
    let mut flag = true;
    for r in 0..n {
        for i in 0..20 {
            if a[r]>>i & 1 == 1 {
                cnt[i] += 1;
            } 
            if cnt[i] > 1 {
                flag = false;
            }
        }
        while !flag {
            for i in 0..20 {
                if a[l]>>i & 1 == 1 {
                    cnt[i] -= 1;
                }
            }
            l += 1;
            let mut check = true;
            for i in 0..20 {
                if cnt[i] > 1 {
                    check = false;
                }
            }
            flag |= check;
        }
        ans += r-l+1; 
        //println!("{} {}: {:?}",l,r,cnt);
    }
    println!("{}",ans);
}

