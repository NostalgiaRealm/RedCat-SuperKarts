/*
 * FUN_00448c20 at 00448c20
 * undefined __register FUN_00448c20(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00448c20-00448c8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448c20(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_c;
  int local_8;
  
  puStack_14 = (undefined1 *)0x448c32;
  local_8 = param_1;
  FUN_00403f84(param_1);
  puStack_18 = &LAB_00448c8b;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  local_c = FUN_00403dd0(local_8);
  (**(code **)(**(int **)(param_4 + -4) + 8))(*(int **)(param_4 + -4),&local_c,4);
  if (0 < local_c) {
    (**(code **)(**(int **)(param_4 + -4) + 8))(*(int **)(param_4 + -4),local_8,local_c);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00448c92;
  puStack_18 = (undefined1 *)0x448c8a;
  FUN_00403b50(&local_8);
  return;
}

