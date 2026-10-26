/*
 * FUN_004534f4 at 004534f4
 * undefined __register FUN_004534f4(int param_1, undefined4 param_2)
 * Address ranges: 004534f4-00453525
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004534f4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x4c) + 8) + -1;
  if (-1 < iVar2) {
    do {
      uVar3 = 0;
      iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x4c),iVar2);
      FUN_004405f0(iVar1,param_2,0,uVar3);
      iVar2 = iVar2 + -1;
    } while (iVar2 != -1);
  }
  return;
}

