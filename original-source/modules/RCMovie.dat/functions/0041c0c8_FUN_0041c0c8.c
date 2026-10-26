/*
 * FUN_0041c0c8 at 0041c0c8
 * undefined4 __stdcall FUN_0041c0c8(HWND param_1, uint param_2, WPARAM param_3, LPARAM param_4)
 * Address ranges: 0041c0c8-0041c216
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041c0c8(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  int iVar3;
  undefined4 uVar4;
  tagPAINTSTRUCT local_44;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      BeginPaint(param_1,&local_44);
      EndPaint(param_1,&local_44);
      return 1;
    }
    if (param_2 == 7) {
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
  }
  else if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      return 1;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x105) {
    if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
    else if (param_2 == 0x100) {
      FUN_00412f44(param_3);
    }
  }
  else if (param_2 == 0x201) {
    uVar4 = 4;
    iVar3 = FUN_00412a9d((int)param_1);
    FUN_00411de7(iVar3,uVar4);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e19c,param_1,param_2,param_3,param_4);
  return 1;
}

