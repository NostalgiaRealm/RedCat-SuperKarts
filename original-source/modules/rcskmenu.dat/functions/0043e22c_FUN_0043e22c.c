/*
 * FUN_0043e22c at 0043e22c
 * undefined __register FUN_0043e22c(void)
 * Address ranges: 0043e22c-0043e2a1;0043e2a9-0043e2c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e22c(void)

{
  int iVar1;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int *local_10;
  undefined4 *local_c;
  int local_8;
  
  puStack_14 = (undefined1 *)0x43e23c;
  local_c = (undefined4 *)FUN_0040fa70(DAT_0047d7e8);
  puStack_18 = &LAB_0043e2ca;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  iVar1 = local_c[2] + -1;
  if (-1 < local_c[2] + -1) {
    do {
      local_8 = iVar1;
      puStack_20 = (undefined1 *)0x43e267;
      local_10 = (int *)FUN_0040f6b0(local_c,local_8);
      puStack_20 = (undefined1 *)0x43e272;
      cVar2 = FUN_00418830((int)local_10);
      if (cVar2 != '\0') {
        puStack_24 = &LAB_0043e2a2;
        uStack_28 = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_28;
        puStack_20 = &stack0xfffffffc;
        FUN_0043e3ac(local_10);
        *in_FS_OFFSET = uStack_28;
        puStack_20 = (undefined1 *)0x43e2a9;
        puStack_24 = (undefined1 *)0x43e2a1;
        FUN_0041888c((int)local_10);
        return;
      }
      local_8 = local_8 + -1;
      iVar1 = local_8;
    } while (local_8 != -1);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0043e2d1;
  puStack_18 = (undefined1 *)0x43e2c9;
  FUN_0040fad4(DAT_0047d7e8);
  return;
}

