/*
 * FUN_0045e4a4 at 0045e4a4
 * undefined __register FUN_0045e4a4(int * param_1)
 * Address ranges: 0045e4a4-0045e4ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e4a4(int *param_1)

{
  bool bVar1;
  HWND hWnd;
  HRGN hRgn;
  BOOL bRedraw;
  
  bVar1 = FUN_00445a20((int)param_1);
  if ((bVar1) && ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
    bRedraw = -1;
    hRgn = (HRGN)0x0;
    hWnd = (HWND)FUN_00445724(param_1);
    SetWindowRgn(hWnd,hRgn,bRedraw);
  }
  param_1[0x85] = 0;
  (**(code **)(*param_1 + 0x7c))(param_1,param_1[0xc],param_1[0xd],0x18,0x68);
  (**(code **)(*param_1 + 0x74))();
  return;
}

