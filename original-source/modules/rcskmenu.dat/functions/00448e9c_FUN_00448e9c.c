/*
 * FUN_00448e9c at 00448e9c
 * undefined __register FUN_00448e9c(int param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00448e9c-00448f02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448e9c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0xc) == 0) && (param_1 != *(int *)(*(int *)(param_4 + -4) + 100))) {
      if (*(int *)(*(int *)(param_4 + -4) + 100) == *(int *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_4 + -4) + 0x68);
      }
      else {
        *(undefined4 *)(param_1 + 0x20) =
             *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 0x20);
      }
    }
    if (*(int *)(param_1 + 8) != 0) {
      iVar1 = param_4;
      FUN_00448e9c(*(int *)(param_1 + 8),param_4,param_3,param_4);
      param_3 = iVar1;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00448e9c(*(int *)(param_1 + 0xc),param_4,param_3,param_4);
    }
  }
  return;
}

