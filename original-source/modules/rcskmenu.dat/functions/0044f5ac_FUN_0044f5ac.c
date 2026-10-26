/*
 * FUN_0044f5ac at 0044f5ac
 * undefined FUN_0044f5ac(void)
 * Address ranges: 0044f5ac-0044f5f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044f5ac(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *in_FS_OFFSET;
  int iStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_1c = &LAB_0044f5f8;
  iStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_20;
  FUN_00407f60(param_4,&iStack_8);
  iVar1 = iStack_8;
  (**(code **)(*param_1 + 4))(param_1,param_2,param_3);
  *in_FS_OFFSET = iVar1;
  puStack_1c = &LAB_0044f5ff;
  iStack_20 = 0x44f5f7;
  FUN_00403b50(&iStack_8);
  return;
}

