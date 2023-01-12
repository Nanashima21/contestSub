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
        h: usize,
        w: usize,
        k: usize,
        s: [Chars; h],
    };
    let mut ans=0;
    for i in 0..1<<h {
        let mut ns=s.clone();
        if (i as u64).count_ones() as usize > k {
            continue;
        }
        for j in 0..h {
            if i>>j&1==1 {
                for l in 0..w {
                    ns[j][l]='#';
                }
            }
        }
        let mut cnt=h*w;
        let mut vec=vec![];
        for j in 0..w {
            let mut num=0;
            for l in 0..h {
                num+= if ns[l][j]=='.' {1} else {0}; 
            }
            vec.push(num);
        }
        vec.sort();
        let x=k - (i as u64).count_ones() as usize;
        for j in 0..w-x {
            cnt-=vec[j];
        }
        ans=ans.max(cnt);
    }
    println!("{}",ans);
}