pub mod rpc;
pub mod scanner;
pub mod score;
pub mod sybil;
pub mod did;
pub mod credential;
pub mod graph;
pub mod reputation;
pub mod api;
pub mod test;

pub const VERSION:&str="280.0.0";

pub struct SovereignExecutionEngine{
    pub version:&'static str
}

impl SovereignExecutionEngine{
    pub fn new()->Self{
        Self{version:VERSION}
    }

    pub fn status(&self)->String{
        format!("Sovereign Execution Identity Engine V{} online",self.version)
    }
}
