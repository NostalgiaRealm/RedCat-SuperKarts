/*
 * FUN_0040fa84 at 0040fa84
 * undefined __register FUN_0040fa84(int param_1, int param_2)
 * Address ranges: 0040fa84-0040fac6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fa84(int param_1,int param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x40fa96;
  FUN_0040fa70(param_1);
  puStack_14 = &LAB_0040fac7;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_0040f848(*(int **)(param_1 + 4),param_2);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0040face;
  puStack_14 = (undefined1 *)0x40fac6;
  FUN_0040fad4(param_1);
  return;
}

