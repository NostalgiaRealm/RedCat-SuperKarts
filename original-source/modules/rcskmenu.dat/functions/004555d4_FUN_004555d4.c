/*
 * FUN_004555d4 at 004555d4
 * undefined __register FUN_004555d4(int param_1, uint * param_2, char param_3, int * param_4)
 * Address ranges: 004555d4-00455635
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004555d4(int param_1,uint *param_2,char param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  
  FUN_00403b50(param_4);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (-1 < iVar2 + -1) {
    iVar3 = 0;
    uVar4 = true;
    do {
      iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 4),iVar3);
      FUN_00403ee0(param_2,*(uint **)(iVar1 + 4));
      if ((bool)uVar4) {
        iVar2 = FUN_0040f6b0(*(undefined4 **)(param_1 + 4),iVar3);
        FUN_00454dc4(iVar2,param_3,param_4);
        return;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
      uVar4 = iVar2 == 0;
    } while (!(bool)uVar4);
  }
  return;
}

