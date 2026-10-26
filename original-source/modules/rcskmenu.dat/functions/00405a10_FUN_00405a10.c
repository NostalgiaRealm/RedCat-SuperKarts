/*
 * FUN_00405a10 at 00405a10
 * undefined __register FUN_00405a10(int param_1)
 * Address ranges: 00405a10-00405aa9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405a10(int param_1)

{
  uint uVar1;
  
  if (param_1 < 0) {
    uVar1 = -param_1;
    if (0x13ff < (int)uVar1) {
      return;
    }
    if ((uVar1 >> 5 != 0) && (uVar1 >> 9 != 0)) {
      return;
    }
  }
  else if ((param_1 != 0) && (0x13ff < param_1)) {
    return;
  }
  return;
}

