/*
 * FUN_004129c8 at 004129c8
 * undefined __register FUN_004129c8(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004129c8-00412a39
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004129c8(int param_1,undefined4 param_2,uint param_3)

{
  uint extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_c;
  char local_5;
  
  puStack_14 = &stack0xfffffffc;
  local_c = 0;
  puStack_18 = &LAB_00412a3a;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0041252c(param_1,6,param_3);
  FUN_0041292c(param_1,(undefined4 *)&local_5,1);
  if (local_5 != '\x01') {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    FUN_00413fec(param_1,&local_c,extraout_ECX);
    FUN_004124c0();
  }
  FUN_0041292c(param_1,(undefined4 *)&local_5,1);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00412a41;
  puStack_18 = (undefined1 *)0x412a39;
  FUN_00403b50(&local_c);
  return;
}

