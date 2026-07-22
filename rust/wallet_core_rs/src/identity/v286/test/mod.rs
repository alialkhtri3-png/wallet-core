#[cfg(test)]
mod tests {
    use crate::identity::v286::SovereignIdentityCloudRuntime;

    #[test]
    fn cloud_runtime_online() {
        let runtime = SovereignIdentityCloudRuntime::new();
        assert!(runtime.status().contains("online"));
        assert_eq!(runtime.version, "286.0.0");
    }
}
