/*
 * FUN_00470508 at 00470508
 * undefined __register FUN_00470508(int param_1, uint * param_2)
 * Address ranges: 00470508-0047054b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00470508(int param_1,uint *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  uint *local_8;
  
  puStack_10 = (undefined1 *)0x47051a;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_14 = &LAB_0047054c;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_8);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00470553;
  puStack_14 = (undefined1 *)0x47054b;
  FUN_00403b50((int *)&local_8);
  return;
}

