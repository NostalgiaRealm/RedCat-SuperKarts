/*
 * FUN_0043ca64 at 0043ca64
 * undefined __register FUN_0043ca64(undefined4 * param_1, int * param_2)
 * Address ranges: 0043ca64-0043ca9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ca64(undefined4 *param_1,int *param_2)

{
  PCNZCH pCVar1;
  
  pCVar1 = FUN_0040b75c(&DAT_0043caa4,(undefined *)param_1);
  if (pCVar1 == (PCNZCH)0x0) {
    FUN_00403ba4(param_2,param_1);
  }
  else {
    FUN_00403fd8((int)param_1,1,(uint)(pCVar1 + -1),param_2);
  }
  return;
}

