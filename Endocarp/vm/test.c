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
    vm_address_t address;
    vm_size_t size = getpagesize();

    kern_return_t kret;

    kret = vm_allocate(mach_task_self(),
                        &address, //address of allocation or out pointer where vm_allocate will allocate
                        size,  // size of page size
                        true); //true means it will allocate at any available page bound. false will allocate at vm_address_t address.

    if (kret != KERN_SUCCESS) {
        printf("Exit with error: %s\n", mach_error_string(kret));
        return kret;
    }

    printf("Allocated memory at 0x%lx\n", address);
    kret = vm_deallocate(mach_task_self(),
                        address, //address of allocation by vm_allocate
                        size); //size of allocation (page size)

    if (kret != KERN_SUCCESS) {
        printf("Exit with error: %s\n", mach_error_string(kret));
        return kret;
    }

    printf("Deallocated memory allocated at 0x%lx\n", address);
    return 0;
}
