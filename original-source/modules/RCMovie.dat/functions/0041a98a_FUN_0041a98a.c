/*
 * FUN_0041a98a at 0041a98a
 * undefined4 __stdcall FUN_0041a98a(HWND param_1, uint param_2, HDC param_3, HWND param_4)
 * Address ranges: 0041a98a-0041ab50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041a98a(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  SHORT SVar1;
  undefined4 uVar2;
  uint *puVar3;
  HWND pHVar4;
  undefined2 local_8;
  
  local_8 = DAT_004365cc;
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      return 1;
    }
    if (param_2 == 7) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      PostMessageA(param_1,0xf,0,0);
    }
    else if (param_2 == 8) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      PostMessageA(param_1,0xf,0,0);
    }
  }
  else if (param_2 < 0x134) {
    if (param_2 == 0x133) {
      uVar2 = FUN_0041a90c(param_3,param_4);
      return uVar2;
    }
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == (HDC)0x9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar4 = GetFocus();
          FUN_00411d9b((int)pHVar4);
        }
        else {
          pHVar4 = GetFocus();
          FUN_00411d4c((int)pHVar4);
        }
        return 1;
      }
    }
    else if (param_2 == 0x102) {
      local_8 = CONCAT11((char)((ushort)DAT_004365cc >> 8),param_3._0_1_);
      switch(param_3._0_1_) {
      case 3:
      case 8:
      case 0x16:
      case 0x18:
        break;
      default:
        puVar3 = FUN_0041fb70((uint *)&DAT_0043df98,(char *)&local_8);
        if (puVar3 == (uint *)0x0) {
          return 0;
        }
      }
    }
    else if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
  }
  else if (param_2 == 0x204) {
    return 0;
  }
  CallWindowProcA(DAT_0043e128,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return 1;
}

