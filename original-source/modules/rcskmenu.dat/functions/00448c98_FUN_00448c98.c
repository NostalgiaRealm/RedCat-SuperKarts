/*
 * FUN_00448c98 at 00448c98
 * undefined __register FUN_00448c98(int param_1, int param_2, undefined4 param_3, int param_4)
 * Address ranges: 00448c98-00448d46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448c98(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  int iVar1;
  int iVar2;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_c;
  int local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_c = 0;
  puStack_1c = &LAB_00448d47;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  local_8 = param_2;
  (**(code **)(**(int **)(param_4 + -4) + 8))(*(int **)(param_4 + -4),&local_8,4);
  (**(code **)(**(int **)(param_4 + -4) + 8))(*(int **)(param_4 + -4),param_1 + 0x10,1);
  (**(code **)(**(int **)(param_4 + -4) + 8))(*(int **)(param_4 + -4),param_1 + 0x20,4);
  iVar1 = param_4;
  FUN_00447450(param_1,&local_c);
  FUN_00448c20(local_c,extraout_EDX,extraout_ECX,iVar1);
  iVar2 = iVar1;
  if (*(int *)(param_1 + 8) != 0) {
    iVar2 = param_4;
    FUN_00448c98(*(int *)(param_1 + 8),local_8 + 1,iVar1,param_4);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00448c98(*(int *)(param_1 + 0xc),local_8,iVar2,param_4);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00448d4e;
  puStack_1c = (undefined1 *)0x448d46;
  FUN_00403b50(&local_c);
  return;
}

