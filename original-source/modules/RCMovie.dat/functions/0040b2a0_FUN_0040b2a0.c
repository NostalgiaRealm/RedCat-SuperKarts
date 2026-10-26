/*
 * FUN_0040b2a0 at 0040b2a0
 * undefined4 __cdecl FUN_0040b2a0(int param_1)
 * Address ranges: 0040b2a0-0040b35a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040b2a0(int param_1)

{
  int local_8;
  
  DAT_0043d5ac = LocalAlloc(0x40,param_1 * 0xc);
  if (DAT_0043d5ac == (HLOCAL)0x0) {
    FUN_0040187a((byte *)s__s__d____error_not_enough_memory_0043173c);
  }
  DAT_0043d5b0 = param_1;
  for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
    *(undefined4 *)((int)DAT_0043d5ac + local_8 * 0xc) = 0xffffffff;
    *(undefined4 *)((int)DAT_0043d5ac + local_8 * 0xc + 4) = 0xffffffff;
    *(undefined4 *)((int)DAT_0043d5ac + local_8 * 0xc + 8) = 0;
  }
  DAT_0043d5b4 = 1;
  FUN_004015a6((byte *)s_timer_init_ok____d_00431780);
  return 0;
}

