/*
 * FUN_00447134 at 00447134
 * undefined FUN_00447134(void)
 * Address ranges: 00447134-004471ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447134(int *param_1,int param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x44714c;
  FUN_004185e8(param_1[0x7c]);
  puStack_14 = &LAB_004471d2;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_1c = (undefined1 *)0x44716a;
  puStack_10 = &stack0xfffffffc;
  FUN_00418a14((int *)param_1[0x7c],param_2);
  puStack_20 = &LAB_004471af;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_1c = &stack0xfffffffc;
  FUN_0043e3f8(param_1[0x7c]);
  (**(code **)(*param_1 + 0xb4))();
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_004471b6;
  puStack_20 = (undefined1 *)0x4471ae;
  FUN_00418a14((int *)param_1[0x7c],0);
  return;
}

