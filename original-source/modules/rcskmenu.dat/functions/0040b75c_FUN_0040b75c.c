/*
 * FUN_0040b75c at 0040b75c
 * PCNZCH __register FUN_0040b75c(undefined * param_1, undefined * param_2)
 * Address ranges: 0040b75c-0040b790
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

PCNZCH FUN_0040b75c(undefined *param_1,undefined *param_2)

{
  char *pcVar1;
  byte *pbVar2;
  PCNZCH pCVar3;
  PCNZCH pCVar4;
  
  pCVar4 = (PCNZCH)0x0;
  pcVar1 = FUN_00403f94(param_1);
  pbVar2 = FUN_00403f94(param_2);
  pCVar3 = FUN_0040b820(pbVar2,pcVar1);
  if (pCVar3 != (PCNZCH)0x0) {
    pCVar4 = pCVar3 + (1 - (int)pbVar2);
  }
  return pCVar4;
}

