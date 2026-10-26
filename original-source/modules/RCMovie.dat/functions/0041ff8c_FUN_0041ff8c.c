/*
 * FUN_0041ff8c at 0041ff8c
 * undefined __stdcall FUN_0041ff8c(undefined * UNRECOVERED_JUMPTABLE)
 * Address ranges: 0041ff8c-0041ffb8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ff8c(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x0041ffb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}

