/*
 * FUN_004b3a20 at 004b3a20
 * undefined FUN_004b3a20(void)
 * Address ranges: 004b3a20-004b3a7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3a20(int param_1)

{
  if (DAT_006ab7b0 == 0) {
    DAT_006ab794 = LocalAlloc(0x40,param_1 * 0xd8);
    if (DAT_006ab794 == (HLOCAL)0x0) {
      FUN_004afee0(s__s__d____not_enough_memory_to_re_00500384);
      return 2000;
    }
    DAT_006ab7a8 = param_1;
    DAT_006ab7ac = 0;
    DAT_006ab7b0 = 1;
  }
  return 0;
}

