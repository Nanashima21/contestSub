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

fn main() {
    input! {
        n: usize,
        q: usize,
    }
    let mut uf = Dsu::new(n+q+1);
    let mut cnt = n;
    let mut leader = vec![INF; n+1];
    let mut inv = vec![0; n+q+1];

    for i in 1..=n {
        leader[i] = i;
        inv[leader[i]] = i;
    }
    for _ in 0..q {
        input! { t: usize }
        match t {
            1 => {
                input! { x: usize, y: usize }
                if leader[y] == INF {
                    continue;
                } else if leader[x] == INF {
                    leader[x] = leader[y];
                    inv[leader[x]] = x;
                    leader[y] = INF;
                } else {
                    uf.merge(leader[x], leader[y]);
                    leader[x] = uf.leader(leader[x]);
                    inv[leader[x]] = x;
                    leader[y] = INF;
                }
            },
            2 => {
                input! { x: usize }
                cnt += 1;
                if leader[x] == INF {
                    leader[x] = cnt;
                    inv[leader[x]] = x;
                } else {
                    uf.merge(leader[x], cnt);
                    leader[x] = uf.leader(leader[x]);
                    inv[leader[x]] = x;
                }
            },
            _ => {
                input! { x: usize }
                println!("{}",inv[uf.leader(x)]);
            },
        }
    }
}

//Disjoint Set Union(Union-Find)
pub struct Dsu {
    n: usize,
    parent_or_size: Vec<i32>,
}

impl Dsu {
    pub fn new(size: usize) -> Self {
        Self {
            n: size,
            parent_or_size: vec![-1; size],
        }
    }
    pub fn merge(&mut self, a: usize, b: usize) -> usize {
        assert!(a < self.n);
        assert!(b < self.n);
        let (mut x, mut y) = (self.leader(a), self.leader(b));
        if x == y { return x; }
        if -self.parent_or_size[x] < -self.parent_or_size[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.parent_or_size[x] += self.parent_or_size[y];
        self.parent_or_size[y] = x as i32;
        x
    }
    pub fn same(&mut self, a: usize, b: usize) -> bool {
        assert!(a < self.n);
        assert!(b < self.n);
        self.leader(a) == self.leader(b)
    }
    pub fn leader(&mut self, a: usize) -> usize {
        assert!(a < self.n);
        if self.parent_or_size[a] < 0 { return a; }
        self.parent_or_size[a] = self.leader(self.parent_or_size[a] as usize) as i32;
        self.parent_or_size[a] as usize
    }
    pub fn size(&mut self, a: usize) -> usize {
        assert!(a < self.n);
        let x = self.leader(a);
        -self.parent_or_size[x] as usize
    }
    pub fn groups(&mut self) -> Vec<Vec<usize>> {
        let mut leader_buf = vec![0; self.n];
        let mut group_size = vec![0; self.n];
        for i in 0..self.n {
            leader_buf[i] = self.leader(i);
            group_size[leader_buf[i]] += 1;
        }
        let mut result = vec![Vec::new(); self.n];
        for i in 0..self.n {
            result[i].reserve(group_size[i]);
        }
        for i in 0..self.n {
            result[leader_buf[i]].push(i);
        }
        result
            .into_iter()
            .filter(|x| !x.is_empty())
            .collect::<Vec<Vec<usize>>>()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_dsu() {
        let mut d = Dsu::new(4);
        d.merge(0, 1);
        assert!(d.same(0, 1));
        d.merge(1, 2);
        assert!(d.same(0, 2));
        assert_eq!(d.size(0), 3);
        assert!(!d.same(0, 3));
        assert_eq!(d.groups(), vec![vec![0, 1, 2], vec![3]]);
    }
}