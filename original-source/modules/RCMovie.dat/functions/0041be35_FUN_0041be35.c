/*
 * FUN_0041be35 at 0041be35
 * undefined __cdecl FUN_0041be35(int * param_1, HMENU param_2)
 * Address ranges: 0041be35-0041c00b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041be35(int *param_1,HMENU param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  HINSTANCE hInstance;
  HWND pHVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  LPVOID lpParam;
  
  piVar1 = (int *)param_1[3];
  iVar3 = *piVar1;
  iVar5 = piVar1[1];
  if (((piVar1[2] != -1) && (piVar1[3] != 0)) && ((*piVar1 == -1 || (piVar1[1] == -1)))) {
    FUN_0040187a((byte *)s__s__d_____create_areabutton__no_w_00436834);
  }
  if (piVar1[2] != -1) {
    iVar2 = FUN_00412687(piVar1[2],0);
    if (*piVar1 == -1) {
      *piVar1 = *(int *)(DAT_0043d6e8 + 8 + iVar2 * 0x20);
    }
    if (piVar1[1] == -1) {
      piVar1[1] = *(int *)(DAT_0043d6e8 + 0xc + iVar2 * 0x20);
    }
    FUN_004126d4(param_2,*param_1,param_1[1],*piVar1,piVar1[1]);
    uVar7 = 1;
    iVar6 = param_1[1] + iVar5 / 2;
    iVar5 = *param_1 + iVar3 / 2;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar2,iVar5,iVar6,uVar7);
  }
  FUN_004126d4(param_2,*param_1,param_1[1],*piVar1,piVar1[1]);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
  pHVar4 = CreateWindowExA(0,s_STATIC_00436884,(LPCSTR)0x0,0x50000000,*param_1,param_1[1],*piVar1,
                           piVar1[1],DAT_0043842c,param_2,hInstance,lpParam);
  param_1[6] = (int)pHVar4;
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_ar_0043688c);
  }
  DAT_0043e19c = SetWindowLongA((HWND)param_1[6],-4,0x41c0c8);
  FUN_00411de7((int)param_2,param_1[4]);
  return;
}

