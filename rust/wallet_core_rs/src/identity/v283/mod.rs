pub mod runtime;
pub mod rpc;
pub mod blocks;
pub mod transactions;
pub mod tokens;
pub mod wallet;
pub mod identity;
pub mod vc;
pub mod api;
pub mod test;

pub const VERSION: &str = "283.0.0";

pub struct OnchainIntelligenceRuntime {
    pub version: &'static str,
}

impl OnchainIntelligenceRuntime {
    pub fn new() -> Self {
        Self {
            version: VERSION,
        }
    }

    pub fn status(&self) -> String {
        format!(
            "Sovereign On-chain Intelligence Runtime V{} online",
            self.version
        )
    }
}
