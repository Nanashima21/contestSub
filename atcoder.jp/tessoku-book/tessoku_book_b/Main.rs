use proconio::input;

fn main() {
    input! {
        n: usize,
        x: usize,
        v: [usize; n],
    };
    println!("{}",if v.contains(&x) {"Yes"} else {"No"});
}
