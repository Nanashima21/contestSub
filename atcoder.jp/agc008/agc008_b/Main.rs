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
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        k: usize,
        a: [isize; n],
    }
    let mut l = vec![0; n];
    let mut r = vec![0; n];
    l[0] = a[0].max(0);
    r[n-1] = a[n-1].max(0);
    for i in 1..n {
        l[i] = l[i-1] + a[i].max(0); 
    }
    for i in (0..n-1).rev() {
        r[i] = r[i+1] + a[i].max(0);
    }
    //println!("{:?}",l);
    //println!("{:?}",r);

    let mut ans = 0;
    let mut tot = 0;
    for i in 0..k {
        tot += a[i];
    }
    if k < n {
        ans = ans.max(tot.max(0)+r[k]);
    } else {
        ans = ans.max(tot.max(0));
    }
    for idx in 0..n-k {
        tot -= a[idx];
        tot += a[idx+k];
        if idx+k+1 < n {
            ans = ans.max(tot.max(0)+l[idx]+r[idx+k+1]);
        } else {
            ans = ans.max(tot.max(0)+l[idx]);
        }
    }
    println!("{}",ans);
}