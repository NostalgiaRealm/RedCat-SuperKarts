/*
 * FUN_0045c09c at 0045c09c
 * undefined FUN_0045c09c(void)
 * Address ranges: 0045c09c-0045c14f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c09c(int *param_1,char param_2,undefined4 param_3)

{
  HWND pHVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  undefined *puStack_c;
  undefined4 *puStack_8;
  
  puStack_8 = (undefined4 *)0x0;
  puStack_c = (undefined *)0x0;
  if (param_2 != '\0') {
    puStack_28 = (undefined1 *)0x45c0b1;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffdc,in_stack_ffffffe0);
    param_3 = extraout_ECX;
  }
  puStack_2c = &LAB_0045c150;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  FUN_0042f8ec(param_1,'\0',param_3);
  pHVar1 = FindWindowA(PTR_s_Progman_0047c2d8,(LPCSTR)0x0);
  param_1[0x2c] = (int)pHVar1;
  pHVar1 = FindWindowA(PTR_s_Shell_TrayWnd_0047c2dc,(LPCSTR)0x0);
  param_1[0x2d] = (int)pHVar1;
  ShowWindow((HWND)param_1[0x2c],0);
  ShowWindow((HWND)param_1[0x2d],0);
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_c);
  FUN_004081c4(puStack_c,(int *)&puStack_8);
  FUN_00403ba4(&DAT_0047e194,puStack_8);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_0045c157;
  puStack_2c = (undefined1 *)0x45c14f;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

