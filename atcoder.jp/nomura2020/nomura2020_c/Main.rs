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
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        a: [usize; n+1],
    }
    let mut flag = true;
    if a[0] != 0 && n != 0 {
        flag = false; 
    }
    if n == 0 {
        match a[0] {
            1 => println!("1"),
            _ => println!("-1"),
        }
        return;
    }
    let mut set = vec![0; n+1];
    set[0] = 1;
    let mut tot = vec![0; n+1];
    tot[n] = a[n];
    for i in (0..n).rev() {
        tot[i] = tot[i+1] + a[i];
    }
    for i in 1..=n {
        if a[i] > 2 * set[i-1] {
            flag = false;
            break;
        } 
        set[i] = 2 * set[i-1];
        if set[i] > tot[i] {
            set[i] = tot[i];
        }
        set[i] -= a[i];
    }
    if !flag {
        println!("-1");
    } else {
        let mut ans = 0;
        for i in 0..=n {
            ans += set[i];
            ans += a[i];
        }
        println!("{}",ans);
    }
}