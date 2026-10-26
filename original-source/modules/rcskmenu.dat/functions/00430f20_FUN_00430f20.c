/*
 * FUN_00430f20 at 00430f20
 * undefined FUN_00430f20(void)
 * Address ranges: 00430f20-004310a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00430f20(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  HICON pHVar3;
  char *pcVar4;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  char extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_fffffee0;
  undefined4 in_stack_fffffee4;
  byte bStack_105;
  CHAR aCStack_104 [255];
  char cStack_5;
  
  cStack_5 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_fffffee0,in_stack_fffffee4);
    param_3 = extraout_ECX;
    cStack_5 = extraout_DL;
  }
  FUN_00414778(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 10) = 0;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  param_1[0x20] = iVar1;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_01);
  param_1[0x26] = iVar1;
  param_1[0x14] = 0;
  param_1[0x1d] = 0;
  param_1[0x13] = -0x7fffffe8;
  param_1[0x1a] = 500;
  *(undefined1 *)(param_1 + 0x1b) = 1;
  param_1[0x1c] = 0;
  param_1[0x19] = 0x9c4;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)((int)param_1 + 0x8d) = 1;
  piVar2 = FUN_0041e048((int *)&PTR_FUN_004169a0,'\x01',extraout_ECX_02);
  param_1[0x22] = (int)piVar2;
  pHVar3 = LoadIconA(*(HINSTANCE *)PTR_DAT_0047c710,"MAINICON");
  FUN_0041e418(piVar2,pHVar3);
  iVar1 = param_1[0x22];
  *(int **)(iVar1 + 0xc) = param_1;
  *(undefined1 **)(iVar1 + 8) = &LAB_00432adc;
  GetModuleFileNameA(*(HMODULE *)PTR_DAT_0047c710,(LPSTR)&bStack_105,0x100);
  OemToCharA((LPCSTR)&bStack_105,(LPSTR)&bStack_105);
  pcVar4 = FUN_0040b8c0(&bStack_105,'\\');
  if (pcVar4 != (char *)0x0) {
    FUN_004083a8((char *)&bStack_105,pcVar4 + 1);
  }
  pcVar4 = FUN_0040b8e8(&bStack_105,'.');
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
  }
  CharLowerA(aCStack_104);
  FUN_00403d80(param_1 + 0x1f,(char *)&bStack_105,0x100);
  if (*PTR_DAT_0047c5e8 == '\0') {
    FUN_00431198((int)param_1);
  }
  *(undefined1 *)((int)param_1 + 0x49) = 1;
  *(undefined1 *)((int)param_1 + 0x4a) = 1;
  *(undefined1 *)((int)param_1 + 0x4b) = 1;
  *(undefined1 *)((int)param_1 + 0x8e) = 1;
  param_1[0x24] = 0;
  if (cStack_5 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_fffffee0;
  }
  return param_1;
}

