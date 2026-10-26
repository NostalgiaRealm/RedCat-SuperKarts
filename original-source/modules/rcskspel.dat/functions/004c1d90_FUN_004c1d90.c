/*
 * FUN_004c1d90 at 004c1d90
 * undefined FUN_004c1d90(void)
 * Address ranges: 004c1d90-004c1db8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

SIZE_T FUN_004c1d90(LPCVOID param_1)

{
  int iVar1;
  SIZE_T SVar2;
  
  iVar1 = FUN_004c6350(param_1);
  if (iVar1 != 0) {
    return *(int *)((int)param_1 + -4) - 9;
  }
  SVar2 = HeapSize(DAT_006b6da0,0,param_1);
  return SVar2;
}

