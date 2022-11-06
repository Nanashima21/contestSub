use proconio::input;

fn main() {
    input! {
        n: usize,
        k: usize,
    };
    let mut cnt=0;
    for i in 1..(n+1) {
        for j in 1..(n+1) {
            if 0<k-i-j && k-i-j<=n {
                cnt+=1;
            } 
        }
    }
    println!("{}",cnt);
}
