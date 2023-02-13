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

#[fastout]
fn main() {
    input! {
        n: usize,
        k: usize,
        q: Usize1,
        a: [usize; n],
    }
    let mut st = BTreeSet::new();
    for i in 0..n {
        st.insert(a[i]);
    }
    let mut ans = INF;
    let mut vec = vec![];
    for &mi in st.iter() {
        let mut v = vec![];
        for i in 0..n {
            if a[i] < mi {
                let m = v.len();
                //print!("{:?} ",v);
                if m >= k {
                    v.sort();
                    for j in 0..=m-k {
                        vec.push(v[j]);
                    }
                }
                v.clear();
            } else {
                v.push(a[i]);
            }
        }
        let m = v.len();
        if m >= k {
            v.sort();
            for j in 0..=m-k {
                vec.push(v[j]);
            }
        }
        //println!("{:?} {:?}",v,vec);
        vec.sort();
        if vec.len() > q {
            ans=ans.min(vec[q]-mi);
        }
        vec.clear();
    } 
    println!("{}",ans);
}
