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
        s: Chars,
    };
    let mut cnt=0i32;
    let mut ans=0i32;
    for i in 0..s.len() {
        if s[i]=='g' {
            if cnt==0 {
                cnt+=1;
            } else {
                cnt-=1;
                ans+=1;
            }
        } else {
            if cnt==0 {
                cnt+=1;
                ans-=1;
            } else {
                cnt-=1;
            }
        }
    }
    println!("{}",ans);
}
