/*
 * FUN_0043caa8 at 0043caa8
 * undefined __register FUN_0043caa8(undefined4 * param_1, int * param_2)
 * Address ranges: 0043caa8-0043cadf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043caa8(undefined4 *param_1,int *param_2)

{
  PCNZCH pCVar1;
  
  pCVar1 = FUN_0040b75c(&DAT_0043cae8,(undefined *)param_1);
  if (pCVar1 == (PCNZCH)0x0) {
    FUN_00403ba4(param_2,param_1);
  }
  else {
    FUN_00403fd8((int)param_1,(int)(pCVar1 + 1),0x7fffffff,param_2);
  }
  return;
}

