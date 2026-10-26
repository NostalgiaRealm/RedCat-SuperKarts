/*
 * FUN_004140e4 at 004140e4
 * undefined __register FUN_004140e4(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004140e4-0041411f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004140e4(int param_1,undefined4 param_2,uint param_3)

{
  uint extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  int local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = 0;
  puStack_14 = &LAB_00414120;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  do {
    FUN_00413fec(param_1,&local_8,param_3);
    param_3 = extraout_ECX;
  } while (local_8 != 0);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00414127;
  puStack_14 = (undefined1 *)0x41411f;
  FUN_00403b50(&local_8);
  return;
}

