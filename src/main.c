#include "mgos.h"
#include "mgos_jstore.h"

enum mgos_app_init_result mgos_app_init(void) {
    char *error;
    struct mgos_jstore *store = mgos_jstore_create("jstore.json", &error);
    if(store == NULL){
        LOG(LL_ERROR, ("JSTORE FAILED TO CREATE!"));
        if(error != NULL){
            LOG(LL_ERROR, ("Error: %s", error));
        }
    }
    mgos_jstore_free(store);
    return MGOS_APP_INIT_SUCCESS;
}