/*
 * FUN_0044329c at 0044329c
 * undefined __register FUN_0044329c(int param_1, UINT * param_2)
 * Address ranges: 0044329c-00443394
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044329c(int param_1,UINT *param_2)

{
  UINT UVar1;
  COLORREF CVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x14c) == 0) {
    FUN_004407d4(param_1,(int *)param_2);
  }
  else {
    if ((*param_2 == 0x7b) && (*(int *)(param_1 + 0x24) != 0)) {
      UVar1 = FUN_004405f0(*(int *)(param_1 + 0x24),0x7b,param_2[1],param_2[2]);
      param_2[3] = UVar1;
      if (UVar1 != 0) {
        return;
      }
    }
    UVar1 = *param_2;
    if (UVar1 - 0x132 < 7) {
      UVar1 = SendMessageA((HWND)param_2[2],UVar1 + 0xbc00,param_2[1],(LPARAM)param_2[2]);
      param_2[3] = UVar1;
    }
    else if (UVar1 - 0xbd32 < 7) {
      CVar2 = FUN_00417210(*(uint *)(*(int *)(param_1 + 0x58) + 0x18));
      SetTextColor((HDC)param_2[1],CVar2);
      uVar3 = FUN_00417e98(*(int *)(param_1 + 0x130));
      CVar2 = FUN_00417210(uVar3);
      SetBkColor((HDC)param_2[1],CVar2);
      UVar1 = FUN_00417ed4(*(int *)(param_1 + 0x130));
      param_2[3] = UVar1;
    }
    else {
      UVar1 = CallWindowProcA(*(WNDPROC *)(param_1 + 0x13c),*(HWND *)(param_1 + 0x14c),UVar1,
                              param_2[1],param_2[2]);
      param_2[3] = UVar1;
    }
    if (*param_2 == 0xc) {
      FUN_0043f24c(param_1,0xc,param_2[1],param_2[2]);
    }
  }
  return;
}

