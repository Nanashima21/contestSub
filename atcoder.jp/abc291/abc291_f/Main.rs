#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
#![allow(unused_assignments)]
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
        m: usize,
        s: [Chars; n],
    }
    let mut dpl = vec![INF; n];
    let mut dpr = vec![INF; n];
    dpl[0] = 0;
    dpr[n-1] = 0;
    for i in 0..n {
        for j in 0..m {
            if s[i][j] == '1' {
                dpl[(j+i+1)%n] = dpl[(j+i+1)%n].min(dpl[i]+1);
            }
        }
    }
    for i in (0..n).rev() {
        for j in 0..m {
            if s[i][j] == '1' {
                dpr[i] = dpr[i].min(dpr[(j+i+1)%n]+1);
            }
        }
    }
    //println!("{:?}",dpl);
    //println!("{:?}",dpr);
    for k in 1..n-1 {
        let mut ans = INF;
        let ma = ((k as isize)-(m as isize)+1).max(0isize) as usize;
        let mi = n.min(k+m) as usize;
        for i in ma..k {
            for j in k+1..mi { 
                if j-i-1 < m && s[i][j-i-1] == '1' {
                    ans = ans.min(dpl[i]+dpr[j]+1);
                }
            }
        }
        if ans == INF {
            print!("-1 ");
        } else {
            print!("{} ",ans);
        }
    }
    println!();
}

