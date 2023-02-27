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
        t: usize,
    }
    for _ in 0..t {
        input! {
            mut n: usize,
            mut s: usize,
            mut k: usize,
        }
        let g = gcd(n, k);
        if s%g != 0 {
            println!("-1");
        } else {
            n /= g;
            s /= g;
            k /= g;
            let mut x = 0i64;
            let mut y = 0i64;
            let m = n as i64;
            ext_gcd(k as i64, m, &mut x, &mut y);
            x = (x+m) % m;
            println!("{}",x*(m - s as i64)%m);
        }
    } 
    
}

fn gcd(x: usize, y: usize) -> usize {
    match y {
        0 => x,
        _ => gcd(y, x%y),
    }
}

fn ext_gcd(a: i64, b: i64, x: &mut i64, y: &mut i64) -> i64 {
    match b {
        0 => {
            *x = 1;
            *y = 0;
            a
        },
        _ => {
            let d = ext_gcd(b, a%b, y, x);
            *y -= a/b * (*x);
            d
        }
    }
}