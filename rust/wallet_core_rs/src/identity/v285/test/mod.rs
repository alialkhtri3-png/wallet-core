#[cfg(test)]
mod tests {
    use crate::identity::v285::IdentityOperatingSystem;

    #[test]
    fn identity_os_online() {
        let os = IdentityOperatingSystem::new();
        assert!(os.status().contains("online"));
        assert_eq!(os.version, "285.0.0");
    }
}
