/*
 * FUN_004248ac at 004248ac
 * undefined FUN_004248ac(void)
 * Address ranges: 004248ac-00424a0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004248ac(int *param_1)

{
  HWND pHVar1;
  int iVar2;
  LONG LVar3;
  UINT UVar4;
  WPARAM WVar5;
  LPARAM LVar6;
  
  FUN_00442914(param_1);
  LVar6 = 0;
  WVar5 = param_1[0x80];
  UVar4 = 0x141;
  pHVar1 = (HWND)FUN_00445724(param_1);
  SendMessageA(pHVar1,UVar4,WVar5,LVar6);
  if (param_1[0x89] != 0) {
    (**(code **)(*(int *)param_1[0x7c] + 8))((int *)param_1[0x7c],param_1[0x89]);
    FUN_00402eac((int *)param_1[0x89]);
    param_1[0x89] = 0;
    if (param_1[0x8a] != -1) {
      iVar2 = (**(code **)(*(int *)param_1[0x7c] + 0x14))();
      if (iVar2 < param_1[0x8a]) {
        iVar2 = (**(code **)(*(int *)param_1[0x7c] + 0x14))();
        param_1[0x8a] = iVar2;
      }
      LVar6 = 0;
      WVar5 = param_1[0x8a];
      UVar4 = 0x14e;
      pHVar1 = (HWND)FUN_00445724(param_1);
      SendMessageA(pHVar1,UVar4,WVar5,LVar6);
    }
  }
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  if (*(byte *)((int)param_1 + 0x1fa) < 2) {
    UVar4 = 5;
    pHVar1 = (HWND)(**(code **)(*param_1 + 0xbc))();
    pHVar1 = GetWindow(pHVar1,UVar4);
    if (pHVar1 != (HWND)0x0) {
      if (*(char *)((int)param_1 + 0x1fa) == '\x01') {
        param_1[0x83] = (int)pHVar1;
        LVar3 = GetWindowLongA(pHVar1,-4);
        param_1[0x87] = LVar3;
        SetWindowLongA((HWND)param_1[0x83],-4,param_1[0x85]);
        pHVar1 = GetWindow(pHVar1,2);
      }
      param_1[0x82] = (int)pHVar1;
      LVar3 = GetWindowLongA(pHVar1,-4);
      param_1[0x86] = LVar3;
      SetWindowLongA((HWND)param_1[0x82],-4,param_1[0x84]);
    }
  }
  if ((*PTR_DAT_0047c7a0 != '\0') && (param_1[0x82] != 0)) {
    SendMessageA((HWND)param_1[0x82],0xd3,3,0);
  }
  return;
}

