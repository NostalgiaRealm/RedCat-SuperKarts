/*
 * FUN_00401fd4 at 00401fd4
 * undefined4 __register FUN_00401fd4(int param_1)
 * Address ranges: 00401fd4-00401ffe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401fd4(int param_1)

{
  undefined4 uVar1;
  uint local_c [2];
  
  FUN_00401840(param_1 + 4,(int *)local_c);
  if ((local_c[0] != 0) && (uVar1 = FUN_00401f48(local_c), (char)uVar1 != '\0')) {
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return 0;
}

