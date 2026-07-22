#[derive(Debug)]
pub struct WalletScanner {
    pub wallet: String,
}

impl WalletScanner {

    pub fn new(wallet:&str)->Self {
        Self {
            wallet: wallet.to_string()
        }
    }

    pub fn scan(&self)->String {
        format!(
            "Wallet scan completed: {}",
            self.wallet
        )
    }
}
