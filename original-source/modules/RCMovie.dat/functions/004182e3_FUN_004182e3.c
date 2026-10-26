/*
 * FUN_004182e3 at 004182e3
 * undefined4 __stdcall FUN_004182e3(void)
 * Address ranges: 004182e3-00418302
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004182e3(void)

{
  undefined4 uVar1;
  
  if (DAT_00435818 == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_00435820 + DAT_00435818 * 0x10);
  }
  return uVar1;
}

