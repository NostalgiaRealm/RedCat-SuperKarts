/*
 * FUN_0043898c at 0043898c
 * bool __register FUN_0043898c(undefined * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0043898c-004389b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0043898c(undefined *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  PCNZCH pCVar1;
  
  pCVar1 = FUN_0040b75c(param_1,*(undefined **)(param_4 + -4));
  if (pCVar1 != (PCNZCH)0x0) {
    FUN_00404018((int *)(param_4 + -4),(int)pCVar1,1);
  }
  return pCVar1 != (PCNZCH)0x0;
}

