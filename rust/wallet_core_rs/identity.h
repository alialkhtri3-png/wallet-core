#ifndef TW_IDENTITY_H
#define TW_IDENTITY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

char *tw_identity_engine_status(void);
void tw_identity_string_free(char *ptr);
uint32_t tw_identity_get_score(void);
char *tw_identity_analyze_wallet(const char *address);
char *tw_identity_scan_wallet(const char *address);
char *tw_identity_scan_chain_wallet(const char *address);
char *tw_identity_rpc_scan_wallet(const char *address);
char *tw_identity_get_reputation(void);
char *tw_identity_export_vc(void);

#ifdef __cplusplus
}
#endif

#endif

char *tw_identity_multichain_scan_wallet(const char *address);

char *tw_identity_graph_analyze_wallet(const char *address);

char *tw_identity_sybil_analyze_wallet(const char *address);

char *tw_identity_generate_attestation(const char *address);

char *tw_identity_get_full_report(const char *address);

char *tw_identity_generate_proof(const char *address);

char *tw_identity_verify_onchain(const char *address);

char *tw_identity_registry_check(const char *address);

char *tw_identity_resolve_did(const char *address);

char *tw_identity_verify_credential(const char *address);

char *tw_identity_trust_score(const char *address);

char *tw_identity_decision_engine(const char *address);

char *tw_identity_ai_reasoning(const char *address);

char *tw_identity_policy_enforce(const char *address);

char *tw_identity_api_gateway(const char *address);

char *tw_identity_zk_proof_generate(const char *address);
