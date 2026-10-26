/*
 * FUN_004bb6c0 at 004bb6c0
 * undefined FUN_004bb6c0(void)
 * Address ranges: 004bb6c0-004bb70a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bb6c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = DAT_006b5798;
  if (0 < *param_1) {
    do {
      iVar1 = *(int *)(param_1[2] + 4 + iVar5 * 8);
      iVar2 = 0;
      if (0 < iVar3) {
        piVar4 = &DAT_006abb58;
        do {
          if (*piVar4 == iVar1) goto LAB_004bb700;
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar2 < iVar3);
      }
      (&DAT_006abb58)[iVar3] = iVar1;
      iVar3 = iVar3 + 1;
      DAT_006b5798 = iVar3;
LAB_004bb700:
      iVar5 = iVar5 + 1;
    } while (iVar5 < *param_1);
  }
  return;
}

