/*
 * FUN_0042b854 at 0042b854
 * undefined __register FUN_0042b854(int * param_1)
 * Address ranges: 0042b854-0042b8ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b854(int *param_1)

{
  bool bVar1;
  LPARAM lParam;
  HWND pHVar2;
  BOOL BVar3;
  UINT Msg;
  WPARAM wParam;
  
  if (*PTR_DAT_0047c7a0 == '\0') {
    pHVar2 = (HWND)FUN_00445724(param_1);
    BVar3 = IsIconic(pHVar2);
    if (BVar3 != 0) {
      (**(code **)(*param_1 + 0x74))();
    }
  }
  else {
    bVar1 = FUN_00445a20((int)param_1);
    if ((bVar1) && (*(char *)((int)param_1 + 0x211) != '\x03')) {
      lParam = FUN_0042d8e4((int)param_1);
      wParam = 1;
      Msg = 0x80;
      pHVar2 = (HWND)FUN_00445724(param_1);
      SendMessageA(pHVar2,Msg,wParam,lParam);
      return;
    }
  }
  return;
}

