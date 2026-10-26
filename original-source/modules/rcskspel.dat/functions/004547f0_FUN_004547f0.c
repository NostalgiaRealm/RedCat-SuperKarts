/*
 * FUN_004547f0 at 004547f0
 * undefined FUN_004547f0(void)
 * Address ranges: 004547f0-004548f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004547f0(int param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined1 local_8 [4];
  uint local_4;
  
  bVar2 = true;
  piVar1 = *(int **)(param_1 + 4);
  piVar3 = piVar1;
  piVar4 = (int *)piVar1[1];
  while (piVar4 != DAT_00543d54) {
    bVar2 = *param_3 < piVar4[3];
    piVar3 = piVar4;
    if (bVar2) {
      piVar4 = (int *)*piVar4;
    }
    else {
      piVar4 = (int *)piVar4[2];
    }
  }
  if (*(char *)(param_1 + 8) != '\0') {
    puVar5 = (undefined4 *)FUN_00454d40(local_8,piVar4,piVar3,param_3);
    local_4 = CONCAT31(local_4._1_3_,1);
    *param_2 = *puVar5;
    param_2[1] = local_4;
    return;
  }
  if (bVar2) {
    if (piVar3 == (int *)*piVar1) {
      puVar5 = (undefined4 *)FUN_00454d40(local_8,piVar4,piVar3,param_3);
      local_4 = CONCAT31(local_4._1_3_,1);
      *param_2 = *puVar5;
      param_2[1] = local_4;
      return;
    }
    FUN_00455000();
  }
  if (piVar3[3] < *param_3) {
    puVar5 = (undefined4 *)FUN_00454d40(local_8,piVar4,piVar3,param_3);
    local_4 = CONCAT31(local_4._1_3_,1);
    *param_2 = *puVar5;
    param_2[1] = local_4;
    return;
  }
  local_4 = local_4 & 0xffffff00;
  *param_2 = piVar3;
  param_2[1] = local_4;
  return;
}

