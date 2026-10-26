/*
 * FUN_00452ccc at 00452ccc
 * undefined FUN_00452ccc(void)
 * Address ranges: 00452ccc-00452d0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452ccc(int param_1,int param_2,uint param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *puStack_8;
  
  puStack_14 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_00452d10;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_00414028(param_2,(int *)&puStack_8,param_3);
  FUN_00403ba4((int *)(param_1 + 0xc),puStack_8);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00452d17;
  puStack_18 = (undefined1 *)0x452d0f;
  FUN_00403b50((int *)&puStack_8);
  return;
}

