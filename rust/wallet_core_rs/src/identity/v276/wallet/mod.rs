pub struct WalletIdentity {
    pub address: String,
}

impl WalletIdentity {
    pub fn new(address: &str) -> Self {
        Self {
            address: address.into(),
        }
    }
}
