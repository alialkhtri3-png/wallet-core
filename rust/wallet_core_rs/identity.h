#ifndef TW_IDENTITY_H
#define TW_IDENTITY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

char *tw_identity_engine_status(void);
uint32_t tw_identity_get_score(void);
char *tw_identity_analyze_wallet(void);
char *tw_identity_get_reputation(void);
char *tw_identity_export_vc(void);
void tw_identity_string_free(char *ptr);

#ifdef __cplusplus
}
#endif

#endif

char *tw_identity_analyze_wallet(void);
char *tw_identity_get_reputation(void);
char *tw_identity_export_vc(void);
