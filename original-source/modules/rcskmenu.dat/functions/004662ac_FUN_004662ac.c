/*
 * FUN_004662ac at 004662ac
 * undefined __register FUN_004662ac(int param_1, int param_2)
 * Address ranges: 004662ac-0046631a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004662ac(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  if (*(int *)(param_1 + 0x1fc) != 0) {
    FUN_0043430c(*(int *)(param_1 + 0x1fc),*(int *)(param_1 + 0x1f8));
  }
  *(int *)(param_1 + 0x1fc) = param_2;
  if (param_2 != 0) {
    FUN_00434350(param_2,*(int *)(param_1 + 0x1f8));
    FUN_00414858(*(int *)(param_1 + 0x1fc),param_1,extraout_ECX);
    iVar1 = FUN_004339b0(*(int **)(param_1 + 0x1fc));
    FUN_004405f0(param_1,0x1303,0,iVar1);
    return;
  }
  FUN_004405f0(param_1,0x1303,0,0);
  return;
}

