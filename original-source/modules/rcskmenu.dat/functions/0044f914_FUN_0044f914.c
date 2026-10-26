/*
 * FUN_0044f914 at 0044f914
 * undefined __register FUN_0044f914(int * param_1, undefined4 param_2, undefined1 * param_3)
 * Address ranges: 0044f914-0044f962
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044f914(int *param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  int *in_FS_OFFSET;
  int iStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = 0;
  puStack_1c = &LAB_0044f963;
  iStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_20;
  FUN_00409aec(&local_8,param_2,param_3);
  iVar1 = local_8;
  (**(code **)(*param_1 + 4))(param_1,param_2,param_3);
  *in_FS_OFFSET = iVar1;
  puStack_1c = &LAB_0044f96a;
  iStack_20 = 0x44f962;
  FUN_00403b50(&local_8);
  return;
}

