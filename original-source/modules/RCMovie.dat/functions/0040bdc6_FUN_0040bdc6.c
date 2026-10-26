/*
 * FUN_0040bdc6 at 0040bdc6
 * undefined4 __cdecl FUN_0040bdc6(int param_1)
 * Address ranges: 0040bdc6-0040be71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040bdc6(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  if (param_1 < 1) {
    uVar1 = 2000;
  }
  else {
    DAT_00431b64 = param_1;
    DAT_0043d6e8 = LocalAlloc(0x40,param_1 << 5);
    if (DAT_0043d6e8 == (HLOCAL)0x0) {
      uVar1 = 2000;
    }
    else {
      for (local_8 = 0; local_8 < DAT_00431b64; local_8 = local_8 + 1) {
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20) = 0;
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x18) = 4;
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x1c) = 0;
      }
      DAT_0043d6f0 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}

