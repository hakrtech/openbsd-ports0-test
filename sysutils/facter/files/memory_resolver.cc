#include <internal/facts/openbsd/memory_resolver.hpp>
#include <facter/execution/execution.hpp>
#include <leatherman/logging/logging.hpp>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/sysctl.h>
#include <sys/swap.h>
#include <unistd.h>

using namespace std;
using namespace facter::execution;
using namespace facter::util;

namespace facter { namespace facts { namespace openbsd {

    memory_resolver::data memory_resolver::collect_data(collection& facts)
    {
        data result;

        // Get the system page size
        int pagesize_mib[] = { CTL_HW, HW_PAGESIZE};
        int page_size = 0;
        size_t len = sizeof(page_size);
        if (sysctl(pagesize_mib, 2, &page_size, &len, nullptr, 0) == -1) {
            LOG_DEBUG("sysctl failed: %1% (%2%): system page size is unknown.", strerror(errno), errno);
        } else {
                int uvmexp_mib[] = { CTL_VM, VM_UVMEXP };
                struct uvmexp uvmexp;
                len = sizeof(uvmexp);
                if (sysctl(uvmexp_mib, 2, &uvmexp, &len, nullptr, 0) == -1) {
                    LOG_DEBUG("sysctl uvmexp failed: %1% (%2%): free memory is not available.", strerror(errno), errno);
                }

                // Should we account for the buffer cache?
                result.mem_total = static_cast<u_int64_t>(uvmexp.npages) << uvmexp.pageshift;
                result.mem_free = static_cast<u_int64_t>(uvmexp.free) << uvmexp.pageshift;
        }

        struct swapent *swapdev;
        int nswaps, s;
        uint64_t swap_used = 0;

        // NB: swapctl(2) for SWAP_NSWAP cannot fail
        nswaps = swapctl(SWAP_NSWAP, 0, 0);

        if ((swapdev = (struct swapent *)calloc(nswaps, sizeof(*swapdev))) == NULL)
            LOG_DEBUG("cannot allocate swapdev.");

        if (swapctl(SWAP_STATS, swapdev, nswaps) == -1)
             LOG_DEBUG("swapctl: SWAP_STATS failed: %1% (%2%)", strerror(errno), errno);

        for (s = 0; s < nswaps; s++) {
            if (swapdev[s].se_flags & SWF_ENABLE) {
                result.swap_total += (swapdev[s].se_nblks * DEV_BSIZE);
                swap_used += (swapdev[s].se_inuse * DEV_BSIZE);
            }
        }

        result.swap_free = result.swap_total - swap_used;

        // 0 is for CTL_SWPENC_NAMES' "enable", see uvm_swap_encrypt.h
        int swap_encrypted_mib[] = { CTL_VM, VM_SWAPENCRYPT, 0 };
        int encrypted;
        len = sizeof(encrypted);

        if (sysctl(swap_encrypted_mib, 3, &encrypted, &len, nullptr, 0) == -1) {
                LOG_DEBUG("sysctl failed: %1% (%2%): encrypted swap fact not available.", strerror(errno), errno);
        }

        result.swap_encryption = encrypted ? encryption_status::encrypted : encryption_status::not_encrypted;
        return result;
    }

}}}  // namespace facter::facts::openbsd
