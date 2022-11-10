#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
    input! {
        n: usize,
        f: [[usize; 10]; n],
        p: [[i64; 11]; n],
    };
    let mut ans:i64=-1_000_000_000;
    for bit in 1..1<<10 {
        let mut tot=0;
        for j in 0..n {
            let mut cnt=0;
            for i in 0..10 {
                if (bit>>i&1)==1 && f[j][i]==1 {
                    cnt+=1;
                }
            }
            tot+=p[j][cnt];
        }
        ans=ans.max(tot);
    }
    println!("{}",ans);
}
