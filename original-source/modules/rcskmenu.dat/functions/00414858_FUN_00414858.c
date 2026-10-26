/*
 * FUN_00414858 at 00414858
 * undefined __register FUN_00414858(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 00414858-004148a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414858(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 4) != *(int *)(param_2 + 4))) {
    if (*(int *)(param_1 + 0x14) == 0) {
      uVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
      *(undefined4 *)(param_1 + 0x14) = uVar1;
    }
    iVar2 = FUN_0040f70c(*(int *)(param_1 + 0x14),param_2);
    if (iVar2 < 0) {
      FUN_0040f504(*(int **)(param_1 + 0x14),param_2);
      FUN_00414858(param_2,param_1,extraout_ECX);
    }
  }
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) | 0x100;
  return;
}

