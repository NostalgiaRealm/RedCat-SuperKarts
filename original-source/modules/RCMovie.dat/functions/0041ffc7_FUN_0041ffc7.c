/*
 * FUN_0041ffc7 at 0041ffc7
 * undefined __stdcall FUN_0041ffc7(undefined4 param_1, undefined * UNRECOVERED_JUMPTABLE)
 * Address ranges: 0041ffc7-0041ffcd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ffc7(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ffcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}

