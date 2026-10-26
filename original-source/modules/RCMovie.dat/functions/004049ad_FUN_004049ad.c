/*
 * FUN_004049ad at 004049ad
 * undefined4 __stdcall FUN_004049ad(void)
 * Address ranges: 004049ad-00404a0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004049ad(void)

{
  undefined4 uVar1;
  
  if (DAT_00438488 == 0) {
    uVar1 = 0;
  }
  else {
    if (((DAT_0042dfa4 != 1) && (DAT_0042dfa4 == 2)) && (DAT_004384ac != (int *)0x0)) {
      (**(code **)(*DAT_004384ac + 8))(DAT_004384ac);
      DAT_004384ac = (int *)0x0;
    }
    DAT_00438488 = 0;
    uVar1 = 1;
  }
  return uVar1;
}

