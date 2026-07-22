pub mod indexer;
pub mod transaction;
pub mod token;
pub mod confidence;
pub mod credential;
pub mod export;
pub mod policy;
pub mod api;
pub mod test;

pub const VERSION:&str="281.0.0";

pub struct SovereignIdentityProtocol {
    pub version:&'static str,
}

impl SovereignIdentityProtocol {

pub fn new()->Self{
Self{
version:VERSION
}
}

pub fn status(&self)->String{
format!(
"Sovereign Identity Protocol V{} online",
self.version
)
}

}
