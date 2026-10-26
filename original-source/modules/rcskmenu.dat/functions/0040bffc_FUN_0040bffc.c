/*
 * FUN_0040bffc at 0040bffc
 * undefined __register FUN_0040bffc(undefined * param_1, UINT param_2)
 * Address ranges: 0040bffc-0040c04f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040bffc(undefined *param_1,UINT param_2)

{
  LPCSTR lpLibFileName;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x40c00b;
  SetErrorMode(param_2);
  puStack_1c = &LAB_0040c06e;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &LAB_0040c050;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_24 = &stack0xfffffffc;
  lpLibFileName = FUN_00403f94(param_1);
  LoadLibraryA(lpLibFileName);
  *in_FS_OFFSET = uStack_2c;
  return;
}

