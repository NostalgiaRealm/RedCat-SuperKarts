/*
 * FUN_00417e74 at 00417e74
 * undefined __register FUN_00417e74(int * param_1, undefined4 param_2)
 * Address ranges: 00417e74-00417e97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417e74(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  byte abStack_18 [8];
  undefined4 local_10;
  
  puVar2 = &DAT_0047b5a4;
  pbVar3 = abStack_18;
  for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pbVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    pbVar3 = (byte *)((int)pbVar3 + 4);
  }
  local_10 = param_2;
  FUN_00417e24(param_1,abStack_18);
  return;
}

