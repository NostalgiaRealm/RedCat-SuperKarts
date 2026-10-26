/*
 * FUN_004b8830 at 004b8830
 * undefined FUN_004b8830(void)
 * Address ranges: 004b8830-004b88c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b8830(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  DAT_00501328 = 0;
  iVar1 = param_1[1];
  for (piVar3 = param_1; (iVar1 != -1 && (*piVar3 != -1)); piVar3 = piVar3 + 3) {
    iVar1 = piVar3[4];
    DAT_00501328 = DAT_00501328 + 1;
  }
  iVar1 = FUN_004b88d0(DAT_00501328);
  if (iVar1 != 0) {
    return 2000;
  }
  iVar1 = 0;
  if (0 < DAT_00501328) {
    iVar2 = 0;
    piVar3 = param_1 + 2;
    do {
      iVar1 = iVar1 + 1;
      *(int *)(iVar2 + DAT_006ab894) = piVar3[-2];
      *(int *)(iVar2 + 4 + DAT_006ab894) = piVar3[-1];
      *(int *)(iVar2 + 8 + DAT_006ab894) = *piVar3;
      iVar2 = iVar2 + 0xc;
      piVar3 = piVar3 + 3;
    } while (iVar1 < DAT_00501328);
  }
  _DAT_006ab898 = 1;
  return 0;
}

