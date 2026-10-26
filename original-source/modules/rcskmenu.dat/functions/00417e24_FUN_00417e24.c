/*
 * FUN_00417e24 at 00417e24
 * undefined __register FUN_00417e24(int * param_1, byte * param_2)
 * Address ranges: 00417e24-00417e68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417e24(int *param_1,byte *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x417e36;
  FUN_00417254((int)param_1);
  puStack_14 = &LAB_00417e69;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_00416cbc(DAT_0047d6d0,param_1,param_2);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00417e70;
  puStack_14 = (undefined1 *)0x417e68;
  FUN_00417264((int)param_1);
  return;
}

