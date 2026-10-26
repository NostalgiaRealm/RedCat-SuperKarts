/*
 * FUN_0044f974 at 0044f974
 * undefined FUN_0044f974(void)
 * Address ranges: 0044f974-0044f9c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044f974(int *param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  int *in_FS_OFFSET;
  int iStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_1c = &LAB_0044f9c3;
  iStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_20;
  FUN_00409b1c(&iStack_8,param_2,param_3);
  iVar1 = iStack_8;
  (**(code **)(*param_1 + 4))(param_1,param_2,param_3);
  *in_FS_OFFSET = iVar1;
  puStack_1c = &LAB_0044f9ca;
  iStack_20 = 0x44f9c2;
  FUN_00403b50(&iStack_8);
  return;
}

