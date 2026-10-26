/*
 * FUN_00452160 at 00452160
 * undefined FUN_00452160(void)
 * Address ranges: 00452160-004521a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452160(int *param_1,undefined4 param_2,HGLOBAL param_3)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x452173;
  piVar1 = FUN_004520d0((int *)FUN_004520a8,'\x01',param_3);
  puStack_14 = &LAB_004521a4;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  (**(code **)(*param_1 + 0x30))(param_1,piVar1);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_004521ab;
  puStack_14 = (undefined1 *)0x4521a3;
  FUN_00402eac(piVar1);
  return;
}

