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
        m: usize,
        s: [Chars; n],
        t: [Chars; m],
    };
    let mut ans = 0;
    for i in 0..n {
        let mut flag = false;
        for j in 0..m {
            let mut cnt = 0;
            for k in 0..3 {
                if s[i][k+3] == t[j][k] {
                    cnt+=1;
                }
            }
            if cnt == 3 {
                flag=true;
            }
        }
        if flag {
            ans+=1;
        }
    }
    println!("{}",ans);
}


