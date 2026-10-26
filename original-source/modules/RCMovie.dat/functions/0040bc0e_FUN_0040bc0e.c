/*
 * FUN_0040bc0e at 0040bc0e
 * undefined4 __cdecl FUN_0040bc0e(int param_1)
 * Address ranges: 0040bc0e-0040bce0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040bc0e(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  if (DAT_0043d6f8 != 0) {
    FUN_0040bbdf();
  }
  DAT_0043d6d4 = LocalAlloc(0x40,param_1 * 0x18);
  if (DAT_0043d6d4 == (HLOCAL)0x0) {
    uVar1 = 2000;
  }
  else {
    DAT_0043d6d8 = param_1;
    for (local_8 = 0; local_8 < DAT_0043d6d8; local_8 = local_8 + 1) {
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 8) = 0;
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 0xc) = 0;
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 0x10) = 0;
      *(int *)((int)DAT_0043d6d4 + local_8 * 0x18 + 0x14) = local_8;
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 4) = 0;
    }
    DAT_0043d6f8 = 0;
    uVar1 = 0;
  }
  return uVar1;
}

