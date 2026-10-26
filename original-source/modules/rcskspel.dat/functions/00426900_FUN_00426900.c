/*
 * FUN_00426900 at 00426900
 * undefined FUN_00426900(void)
 * Address ranges: 00426900-004269d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426900(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  FUN_00426670(param_2,local_40,local_80);
  FUN_00426720(param_3,local_40,local_80);
  FUN_00426780(0,local_40,local_80);
  FUN_00426800(param_1,local_40,local_80);
  iVar1 = FUN_00426540(param_1);
  *(undefined4 *)(&DAT_0050dfb0 + iVar1 * 0x1910) = 2;
  FUN_0048f4e0();
  uVar2 = __ftol();
  iVar1 = FUN_00426540(param_1);
  *(undefined4 *)(&DAT_0050f8b8 + iVar1 * 0x1910) = uVar2;
  iVar1 = FUN_00426540(param_1);
  *(undefined4 *)(&DAT_0050f8b4 + iVar1 * 0x1910) = 1;
  return;
}

