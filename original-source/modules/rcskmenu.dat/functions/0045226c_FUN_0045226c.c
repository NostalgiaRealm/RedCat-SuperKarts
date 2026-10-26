/*
 * FUN_0045226c at 0045226c
 * undefined FUN_0045226c(void)
 * Address ranges: 0045226c-004522b0;004522c8-004522e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045226c(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = (undefined1 *)0x452283;
  piVar1 = FUN_004507f8((int *)&PTR_FUN_004501d8,'\x01',param_3);
  puStack_1c = &LAB_004522b1;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_18 = &stack0xfffffffc;
  FUN_00451288(piVar1,param_2,*(char *)(param_1[9] + 0x42c));
  *in_FS_OFFSET = uStack_20;
  puStack_18 = (undefined1 *)0x4522d2;
  FUN_004524e4((int)param_1,(int)piVar1);
  puStack_18 = (undefined1 *)0x4522db;
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

