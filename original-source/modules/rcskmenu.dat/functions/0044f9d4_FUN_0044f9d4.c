/*
 * FUN_0044f9d4 at 0044f9d4
 * undefined FUN_0044f9d4(void)
 * Address ranges: 0044f9d4-0044fa26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044f9d4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *in_FS_OFFSET;
  int iStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_1c = &LAB_0044fa27;
  iStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_20;
  FUN_00408b38(&iStack_8);
  iVar1 = iStack_8;
  (**(code **)(*param_1 + 4))(param_1,param_2,param_3);
  *in_FS_OFFSET = iVar1;
  puStack_1c = &LAB_0044fa2e;
  iStack_20 = 0x44fa26;
  FUN_00403b50(&iStack_8);
  return;
}

