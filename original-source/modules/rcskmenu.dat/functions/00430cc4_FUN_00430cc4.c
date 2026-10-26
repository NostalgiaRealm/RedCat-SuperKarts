/*
 * FUN_00430cc4 at 00430cc4
 * undefined __register FUN_00430cc4(void)
 * Address ranges: 00430cc4-00430cf4;00430d0f-00430d15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430cc4(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  if (DAT_0047d770 != 0) {
    puStack_18 = &LAB_00430cf5;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    FUN_00432e1c(DAT_0047d770);
    *in_FS_OFFSET = uStack_1c;
  }
  return;
}

