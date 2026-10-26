/*
 * FUN_00405c6e at 00405c6e
 * undefined4 __cdecl FUN_00405c6e(int param_1)
 * Address ranges: 00405c6e-00405cd2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00405c6e(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_0043d438 == 0) {
    DAT_0043d41c = LocalAlloc(0x40,param_1 * 0xd8);
    if (DAT_0043d41c == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_re_0042f194);
      uVar1 = 2000;
    }
    else {
      DAT_0043d430 = param_1;
      DAT_0043d434 = 0;
      DAT_0043d438 = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

