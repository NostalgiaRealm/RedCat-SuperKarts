/*
 * FUN_00451dc0 at 00451dc0
 * undefined __register FUN_00451dc0(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00451dc0-00451e0e;00451e26-00451e35
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451dc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  if (*(char *)(*(int *)(param_1 + 0x24) + 0x41c) != '\0') {
    puStack_18 = (undefined1 *)0x451de1;
    piVar1 = FUN_004507f8((int *)&PTR_FUN_004501d8,'\x01',param_3);
    puStack_1c = &LAB_00451e0f;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_004510c0(piVar1,*(int *)(param_1 + 0x24),
                 CONCAT31((int3)((uint)extraout_ECX >> 8),
                          *(undefined1 *)(*(int *)(param_1 + 0x24) + 0x42c)));
    *in_FS_OFFSET = uStack_20;
    puStack_18 = (undefined1 *)0x451e30;
    FUN_004524e4(param_1,(int)piVar1);
  }
  return;
}

