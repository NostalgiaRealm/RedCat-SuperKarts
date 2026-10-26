/*
 * FUN_00414db8 at 00414db8
 * undefined __register FUN_00414db8(int param_1, int param_2)
 * Address ranges: 00414db8-00414e08
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414db8(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = FUN_0040f70c(*(int *)(*(int *)(param_1 + 4) + 0x10),param_1);
    if (-1 < iVar3) {
      piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x10);
      iVar2 = piVar1[2];
      if (param_2 < 0) {
        param_2 = 0;
      }
      if (iVar2 <= param_2) {
        param_2 = iVar2 + -1;
      }
      if (iVar3 != param_2) {
        FUN_0040f550(piVar1,iVar3);
        FUN_0040f72c(*(int **)(*(int *)(param_1 + 4) + 0x10),param_2,param_1);
      }
    }
  }
  return;
}

