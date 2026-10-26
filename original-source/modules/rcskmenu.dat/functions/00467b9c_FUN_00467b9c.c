/*
 * FUN_00467b9c at 00467b9c
 * undefined FUN_00467b9c(void)
 * Address ranges: 00467b9c-00467bd2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467b9c(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (-1 < param_2) {
    iVar1 = FUN_004674c4((int)param_1);
    if (param_2 < iVar1) {
      piVar2 = (int *)FUN_004674ac((int)param_1,param_2);
      FUN_00467660(param_1,piVar2);
      return;
    }
  }
  FUN_00467660(param_1,(int *)0x0);
  return;
}

