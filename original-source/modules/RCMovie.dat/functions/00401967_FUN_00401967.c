/*
 * FUN_00401967 at 00401967
 * undefined4 __stdcall FUN_00401967(HWND param_1, int param_2, int param_3)
 * Address ranges: 00401967-00401c83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401967(HWND param_1,int param_2,int param_3)

{
  undefined *lpText;
  HICON lParam;
  UINT UVar1;
  uint *puVar2;
  HINSTANCE pHVar3;
  undefined4 uVar4;
  uint local_40 [13];
  char *local_c;
  undefined4 local_8;
  
  local_c = s_Service_exe_0042c59c;
  FUN_00401590(0,1);
  lpText = PTR_s_Fout_opgetreden_in_Davi_Service_0042c304;
  local_8 = 1;
  if (param_2 == 0x10) {
    PostMessageA(param_1,0x111,2,0);
    uVar4 = 1;
  }
  else if (param_2 == 0x110) {
    lParam = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f01);
    SendDlgItemMessageA(param_1,0x65,0x172,1,(LPARAM)lParam);
    CheckDlgButton(param_1,0x68,1);
    uVar4 = 1;
  }
  else if (param_2 == 0x111) {
    if (param_3 == 2) {
      EndDialog(param_1,0);
    }
    else if (param_3 == 0x6b) {
      DAT_00438428 = &DAT_004383b8;
      DAT_0043843c = (LPRECT)&DAT_004383d0;
      GetWindowRect(param_1,(LPRECT)&DAT_004383b8);
      SetWindowPos(param_1,(HWND)0x0,*DAT_00438428,DAT_00438428[1],DAT_00438428[2] - *DAT_00438428,
                   (DAT_00438428[3] - DAT_00438428[1]) + 0x50,6);
      DAT_004383b0 = GetDlgItem(param_1,0x6b);
      ShowWindow(DAT_004383b0,0);
      EnableWindow(DAT_004383b0,0);
      DAT_004383b0 = GetDlgItem(param_1,0x6c);
      GetWindowRect(DAT_004383b0,DAT_0043843c);
      SetWindowPos(DAT_004383b0,(HWND)0x0,DAT_0043843c->left - *DAT_00438428,
                   (DAT_0043843c->top - DAT_00438428[1]) + 0x3c,0,0,5);
      DAT_004383b0 = GetDlgItem(param_1,0x6d);
      GetWindowRect(DAT_004383b0,DAT_0043843c);
      SetWindowPos(DAT_004383b0,(HWND)0x0,0,(DAT_0043843c->top - DAT_00438428[1]) + 0x3c,0,0,5);
      DAT_004383b0 = GetDlgItem(param_1,0x6e);
      ShowWindow(DAT_004383b0,5);
      InvalidateRect(param_1,(RECT *)0x0,1);
    }
    else {
      if (param_3 != 0x6c) {
        return 0;
      }
      UVar1 = IsDlgButtonChecked(param_1,0x68);
      if (UVar1 == 0) {
        FUN_004015a6((byte *)s_Fatal_Exit_cancelled_0042c600);
      }
      else {
        puVar2 = (uint *)FUN_00401ce9();
        FUN_0041f7a0(local_40,(uint *)&DAT_0042c5a8);
        FUN_0041f7b0(local_40,puVar2);
        pHVar3 = ShellExecuteA(param_1,&DAT_0042c5b8,s_service_exe_0042c5ac,(LPCSTR)local_40,
                               &DAT_0043847c,1);
        if (pHVar3 < (HINSTANCE)0x21) {
          FUN_004015a6((byte *)s_ShellExecute_error_number__d_in_F_0042c5c0);
          MessageBoxA((HWND)0x0,lpText,s_Fatal_Exit_0042c5f4,0x10);
        }
      }
      EndDialog(param_1,1);
    }
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

