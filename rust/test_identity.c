#include <stdio.h>
#include "wallet_core_rs/identity.h"

int main() {
    char *status = tw_identity_engine_status();

    if(status) {
        printf("%s\n", status);
        tw_identity_string_free(status);
    }

    return 0;
}
