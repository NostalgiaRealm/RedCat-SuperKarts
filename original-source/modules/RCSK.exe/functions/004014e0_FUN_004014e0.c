/*
 * FUN_004014e0 at 004014e0
 * undefined4 __stdcall FUN_004014e0(HINSTANCE param_1, int param_2, undefined4 param_3, int param_4)
 * Address ranges: 004014e0-00401647
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004014e0(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

{
  ATOM AVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 extraout_ECX;
  HWND pHVar5;
  HMENU hMenu;
  LPVOID lpParam;
  tagMSG local_4c;
  WNDCLASSEXA local_30;
  
  if (param_2 == 0) {
    local_30.cbSize = 0x30;
    local_30.lpszClassName = s_REDCAT_MOTOR_00408140;
    local_30.hInstance = param_1;
    local_30.lpfnWndProc = FUN_00401650;
    local_30.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hIcon = LoadIconA(param_1,(LPCSTR)0x7f00);
    local_30.hIconSm = LoadIconA(param_1,(LPCSTR)0x7f00);
    local_30.lpszMenuName = (LPCSTR)0x0;
    local_30.hbrBackground = GetStockObject(4);
    local_30.style = 0;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0;
    AVar1 = RegisterClassExA(&local_30);
    if (AVar1 == 0) {
      MessageBoxA((HWND)0x0,s_WinMain____RegisterClass___faile_004081fc,
                  s_Err___7_MOTOR_FAILED_00408220,0x30);
    }
    else {
      lpParam = (LPVOID)0x0;
      hMenu = (HMENU)0x0;
      pHVar5 = (HWND)0x0;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      pHVar5 = CreateWindowExA(0x40000,s_REDCAT_MOTOR_00408140,&DAT_00408c00,0x80000000,0,0,iVar3,
                               iVar2,pHVar5,hMenu,param_1,lpParam);
      if (pHVar5 != (HWND)0x0) {
        ShowWindow(pHVar5,param_4);
        iVar2 = 1;
        FUN_00401120((uint3)extraout_ECX);
        while( true ) {
          do {
            while( true ) {
              BVar4 = PeekMessageA(&local_4c,(HWND)0x0,0,0,1);
              if (BVar4 != 0) break;
              iVar2 = FUN_004012c0(iVar2);
              if (iVar2 == 0) {
                SendMessageA(pHVar5,0x10,0,0);
              }
              iVar2 = 0;
            }
            iVar3 = TranslateAcceleratorA(pHVar5,(HACCEL)0x0,&local_4c);
          } while (iVar3 != 0);
          if (local_4c.message == 0x12) break;
          TranslateMessage(&local_4c);
          DispatchMessageA(&local_4c);
        }
        return local_4c.wParam;
      }
    }
  }
  return 0;
}

