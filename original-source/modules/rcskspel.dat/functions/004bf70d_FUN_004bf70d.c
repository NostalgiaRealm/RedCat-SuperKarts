/*
 * FUN_004bf70d at 004bf70d
 * undefined FUN_004bf70d(void)
 * Address ranges: 004bf70d-004bf75a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bf70d(uint param_1,uint param_2,int param_3,code *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  for (; uVar2 = param_1, uVar3 = param_1, param_1 < param_2; param_2 = param_2 - param_3) {
    while (uVar3 = uVar3 + param_3, uVar3 <= param_2) {
      iVar1 = (*param_4)(uVar3,uVar2);
      if (0 < iVar1) {
        uVar2 = uVar3;
      }
    }
    FUN_004bf75b(uVar2,param_2,param_3);
  }
  return;
}

