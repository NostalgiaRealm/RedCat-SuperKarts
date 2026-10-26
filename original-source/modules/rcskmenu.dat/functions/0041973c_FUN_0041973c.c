/*
 * FUN_0041973c at 0041973c
 * undefined4 __register FUN_0041973c(byte * param_1, byte * param_2, undefined4 param_3, int param_4)
 * Address ranges: 0041973c-004197cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041973c(byte *param_1,byte *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (uint)*param_2 - **(int **)(param_4 + 8);
  uVar5 = (uint)param_2[1] - *(int *)(*(int *)(param_4 + 8) + 4);
  uVar6 = (uint)*param_1 - **(int **)(param_4 + 8);
  uVar1 = (uint)param_1[1] - *(int *)(*(int *)(param_4 + 8) + 4);
  if ((((int)((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f)) <
        (int)((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f))) ||
      (((0 < (int)uVar4 && ((int)uVar6 < (int)uVar4)) ||
       (iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f),
       iVar2 < (int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f)))))) ||
     ((0 < (int)uVar5 && ((int)uVar1 < (int)uVar5)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return uVar3;
}

