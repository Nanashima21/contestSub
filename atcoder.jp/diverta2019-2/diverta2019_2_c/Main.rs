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
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        mut a: [isize; n],
    }
    a.sort();
    let mut p = vec![];
    let mut ma;
    let mut mi;
    if n == 2 {
        mi = a[0];
        ma = a[n-1];
    } else if a[0] >= 0 {
        p.push((a[0], a[n-1]));
        mi = a[0] - a[n-1];
        ma = a[n-2];
        for i in 1..n-2 {
            if a[i] <= 0 {
                p.push((ma, a[i]));
                ma -= a[i];
            } else {
                p.push((mi, a[i]));
                mi -= a[i];
            }
        }
    } else if a[n-1] <= 0 {
        mi = a[1];
        p.push((a[n-1], a[0]));
        ma = a[n-1] - a[0];
        for i in 2..n-1 {
            if a[i] <= 0 {
                p.push((ma, a[i]));
                ma -= a[i];
            } else {
                p.push((mi, a[i]));
                mi -= a[i];
            }
        }
    } else {
        mi = a[0];
        ma = a[n-1];
        for i in 1..n-1 {
            if a[i] <= 0 {
                p.push((ma, a[i]));
                ma -= a[i];
            } else {
                p.push((mi, a[i]));
                mi -= a[i];
            }
        }
    }
    p.push((ma,mi));
    ma -= mi;
    println!("{}",ma);
    for &(x,y) in p.iter() {
        println!("{} {}",x,y);
    }
}

