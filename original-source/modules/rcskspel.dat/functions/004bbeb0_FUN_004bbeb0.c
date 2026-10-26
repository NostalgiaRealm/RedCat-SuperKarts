/*
 * FUN_004bbeb0 at 004bbeb0
 * undefined FUN_004bbeb0(void)
 * Address ranges: 004bbeb0-004bbf2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bbeb0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_006b5c20 != 0) {
    iVar3 = 0;
    if (0 < DAT_006b5c1c) {
      iVar2 = 0;
      iVar1 = DAT_006b5c18;
      do {
        if (*(int *)(iVar2 + iVar1) == param_1) {
          *(undefined4 *)(iVar2 + iVar1) = 0xffffffff;
          *(undefined4 *)(iVar2 + 4 + DAT_006b5c18) = 0xffffffff;
          *(undefined4 *)(iVar2 + 8 + DAT_006b5c18) = 0;
          KillTimer(DAT_006a64b4,*(UINT_PTR *)(iVar2 + DAT_006b5c18));
          iVar1 = DAT_006b5c18;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0xc;
      } while (iVar3 < DAT_006b5c1c);
    }
    return 0;
  }
  return 0;
}

