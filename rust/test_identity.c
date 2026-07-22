#include <stdio.h>
#include "wallet_core_rs/identity.h"

int main(){

    char *report = tw_identity_registry_check(
        "0xC9feC3B35382A27e46353005516C4f7364fc0f7A"
    );

    printf("V55 Identity Registry:\n%s\n", report);

    tw_identity_string_free(report);

    return 0;
}
