/*
you shouldn't be here!
*/

#include <stdio.h>
#include <mach/mach.h>
#include <unistd.h>
#include <sys/types.h>
#include <mach-o/dyld.h>
#include <string.h>
#include <stdlib.h>



/*
kern_return_t vm_region_recurse_64(
     vm_map_t map,
     vm_address_t *address,
     vm_size_t *size,
     uint32_t *depth,
     vm_region_recurse_info_64_t info,
     mach_msg_type_number_t *infoCnt)


*/

int main() {

    vm_size_t size = 0;
    kern_return_t kret;

    kret = host_page_size(mach_host_self(), &size);
    printf("Host Page Size: 0x%x\n", size);

    if (kret != KERN_SUCCESS) {
         return kret;
    }
    return 0;
}
