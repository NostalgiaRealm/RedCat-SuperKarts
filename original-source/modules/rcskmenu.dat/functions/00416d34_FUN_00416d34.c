/*
 * FUN_00416d34 at 00416d34
 * undefined __register FUN_00416d34(int param_1, int * param_2, undefined4 * param_3)
 * Address ranges: 00416d34-00416d8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416d34(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = (undefined1 *)0x416d4a;
  FUN_00416b10(param_1);
  puStack_1c = &LAB_00416d90;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puVar1 = (undefined4 *)param_2[4];
  if (param_3 != puVar1) {
    param_3[1] = param_3[1] + 1;
    param_2[4] = (int)param_3;
    puStack_18 = &stack0xfffffffc;
    FUN_00403088(param_2,extraout_EDX,extraout_ECX);
    FUN_00416c0c(param_1,puVar1);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00416d97;
  puStack_1c = (undefined1 *)0x416d8f;
  FUN_00416b1c(param_1);
  return;
}

