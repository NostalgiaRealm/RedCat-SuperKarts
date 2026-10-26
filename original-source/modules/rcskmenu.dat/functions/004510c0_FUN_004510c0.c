/*
 * FUN_004510c0 at 004510c0
 * undefined __register FUN_004510c0(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 004510c0-00451150
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004510c0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x41c) == '\0') {
    FUN_00450dc0(param_1,param_2,param_3);
  }
  else {
    FUN_004508a8(param_1,*(int *)(param_2 + 0x47c),*(undefined4 *)(param_2 + 0x428),'\0',
                 (char)param_3,(undefined4 *)(param_2 + 0x15),(int *)(param_2 + 0x444),
                 *(int *)(param_2 + 8));
    iVar1 = *(int *)(*(int *)(param_2 + 0xc) + 0x10);
    if (iVar1 == 1) {
      FUN_00450fd4();
    }
    else if (iVar1 == 2) {
      FUN_00450e64();
    }
    else {
      FUN_00450dc0(param_1,param_2,param_3);
    }
  }
  return;
}

