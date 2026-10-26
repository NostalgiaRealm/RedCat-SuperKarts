/*
 * FUN_0041a0d0 at 0041a0d0
 * undefined4 __stdcall FUN_0041a0d0(HWND param_1, uint param_2, HDC param_3, HWND param_4)
 * Address ranges: 0041a0d0-0041a36b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041a0d0(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  SHORT SVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  HWND pHVar7;
  
  iVar2 = FUN_00412a9d((int)param_1);
  piVar3 = (int *)FUN_00412b01((int)param_1);
  iVar4 = FUN_00412d96();
  iVar5 = FUN_004152a3();
  FUN_004152ad(piVar3[3]);
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 == 7) {
      piVar3[0x13] = 1;
      FUN_00404a0d();
      FUN_004195c9(piVar3,(int *)(iVar4 + iVar2 * 0x1c));
      FUN_00404a81();
    }
    else if (param_2 == 8) {
      piVar3[0x13] = 0;
      FUN_00404a0d();
      FUN_004195c9(piVar3,(int *)(iVar4 + iVar2 * 0x1c));
      FUN_00404a81();
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      switch(param_3) {
      case (HDC)0x9:
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar7 = GetFocus();
          FUN_00411d9b((int)pHVar7);
        }
        else {
          pHVar7 = GetFocus();
          FUN_00411d4c((int)pHVar7);
        }
        return 1;
      default:
        break;
      case (HDC)0xd:
      case (HDC)0x23:
      case (HDC)0x24:
      case (HDC)0x25:
      case (HDC)0x26:
      case (HDC)0x27:
      case (HDC)0x28:
      case (HDC)0x2d:
      case (HDC)0x2e:
        FUN_00404a0d();
        FUN_00419874((int)param_1,(char)param_3);
        FUN_00404a81();
        return 1;
      }
    }
    else if (param_2 == 0x2b) {
      FUN_00404a0d();
      FUN_004195c9(piVar3,(int *)(iVar4 + iVar2 * 0x1c));
      FUN_00404a81();
      return 1;
    }
  }
  else if (param_2 < 0x134) {
    if (param_2 == 0x133) {
      uVar6 = FUN_0041a90c(param_3,param_4);
      return uVar6;
    }
    if (param_2 == 0x102) {
      FUN_00404a0d();
      iVar2 = FUN_00419874((int)param_1,(char)param_3);
      if (iVar2 == 0) {
        return 0;
      }
      FUN_00404a81();
    }
    else if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
  }
  else if (param_2 == 0x204) {
    return 0;
  }
  FUN_004152ad(iVar5);
  CallWindowProcA(DAT_0043df90,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return 1;
}

