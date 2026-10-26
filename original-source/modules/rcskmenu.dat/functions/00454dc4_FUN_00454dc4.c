/*
 * FUN_00454dc4 at 00454dc4
 * undefined __register FUN_00454dc4(int param_1, char param_2, int * param_3)
 * Address ranges: 00454dc4-00454e15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454dc4(int param_1,char param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00403b50(param_3);
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (-1 < iVar2 + -1) {
    iVar3 = 0;
    do {
      iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 8),iVar3);
      if (param_2 == *(char *)(iVar1 + 4)) {
        iVar2 = FUN_0040f6b0(*(undefined4 **)(param_1 + 8),iVar3);
        FUN_00403ba4(param_3,*(undefined4 **)(iVar2 + 8));
        return;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

