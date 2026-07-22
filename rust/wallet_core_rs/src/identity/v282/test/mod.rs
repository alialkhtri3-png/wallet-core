#[cfg(test)]
mod tests{
    use crate::identity::v282::RealIdentityEngine;

    #[test]
    fn real_engine_online(){
        let e=RealIdentityEngine::new();
        assert!(e.status().contains("online"));
        assert_eq!(e.version,"282.0.0");
    }
}
