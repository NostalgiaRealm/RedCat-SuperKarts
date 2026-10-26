/*
 * FUN_004bbf30 at 004bbf30
 * undefined FUN_004bbf30(void)
 * Address ranges: 004bbf30-004bbf87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bbf30(void)

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
        if (((*(int *)(iVar2 + iVar1) != -1) && (*(int *)(iVar2 + 4 + iVar1) != -1)) &&
           (*(int *)(iVar2 + 8 + iVar1) != 0)) {
          FUN_004bbeb0(*(int *)(iVar2 + iVar1));
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

