/*
 * FUN_0042d900 at 0042d900
 * undefined FUN_0042d900(void)
 * Address ranges: 0042d900-0042d989
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d900(int *param_1,int param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x42d918;
  FUN_004185e8(param_1[0x88]);
  puStack_14 = &LAB_0042d9ad;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_1c = (undefined1 *)0x42d936;
  puStack_10 = &stack0xfffffffc;
  FUN_00418a14((int *)param_1[0x88],param_2);
  puStack_20 = &LAB_0042d98a;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  if (param_1[0x8e] == 0) {
    puStack_1c = &stack0xfffffffc;
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  }
  else {
    puStack_1c = &stack0xfffffffc;
    (**(code **)(*(int *)param_1[0x8e] + 0x28))();
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0042d991;
  puStack_20 = (undefined1 *)0x42d989;
  FUN_00418a14((int *)param_1[0x88],0);
  return;
}

