/*
 * FUN_004328ac at 004328ac
 * undefined __register FUN_004328ac(void)
 * Address ranges: 004328ac-0043290f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004328ac(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  HWND pHVar4;
  BOOL BVar5;
  int iVar6;
  
  iVar2 = FUN_004301f4(DAT_0047d774);
  if (-1 < iVar2 + -1) {
    iVar6 = 0;
    do {
      piVar3 = (int *)FUN_004301e0(DAT_0047d774,iVar6);
      bVar1 = FUN_00445a20((int)piVar3);
      if (bVar1) {
        pHVar4 = (HWND)FUN_00445724(piVar3);
        BVar5 = IsWindowVisible(pHVar4);
        if (BVar5 != 0) {
          pHVar4 = (HWND)FUN_00445724(piVar3);
          BVar5 = IsWindowEnabled(pHVar4);
          if (BVar5 != 0) {
            (**(code **)(*piVar3 + 200))();
          }
        }
      }
      iVar6 = iVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

