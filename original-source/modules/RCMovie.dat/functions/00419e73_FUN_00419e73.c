/*
 * FUN_00419e73 at 00419e73
 * undefined __cdecl FUN_00419e73(int * param_1, HMENU param_2)
 * Address ranges: 00419e73-0041a0cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00419e73(int *param_1,HMENU param_2)

{
  uint *puVar1;
  HINSTANCE hInstance;
  HWND pHVar2;
  size_t sVar3;
  LPVOID lpParam;
  
  puVar1 = (uint *)param_1[3];
  if (((int)puVar1[1] < 1) || (10 < (int)puVar1[1])) {
    FUN_0040187a((byte *)s__s__d_____create_ownedit_box__nu_004360b0);
  }
  if (((int)*puVar1 < 1) || (100 < (int)*puVar1)) {
    FUN_0040187a((byte *)s__s__d_____create_ownedit_box__nu_00436120);
  }
  if (*(int *)(puVar1[3] + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____create_ownedit_box__tr_0043618c);
  }
  puVar1[0x11] = *(uint *)(puVar1[3] + 0x84);
  puVar1[0x12] = *(uint *)(puVar1[3] + 0x80);
  FUN_004126d4(param_2,*param_1,param_1[1],puVar1[0x12] * *puVar1,puVar1[0x11] * puVar1[1]);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
  pHVar2 = CreateWindowExA(0,s_BUTTON_004361e4,(LPCSTR)0x0,0x5001000b,*param_1,param_1[1],
                           puVar1[0x12] * *puVar1,puVar1[0x11] * puVar1[1],DAT_0043842c,param_2,
                           hInstance,lpParam);
  param_1[6] = (int)pHVar2;
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_ow_004361ec);
  }
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0xffffffff;
  puVar1[0x10] = 0xffffffff;
  puVar1[0x13] = 0;
  FUN_00419839((int)puVar1,0xfe,1,2,0xfe,200,0xc9);
  if (puVar1[2] == 0) goto LAB_0041a0a0;
  sVar3 = _strlen((char *)puVar1[2]);
  if (*puVar1 < sVar3) {
LAB_0041a06f:
    FUN_0040187a((byte *)s__s__d_____create_ownedit_box__de_00436228);
  }
  else {
    sVar3 = _strlen((char *)puVar1[2]);
    if (100 < sVar3) goto LAB_0041a06f;
  }
  _strncpy((char *)(puVar1 + 0x14),(char *)puVar1[2],100);
LAB_0041a0a0:
  DAT_0043df90 = SetWindowLongA((HWND)param_1[6],-4,0x41a0d0);
  FUN_00411de7((int)param_2,param_1[4]);
  return;
}

