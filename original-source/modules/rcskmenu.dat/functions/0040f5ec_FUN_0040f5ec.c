/*
 * FUN_0040f5ec at 0040f5ec
 * undefined __register FUN_0040f5ec(undefined4 param_1, undefined4 * param_2, undefined4 param_3)
 * Address ranges: 0040f5ec-0040f633
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f5ec(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  byte *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (byte *)0x0;
  puStack_18 = &LAB_0040f634;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_00405438(param_2,(int *)&local_8);
  FUN_0040f5b4(&PTR_FUN_0040de6c,local_8,param_3);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0040f63b;
  puStack_18 = (undefined1 *)0x40f633;
  FUN_00403b50((int *)&local_8);
  return;
}

