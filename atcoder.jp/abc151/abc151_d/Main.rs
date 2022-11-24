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
        h: usize,
        w: usize,
        s: [Chars; h],
    };
    let mut ans=0;
    let dx=[-1,1,0,0];
    let dy=[0,0,-1,1];
    for si in 0..h {
        for sj in 0..w {
            for gi in 0..h {
                for gj in 0..w {
                    if s[si][sj]=='#' || s[gi][gj]=='#' {
                        continue;
                    }
                    if si==gi && sj==gj {
                        continue;
                    }
                    let mut q=VecDeque::new();
                    let mut dist=vec![vec![-1; w]; h];
                    q.push_back((si,sj));
                    dist[si][sj]=0;
                    while let Some(c)=q.pop_front() {
                        for i in 0..4 {
                            let nx=c.1 as isize +dx[i];
                            let ny=c.0 as isize +dy[i];
                            if ny<0||h as isize <= ny||nx<0||w as isize <= nx {continue}
                            let nx=nx as usize;
                            let ny=ny as usize;
                            if s[ny][nx]=='#' {continue}
                            if dist[ny][nx]!=-1 {continue}
                            dist[ny][nx]=dist[c.0][c.1]+1;
                            q.push_back((ny,nx));
                        }
                    }
                    ans=ans.max(dist[gi][gj]);
                }
            }
        }
    }
    println!("{}",ans);
}
