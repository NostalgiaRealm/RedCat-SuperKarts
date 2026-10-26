/*
 * FUN_0043e170 at 0043e170
 * undefined __register FUN_0043e170(void)
 * Address ranges: 0043e170-0043e1e2;0043e200-0043e21f;0043e227-0043e22a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e170(void)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int *local_14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  puStack_18 = (undefined1 *)0x43e180;
  local_c = (undefined4 *)FUN_0040fa70(DAT_0047d7e8);
  puStack_1c = &LAB_0043e220;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if (-1 < local_c[2] + -1) {
    local_8 = 0;
    puStack_18 = &stack0xfffffffc;
    local_10 = local_c[2];
    do {
      puStack_24 = (undefined1 *)0x43e1b2;
      local_14 = (int *)FUN_0040f6b0(local_c,local_8);
      puStack_24 = (undefined1 *)0x43e1bd;
      cVar1 = FUN_00418830((int)local_14);
      if (cVar1 != '\0') {
        puStack_28 = &LAB_0043e1f9;
        uStack_2c = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_2c;
        puStack_24 = &stack0xfffffffc;
        FUN_0043e3ac(local_14);
        FUN_004036a4();
        puStack_24 = (undefined1 *)0x43e1e1;
        FUN_004036a4();
        return;
      }
      local_8 = local_8 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = (undefined1 *)0x43e227;
  puStack_1c = (undefined1 *)0x43e21f;
  FUN_0040fad4(DAT_0047d7e8);
  return;
}

