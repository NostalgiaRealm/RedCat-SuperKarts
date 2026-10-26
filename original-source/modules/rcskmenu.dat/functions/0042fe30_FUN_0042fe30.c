/*
 * FUN_0042fe30 at 0042fe30
 * undefined FUN_0042fe30(void)
 * Address ranges: 0042fe30-0042fe41
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042fe30(int *param_1,int *param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = CONCAT31((int3)((uint)param_3 >> 8),DAT_0047d4d1) ^ 1;
  *(char *)(param_1 + 0x12) = (char)uVar1;
  FUN_00414be4(param_1,param_2,uVar1);
  return;
}

