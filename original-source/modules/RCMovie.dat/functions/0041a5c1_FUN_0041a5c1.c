/*
 * FUN_0041a5c1 at 0041a5c1
 * undefined __cdecl FUN_0041a5c1(int * param_1, HMENU param_2)
 * Address ranges: 0041a5c1-0041a90b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041a5c1(int *param_1,HMENU param_2)

{
  int *piVar1;
  LONG LVar2;
  HINSTANCE pHVar3;
  HWND pHVar4;
  WPARAM wParam;
  HBRUSH pHVar5;
  LPVOID pvVar6;
  
  piVar1 = (int *)param_1[3];
  if (DAT_0043e12c == '\0') {
    FUN_0040187a((byte *)s__s__d_____edit_windows_box__edit_00436410);
  }
  if (piVar1[3] < 1) {
    FUN_0040187a((byte *)s__s__d_____edit_windows_box__numb_0043646c);
  }
  if (piVar1[2] < 1) {
    FUN_0040187a((byte *)s__s__d_____edit_windows_box__numb_004364cc);
  }
  LVar2 = FUN_00417328(&DAT_00436518,1);
  if (piVar1[1] < LVar2 * piVar1[3]) {
    FUN_00417328(&DAT_0043651c,1);
    FUN_0040187a((byte *)s__s__d_____edit_windows_box__heig_0043652c);
  }
  FUN_004126d4(param_2,*param_1,param_1[1],*piVar1,piVar1[1]);
  if (piVar1[3] == 1) {
    if (param_1[2] == 0) {
      pvVar6 = (LPVOID)0x0;
      pHVar3 = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
      pHVar4 = CreateWindowExA(0,&DAT_00436580,(LPCSTR)0x0,0x50010000,*param_1,param_1[1],*piVar1,
                               piVar1[1],DAT_0043842c,param_2,pHVar3,pvVar6);
      param_1[6] = (int)pHVar4;
    }
    else if (param_1[2] == 3) {
      pvVar6 = (LPVOID)0x0;
      pHVar3 = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
      pHVar4 = CreateWindowExA(0,&DAT_00436588,(LPCSTR)0x0,0x50012000,*param_1,param_1[1],*piVar1,
                               piVar1[1],DAT_0043842c,param_2,pHVar3,pvVar6);
      param_1[6] = (int)pHVar4;
    }
  }
  else if (param_1[2] == 0) {
    pvVar6 = (LPVOID)0x0;
    pHVar3 = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
    pHVar4 = CreateWindowExA(0,&DAT_00436590,(LPCSTR)0x0,0x50010004,*param_1,param_1[1],*piVar1,
                             piVar1[1],DAT_0043842c,param_2,pHVar3,pvVar6);
    param_1[6] = (int)pHVar4;
  }
  else if (param_1[2] == 3) {
    pvVar6 = (LPVOID)0x0;
    pHVar3 = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
    pHVar4 = CreateWindowExA(0,&DAT_00436598,(LPCSTR)0x0,0x50012004,*param_1,param_1[1],*piVar1,
                             piVar1[1],DAT_0043842c,param_2,pHVar3,pvVar6);
    param_1[6] = (int)pHVar4;
  }
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_ed_004365a0);
  }
  DAT_0043e128 = SetWindowLongA((HWND)param_1[6],-4,0x41a98a);
  wParam = FUN_004182e3();
  if (wParam != 0) {
    SendMessageA((HWND)param_1[6],0x30,wParam,1);
  }
  if (piVar1[4] != 0) {
    SendMessageA((HWND)param_1[6],0xc,0,piVar1[4]);
  }
  piVar1[5] = 0;
  piVar1[6] = 0xffffff;
  pHVar5 = CreateSolidBrush(piVar1[5]);
  piVar1[7] = (int)pHVar5;
  piVar1[8] = 0xff;
  piVar1[9] = 0xffffff;
  pHVar5 = CreateSolidBrush(piVar1[8]);
  piVar1[10] = (int)pHVar5;
  FUN_00411de7((int)param_2,param_1[4]);
  return;
}

