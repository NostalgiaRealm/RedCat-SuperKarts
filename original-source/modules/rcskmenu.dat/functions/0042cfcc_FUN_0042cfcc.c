/*
 * FUN_0042cfcc at 0042cfcc
 * undefined FUN_0042cfcc(void)
 * Address ranges: 0042cfcc-0042d0fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042cfcc(int *param_1)

{
  LPARAM LVar1;
  HWND pHVar2;
  undefined1 *puVar3;
  LONG LVar4;
  HWND hWndInsertAfter;
  int iVar5;
  int iVar6;
  UINT UVar7;
  HMENU hMenu;
  int cx;
  WPARAM WVar8;
  HINSTANCE hInstance;
  int cy;
  undefined4 *lpParam;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  FUN_0042a59c(param_1);
  if (*PTR_DAT_0047c7a0 != '\0') {
    if (*(char *)((int)param_1 + 0x211) == '\x03') {
      LVar1 = 0;
      WVar8 = 1;
      UVar7 = 0x80;
      pHVar2 = (HWND)FUN_00445724(param_1);
      SendMessageA(pHVar2,UVar7,WVar8,LVar1);
    }
    else {
      LVar1 = FUN_0042d8e4((int)param_1);
      WVar8 = 1;
      UVar7 = 0x80;
      pHVar2 = (HWND)FUN_00445724(param_1);
      SendMessageA(pHVar2,UVar7,WVar8,LVar1);
    }
  }
  lpParam = &uStack_10;
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    if (*(char *)((int)param_1 + 0x217) == '\x02') {
      uStack_c = 0xff00;
      uStack_10 = 0;
      if (param_1[0x90] != 0) {
        uStack_10 = FUN_00436734(param_1[0x90]);
      }
      hMenu = (HMENU)0x0;
      hInstance = DAT_0047d4dc;
      pHVar2 = (HWND)FUN_00445724(param_1);
      iVar5 = FUN_0043f0f4(param_1);
      iVar6 = FUN_0043f0b0(param_1);
      pHVar2 = CreateWindowExA(0x200,"MDICLIENT",(LPCSTR)0x0,0x56330001,0,0,iVar6,iVar5,pHVar2,hMenu
                               ,hInstance,lpParam);
      param_1[0x8f] = (int)pHVar2;
      puVar3 = FUN_004295d8();
      param_1[0x98] = (int)puVar3;
      LVar4 = GetWindowLongA((HWND)param_1[0x8f],-4);
      param_1[0x97] = LVar4;
      SetWindowLongA((HWND)param_1[0x8f],-4,param_1[0x98]);
    }
    else if (*(char *)((int)param_1 + 0x217) == '\x03') {
      UVar7 = 0x13;
      cy = 0;
      cx = 0;
      iVar6 = 0;
      iVar5 = 0;
      hWndInsertAfter = (HWND)0xffffffff;
      pHVar2 = (HWND)FUN_00445724(param_1);
      SetWindowPos(pHVar2,hWndInsertAfter,iVar5,iVar6,cx,cy,UVar7);
    }
  }
  return;
}

