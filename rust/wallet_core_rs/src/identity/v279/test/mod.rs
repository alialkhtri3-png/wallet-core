#[cfg(test)]
mod tests {

use crate::identity::v279::{
    WalletScanner
};

use crate::identity::v279::score::identity_score;


#[test]
fn multichain_identity_engine_online(){

let scanner =
WalletScanner::new("0xidentity");


assert!(
scanner.scan().contains("completed")
);


assert_eq!(
identity_score(90),
90
);

}

}
