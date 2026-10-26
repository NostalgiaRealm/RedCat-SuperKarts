/*
 * FUN_004b8d50 at 004b8d50
 * undefined FUN_004b8d50(void)
 * Address ranges: 004b8d50-004b8daa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b8d50(int param_1)

{
  if (DAT_006ab924 == 0) {
    DAT_006ab8f4 = LocalAlloc(0x40,param_1 * 0xd8);
    if (DAT_006ab8f4 == (HLOCAL)0x0) {
      FUN_004afee0(s__s__d____not_enough_memory_to_re_00500384);
      return 2000;
    }
    DAT_006ab91c = param_1;
    DAT_006ab920 = 0;
    DAT_006ab924 = 1;
  }
  return 0;
}

