/*
 * FUN_0043a008 at 0043a008
 * undefined __register FUN_0043a008(int * param_1)
 * Address ranges: 0043a008-0043a031;0043a04b-0043a050
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a008(int *param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_1c = &LAB_0043a032;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  (**(code **)(*param_1 + 0x10))();
  *in_FS_OFFSET = uStack_20;
  return;
}

