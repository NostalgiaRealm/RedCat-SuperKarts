/*
 * FUN_0041175c at 0041175c
 * undefined __register FUN_0041175c(int param_1, uint param_2, uint param_3, undefined * param_4)
 * Address ranges: 0041175c-004117ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041175c(int param_1,uint param_2,uint param_3,undefined *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_14;
  uint local_c;
  
  local_c = param_2;
  do {
    local_14 = local_c + param_3 >> 1;
    uVar3 = local_c;
    uVar4 = param_3;
    do {
      while (iVar2 = (*(code *)param_4)(param_1,uVar3,local_14), iVar2 < 0) {
        uVar3 = uVar3 + 1;
      }
      while (iVar2 = (*(code *)param_4)(param_1,uVar4,local_14), 0 < iVar2) {
        uVar4 = uVar4 - 1;
      }
      if ((int)uVar3 <= (int)uVar4) {
        FUN_004114bc(param_1,uVar3,uVar4);
        uVar1 = uVar4;
        if ((uVar3 != local_14) && (uVar1 = local_14, uVar4 == local_14)) {
          uVar1 = uVar3;
        }
        local_14 = uVar1;
        uVar3 = uVar3 + 1;
        uVar4 = uVar4 - 1;
      }
    } while ((int)uVar3 <= (int)uVar4);
    if ((int)local_c < (int)uVar4) {
      FUN_0041175c(param_1,local_c,uVar4,param_4);
    }
    local_c = uVar3;
  } while ((int)uVar3 < (int)param_3);
  return;
}

