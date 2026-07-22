#[derive(Debug)]
pub struct DidDocument {
    pub id: String,
    pub controller: String,
}

impl DidDocument {
    pub fn new(id: &str, controller: &str) -> Self {
        Self {
            id: id.to_string(),
            controller: controller.to_string(),
        }
    }
}
