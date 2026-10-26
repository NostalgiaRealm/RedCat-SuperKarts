/*
 * FUN_00417b64 at 00417b64
 * undefined __register FUN_00417b64(int * param_1, byte * param_2)
 * Address ranges: 00417b64-00417ba8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417b64(int *param_1,byte *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x417b76;
  FUN_00417254((int)param_1);
  puStack_14 = &LAB_00417ba9;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_00416cbc(DAT_0047d6cc,param_1,param_2);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00417bb0;
  puStack_14 = (undefined1 *)0x417ba8;
  FUN_00417264((int)param_1);
  return;
}

