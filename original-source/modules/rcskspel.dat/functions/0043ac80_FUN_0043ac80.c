/*
 * FUN_0043ac80 at 0043ac80
 * undefined FUN_0043ac80(void)
 * Address ranges: 0043ac80-0043ace1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0043ac80(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = *param_1;
  iVar4 = param_1[1];
  iVar5 = param_1[3];
  iVar6 = param_1[2] + param_3 * -4;
  uVar1 = iVar6 - iVar3 >> 2;
  if ((int)uVar1 < 0) {
    uVar2 = -(0x3ff - uVar1 >> 10);
  }
  else {
    uVar2 = uVar1 >> 10;
  }
  if (uVar2 != 0) {
    iVar3 = *(int *)(iVar5 + uVar2 * 4);
    iVar5 = iVar5 + uVar2 * 4;
    iVar4 = iVar3 + 0x1000;
    iVar6 = iVar3 + (uVar1 + uVar2 * -0x400) * 4;
  }
  *param_2 = iVar3;
  param_2[1] = iVar4;
  param_2[2] = iVar6;
  param_2[3] = iVar5;
  return;
}

