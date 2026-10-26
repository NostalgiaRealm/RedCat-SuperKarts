/*
 * FUN_00451d50 at 00451d50
 * undefined __register FUN_00451d50(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00451d50-00451d98;00451db0-00451dbf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451d50(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  if (*(char *)(*(int *)(param_1 + 0x24) + 0x42c) != '\0') {
    puStack_18 = (undefined1 *)0x451d71;
    piVar1 = FUN_004507f8((int *)&PTR_FUN_004501d8,'\x01',param_3);
    puStack_1c = &LAB_00451d99;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_004510c0(piVar1,*(int *)(param_1 + 0x24),0);
    *in_FS_OFFSET = uStack_20;
    puStack_18 = (undefined1 *)0x451dba;
    FUN_004524e4(param_1,(int)piVar1);
  }
  return;
}

