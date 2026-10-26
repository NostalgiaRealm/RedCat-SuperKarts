/*
 * FUN_0041d1f5 at 0041d1f5
 * undefined4 __stdcall FUN_0041d1f5(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041d1f5-0041d3fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041d1f5(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 == 7) {
      if (DAT_0043d568 != (code *)0x0) {
        (*DAT_0043d568)(param_1,7,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 8) && (DAT_0043d564 != (code *)0x0)) {
      (*DAT_0043d564)(param_1,8,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == 9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar2 = GetFocus();
          FUN_00411d9b((int)pHVar2);
        }
        else {
          pHVar2 = GetFocus();
          FUN_00411d4c((int)pHVar2);
        }
      }
      else if (param_3 == 0xd) {
        _DAT_0043e1f4 = param_1;
        _DAT_0043e1f0 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e1e0);
      }
      return 1;
    }
    if (param_2 == 0x2b) {
      FUN_0041cf50(param_4);
      return 1;
    }
  }
  else if (param_2 == 0x101) {
    if (param_3 == 0xd) {
      _DAT_0043e1f4 = param_1;
      pHVar2 = GetFocus();
      if (pHVar2 == param_1) {
        _DAT_0043e1f0 = 0x10;
      }
      else {
        _DAT_0043e1f0 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e1e0);
    }
  }
  else if (param_2 == 0x104) {
    FUN_00412f44(param_3);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e1d8,param_1,param_2,param_3,param_4);
  return 1;
}

