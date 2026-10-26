/*
 * FUN_00408f54 at 00408f54
 * undefined __register FUN_00408f54(undefined4 * param_1, uint param_2, undefined4 param_3, int param_4)
 * Address ranges: 00408f54-00408f95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408f54(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = 0x100 - *(int *)(param_4 + -0x104);
  if ((int)param_2 < (int)uVar1) {
    uVar1 = param_2;
  }
  if (uVar1 != 0) {
    FUN_0040282c(param_1,(undefined4 *)(param_4 + -0x100 + *(int *)(param_4 + -0x104)),uVar1);
  }
  *(int *)(param_4 + -0x104) = *(int *)(param_4 + -0x104) + uVar1;
  return;
}

