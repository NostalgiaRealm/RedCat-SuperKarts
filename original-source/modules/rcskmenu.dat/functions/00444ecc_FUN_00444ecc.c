/*
 * FUN_00444ecc at 00444ecc
 * undefined __register FUN_00444ecc(int param_1)
 * Address ranges: 00444ecc-00444edd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444ecc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    (**(code **)(iVar1 + 0x28))(*(undefined4 *)(iVar1 + 0x2c));
  }
  return;
}

