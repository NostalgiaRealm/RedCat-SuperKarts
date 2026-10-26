/*
 * FUN_004478f4 at 004478f4
 * undefined __register FUN_004478f4(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 004478f4-0044792d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004478f4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int extraout_ECX;
  int iVar1;
  
  (**(code **)(param_4 + 8))(*(undefined4 *)(param_4 + 0xc),param_1);
  iVar1 = extraout_ECX;
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar1 = param_4;
    FUN_004478f4(*(int *)(param_1 + 0xc),param_4,extraout_ECX,param_4);
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_004478f4(*(int *)(param_1 + 8),param_4,iVar1,param_4);
  }
  return;
}

