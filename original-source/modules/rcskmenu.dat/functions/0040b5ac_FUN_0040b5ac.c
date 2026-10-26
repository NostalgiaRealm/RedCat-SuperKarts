/*
 * FUN_0040b5ac at 0040b5ac
 * undefined __register FUN_0040b5ac(int param_1, int param_2)
 * Address ranges: 0040b5ac-0040b5d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b5ac(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00403dd0(param_1);
  if (iVar1 < param_2) {
    param_2 = FUN_00403dd0(param_1);
  }
  FUN_0040b5d4(param_1,param_2);
  return;
}

