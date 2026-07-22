pub mod rpc;
pub mod scanner;
pub mod did;
pub mod resolver;
pub mod reputation;
pub mod risk;
pub mod portfolio;
pub mod export;
pub mod test;

pub const VERSION:&str="282.0.0";

pub struct RealIdentityEngine {
    pub version:&'static str,
}

impl RealIdentityEngine {
    pub fn new()->Self{
        Self{version:VERSION}
    }

    pub fn status(&self)->String{
        format!("Sovereign Real Data Identity Engine V{} online",self.version)
    }
}
