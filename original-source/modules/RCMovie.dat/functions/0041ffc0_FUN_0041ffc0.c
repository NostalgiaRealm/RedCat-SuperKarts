/*
 * FUN_0041ffc0 at 0041ffc0
 * undefined __stdcall FUN_0041ffc0(undefined4 param_1, undefined * UNRECOVERED_JUMPTABLE)
 * Address ranges: 0041ffc0-0041ffc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ffc0(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ffc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}

