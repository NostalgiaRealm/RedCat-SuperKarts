/*
 * FUN_00442bf4 at 00442bf4
 * undefined __register FUN_00442bf4(int * param_1)
 * Address ranges: 00442bf4-00442c89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442bf4(int *param_1)

{
  HWND hWndInsertAfter;
  int iVar1;
  int iVar2;
  int iVar3;
  int cy;
  UINT uFlags;
  
  if (param_1[0x53] == 0) {
    (**(code **)(*param_1 + 0x98))();
    SetPropA((HWND)param_1[0x53],(LPCSTR)(uint)DAT_0047d7b6,param_1);
    SetPropA((HWND)param_1[0x53],(LPCSTR)(uint)DAT_0047d7b4,param_1);
    if (param_1[9] != 0) {
      uFlags = 0x13;
      cy = 0;
      iVar3 = 0;
      iVar2 = 0;
      iVar1 = 0;
      hWndInsertAfter = (HWND)FUN_00442bac(param_1[9],(int)param_1);
      SetWindowPos((HWND)param_1[0x53],hWndInsertAfter,iVar1,iVar2,iVar3,cy,uFlags);
    }
    iVar1 = FUN_0044268c((int)param_1);
    if (-1 < iVar1 + -1) {
      iVar2 = 0;
      do {
        iVar3 = FUN_00442650((int)param_1,iVar2);
        FUN_0043ed90(iVar3);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

