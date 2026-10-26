/*
 * FUN_004beae4 at 004beae4
 * undefined FUN_004beae4(void)
 * Address ranges: 004beae4-004beb10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004beae4(code *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x004beb0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

