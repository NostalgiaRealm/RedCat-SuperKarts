/*
 * FUN_0041e834 at 0041e834
 * undefined __register FUN_0041e834(int param_1)
 * Address ranges: 0041e834-0041e87e;0041e89d-0041e8aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e834(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined *puStack_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  local_10 = *(undefined4 **)(param_1 + 4);
  if (local_10 == (undefined4 *)0x0) {
    return;
  }
  puStack_14 = (undefined *)0x41e850;
  local_c = local_10;
  local_8 = param_1;
  FUN_0041e668(param_1);
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  *(undefined4 *)(local_8 + 4) = *local_10;
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &DAT_0041e886;
  uStack_18 = 0x41e87e;
  FUN_0041e674(local_8);
  return;
}

