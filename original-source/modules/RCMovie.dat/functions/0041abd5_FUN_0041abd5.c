/*
 * FUN_0041abd5 at 0041abd5
 * undefined __cdecl FUN_0041abd5(int * param_1, HMENU param_2)
 * Address ranges: 0041abd5-0041ad40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041abd5(int *param_1,HMENU param_2)

{
  int *piVar1;
  int iVar2;
  HINSTANCE hInstance;
  HWND pHVar3;
  LPVOID lpParam;
  
  piVar1 = (int *)param_1[3];
  iVar2 = FUN_00412687(*piVar1,0);
  if (piVar1[1] == -1) {
    piVar1[1] = *(int *)(DAT_0043d6e8 + 8 + iVar2 * 0x20);
  }
  if (piVar1[2] == -1) {
    piVar1[2] = *(int *)(DAT_0043d6e8 + 0xc + iVar2 * 0x20);
  }
  if (*(int *)(DAT_0043d858 + *piVar1 * 0xc) < 5) {
    FUN_0040187a((byte *)s__s__d_____create_radiobutton__no_00436628);
  }
  FUN_004126d4(param_2,*param_1,param_1[1],piVar1[1],piVar1[2]);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
  pHVar3 = CreateWindowExA(0,s_BUTTON_0043667c,(LPCSTR)piVar1[4],0x5001000b,*param_1,param_1[1],
                           piVar1[1],piVar1[2],DAT_0043842c,param_2,hInstance,lpParam);
  param_1[6] = (int)pHVar3;
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_ra_00436684);
  }
  DAT_0043e160 = SetWindowLongA((HWND)param_1[6],-4,0x41b204);
  FUN_00411de7((int)param_2,param_1[4]);
  piVar1[8] = param_1[4];
  return;
}

