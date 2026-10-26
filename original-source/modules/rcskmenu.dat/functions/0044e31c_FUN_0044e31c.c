/*
 * FUN_0044e31c at 0044e31c
 * undefined __register FUN_0044e31c(undefined4 param_1)
 * Address ranges: 0044e31c-0044e37b;0044e3bd-0044e3d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e31c(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_130;
  undefined1 *puStack_12c;
  undefined1 *puStack_128;
  undefined4 local_124;
  undefined1 *puStack_120;
  undefined1 *puStack_11c;
  int local_c;
  undefined4 local_8;
  
  puStack_11c = &stack0xfffffffc;
  puStack_128 = &stack0xfffffffc;
  local_c = 0;
  puStack_120 = &LAB_0044e3d3;
  local_124 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_124;
  puStack_12c = &LAB_0044e37c;
  uStack_130 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_130;
  puVar1 = &stack0xfffffffc;
  local_8 = param_1;
  if (DAT_0047bbf8 != 0) {
    FUN_0044e424(DAT_0047bbf8);
    *(undefined1 *)(DAT_0047bbf8 + 4) = 1;
    FUN_0040bfec(&DAT_0047bbf8);
    puVar1 = puStack_128;
  }
  puStack_128 = puVar1;
  *in_FS_OFFSET = uStack_130;
  *in_FS_OFFSET = local_124;
  puStack_11c = &LAB_0044e3da;
  puStack_120 = (undefined1 *)0x44e3d2;
  FUN_00403b50(&local_c);
  return;
}

