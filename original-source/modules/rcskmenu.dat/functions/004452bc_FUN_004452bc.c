/*
 * FUN_004452bc at 004452bc
 * undefined __register FUN_004452bc(int * param_1, int param_2, int param_3)
 * Address ranges: 004452bc-0044530c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004452bc(int *param_1,int param_2,int param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x4452d1;
  FUN_004421f4((int)param_1);
  puStack_18 = &LAB_0044530d;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  FUN_00445274((int)param_1,param_2,param_3);
  FUN_0043f2c8(param_1,param_2,param_3);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00445314;
  puStack_18 = (undefined1 *)0x44530c;
  FUN_004421fc((int)param_1);
  return;
}

