/*
 * FUN_0041b204 at 0041b204
 * undefined4 __stdcall FUN_0041b204(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041b204-0041b395
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041b204(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
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
        DAT_0043e144 = param_1;
        _DAT_0043e140 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e130);
      }
    }
    else if (param_2 == 0x2b) {
      FUN_0041af21(param_4);
      return 1;
    }
  }
  else if (param_2 == 0x101) {
    if (param_3 == 0xd) {
      DAT_0043e144 = param_1;
      pHVar2 = GetFocus();
      if (pHVar2 == param_1) {
        _DAT_0043e140 = 0x10;
      }
      else {
        _DAT_0043e140 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e130);
    }
  }
  else if (param_2 == 0x104) {
    FUN_00412f44(param_3);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e160,param_1,param_2,param_3,param_4);
  return 1;
}

