/*
 * FUN_004030a0 at 004030a0
 * undefined4 __register FUN_004030a0(int * param_1, undefined4 param_2)
 * Address ranges: 004030a0-004030b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004030a0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 in_ZF;
  
  FUN_00403058(*param_1);
  if ((bool)in_ZF) {
    uVar1 = FUN_004029c8();
    return uVar1;
  }
  return param_2;
}

