/*
 * FUN_00458eb4 at 00458eb4
 * undefined4 __register FUN_00458eb4(int param_1, undefined4 param_2, int param_3)
 * Address ranges: 00458eb4-00458ecf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00458eb4(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_3 == *(int *)(param_1 + 4 + (uVar1 & 0xff) * 4)) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    uVar1 = uVar1 + 1;
  } while ((char)uVar1 != '\x06');
  return 0;
}

