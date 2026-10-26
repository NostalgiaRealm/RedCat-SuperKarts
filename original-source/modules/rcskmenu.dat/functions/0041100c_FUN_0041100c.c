/*
 * FUN_0041100c at 0041100c
 * undefined FUN_0041100c(void)
 * Address ranges: 0041100c-00411058
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041100c(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int iStack_8;
  
  puStack_14 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_18 = &LAB_00411059;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  (**(code **)(*param_1 + 0x1c))(param_1,&iStack_8);
  iVar1 = FUN_00403dd0(iStack_8);
  FUN_00411920(param_2,iStack_8,iVar1);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00411060;
  puStack_18 = (undefined1 *)0x411058;
  FUN_00403b50(&iStack_8);
  return;
}

