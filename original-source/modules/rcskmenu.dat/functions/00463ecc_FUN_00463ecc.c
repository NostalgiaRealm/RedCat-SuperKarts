/*
 * FUN_00463ecc at 00463ecc
 * undefined __register FUN_00463ecc(int * param_1, LPRECT param_2)
 * Address ranges: 00463ecc-00463f20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463ecc(int *param_1,LPRECT param_2)

{
  HWND hWnd;
  int iVar1;
  LPRECT lpRect;
  
  lpRect = param_2;
  hWnd = (HWND)FUN_00445724(param_1);
  GetWindowRect(hWnd,lpRect);
  OffsetRect(param_2,-param_2->left,-param_2->top);
  iVar1 = GetSystemMetrics(0x47);
  if (*(char *)((int)param_1 + 0x212) == '\0') {
    OffsetRect(param_2,5,-1);
  }
  else if (*(char *)((int)param_1 + 0x212) == '\x01') {
    OffsetRect(param_2,iVar1 + 5,-1);
    return;
  }
  return;
}

