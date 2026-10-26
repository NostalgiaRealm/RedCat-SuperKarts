/*
 * FUN_00403dd0 at 00403dd0
 * undefined4 __register FUN_00403dd0(int param_1)
 * Address ranges: 00403dd0-00403dd7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00403dd0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + -4);
  }
  return uVar1;
}

