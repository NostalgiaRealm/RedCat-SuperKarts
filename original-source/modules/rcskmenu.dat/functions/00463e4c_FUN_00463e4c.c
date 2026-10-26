/*
 * FUN_00463e4c at 00463e4c
 * undefined __register FUN_00463e4c(int * param_1, int * param_2)
 * Address ranges: 00463e4c-00463ecb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463e4c(int *param_1,int *param_2)

{
  HWND hWnd;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  tagRECT *lpRect;
  tagRECT tStack_30;
  undefined1 local_20 [8];
  int iStack_18;
  
  lpRect = &tStack_30;
  hWnd = (HWND)FUN_00445724(param_1);
  GetWindowRect(hWnd,lpRect);
  iVar1 = GetSystemMetrics(0x47);
  uVar2 = GetSystemMetrics(0x48);
  if (*(char *)((int)param_1 + 0x212) == '\0') {
    (**(code **)(*param_1 + 0x40))(param_1,local_20);
    *param_2 = iStack_18 - iVar1;
  }
  else if (*(char *)((int)param_1 + 0x212) == '\x01') {
    *param_2 = 0;
  }
  iVar3 = tStack_30.bottom - tStack_30.top >> 1;
  if (iVar3 < 0) {
    iVar3 = iVar3 + (uint)((tStack_30.bottom - tStack_30.top & 1U) != 0);
  }
  iVar4 = (int)uVar2 >> 1;
  if (iVar4 < 0) {
    iVar4 = iVar4 + (uint)((uVar2 & 1) != 0);
  }
  param_2[1] = iVar3 - iVar4;
  param_2[2] = iVar1 + *param_2;
  param_2[3] = uVar2 + param_2[1];
  return;
}

