/*
 * FUN_00422eb4 at 00422eb4
 * undefined4 __register FUN_00422eb4(int param_1)
 * Address ranges: 00422eb4-00422ecb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00422eb4(int param_1)

{
  undefined4 in_EDX;
  
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x6c) != 0) break;
    param_1 = *(int *)(param_1 + 0x24);
  }
  return CONCAT31((int3)((uint)in_EDX >> 8),1);
}

