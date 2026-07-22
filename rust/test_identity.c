#include <stdio.h>
#include "wallet_core_rs/identity.h"
int main(){
    char *report = tw_identity_zora_bridge("0xC9feC3B35382A27e46353005516C4f7364fc0f7A");
    printf("V64 Zora Bridge Report:\n%s\n", report);
    tw_identity_string_free(report);
    return 0;
}
