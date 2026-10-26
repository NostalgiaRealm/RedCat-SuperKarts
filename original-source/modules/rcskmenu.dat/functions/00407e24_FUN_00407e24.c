/*
 * FUN_00407e24 at 00407e24
 * int __register FUN_00407e24(PCNZCH param_1, PCNZCH param_2, int param_3)
 * Address ranges: 00407e24-00407e43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00407e24(PCNZCH param_1,PCNZCH param_2,int param_3)

{
  int iVar1;
  
  iVar1 = CompareStringA(0x400,1,param_1,param_3,param_2,param_3);
  return iVar1 + -2;
}

