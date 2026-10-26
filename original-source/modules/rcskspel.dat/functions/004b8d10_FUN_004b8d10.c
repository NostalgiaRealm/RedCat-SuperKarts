/*
 * FUN_004b8d10 at 004b8d10
 * undefined FUN_004b8d10(void)
 * Address ranges: 004b8d10-004b8d44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b8d10(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_004fe94c;
  while (((piVar2[-1] != param_1 || (*piVar2 != param_2)) || (piVar2[1] != param_3))) {
    piVar2 = piVar2 + 5;
    iVar1 = iVar1 + 1;
    if (0x4feadb < (int)piVar2) {
      return -1;
    }
  }
  return iVar1;
}

