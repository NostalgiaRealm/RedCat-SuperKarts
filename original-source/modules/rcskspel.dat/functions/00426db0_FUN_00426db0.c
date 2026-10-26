/*
 * FUN_00426db0 at 00426db0
 * undefined FUN_00426db0(void)
 * Address ranges: 00426db0-00426e4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426db0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = FUN_00426540(iVar3);
    if (*(int *)(&DAT_0050f8b4 + iVar1 * 0x1910) != 0) {
      iVar1 = FUN_00426540(iVar3);
      *(int *)(&DAT_0050f8bc + iVar1 * 0x1910) = *(int *)(&DAT_0050f8bc + iVar1 * 0x1910) + 1;
      iVar1 = FUN_00426540(iVar3);
      iVar2 = FUN_00426540(iVar3);
      if (*(int *)(&DAT_0050f8bc + iVar2 * 0x1910) < *(int *)(&DAT_0050f8b8 + iVar1 * 0x1910)) {
        FUN_00426c50(iVar3);
      }
      else {
        FUN_00426b90();
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  return;
}

