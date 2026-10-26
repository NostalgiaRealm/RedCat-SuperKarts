/*
 * FUN_0043a020 at 0043a020
 * undefined FUN_0043a020(void)
 * Address ranges: 0043a020-0043a084
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0043a020(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  iVar1 = param_1[2] + param_2 * 4;
  uVar2 = iVar1 - *param_1 >> 2;
  if ((int)uVar2 < 0) {
    uVar3 = -(0x3ff - uVar2 >> 10);
  }
  else {
    uVar3 = uVar2 >> 10;
  }
  if (uVar3 == 0) {
    param_1[2] = iVar1;
    return;
  }
  piVar4 = (int *)(param_1[3] + uVar3 * 4);
  param_1[3] = (int)piVar4;
  iVar1 = *piVar4;
  *param_1 = iVar1;
  param_1[1] = iVar1 + 0x1000;
  param_1[2] = *param_1 + (uVar2 + uVar3 * -0x400) * 4;
  return;
}

