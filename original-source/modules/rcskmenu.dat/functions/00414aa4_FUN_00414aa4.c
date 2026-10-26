/*
 * FUN_00414aa4 at 00414aa4
 * undefined __register FUN_00414aa4(int param_1, int param_2, char param_3)
 * Address ranges: 00414aa4-00414afd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414aa4(int param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((param_3 == '\x01') && (param_2 != 0)) {
    FUN_00414a88(param_1,param_2);
  }
  if ((*(int *)(param_1 + 0x10) != 0) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 8), -1 < iVar2 + -1)) {
    iVar3 = 0;
    do {
      piVar1 = (int *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x10),iVar3);
      (**(code **)(*piVar1 + 0x10))(piVar1,param_2,param_3);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

