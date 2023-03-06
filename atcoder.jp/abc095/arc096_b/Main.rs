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
        c: isize,
        mut p: [(isize, isize); n],
    }
    let mut ans = 0;

    for _ in 0..2 {
        let mut ma = vec![0isize; n];
        ma[0] = ma[0].max(p[0].1 - p[0].0);
        let mut val = p[0].1;
        ans = ans.max(ma[0]);
        for i in 1..n {
            val += p[i].1;
            ma[i] = ma[i-1].max(val - p[i].0);
            ans = ans.max(ma[i]);
        }
        //println!("{:?}",ma);
        
        val = 0;
        for i in 1..n {
            val += p[n-i].1;
            ans = ans.max(val - 2*(c - p[n-i].0) + ma[n-i-1]); 
        }

        for i in 0..n {
            p[i].0 = c - p[i].0;
        }
        p.reverse();
    }
    println!("{}",ans);
}

