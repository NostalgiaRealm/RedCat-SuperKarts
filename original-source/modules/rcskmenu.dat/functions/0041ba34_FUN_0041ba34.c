/*
 * FUN_0041ba34 at 0041ba34
 * undefined __register FUN_0041ba34(void)
 * Address ranges: 0041ba34-0041baa9;0041bab1-0041bad1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ba34(void)

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
  
  puStack_14 = (undefined1 *)0x41ba44;
  local_c = (undefined4 *)FUN_0040fa70(DAT_0047b5dc);
  puStack_18 = &LAB_0041bad2;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  iVar1 = local_c[2] + -1;
  if (-1 < local_c[2] + -1) {
    do {
      local_8 = iVar1;
      puStack_20 = (undefined1 *)0x41ba6f;
      local_10 = (int *)FUN_0040f6b0(local_c,local_8);
      puStack_20 = (undefined1 *)0x41ba7a;
      cVar2 = FUN_00418830((int)local_10);
      if (cVar2 != '\0') {
        puStack_24 = &LAB_0041baaa;
        uStack_28 = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_28;
        puStack_20 = &stack0xfffffffc;
        FUN_0041bbc4(local_10);
        *in_FS_OFFSET = uStack_28;
        puStack_20 = (undefined1 *)0x41bab1;
        puStack_24 = (undefined1 *)0x41baa9;
        FUN_0041888c((int)local_10);
        return;
      }
      local_8 = local_8 + -1;
      iVar1 = local_8;
    } while (local_8 != -1);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0041bad9;
  puStack_18 = (undefined1 *)0x41bad1;
  FUN_0040fad4(DAT_0047b5dc);
  return;
}

