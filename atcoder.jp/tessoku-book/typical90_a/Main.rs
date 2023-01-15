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
        x: usize,
        k: usize,
        a: [usize; n],
    };
    let mut l=0usize;
    let mut r=x+1;
    while r-l > 1usize {
        let mid=(l+r)/2;
        let mut mi=x+1;
        let mut pre=0;
        let mut cnt=0;
        for i in 0..n {
            if a[i]-pre >= mid {
                mi=mi.min(a[i]-pre);
                pre=a[i];
                cnt+=1;
            } 
        }
        mi=mi.min(x-pre);
        if cnt > k {
            l=mid;
        } else if cnt < k {
            r=mid;
        } else {
            if mi >= mid {
                l=mid;
            } else {
                r=mid;
            }
        }
    }
    println!("{}",l);
}

