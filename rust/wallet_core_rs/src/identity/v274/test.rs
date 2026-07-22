#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn identity_core_online() {
        let core = IdentityCore::new();
        assert!(core.status().contains("online"));
    }
}
