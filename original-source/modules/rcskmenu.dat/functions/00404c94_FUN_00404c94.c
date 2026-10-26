/*
 * FUN_00404c94 at 00404c94
 * undefined4 __register FUN_00404c94(int param_1)
 * Address ranges: 00404c94-00404c9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00404c94(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + -4);
  }
  return uVar1;
}

