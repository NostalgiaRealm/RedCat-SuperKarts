/*
 * FUN_0047695c at 0047695c
 * undefined4 __register FUN_0047695c(int param_1)
 * Address ranges: 0047695c-00476989
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0047695c(int param_1)

{
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  
  FUN_00476a1c();
  FUN_00476b28();
  *(undefined1 *)(param_1 + 900) = 0;
  FUN_00476cd8(param_1,extraout_EDX);
  FUN_00476eb8(param_1);
  return CONCAT31((int3)((uint)unaff_EBX >> 8),1);
}

