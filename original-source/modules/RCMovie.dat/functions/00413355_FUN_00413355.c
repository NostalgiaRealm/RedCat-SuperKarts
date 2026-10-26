/*
 * FUN_00413355 at 00413355
 * undefined4 __cdecl FUN_00413355(int param_1)
 * Address ranges: 00413355-004133e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00413355(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  DAT_00434c1c = param_1;
  DAT_0043d858 = LocalAlloc(0x40,param_1 * 0xc);
  if (DAT_0043d858 == (HLOCAL)0x0) {
    uVar1 = 2000;
  }
  else {
    for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
      *(undefined4 *)((int)DAT_0043d858 + local_8 * 0xc + 8) = 0;
      *(undefined4 *)((int)DAT_0043d858 + local_8 * 0xc + 4) = 0;
      *(undefined4 *)((int)DAT_0043d858 + local_8 * 0xc) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}

