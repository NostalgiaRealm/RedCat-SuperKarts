/*
 * FUN_00417be4 at 00417be4
 * undefined4 __register FUN_00417be4(int param_1)
 * Address ranges: 00417be4-00417c69;00417c71-00417c7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00417be4(int param_1)

{
  HPEN pHVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  LOGPEN local_18;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x10);
  if (*(int *)(local_8 + 8) == 0) {
    puStack_1c = (undefined1 *)0x417c03;
    FUN_00416b10(DAT_0047d6cc);
    puStack_20 = &LAB_00417c6a;
    uStack_24 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_24;
    if (*(int *)(local_8 + 8) == 0) {
      local_18.lopnStyle = (UINT)*(ushort *)(&DAT_0047b594 + (uint)*(byte *)(local_8 + 0x1c) * 2);
      local_18.lopnWidth.x = *(LONG *)(local_8 + 0x18);
      puStack_1c = &stack0xfffffffc;
      local_18.lopnColor = FUN_00417210(*(uint *)(local_8 + 0x14));
      pHVar1 = CreatePenIndirect(&local_18);
      *(HPEN *)(local_8 + 8) = pHVar1;
    }
    *in_FS_OFFSET = uStack_24;
    puStack_1c = (undefined1 *)0x417c71;
    puStack_20 = (undefined1 *)0x417c69;
    uVar2 = FUN_00416b1c(DAT_0047d6cc);
    return uVar2;
  }
  return *(undefined4 *)(local_8 + 8);
}

