/*
 * FUN_0041bba6 at 0041bba6
 * undefined4 __stdcall FUN_0041bba6(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041bba6-0041bddf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041bba6(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  int iVar2;
  HWND pHVar3;
  undefined4 uVar4;
  
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
          pHVar3 = GetFocus();
          FUN_00411d9b((int)pHVar3);
        }
        else {
          pHVar3 = GetFocus();
          FUN_00411d4c((int)pHVar3);
        }
      }
      else if (param_3 == 0xd) {
        _DAT_0043e17c = param_1;
        _DAT_0043e178 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e168);
      }
    }
    else if (param_2 == 0x2b) {
      FUN_0041b885(param_4);
      return 1;
    }
  }
  else if (param_2 < 0x105) {
    if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
    else if ((param_2 == 0x101) && (param_3 == 0xd)) {
      _DAT_0043e17c = param_1;
      pHVar3 = GetFocus();
      if (pHVar3 == param_1) {
        _DAT_0043e178 = 0x10;
      }
      else {
        _DAT_0043e178 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e168);
    }
  }
  else if (param_2 == 0x201) {
    uVar4 = 4;
    iVar2 = FUN_00412a9d((int)param_1);
    FUN_00411de7(iVar2,uVar4);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e198,param_1,param_2,param_3,param_4);
  return 1;
}

