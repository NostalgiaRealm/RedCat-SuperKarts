/*
 * FUN_00417954 at 00417954
 * int __register FUN_00417954(int param_1)
 * Address ranges: 00417954-0041796d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00417954(int param_1)

{
  int nNumber;
  int iVar1;
  int nNumerator;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  nNumerator = 0x48;
  nNumber = FUN_004178b0(param_1);
  iVar1 = MulDiv(nNumber,nNumerator,iVar1);
  return -iVar1;
}

