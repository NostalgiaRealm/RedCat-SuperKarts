/*
 * FUN_00431cec at 00431cec
 * undefined __register FUN_00431cec(int param_1)
 * Address ranges: 00431cec-00431d89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431cec(int param_1)

{
  BOOL BVar1;
  HWND hWndInsertAfter;
  int iVar2;
  int Y;
  int cx;
  int cy;
  UINT uFlags;
  
  BVar1 = IsIconic(*(HWND *)(param_1 + 0x24));
  if (BVar1 == 0) {
    FUN_004314b0(param_1);
    SetActiveWindow(*(HWND *)(param_1 + 0x24));
    if ((*(int *)(param_1 + 0x38) == 0) ||
       ((*(char *)(param_1 + 0x4b) == '\0' && (*(char *)(*(int *)(param_1 + 0x38) + 0x47) == '\0')))
       ) {
      FUN_00430ee0(*(HWND *)(param_1 + 0x24),6);
    }
    else {
      uFlags = 0x40;
      cy = 0;
      iVar2 = *(int *)(param_1 + 0x38);
      cx = *(int *)(iVar2 + 0x38);
      Y = *(int *)(iVar2 + 0x34);
      iVar2 = *(int *)(iVar2 + 0x30);
      hWndInsertAfter = (HWND)FUN_00445724(*(int **)(param_1 + 0x38));
      SetWindowPos(*(HWND *)(param_1 + 0x24),hWndInsertAfter,iVar2,Y,cx,cy,uFlags);
      DefWindowProcA(*(HWND *)(param_1 + 0x24),0x112,0xf020,0);
    }
    if (*(short *)(param_1 + 0xf2) != 0) {
      (**(code **)(param_1 + 0xf0))(*(undefined4 *)(param_1 + 0xf4),param_1);
    }
  }
  return;
}

