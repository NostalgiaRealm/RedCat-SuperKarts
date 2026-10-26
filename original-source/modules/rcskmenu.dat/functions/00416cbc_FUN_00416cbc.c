/*
 * FUN_00416cbc at 00416cbc
 * undefined __register FUN_00416cbc(int param_1, int * param_2, byte * param_3)
 * Address ranges: 00416cbc-00416d24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416cbc(int param_1,int *param_2,byte *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x416cd5;
  FUN_00416b10(param_1);
  puStack_20 = &LAB_00416d25;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puVar1 = (undefined4 *)param_2[4];
  puStack_1c = &stack0xfffffffc;
  puVar2 = (undefined4 *)FUN_00416b28(param_1,param_3);
  param_2[4] = (int)puVar2;
  if (puVar1 != puVar2) {
    FUN_00403088(param_2,extraout_EDX,extraout_ECX);
  }
  FUN_00416c0c(param_1,puVar1);
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00416d2c;
  puStack_20 = (undefined1 *)0x416d24;
  FUN_00416b1c(param_1);
  return;
}

