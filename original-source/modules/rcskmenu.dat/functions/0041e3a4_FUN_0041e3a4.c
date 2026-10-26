/*
 * FUN_0041e3a4 at 0041e3a4
 * undefined __register FUN_0041e3a4(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0041e3a4-0041e3e3;0041e3fb-0041e416
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e3a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  
  uStack_18 = 0x41e3bd;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_00416944,'\x01',param_3);
  puStack_1c = &LAB_0041e3e4;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  *(undefined4 *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  *in_FS_OFFSET = uStack_20;
  uStack_18 = 0x41e403;
  FUN_0041bd50(iVar1);
  uStack_18 = 0x41e40b;
  FUN_0041bd54(*(int **)(param_1 + 0x20));
  *(int *)(param_1 + 0x20) = iVar1;
  return;
}

