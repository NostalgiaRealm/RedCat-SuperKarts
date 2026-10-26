/*
 * FUN_0042581c at 0042581c
 * undefined __register FUN_0042581c(int * param_1, char param_2)
 * Address ranges: 0042581c-0042586d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042581c(int *param_1,char param_2)

{
  bool bVar1;
  HWND pHVar2;
  uint uVar3;
  uint wParam;
  UINT Msg;
  int nIndex;
  LPARAM lParam;
  
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    wParam = (uint)(param_2 != '\0');
    nIndex = -0x10;
    pHVar2 = (HWND)FUN_00445724(param_1);
    uVar3 = GetWindowLongA(pHVar2,nIndex);
    if ((uVar3 & 0xf) != wParam) {
      lParam = 1;
      Msg = 0xf4;
      pHVar2 = (HWND)FUN_00445724(param_1);
      SendMessageA(pHVar2,Msg,wParam,lParam);
    }
  }
  return;
}

