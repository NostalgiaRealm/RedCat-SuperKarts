/*
 * FUN_00441a54 at 00441a54
 * undefined __register FUN_00441a54(int * param_1, int * param_2)
 * Address ranges: 00441a54-00441a93
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441a54(int *param_1,int *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x441a66;
  FUN_004421f4((int)param_1);
  puStack_14 = &LAB_00441a94;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_0043eb8c(param_1,param_2);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00441a9b;
  puStack_14 = (undefined1 *)0x441a93;
  FUN_004421fc((int)param_1);
  return;
}

