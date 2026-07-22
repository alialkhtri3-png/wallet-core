pub mod mesh;
pub mod nodes;
pub mod peers;
pub mod sync;
pub mod resolver;
pub mod events;
pub mod reputation;
pub mod agents;
pub mod api;
pub mod test;

pub const VERSION: &str = "287.0.0";

pub struct SovereignIdentityMesh {
    pub version: &'static str,
}

impl SovereignIdentityMesh {
    pub fn new() -> Self {
        Self { version: VERSION }
    }

    pub fn status(&self) -> String {
        format!("Sovereign Identity Mesh Network V{} online", self.version)
    }
}
