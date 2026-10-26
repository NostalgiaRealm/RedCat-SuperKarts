/*
 * FUN_00404298 at 00404298
 * uint __register FUN_00404298(int param_1)
 * Address ranges: 00404298-004042a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00404298(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + -4) >> 1;
  }
  return uVar1;
}

