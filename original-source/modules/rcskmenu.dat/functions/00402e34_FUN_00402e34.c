/*
 * FUN_00402e34 at 00402e34
 * undefined4 __register FUN_00402e34(int param_1)
 * Address ranges: 00402e34-00402e3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402e34(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(undefined4 **)(param_1 + -0x24) != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)(param_1 + -0x24);
  }
  return uVar1;
}

