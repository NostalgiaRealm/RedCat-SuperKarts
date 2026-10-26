/*
 * FUN_00433504 at 00433504
 * undefined FUN_00433504(void)
 * Address ranges: 00433504-0043354c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433504(void)

{
  undefined1 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0043354d;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d778 = _DAT_0047d778 + 1;
  if (_DAT_0047d778 == 0) {
    puVar1 = &stack0xfffffffc;
    if (DAT_0047d770 != 0) {
      FUN_004292ac();
      puVar1 = puStack_8;
    }
    puStack_8 = puVar1;
    if (DAT_0047d788 != (HANDLE)0x0) {
      CloseHandle(DAT_0047d788);
    }
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

