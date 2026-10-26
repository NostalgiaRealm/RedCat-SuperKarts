/*
 * FUN_0040f1dc at 0040f1dc
 * undefined4 __cdecl FUN_0040f1dc(int param_1)
 * Address ranges: 0040f1dc-0040f240
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040f1dc(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_0043d7f8 == 0) {
    DAT_0043d7c8 = LocalAlloc(0x40,param_1 * 0xd8);
    if (DAT_0043d7c8 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_re_00432f30);
      uVar1 = 2000;
    }
    else {
      DAT_0043d7f0 = param_1;
      DAT_0043d7f4 = 0;
      DAT_0043d7f8 = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

