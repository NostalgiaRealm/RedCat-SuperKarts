/*
 * FUN_004bbf90 at 004bbf90
 * undefined FUN_004bbf90(void)
 * Address ranges: 004bbf90-004bbfe4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bbf90(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_006b5c20 != 0) {
    iVar4 = 0;
    if (0 < DAT_006b5c1c) {
      iVar3 = 0;
      iVar2 = DAT_006b5c18;
      do {
        if (((*(int *)(iVar3 + iVar2) == param_1) && (*(int *)(iVar3 + 4 + iVar2) != -1)) &&
           (pcVar1 = *(code **)(iVar3 + 8 + iVar2), pcVar1 != (code *)0x0)) {
          (*pcVar1)();
          iVar2 = DAT_006b5c18;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0xc;
      } while (iVar4 < DAT_006b5c1c);
    }
    return 0;
  }
  return 0;
}

