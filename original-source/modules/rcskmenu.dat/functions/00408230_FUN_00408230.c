/*
 * FUN_00408230 at 00408230
 * undefined FUN_00408230(void)
 * Address ranges: 00408230-0040826b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408230(undefined *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00408174(&UNK_00408274,param_1);
  if ((iVar1 < 1) || (param_1[iVar1 + -1] != '.')) {
    FUN_00403b50(param_2);
  }
  else {
    FUN_00403fd8((int)param_1,iVar1,0x7fffffff,param_2);
  }
  return;
}

