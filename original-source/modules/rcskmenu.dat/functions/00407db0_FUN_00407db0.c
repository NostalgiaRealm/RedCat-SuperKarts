/*
 * FUN_00407db0 at 00407db0
 * int __register FUN_00407db0(undefined * param_1, undefined * param_2)
 * Address ranges: 00407db0-00407de7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00407db0(undefined *param_1,undefined *param_2)

{
  int iVar1;
  PCNZCH lpString2;
  int cchCount1;
  PCNZCH lpString1;
  
  iVar1 = FUN_00403dd0((int)param_2);
  lpString2 = FUN_00403f94(param_2);
  cchCount1 = FUN_00403dd0((int)param_1);
  lpString1 = FUN_00403f94(param_1);
  iVar1 = CompareStringA(0x400,1,lpString1,cchCount1,lpString2,iVar1);
  return iVar1 + -2;
}

