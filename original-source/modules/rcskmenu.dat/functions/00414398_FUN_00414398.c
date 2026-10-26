/*
 * FUN_00414398 at 00414398
 * undefined __register FUN_00414398(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 00414398-004143d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414398(int param_1,undefined4 param_2,uint param_3)

{
  uint extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  int local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = 0;
  puStack_14 = &LAB_004143d5;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  FUN_00413fec(param_1,&local_8,param_3);
  FUN_00414230(param_1,extraout_EDX,extraout_ECX);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_004143dc;
  puStack_14 = (undefined1 *)0x4143d4;
  FUN_00403b50(&local_8);
  return;
}

