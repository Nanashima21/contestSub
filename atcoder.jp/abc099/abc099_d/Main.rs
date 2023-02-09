#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        m: usize,
        d: [[usize; m]; m],
        c: [[Usize1; n]; n],
    }
    let mut ans = INF;
    let mut tot = vec![vec![0; 3]; m];
    let mut vec = vec![vec![]; 3];
    for i in 0..m {
        for x in 0..n {
            for y in 0..n {
                if i != c[x][y] {
                    tot[i][(x+y)%3]+=d[c[x][y]][i];
                }
            }
        }
        for j in 0..3 {
            vec[j].push((tot[i][j],i));
        }
    }
    for i in 0..3 {
        vec[i].sort();
    }
    for i in 0..3 {
        for j in 0..3 {
            for k in 0..3 {
                if vec[0][i].1 == vec[1][j].1 || vec[1][j].1 == vec[2][k].1 || vec[2][k].1 == vec[0][i].1 {
                    continue;
                }
                ans=ans.min(vec[0][i].0+vec[1][j].0+vec[2][k].0);
            }
        }
    }
    println!("{}",ans);
}

