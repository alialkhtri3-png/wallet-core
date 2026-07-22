#[cfg(test)]
mod tests {
    use crate::identity::v287::SovereignIdentityMesh;

    #[test]
    fn mesh_network_online() {
        let mesh = SovereignIdentityMesh::new();
        assert!(mesh.status().contains("online"));
        assert_eq!(mesh.version, "287.0.0");
    }
}
