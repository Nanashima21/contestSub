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
        k: usize,
        v: [isize; n],
    }
    let mut ans = 0;
    for l in 0..n+1 {
        for r in 0..n+1 {
            if l+r > k || l+r > n {
                continue;
            }
            let mut vec = vec![];
            let mut tot = 0;
            for li in 0..l {
                vec.push(v[li]);
                tot+=v[li];
            }
            for ri in 0..r {
                vec.push(v[n-ri-1]);
                tot+=v[n-ri-1];
            }
            vec.sort();
            let mut rem = k-r-l;
            let mut idx = 0;
            while rem > 0 {
                if vec.len() > idx && vec[idx] < 0 { 
                    tot-=vec[idx];
                    idx+=1;
                }
                rem-=1;
            }
            ans=ans.max(tot);
        }
    }
    println!("{}",ans);
}
