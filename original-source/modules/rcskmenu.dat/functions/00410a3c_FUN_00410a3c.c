/*
 * FUN_00410a3c at 00410a3c
 * undefined __register FUN_00410a3c(int * param_1)
 * Address ranges: 00410a3c-00410a80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410a3c(int *param_1)

{
  char *pcVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined *local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = (undefined *)0x0;
  puStack_14 = &LAB_00410a81;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  (**(code **)(*param_1 + 0x1c))(param_1,&local_8);
  pcVar1 = FUN_00403f94(local_8);
  FUN_00408548(pcVar1);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00410a88;
  puStack_14 = (undefined1 *)0x410a80;
  FUN_00403b50((int *)&local_8);
  return;
}

