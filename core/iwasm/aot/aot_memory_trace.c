/*
 * Memory OOB trace helper (debug only)
 * Build with -DWAMR_MEMORY_OOB_TRACE to enable.
 */
#include <stdio.h>
#include <inttypes.h>
#include "aot_runtime.h"

#ifdef WAMR_MEMORY_OOB_TRACE
/* Extended version: captures raw addr operand, offset immediate, mem base */
void
aot_memory_oob_trace(void *module_inst,
                      uint64_t offset1, uint64_t bound, uint32_t bytes,
                      uint64_t addr_raw, uint64_t offset_const_raw,
                      uint64_t mem_base)
{
    /* offset1 > bound triggers exception; bound = (data_size - bytes) */
    fprintf(stderr,
            "[WAMR][OOB] off=%" PRIu64 " bound=%" PRIu64 " bytes=%u | addr=%" PRIu64 " off_imm=%" PRIu64 " base=%" PRIu64 "\n",
            offset1, bound, bytes, addr_raw, offset_const_raw, mem_base);
    (void)module_inst;
    (void)mem_base; /* keep for future richer diagnostics */
}
#endif /* WAMR_MEMORY_OOB_TRACE */
