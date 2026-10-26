/*
 * FUN_00442b48 at 00442b48
 * undefined __register FUN_00442b48(int param_1)
 * Address ranges: 00442b48-00442b94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442b48(int param_1)

{
  BOOL BVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &stack0xfffffffc;
  *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x200;
  puStack_10 = &LAB_00442b95;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  local_8 = param_1;
  BVar1 = DestroyWindow(*(HWND *)(param_1 + 0x14c));
  if (BVar1 == 0) {
    FUN_0040bd58();
  }
  *in_FS_OFFSET = uStack_14;
  *(ushort *)(local_8 + 0x44) = *(ushort *)(local_8 + 0x44) & 0xfdff;
  return;
}

