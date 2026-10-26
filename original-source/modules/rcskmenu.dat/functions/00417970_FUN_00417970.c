/*
 * FUN_00417970 at 00417970
 * undefined __register FUN_00417970(int * param_1, int param_2)
 * Address ranges: 00417970-0041798f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417970(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = MulDiv(param_2,param_1[7],0x48);
  FUN_004178b8(param_1,-iVar1);
  return;
}

