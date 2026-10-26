/*
 * FUN_00425b7c at 00425b7c
 * undefined __register FUN_00425b7c(int * param_1, char param_2)
 * Address ranges: 00425b7c-00425bca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00425b7c(int *param_1,char param_2)

{
  bool bVar1;
  uint wParam;
  HWND hWnd;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  UINT Msg;
  LPARAM lParam;
  
  if (param_2 != *(char *)((int)param_1 + 0x1fa)) {
    *(char *)((int)param_1 + 0x1fa) = param_2;
    bVar1 = FUN_00445a20((int)param_1);
    uVar2 = extraout_ECX;
    uVar3 = extraout_EDX;
    if (bVar1) {
      lParam = 0;
      wParam = (uint)*(byte *)((int)param_1 + 0x1fa);
      Msg = 0xf1;
      hWnd = (HWND)FUN_00445724(param_1);
      SendMessageA(hWnd,Msg,wParam,lParam);
      uVar2 = extraout_ECX_00;
      uVar3 = extraout_EDX_00;
    }
    if ((char)param_1[0x7c] == '\0') {
      FUN_00403088(param_1,uVar3,uVar2);
    }
  }
  return;
}

