/*
 * FUN_0042ca2c at 0042ca2c
 * undefined __register FUN_0042ca2c(int * param_1, byte param_2)
 * Address ranges: 0042ca2c-0042ca6a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ca2c(int *param_1,byte param_2)

{
  HWND hWnd;
  int nCmdShow;
  
  if (((param_2 != *(byte *)((int)param_1 + 0x213)) &&
      (*(byte *)((int)param_1 + 0x213) = param_2, (*(byte *)(param_1 + 8) & 0x10) == 0)) &&
     ((char)param_1[0x5a] != '\0')) {
    nCmdShow = *(int *)(&DAT_0047b744 + (uint)param_2 * 4);
    hWnd = (HWND)FUN_00445724(param_1);
    ShowWindow(hWnd,nCmdShow);
  }
  return;
}

