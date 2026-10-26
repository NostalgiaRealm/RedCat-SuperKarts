/*
 * FUN_004bb710 at 004bb710
 * undefined FUN_004bb710(void)
 * Address ranges: 004bb710-004bb73d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bb710(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_2;
  while (iVar2 != -1) {
    FUN_004bb6c0(param_1 + iVar2 * 0xc);
    piVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    iVar2 = *piVar1;
  }
  return;
}

