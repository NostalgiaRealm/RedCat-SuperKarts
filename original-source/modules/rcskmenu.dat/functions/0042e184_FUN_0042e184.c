/*
 * FUN_0042e184 at 0042e184
 * int __register FUN_0042e184(int * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0042e184-0042e1c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0042e184(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = FUN_00439428(param_1,*(int *)(*(int *)(*(int *)(param_4 + -4) + 8) + 8),'\x01');
    if (iVar1 == 0) {
      iVar1 = FUN_00439428(param_1,*(int *)(*(int *)(*(int *)(param_4 + -4) + 8) + 0xc),'\0');
    }
  }
  return iVar1;
}

