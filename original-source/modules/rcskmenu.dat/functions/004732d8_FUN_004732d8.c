/*
 * FUN_004732d8 at 004732d8
 * undefined __register FUN_004732d8(void)
 * Address ranges: 004732d8-00473329
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004732d8(void)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_14 = &LAB_0047332a;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  cVar1 = FUN_00472c1c();
  if (cVar1 == '\0') {
    FUN_0045c4c8(0x4b,(int *)&local_8);
    FUN_00460d08(local_8);
  }
  FUN_00472c1c();
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00473331;
  puStack_14 = (undefined1 *)0x473329;
  FUN_00403b50((int *)&local_8);
  return;
}

