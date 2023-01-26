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
        mut a: [[usize; w]; h],
    };
    let mut ans = vec![];
    for i in 0..h {
        for j in 0..w-1 {
            if a[i][j]%2 == 1 {
                a[i][j]-=1;
                a[i][j+1]+=1;
                ans.push((i+1,j+1,i+1,j+2));
            } 
        }
    }
    for i in 0..h-1 {
        if a[i][w-1]%2 == 1 {
            a[i][w-1]-=1;
            a[i+1][w-1]+=1;
            ans.push((i+1,w,i+2,w));
        }
    }
    println!("{}",ans.len());
    for (a,b,c,d) in ans.iter() {
        println!("{} {} {} {}",a,b,c,d);
    }
}


