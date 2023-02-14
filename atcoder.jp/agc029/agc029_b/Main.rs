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
        mut a: [usize; n],
    }
    a.sort();
    let mut mp = HashMap::new();
    for &ai in a.iter() {
        *mp.entry(ai).or_insert(0)+=1;
    } 
    //println!("{:?}",mp);
    let mut p2 = 1usize;
    let mut vec = vec![];
    for _ in 1..=32 {
        vec.push(p2);
        p2 *= 2;
    }
    vec.reverse();
    let mut ans = 0;
    for &vi in vec.iter() {
        for &ai in a.iter() {
            if vi <= ai {
                continue;
            }
            if !mp.contains_key(&(vi-ai)) {
                continue;
            }
            let mut vflag = true;
            let mut aflag = true;
            if let Some(num) = mp.get(&(vi-ai)) {
                if *num <= 0 {
                    vflag = false;
                }
                if vi == ai*2 && *num <= 1 {
                    vflag = false;
                }
            }
            if let Some(num) = mp.get(&ai) {
                if *num <= 0 {
                    aflag = false;
                }
            }
            if !vflag || !aflag {
                continue;
            }
            *mp.entry(vi-ai).or_insert(0)-=1;
            *mp.entry(ai).or_insert(0)-=1;
            ans += 1;
        }
    }
    //println!("{:?}",mp);
    println!("{}",ans);
}
