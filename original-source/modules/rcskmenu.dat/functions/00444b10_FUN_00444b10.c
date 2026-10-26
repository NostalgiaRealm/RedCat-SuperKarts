/*
 * FUN_00444b10 at 00444b10
 * undefined __register FUN_00444b10(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 00444b10-00444b2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444b10(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = FUN_00403088(param_1,0,param_3);
  *(uint *)(param_2 + 0xc) = uVar1 & 0x7f;
  return;
}

