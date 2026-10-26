/*
 * FUN_00407fcc at 00407fcc
 * undefined4 __register FUN_00407fcc(byte * param_1, undefined4 param_2, int param_3)
 * Address ranges: 00407fcc-00407fe1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00407fcc(byte *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = param_3;
  uVar1 = FUN_00402b8c(param_1,&local_8);
  if (local_8 != 0) {
    uVar1 = param_2;
  }
  return uVar1;
}

