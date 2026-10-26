/*
 * FUN_0043fa78 at 0043fa78
 * undefined __register FUN_0043fa78(int param_1, char param_2, char param_3)
 * Address ranges: 0043fa78-0043fb01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043fa78(int param_1,char param_2,char param_3)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  HWND hWnd;
  RECT *lpRect;
  int bErase;
  RECT local_18;
  int local_8;
  
  if (param_2 == '\0') {
    if ((*(byte *)(param_1 + 0x20) & 0x10) == 0) {
      return;
    }
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      return;
    }
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    return;
  }
  local_8 = param_1;
  bVar2 = FUN_00445a20(*(int *)(param_1 + 0x24));
  if (bVar2) {
    FUN_0043f054(local_8,&local_18.left);
    if (((param_3 == '\0') && ((*(byte *)(*(int *)(local_8 + 0x24) + 0x40) & 0x40) == 0)) &&
       (cVar3 = FUN_0043f9ec(), cVar3 == '\0')) {
      bVar1 = 1;
    }
    else {
      bVar1 = 0;
    }
    bErase = -(uint)bVar1;
    lpRect = &local_18;
    hWnd = (HWND)FUN_00445724(*(int **)(local_8 + 0x24));
    InvalidateRect(hWnd,lpRect,bErase);
    return;
  }
  return;
}

