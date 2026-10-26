/*
 * FUN_004110a0 at 004110a0
 * undefined FUN_004110a0(void)
 * Address ranges: 004110a0-004110e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004110a0(int *param_1,char *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int iStack_8;
  
  puStack_14 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_18 = &LAB_004110e3;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_00403d08(&iStack_8,param_2);
  (**(code **)(*param_1 + 0x2c))(param_1,iStack_8);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004110ea;
  puStack_18 = (undefined1 *)0x4110e2;
  FUN_00403b50(&iStack_8);
  return;
}

