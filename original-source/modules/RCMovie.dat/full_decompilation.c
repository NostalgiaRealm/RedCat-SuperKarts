/* Ghidra-generated C-like pseudocode for inspection. Not original source and not a buildable reconstruction. */
/*
 * FUN_00401000 at 00401000
 * undefined4 __cdecl FUN_00401000(LPCSTR param_1)
 * Address ranges: 00401000-00401082
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401000(LPCSTR param_1)

{
  FILE *pFVar1;
  int iVar2;
  
  pFVar1 = (FILE *)FUN_0041f4c6(param_1,&DAT_0042c09c);
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  FUN_0041f3be((char *)&param_1,3,1,(int *)pFVar1);
  FUN_0041f368(pFVar1);
  iVar2 = _strncmp((char *)&param_1,&DAT_0042c098,3);
  if (iVar2 == 0) {
    FUN_004015a6((byte *)s__s__d__MovieFormat_of__s___SMK_0042c060);
    return 1;
  }
  FUN_004015a6((byte *)s__s__d__MovieFormat_of__s___AVI_0042c040);
  return 2;
}


/*
 * FUN_00401090 at 00401090
 * undefined4 __stdcall FUN_00401090(void)
 * Address ranges: 00401090-004010e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00401090(void)

{
  BOOL BVar1;
  tagMSG local_1c;
  
  BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  if (BVar1 == 0) {
    return 0;
  }
  do {
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  } while (BVar1 != 0);
  return 0;
}


/*
 * FUN_004010f0 at 004010f0
 * undefined __stdcall FUN_004010f0(void)
 * Address ranges: 004010f0-00401119
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004010f0(void)

{
  FUN_004015a6((byte *)s__s__d__Deactivating_mouse_0042c0a0);
  FUN_00404807(1);
  FUN_00404863();
  FUN_00404b2d();
  FUN_00401090();
  return;
}


/*
 * FUN_00401160 at 00401160
 * undefined __stdcall FUN_00401160(void)
 * Address ranges: 00401160-004011e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00401160(void)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_4;
  
  DAT_00437da0 = 0;
  FUN_004015a6((byte *)s__s__d__Getting_videomodes_0042c0f4);
  ppuVar2 = &local_4;
  iVar1 = DirectDrawCreate();
  if (iVar1 != 0) {
    FUN_0040187a((byte *)s_Error_creating_DirectDraw_0042c0d8);
  }
  iVar1 = (*(code *)*local_4)(ppuVar2,&DAT_004286d0,&stack0xffffffec);
  if (iVar1 != 0) {
    FUN_0040187a((byte *)s_Error_getting_DirectDraw4_0042c0bc);
  }
  (*(code *)(*ppuVar2)[8])(ppuVar2,0,0,0,&LAB_00401120);
  (*(code *)(*ppuVar2)[2])(ppuVar2);
  return;
}


/*
 * FUN_004011f0 at 004011f0
 * uint __cdecl FUN_004011f0(int param_1, int param_2, int param_3)
 * Address ranges: 004011f0-00401245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_004011f0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = DAT_00437da0;
  if (0 < (int)DAT_00437da0 + -1) {
    piVar1 = &DAT_00437dac;
    do {
      if (param_2 == *piVar1 && (param_1 == piVar1[-1] && param_3 == piVar1[1])) {
        return CONCAT31((int3)((uint)piVar1 >> 8),1);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 3;
    } while (iVar2 < (int)DAT_00437da0 + -1);
  }
  return (uint)piVar1 & 0xffffff00;
}


/*
 * FUN_00401250 at 00401250
 * undefined __stdcall FUN_00401250(void)
 * Address ranges: 00401250-00401297
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00401250(void)

{
  int iVar1;
  
  FUN_004056d0((uint *)s_movie_ini_0042c134);
  iVar1 = FUN_0040584a(s_HELPDESK_0042c120,s_DEBUG_0042c12c);
  FUN_00401590(0,(uint)(iVar1 == 1));
  DAT_004383a8 = FUN_0040584a(s_PLAYER_0042c110,&DAT_0042c118);
  return;
}


/*
 * FUN_004012a0 at 004012a0
 * undefined4 __cdecl FUN_004012a0(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 004012a0-0040134d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004012a0(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  if (DAT_004383a8 == 1) {
    uVar1 = FUN_004011f0(0x140,0xf0,8);
    if ((char)uVar1 == '\x01') {
      FUN_004015a6((byte *)s__s__d__Using_videomode_MODE_320X_0042c174);
      FUN_00401e18(0,1,0);
      *param_1 = 0x140;
      *param_2 = 0xf0;
      return CONCAT31((int3)((uint)param_1 >> 8),1);
    }
  }
  uVar1 = FUN_004011f0(0x280,0x1e0,8);
  if ((char)uVar1 == '\x01') {
    FUN_004015a6((byte *)s__s__d__Using_videomode_MODE_640X_0042c140);
    FUN_00401e18(0,3,0);
    *param_1 = 0x280;
    *param_2 = 0x1e0;
    return CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}


/*
 * FUN_00401350 at 00401350
 * undefined4 __cdecl FUN_00401350(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 00401350-004013fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401350(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  if (DAT_004383a8 == 1) {
    uVar1 = FUN_004011f0(0x140,200,0x10);
    if ((char)uVar1 == '\x01') {
      FUN_004015a6((byte *)s__s__d__Using_videomode_MODE_320X_0042c1e0);
      FUN_00401e18(0,6,0);
      *param_1 = 0x140;
      *param_2 = 200;
      return CONCAT31((int3)((uint)param_1 >> 8),1);
    }
  }
  uVar1 = FUN_004011f0(0x280,0x1e0,0x10);
  if ((char)uVar1 == '\x01') {
    FUN_004015a6((byte *)s__s__d__Using_videomode_MODE_640X_0042c1a8);
    FUN_00401e18(0,9,0);
    *param_1 = 0x280;
    *param_2 = 0x1e0;
    return CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}


/*
 * FUN_00401400 at 00401400
 * undefined4 __stdcall FUN_00401400(HINSTANCE param_1, undefined4 param_2, LPCSTR param_3, int param_4)
 * Address ranges: 00401400-0040158d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00401400(HINSTANCE param_1,undefined4 param_2,LPCSTR param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int local_18;
  int local_14;
  CRect aCStack_10 [16];
  
  FUN_00401250();
  if (DAT_004383a8 == -1) {
    FUN_004015a6((byte *)s__s__d__No_playback_requested___S_0042c28c);
    return 0;
  }
  iVar1 = FUN_00401000(param_3);
  if (iVar1 != 0) {
    FUN_00401160();
    FUN_00401e18(1,0x40,1);
    FUN_00401e18(2,0,0);
    if (iVar1 == 1) {
      uVar2 = FUN_004012a0(&local_14,&local_18);
      if ((char)uVar2 == '\0') {
        return 0;
      }
    }
    else if ((iVar1 == 2) && (uVar2 = FUN_00401350(&local_14,&local_18), (char)uVar2 == '\0')) {
      return 0;
    }
    FUN_00403f60(param_1,param_4,s_Davilex_Entertainment_0042c264,s_Movie_player_0042c27c);
    FUN_004010f0();
    if (iVar1 == 1) {
      FUN_0040a0e0(0);
      FUN_004015a6((byte *)s__s__d__Playing_Smacker____0042c218);
      FUN_0040a616(param_3,0,0,local_14,local_18,1,0);
    }
    else if (iVar1 == 2) {
      FUN_0041e730();
      FUN_004015a6((byte *)s__s__d__Playing_AVI____0042c234);
      puVar3 = (undefined4 *)CRect::CRect(aCStack_10,0,0,local_14,local_18);
      FUN_0041e870(&stack0xffffffcc,puVar3);
      FUN_0041e4e0(0,param_3);
      FUN_0041e760();
    }
    else {
      FUN_0040187a((byte *)s_Unknown_movie_format__0042c24c);
    }
    FUN_0040a088();
    FUN_00406d14();
    FUN_0040173e();
    return 0;
  }
  return 1;
}


/*
 * FUN_00401590 at 00401590
 * undefined __cdecl FUN_00401590(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00401590-004015a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401590(undefined4 param_1,undefined4 param_2)

{
  DAT_0043846c = param_2;
  DAT_00438470 = param_1;
  return;
}


/*
 * FUN_004015a6 at 004015a6
 * undefined __cdecl FUN_004015a6(byte * param_1)
 * Address ranges: 004015a6-0040166d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004015a6(byte *param_1)

{
  FILE *pFVar1;
  byte local_324 [800];
  
  if (DAT_0043846c == 1) {
    if (DAT_00438470 == 0) {
      pFVar1 = (FILE *)FUN_0041f4c6(s_debug_txt_0042c4d8,&DAT_0042c4d4);
      if (pFVar1 != (FILE *)0x0) {
        FUN_0041f64a(local_324,param_1,(undefined4 *)&stack0x00000008);
        FUN_0041f618((int *)pFVar1,local_324);
        FUN_0041f368(pFVar1);
      }
    }
    else if (DAT_00438470 == 1) {
      OutputDebugStringA((LPCSTR)local_324);
    }
  }
  return;
}


/*
 * FUN_0040166e at 0040166e
 * undefined __cdecl FUN_0040166e(byte * param_1)
 * Address ranges: 0040166e-004016c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040166e(byte *param_1)

{
  CHAR local_194 [400];
  
  FUN_0041f64a(local_194,param_1,(undefined4 *)&stack0x00000008);
  MessageBoxA(DAT_0043842c,local_194,(LPCSTR)0x0,0);
  return;
}


/*
 * FUN_004016c6 at 004016c6
 * undefined __cdecl FUN_004016c6(int param_1)
 * Address ranges: 004016c6-004016fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004016c6(int param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    FUN_0040187a((byte *)s__s__d____Illegal_color_key_index_0042c4f0);
  }
  DAT_0042c4d0 = param_1;
  return;
}


/*
 * FUN_004016fe at 004016fe
 * undefined4 __stdcall FUN_004016fe(void)
 * Address ranges: 004016fe-00401707
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004016fe(void)

{
  return DAT_0042c4d0;
}


/*
 * FUN_00401708 at 00401708
 * undefined4 __stdcall FUN_00401708(void)
 * Address ranges: 00401708-00401711
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00401708(void)

{
  return DAT_00438474;
}


/*
 * FUN_00401712 at 00401712
 * undefined __cdecl FUN_00401712(undefined4 param_1)
 * Address ranges: 00401712-0040171e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401712(undefined4 param_1)

{
  DAT_00438474 = param_1;
  return;
}


/*
 * FUN_0040171f at 0040171f
 * undefined __cdecl FUN_0040171f(int param_1)
 * Address ranges: 0040171f-00401733
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040171f(int param_1)

{
  if (param_1 == 1) {
    DAT_00438478 = 1;
  }
  return;
}


/*
 * FUN_00401734 at 00401734
 * undefined4 __stdcall FUN_00401734(void)
 * Address ranges: 00401734-0040173d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00401734(void)

{
  return DAT_00438478;
}


/*
 * FUN_0040173e at 0040173e
 * undefined __stdcall FUN_0040173e(void)
 * Address ranges: 0040173e-00401879
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040173e(void)

{
  int iVar1;
  
  FUN_0040d190();
  FUN_0040cb40();
  if (DAT_00438454 != 0) {
    FUN_0040b918();
    if (DAT_00438458 != 0) {
      FUN_004015a6((byte *)s_Releasing_screen_0042c518);
      (**(code **)(*DAT_00438434 + 8))(DAT_00438434);
      DAT_00438434 = (int *)0x0;
      DAT_00438458 = 0;
    }
    if ((DAT_0043845c != 0) && (DAT_0042c360 == 0)) {
      FUN_004015a6((byte *)s_Releasing_buffer_screen_0042c52c);
      (**(code **)(*DAT_00438438 + 8))(DAT_00438438);
      DAT_00438438 = (int *)0x0;
      DAT_0043845c = 0;
    }
    if (DAT_00438460 != 0) {
      FUN_004015a6((byte *)s_Releasing_buffer_screen_0042c548);
      (**(code **)(*DAT_00438418 + 8))(DAT_00438418);
      DAT_00438418 = (int *)0x0;
      DAT_00438460 = 0;
    }
    FUN_004015a6((byte *)s_Releasing_dd_object_0042c564);
    (**(code **)(*DAT_00438414 + 8))(DAT_00438414);
    DAT_00438414 = (int *)0x0;
    DAT_00438454 = 0;
  }
  FUN_0040b542();
  FUN_004015a6((byte *)s_post_quit_0042c57c);
  PostMessageA(DAT_0043842c,0x10,0,0);
  do {
    iVar1 = FUN_0040a9d3();
  } while (iVar1 != 0);
  return;
}


/*
 * FUN_0040187a at 0040187a
 * undefined4 __cdecl FUN_0040187a(byte * param_1)
 * Address ranges: 0040187a-00401966
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 __cdecl FUN_0040187a(byte *param_1)

{
  int iVar1;
  CHAR local_1b0 [400];
  UINT local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_20 = 0x10010;
  local_1c = 0x10021;
  local_18 = 0x10045;
  local_14 = 0x10034;
  local_10 = 0x10013;
  local_c = 0x110011;
  local_8 = 0x90025;
  FUN_0041f64a(local_1b0,param_1,(undefined4 *)&stack0x00000008);
  FUN_00401590(0,1);
  FUN_004015a6((byte *)s___d___s_0042c588);
  ShowWindow(DAT_0043842c,6);
  do {
    iVar1 = FUN_0040a97d();
  } while (iVar1 != 0);
  MessageBoxExA((HWND)0x0,local_1b0,&DAT_0042c594,local_20,0);
  FUN_0040173e();
  FUN_0041f6c8(0);
  return 0;
}


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


/*
 * FUN_00401c84 at 00401c84
 * undefined1 __cdecl FUN_00401c84(int param_1)
 * Address ranges: 00401c84-00401cc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __cdecl FUN_00401c84(int param_1)

{
  undefined1 local_8;
  
  if ((((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) || (param_1 == 3)) {
    DAT_0042c348 = param_1;
    local_8 = 1;
  }
  else {
    local_8 = 0;
    DAT_0042c348 = 0;
  }
  return local_8;
}


/*
 * FUN_00401cc7 at 00401cc7
 * undefined4 __stdcall FUN_00401cc7(void)
 * Address ranges: 00401cc7-00401cd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00401cc7(void)

{
  return DAT_0042c348;
}


/*
 * FUN_00401cd1 at 00401cd1
 * undefined4 __cdecl FUN_00401cd1(uint * param_1)
 * Address ranges: 00401cd1-00401ce8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401cd1(uint *param_1)

{
  uint *puVar1;
  
  puVar1 = FUN_0041f7a0((uint *)&DAT_004383e0,param_1);
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}


/*
 * FUN_00401ce9 at 00401ce9
 * undefined * __stdcall FUN_00401ce9(void)
 * Address ranges: 00401ce9-00401cf2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined * FUN_00401ce9(void)

{
  return &DAT_004383e0;
}


/*
 * FUN_00401cf3 at 00401cf3
 * undefined __stdcall FUN_00401cf3(void)
 * Address ranges: 00401cf3-00401e17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00401cf3(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0;
  local_c = DAT_0042c350;
  local_10 = 0;
  local_8 = DAT_0042c354;
  local_24 = 0;
  local_1c = DAT_0042c350;
  local_20 = 0;
  local_18 = DAT_0042c354;
  if (DAT_0042c360 == 0) {
    FUN_004028c2(DAT_00438434);
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_14,DAT_00438438,&local_24,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042c654);
    }
  }
  else {
    FUN_004028c2(DAT_00438434);
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438434 + 0x2c))(DAT_00438434,0,1);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____error_flipping_surfaces_0042c624);
    }
  }
  return;
}


/*
 * FUN_00401e18 at 00401e18
 * undefined4 __cdecl FUN_00401e18(int param_1, uint param_2, int param_3)
 * Address ranges: 00401e18-00401f0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401e18(int param_1,uint param_2,int param_3)

{
  if (param_1 == 0) {
    if (((int)param_2 < 0) || (0x12 < (int)param_2)) {
      FUN_0040187a((byte *)s__s__d____error_predefined_screen_0042c680);
    }
    DAT_0042c34c = param_2;
    DAT_0042c350 = *(undefined4 *)(&DAT_0042c368 + param_2 * 0x14);
    DAT_0042c354 = *(undefined4 *)(&DAT_0042c36c + param_2 * 0x14);
    DAT_0042c358 = *(undefined4 *)(&DAT_0042c370 + param_2 * 0x14);
    DAT_00438468 = *(undefined4 *)(&DAT_0042c374 + param_2 * 0x14);
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      DAT_0042c35c = DAT_0042c35c | param_2;
    }
    else {
      DAT_0042c35c = param_2;
    }
  }
  else if (param_1 == 2) {
    DAT_0042c364 = param_2;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unknown_variable___d__r_0042c6d0);
  }
  return 0;
}


/*
 * FUN_00401f0d at 00401f0d
 * undefined4 __cdecl FUN_00401f0d(int param_1)
 * Address ranges: 00401f0d-00401f60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401f0d(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0042c34c;
  if (((param_1 != 0) && (uVar1 = DAT_0042c35c, param_1 != 1)) &&
     (uVar1 = DAT_0042c364, param_1 != 2)) {
    FUN_0040187a((byte *)s__s__d____unknown_variable___d__r_0042c708);
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_00401f61 at 00401f61
 * char * __cdecl FUN_00401f61(int param_1)
 * Address ranges: 00401f61-0040221a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_00401f61(int param_1)

{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return s_undefined_error_condition_0042c778;
    }
    if (param_1 == -0x7fffbfff) {
      return s_operation_is_not_supported_0042cdf8;
    }
  }
  else if (param_1 < -0x7ff8ffa8) {
    if (param_1 == -0x7ff8ffa9) {
      return s_one_or_more_invalid_parameters_0042c980;
    }
    if (param_1 == -0x7ff8fff2) {
      return s_application_out_of_free_memory_0042cd2c;
    }
  }
  else if (param_1 < -0x7789ff9b) {
    if (param_1 == -0x7789ff9c) {
      return s_one_or_more_of_the_capability_bi_0042c8f8;
    }
    if (param_1 == -0x7789ffa1) {
      return s_primary_surface_creation_request_0042c8a8;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return s_pointer_is_not_a_dd_object_0042c964;
    }
    if (param_1 == -0x7789ff88) {
      return s_screen_mode_not_supported_0042c948;
    }
  }
  else if (param_1 < -0x7789ff5f) {
    if (param_1 == -0x7789ff60) {
      return s_one_or_more_surfaces_of_the_dd_o_0042c9e4;
    }
    if (param_1 == -0x7789ff6f) {
      return s_pixel_format_is_invalid_0042c9a0;
    }
  }
  else if (param_1 < -0x7789ff2b) {
    if (param_1 == -0x7789ff2c) {
      return s_the_setcooperativelevel_must_be_c_0042ca94;
    }
    if (param_1 == -0x7789ff4c) {
      return s_hardware_does_not_support_alpha_a_0042ca64;
    }
  }
  else if (param_1 < -0x7789ff19) {
    if (param_1 == -0x7789ff1a) {
      return s__hardware__flipping_of_visible_s_0042cb94;
    }
    if (param_1 == -0x7789ff1f) {
      return s_exclusive_mode_necessary_for_thi_0042cb68;
    }
  }
  else if (param_1 < -0x7789feab) {
    if (param_1 == -0x7789feac) {
      return s__hardware__no_hardware_support_f_0042ccb0;
    }
    if (param_1 == -0x7789fec0) {
      return s_surface_does_not_use_an_8_bit_pa_0042ca18;
    }
  }
  else {
    switch(param_1) {
    case -0x7789fe98:
      return s_hardware_needed_for_this_operati_0042ccec;
    case -0x7789fe84:
      return s_application_out_of_video_memory_0042cd4c;
    case -0x7789fe52:
      return s_access_to_surface_denied_by_othe_0042cd9c;
    case -0x7789fe3e:
      return s_access_to_surface_denied_because_0042cdc8;
    case -0x7789fde4:
      return s_previous_blit_is_still_in_progre_0042ce44;
    case -0x7789fdcf:
      return s_direct_draw_invalid_gui_id_0042c92c;
    case -0x7789fdce:
      return s_direct_draw_object_already_creat_0042c734;
    case -0x7789fdcd:
      return s_hardware_only_dd_objects_not_all_0042cae0;
    case -0x7789fdcc:
      return s_application_already_created_a_pr_0042cd6c;
    case -0x7789fdcb:
      return s_there_is_no_software_emulation_f_0042cb2c;
    case -0x7789fdc6:
      return s_dd_is_prevented_from_restoring_s_0042c804;
    case -0x7789fdc5:
      return s_cooperative_level_for_HWND_alrea_0042c794;
    case -0x7789fdc4:
      return s_there_was_no_palette_attached_to_0042cc0c;
    case -0x7789fdc3:
      return s_there_is_no_hardware_support_for_0042cc3c;
    case -0x7789fdbb:
      return s_exclusive_mode_was_already_set_0042c758;
    case -0x7789fdb5:
      return s_surface_was_created_in_different_0042ce68;
    case -0x7789fdb4:
      return s_this_surface_was_implicitly_crea_0042c860;
    case -0x7789fdb3:
      return s_the_surface_being_used_is_not_a_p_0042cc78;
    case -0x7789fdb2:
      return s_display_is_currently_in_an_unsup_0042ce14;
    case -0x7789fdb1:
      return s__hardware__no_mipmap_texture_map_0042cbd0;
    case -0x7789fdb0:
      return s_surface_type_incompatible_with_o_0042c9b8;
    }
  }
  return s_unidentified_error_0042ce90;
}


/*
 * FUN_0040235c at 0040235c
 * undefined4 __cdecl FUN_0040235c(int * param_1)
 * Address ranges: 0040235c-004023cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040235c(int *param_1)

{
  int iVar1;
  undefined4 local_70 [9];
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042ceb0);
  }
  return local_4c;
}


/*
 * FUN_004023cc at 004023cc
 * undefined4 __cdecl FUN_004023cc(int * param_1)
 * Address ranges: 004023cc-0040243b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004023cc(int *param_1)

{
  int iVar1;
  undefined4 local_70 [9];
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cee4);
  }
  return local_4c;
}


/*
 * FUN_0040243c at 0040243c
 * undefined4 __cdecl FUN_0040243c(int param_1)
 * Address ranges: 0040243c-00402530
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040243c(int param_1)

{
  int iVar1;
  int *local_78;
  undefined4 local_70 [9];
  undefined4 local_4c;
  
  if (param_1 == 0) {
    if (DAT_00438444 == 0) {
      return 0;
    }
    local_78 = DAT_00438434;
  }
  else if (param_1 == 1) {
    if (DAT_00438448 == 0) {
      return 0;
    }
    local_78 = DAT_00438438;
  }
  else if (param_1 == 2) {
    if (DAT_0043844c == 0) {
      return 0;
    }
    local_78 = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042cf18);
  }
  FUN_004028c2(local_78);
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  iVar1 = (**(code **)(*local_78 + 100))(local_78,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cf50);
  }
  return local_4c;
}


/*
 * FUN_00402531 at 00402531
 * undefined4 __cdecl FUN_00402531(int param_1, undefined4 * param_2)
 * Address ranges: 00402531-00402630
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00402531(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *local_78;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_4c;
  
  if (param_1 == 0) {
    if (DAT_00438444 == 0) {
      return 0;
    }
    local_78 = DAT_00438434;
  }
  else if (param_1 == 1) {
    if (DAT_00438448 == 0) {
      return 0;
    }
    local_78 = DAT_00438438;
  }
  else if (param_1 == 2) {
    if (DAT_0043844c == 0) {
      return 0;
    }
    local_78 = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042cf84);
  }
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028c2(local_78);
  iVar1 = (**(code **)(*local_78 + 100))(local_78,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cfbc);
  }
  *param_2 = local_60;
  return local_4c;
}


/*
 * FUN_00402631 at 00402631
 * undefined4 __cdecl FUN_00402631(int * param_1, undefined4 * param_2)
 * Address ranges: 00402631-004026ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00402631(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cff0);
  }
  *param_2 = local_60;
  return local_4c;
}


/*
 * FUN_004026ac at 004026ac
 * undefined4 __cdecl FUN_004026ac(int * param_1, undefined4 * param_2)
 * Address ranges: 004026ac-00402726
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004026ac(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_4c;
  
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042d024);
  }
  *param_2 = local_60;
  return local_4c;
}


/*
 * FUN_00402727 at 00402727
 * undefined __cdecl FUN_00402727(int param_1, undefined4 param_2)
 * Address ranges: 00402727-004027f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00402727(int param_1,undefined4 param_2)

{
  int iVar1;
  int *local_c;
  
  if (param_1 == 0) {
    if (DAT_00438444 == 0) {
      return;
    }
    local_c = DAT_00438434;
  }
  else if (param_1 == 1) {
    if (DAT_00438448 == 0) {
      return;
    }
    local_c = DAT_00438438;
  }
  else if (param_1 == 2) {
    if (DAT_0043844c == 0) {
      return;
    }
    local_c = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042d058);
  }
  FUN_004028c2(local_c);
  iVar1 = (**(code **)(*local_c + 0x80))(local_c,param_2);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_unlock_surfac_0042d090);
  }
  return;
}


/*
 * FUN_004027f9 at 004027f9
 * undefined __cdecl FUN_004027f9(int * param_1, undefined4 param_2)
 * Address ranges: 004027f9-0040284c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004027f9(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,param_2);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_unlock_surfac_0042d0c8);
  }
  return;
}


/*
 * FUN_0040284d at 0040284d
 * undefined __cdecl FUN_0040284d(int * param_1, undefined4 param_2)
 * Address ranges: 0040284d-004028a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040284d(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,param_2);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_unlock_surfac_0042d100);
  }
  return;
}


/*
 * FUN_004028a1 at 004028a1
 * undefined __cdecl FUN_004028a1(int * param_1)
 * Address ranges: 004028a1-004028c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004028a1(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x6c))(param_1);
  }
  return;
}


/*
 * FUN_004028c2 at 004028c2
 * undefined __cdecl FUN_004028c2(int * param_1)
 * Address ranges: 004028c2-004028e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004028c2(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x6c))(param_1);
  }
  return;
}


/*
 * FUN_004028e3 at 004028e3
 * undefined4 __cdecl FUN_004028e3(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004028e3-00402969
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004028e3(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 7;
  local_8 = 0x800;
  local_64 = param_1;
  local_68 = param_2;
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d138);
  }
  return local_78;
}


/*
 * FUN_0040296a at 0040296a
 * undefined4 __cdecl FUN_0040296a(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0040296a-00402a31
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040296a(undefined4 param_1,undefined4 param_2)

{
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 7;
  local_8 = 0x800;
  local_64 = param_1;
  local_68 = param_2;
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d170);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d1a8);
  }
  return local_74;
}


/*
 * FUN_00402a32 at 00402a32
 * undefined4 __cdecl FUN_00402a32(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00402a32-00402ab6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00402a32(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 7;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d1dc);
  }
  return local_78;
}


/*
 * FUN_00402ab7 at 00402ab7
 * undefined4 __cdecl FUN_00402ab7(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00402ab7-00402b7c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00402ab7(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 7;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d214);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d24c);
  }
  return local_74;
}


/*
 * FUN_00402b7d at 00402b7d
 * undefined4 __cdecl FUN_00402b7d(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint param_4)
 * Address ranges: 00402b7d-00402c03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402b7d(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = param_4 | 7;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d280);
  }
  return local_78;
}


/*
 * FUN_00402c04 at 00402c04
 * undefined4 __cdecl FUN_00402c04(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint param_4)
 * Address ranges: 00402c04-00402ccb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402c04(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = param_4 | 7;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d2b8);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d2f0);
  }
  return local_74;
}


/*
 * FUN_00402ccc at 00402ccc
 * undefined4 __cdecl FUN_00402ccc(undefined4 param_1, undefined4 param_2, uint param_3, uint param_4, undefined4 param_5)
 * Address ranges: 00402ccc-00402d62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402ccc(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_58;
  uint local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = param_4 | 0x20007;
  local_8 = param_3 | 0x401008;
  local_58 = param_5;
  local_64 = param_1;
  local_68 = param_2;
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d324);
  }
  return local_78;
}


/*
 * FUN_00402d63 at 00402d63
 * undefined4 __cdecl FUN_00402d63(undefined4 param_1, undefined4 param_2, uint param_3, uint param_4, undefined4 param_5)
 * Address ranges: 00402d63-00402e3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402d63(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_58;
  uint local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = param_4 | 0x20007;
  local_8 = param_3 | 0x401008;
  local_58 = param_5;
  local_64 = param_1;
  local_68 = param_2;
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d35c);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d394);
  }
  return local_74;
}


/*
 * FUN_00402e3b at 00402e3b
 * undefined4 __cdecl FUN_00402e3b(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4)
 * Address ranges: 00402e3b-00402ed0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402e3b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_28 [8];
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 0x1007;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  puVar2 = local_28;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d3c8);
  }
  return local_78;
}


/*
 * FUN_00402ed1 at 00402ed1
 * undefined4 __cdecl FUN_00402ed1(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4)
 * Address ranges: 00402ed1-00402fa7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402ed1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_28 [8];
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 0x1007;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  puVar2 = local_28;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d400);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d438);
  }
  return local_74;
}


/*
 * FUN_00402fa8 at 00402fa8
 * undefined4 __cdecl FUN_00402fa8(undefined4 param_1, undefined4 param_2, uint param_3, undefined4 * param_4, undefined4 param_5)
 * Address ranges: 00402fa8-00403049
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00402fa8(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_58;
  undefined4 local_28 [8];
  uint local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 0x21007;
  local_8 = param_3 | 0x401008;
  local_58 = param_5;
  local_64 = param_1;
  local_68 = param_2;
  puVar2 = local_28;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d46c);
  }
  return local_78;
}


/*
 * FUN_0040304a at 0040304a
 * undefined4 __cdecl FUN_0040304a(undefined4 param_1, undefined4 param_2, uint param_3, undefined4 * param_4, undefined4 param_5)
 * Address ranges: 0040304a-0040312c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_0040304a(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_58;
  undefined4 local_28 [8];
  uint local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 0x21007;
  local_8 = param_3 | 0x401008;
  local_58 = param_5;
  local_64 = param_1;
  local_68 = param_2;
  puVar2 = local_28;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d4a4);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d4dc);
  }
  return local_74;
}


/*
 * FUN_0040312d at 0040312d
 * undefined __cdecl FUN_0040312d(int * param_1, undefined4 * param_2, undefined4 * param_3)
 * Address ranges: 0040312d-004031ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040312d(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 6;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_70);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_get_desc_of_s_0042d510);
  }
  *param_2 = local_64;
  *param_3 = local_68;
  return;
}


/*
 * FUN_004031ae at 004031ae
 * undefined __cdecl FUN_004031ae(int * param_1, undefined4 * param_2, undefined4 * param_3)
 * Address ranges: 004031ae-0040322e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004031ae(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 6;
  FUN_004028a1(param_1);
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_70);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_get_desc_of_s_0042d54c);
  }
  *param_2 = local_64;
  *param_3 = local_68;
  return;
}


/*
 * FUN_0040322f at 0040322f
 * undefined4 __cdecl FUN_0040322f(int param_1)
 * Address ranges: 0040322f-0040330c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040322f(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *local_78;
  undefined4 local_70 [27];
  
  if ((DAT_00438468 == 0) || (param_1 != 0)) {
    if (param_1 == 0) {
      local_78 = DAT_00438434;
    }
    else if (param_1 == 1) {
      local_78 = DAT_00438438;
    }
    else if (param_1 == 2) {
      local_78 = DAT_00438418;
    }
    else {
      FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042d588);
    }
    _memset(local_70,0,0x6c);
    local_70[0] = 0x6c;
    FUN_004028c2(local_78);
    iVar2 = (**(code **)(*local_78 + 100))(local_78,0,local_70,1,0);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*local_78 + 0x80))(local_78,0);
      if (iVar2 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_0040330d at 0040330d
 * undefined __cdecl FUN_0040330d(int * param_1, undefined4 param_2)
 * Address ranges: 0040330d-0040337d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040330d(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_6c [20];
  undefined4 local_1c;
  undefined4 local_8;
  
  local_8 = 0x1000400;
  local_6c[0] = 100;
  local_1c = param_2;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,0,0,0,local_8,local_6c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____clear_surface_blt_error_0042d5c0);
  }
  return;
}


/*
 * FUN_0040337e at 0040337e
 * undefined __stdcall FUN_0040337e(void)
 * Address ranges: 0040337e-00403445
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040337e(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_00438468 == 0) {
    local_14 = 0;
    local_c = DAT_0042c350;
    local_10 = 0;
    local_8 = DAT_0042c354;
    local_24 = 0;
    local_1c = DAT_0042c350;
    local_20 = 0;
    local_18 = DAT_0042c354;
    FUN_004028c2(DAT_00438434);
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_14,DAT_00438418,&local_24,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d5fc);
    }
  }
  return;
}


/*
 * FUN_00403446 at 00403446
 * undefined __stdcall FUN_00403446(void)
 * Address ranges: 00403446-004034ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00403446(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0;
  local_c = DAT_0042c350;
  local_10 = 0;
  local_8 = DAT_0042c354;
  local_24 = 0;
  local_1c = DAT_0042c350;
  local_20 = 0;
  local_18 = DAT_0042c354;
  FUN_004028c2(DAT_00438434);
  FUN_004028c2(DAT_00438418);
  iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                    (DAT_00438418,&local_14,DAT_00438434,&local_24,0x1000000,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d628);
  }
  return;
}


/*
 * FUN_00403500 at 00403500
 * undefined __stdcall FUN_00403500(void)
 * Address ranges: 00403500-004035c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00403500(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_0043845c != 0) {
    local_14 = 0;
    local_c = DAT_0042c350;
    local_10 = 0;
    local_8 = DAT_0042c354;
    local_24 = 0;
    local_1c = DAT_0042c350;
    local_20 = 0;
    local_18 = DAT_0042c354;
    FUN_004028c2(DAT_00438438);
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                      (DAT_00438438,&local_14,DAT_00438418,&local_24,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d654);
    }
  }
  return;
}


/*
 * FUN_004035c8 at 004035c8
 * undefined __cdecl FUN_004035c8(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, uint param_6)
 * Address ranges: 004035c8-004037c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_004035c8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,uint param_6)

{
  int iVar1;
  undefined4 local_7c [20];
  uint local_2c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x1000400;
  local_18 = param_2;
  local_10 = param_4;
  local_14 = param_3;
  local_c = param_5;
  local_7c[0] = 100;
  if ((DAT_0042c358 == 0x10) || (DAT_0042c358 == 0x18)) {
    if (DAT_00438478 == 0) {
      local_2c = param_6;
    }
    else {
      local_2c = FUN_0040de93(param_6,0x18);
    }
  }
  else {
    local_2c = param_6;
  }
  if (param_1 == 0) {
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))(DAT_00438434,&local_18,0,0,local_8,local_7c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d680);
    }
  }
  else if (param_1 == 1) {
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))(DAT_00438438,&local_18,0,0,local_8,local_7c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d6d8);
    }
  }
  else if (param_1 == 2) {
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438418 + 0x14))(DAT_00438418,&local_18,0,0,local_8,local_7c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d6ac);
    }
  }
  return;
}


/*
 * FUN_004037c9 at 004037c9
 * undefined __cdecl FUN_004037c9(int param_1, uint param_2)
 * Address ranges: 004037c9-004037ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004037c9(int param_1,uint param_2)

{
  FUN_004035c8(param_1,0,0,DAT_0042c350,DAT_0042c354,param_2);
  return;
}


/*
 * FUN_004037f0 at 004037f0
 * undefined __stdcall FUN_004037f0(void)
 * Address ranges: 004037f0-00403e99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004037f0(void)

{
  int iVar1;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_68;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  local_c = DAT_0042c4d0;
  local_10 = DAT_0042c4d0;
  if (DAT_00438458 == 0) {
    while( true ) {
      _memset(&local_7c,0,0x6c);
      local_7c = 0x6c;
      if (DAT_0042c360 == 0) {
        local_78 = 1;
        local_14 = 0x2200;
      }
      else {
        local_78 = 0x21;
        local_14 = 0x2218;
      }
      local_68 = DAT_0042c360;
      FUN_004015a6((byte *)s_creating_0042d6f8);
      iVar1 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_7c,&DAT_00438434,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_create_primar_0042d710);
      }
      iVar1 = (**(code **)*DAT_00438434)(DAT_00438434,&DAT_00428700,&DAT_004383c8);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_create_dd2_su_0042d750);
      }
      FUN_004015a6((byte *)s_locking_0042d784);
      iVar1 = FUN_0040322f(0);
      if (iVar1 != 0) break;
      if ((DAT_0042c360 == 0) || (DAT_00438468 != 0)) goto LAB_004039a5;
      (**(code **)(*DAT_00438434 + 8))(DAT_00438434);
      (**(code **)(*DAT_004383c8 + 8))(DAT_004383c8);
      DAT_0042c360 = 0;
    }
    DAT_00438444 = 1;
    local_8 = FUN_00402631(DAT_00438434,&DAT_004383b4);
    FUN_004015a6((byte *)s_locking_inter_0042d790);
    FUN_004027f9(DAT_00438434,local_8);
    FUN_004015a6((byte *)s_locking_done_0042d7a0);
LAB_004039a5:
    FUN_004015a6((byte *)s_getting_pixel_format_0042d7b0);
    FUN_0040e321();
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar1 = (**(code **)(*DAT_00438434 + 0x74))(DAT_00438434,8,&local_10);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042d7d4);
    }
    DAT_00438458 = 1;
  }
  if (DAT_0043845c == 0) {
    if (DAT_0042c360 == 0) {
      FUN_004015a6((byte *)s_back_screen_0042d8c0);
      DAT_00438438 = (int *)FUN_00402a32(DAT_0042c350,DAT_0042c354,0x2800);
      iVar1 = (**(code **)*DAT_00438438)(DAT_00438438,&DAT_00428700,&DAT_00438440);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____unable_to_create_attach_0042d8dc);
      }
      iVar1 = FUN_0040322f(1);
      if (iVar1 != 0) {
        DAT_00438448 = 1;
        local_8 = FUN_00402631(DAT_00438438,&DAT_00438420);
        FUN_004027f9(DAT_00438438,local_8);
        FUN_004015a6((byte *)s_back_screen_locking_done_0042d910);
      }
    }
    else {
      FUN_004015a6((byte *)s_back_screen_0042d7fc);
      local_80 = 4;
      iVar1 = (**(code **)(*DAT_00438434 + 0x30))(DAT_00438434,&local_80,&DAT_00438438);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____unable_to_create_attach_0042d818);
      }
      iVar1 = (**(code **)*DAT_00438438)(DAT_00438438,&DAT_00428700,&DAT_00438440);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____unable_to_create_attach_0042d858);
      }
      FUN_004015a6((byte *)s_back_screen_locking_0042d88c);
      iVar1 = FUN_0040322f(1);
      if (iVar1 != 0) {
        DAT_00438448 = 1;
        local_8 = FUN_00402631(DAT_00438438,&DAT_00438420);
        FUN_004027f9(DAT_00438438,local_8);
        FUN_004015a6((byte *)s_back_screen_locking_done_0042d8a4);
      }
    }
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar1 = (**(code **)(*DAT_00438438 + 0x74))(DAT_00438438,8,&local_10);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042d938);
    }
    DAT_0043845c = 1;
  }
  if (DAT_00438460 == 0) {
    DAT_00438418 = (int *)FUN_00402a32(DAT_0042c350,DAT_0042c354,0x2800);
    iVar1 = (**(code **)*DAT_00438418)(DAT_00438418,&DAT_00428700,&DAT_00438424);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____query_interface_for_sur_0042d96c);
    }
    iVar1 = FUN_0040322f(2);
    if (iVar1 != 0) {
      DAT_0043844c = 1;
      local_8 = FUN_00402631(DAT_00438418,&DAT_00438430);
      FUN_004027f9(DAT_00438418,local_8);
    }
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar1 = (**(code **)(*DAT_00438418 + 0x74))(DAT_00438418,8,&local_10);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042d9ac);
    }
    DAT_00438460 = 1;
  }
  FUN_004015a6((byte *)s_init_palette_done_0042d9d4);
  FUN_0040e6fa();
  FUN_004037c9(2,0);
  FUN_004037c9(1,0);
  FUN_00401cf3();
  return;
}


/*
 * FUN_00403e9a at 00403e9a
 * undefined __stdcall FUN_00403e9a(void)
 * Address ranges: 00403e9a-00403f3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00403e9a(void)

{
  if (DAT_00438460 != 0) {
    FUN_004015a6((byte *)s_release_buffer_screen_0042d9e8);
    (**(code **)(*DAT_00438418 + 8))(DAT_00438418);
    DAT_00438460 = 0;
  }
  if ((DAT_0043845c != 0) && (DAT_0042c360 == 0)) {
    FUN_004015a6((byte *)s_release_back_screen_0042da00);
    (**(code **)(*DAT_00438438 + 8))(DAT_00438438);
    DAT_0043845c = 0;
  }
  if (DAT_00438458 != 0) {
    FUN_004015a6((byte *)s_release_primary_surface_0042da18);
    (**(code **)(*DAT_00438434 + 8))(DAT_00438434);
    DAT_00438458 = 0;
  }
  FUN_0040e7e0();
  return;
}


/*
 * FUN_00403f40 at 00403f40
 * undefined __stdcall FUN_00403f40(void)
 * Address ranges: 00403f40-00403f5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00403f40(void)

{
  HANDLE hProcess;
  
  hProcess = GetCurrentProcess();
  SetPriorityClass(hProcess,0x100);
  return;
}


/*
 * FUN_00403f60 at 00403f60
 * undefined4 __cdecl FUN_00403f60(HINSTANCE param_1, int param_2, LPCSTR param_3, LPCSTR param_4)
 * Address ranges: 00403f60-004042c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00403f60(HINSTANCE param_1,int param_2,LPCSTR param_3,LPCSTR param_4)

{
  int iVar1;
  int nWidth;
  HWND hWndParent;
  HMENU hMenu;
  LPVOID lpParam;
  int local_30;
  WNDCLASSA local_2c;
  
  FUN_0041f910(&local_30);
  FUN_0041f8e8(local_30);
  if (DAT_00438450 == 0) {
    local_2c.style = 3;
    local_2c.lpfnWndProc = FUN_0040aa20;
    local_2c.cbClsExtra = 0;
    local_2c.cbWndExtra = 0;
    local_2c.hInstance = param_1;
    local_2c.hIcon = LoadIconA(param_1,(LPCSTR)0x7f00);
    local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_2c.hbrBackground = (HBRUSH)0x0;
    local_2c.lpszMenuName = (LPCSTR)0x0;
    local_2c.lpszClassName = param_3;
    RegisterClassA(&local_2c);
    FUN_004015a6((byte *)s_____init_xvgalib_______version___0042da40);
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hWndParent = (HWND)0x0;
    iVar1 = GetSystemMetrics(1);
    nWidth = GetSystemMetrics(0);
    DAT_0043842c = CreateWindowExA(0x40000,param_3,param_4,0x80000000,0,0,nWidth,iVar1,hWndParent,
                                   hMenu,param_1,lpParam);
    if (DAT_0043842c == (HWND)0x0) {
      FUN_004015a6((byte *)s_failure_to_make_window_0042da64);
      return 0;
    }
    FUN_004015a6((byte *)s_window_defined_0042da7c);
    ShowWindow(DAT_0043842c,param_2);
    UpdateWindow(DAT_0043842c);
    DAT_00438450 = 1;
  }
  FUN_004015a6((byte *)s_starting_direct_draw_driver_sear_0042da8c);
  FUN_0040f523();
  FUN_004015a6((byte *)s_Finished_search_0042dab0);
  if (DAT_00438454 == 0) {
    FUN_004015a6((byte *)s_create_direct_draw_object_0042dac4);
    iVar1 = FUN_0040f551(DAT_0042c364);
    iVar1 = DirectDrawCreate(iVar1,&DAT_00438414,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_not_create_dd_obj_0042daec);
    }
    DAT_00438454 = 1;
  }
  if (DAT_00438464 == 0) {
    FUN_004015a6((byte *)s_set_cooperative_level_0042db18);
    iVar1 = (**(code **)(*DAT_00438414 + 0x50))(DAT_00438414,DAT_0043842c,DAT_0042c35c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_not_set_cooperati_0042db3c);
    }
    DAT_00438464 = 1;
  }
  iVar1 = (**(code **)*DAT_00438414)(DAT_00438414,&DAT_004286d0,&DAT_0043841c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_query_interfa_0042db78);
  }
  FUN_0040f71c();
  iVar1 = FUN_0040f789(DAT_0042c34c);
  if (iVar1 == 0) {
    FUN_004015a6((byte *)s_could_not_find_mode_0042dbac);
  }
  FUN_004015a6((byte *)s_set_display_mode__dx_dx_d_0042dbc4);
  iVar1 = (**(code **)(*DAT_0043841c + 0x54))
                    (DAT_0043841c,DAT_0042c350,DAT_0042c354,DAT_0042c358,0,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042dbec);
  }
  FUN_0040f7fd(0,0,DAT_0042c350,DAT_0042c354);
  FUN_004037f0();
  FUN_004015a6((byte *)s_screen_update_0042dc18);
  FUN_0040337e();
  FUN_004015a6((byte *)s_init_input_0042dc28);
  FUN_004015a6((byte *)s_system_info_0042dc34);
  FUN_0040ef12();
  return 1;
}


/*
 * FUN_004042c3 at 004042c3
 * undefined4 __cdecl FUN_004042c3(HINSTANCE param_1, int param_2, LPCSTR param_3, LPCSTR param_4, uint param_5)
 * Address ranges: 004042c3-00404625
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_004042c3(HINSTANCE param_1,int param_2,LPCSTR param_3,LPCSTR param_4,uint param_5)

{
  int iVar1;
  int nWidth;
  HWND hWndParent;
  HMENU hMenu;
  LPVOID lpParam;
  int local_30;
  WNDCLASSA local_2c;
  
  FUN_0041f910(&local_30);
  FUN_0041f8e8(local_30);
  if (DAT_00438450 == 0) {
    local_2c.style = 3;
    local_2c.lpfnWndProc = FUN_0040aa20;
    local_2c.cbClsExtra = 0;
    local_2c.cbWndExtra = 0;
    local_2c.hInstance = param_1;
    local_2c.hIcon = LoadIconA(param_1,(LPCSTR)0x7f00);
    local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_2c.hbrBackground = (HBRUSH)0x0;
    local_2c.lpszMenuName = (LPCSTR)(param_5 & 0xffff);
    local_2c.lpszClassName = param_3;
    RegisterClassA(&local_2c);
    FUN_004015a6((byte *)s_____init_xvgalib_____0042dc44);
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hWndParent = (HWND)0x0;
    iVar1 = GetSystemMetrics(1);
    nWidth = GetSystemMetrics(0);
    DAT_0043842c = CreateWindowExA(0x40000,param_3,param_4,0x80080000,0,0,nWidth,iVar1,hWndParent,
                                   hMenu,param_1,lpParam);
    if (DAT_0043842c == (HWND)0x0) {
      FUN_004015a6((byte *)s_failure_to_make_window_0042dc5c);
      return 0;
    }
    FUN_004015a6((byte *)s_window_defined_0042dc74);
    ShowWindow(DAT_0043842c,param_2);
    UpdateWindow(DAT_0043842c);
    DAT_00438450 = 1;
  }
  FUN_004015a6((byte *)s_starting_direct_draw_driver_sear_0042dc84);
  FUN_0040f523();
  FUN_004015a6((byte *)s_Finished_search_0042dca8);
  if (DAT_00438454 == 0) {
    FUN_004015a6((byte *)s_create_direct_draw_object_0042dcbc);
    iVar1 = FUN_0040f551(DAT_0042c364);
    iVar1 = DirectDrawCreate(iVar1,&DAT_00438414,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_not_create_dd_obj_0042dce4);
    }
    DAT_00438454 = 1;
  }
  if (DAT_00438464 == 0) {
    FUN_004015a6((byte *)s_set_cooperative_level_0042dd10);
    iVar1 = (**(code **)(*DAT_00438414 + 0x50))(DAT_00438414,DAT_0043842c,DAT_0042c35c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_not_set_cooperati_0042dd34);
    }
    DAT_00438464 = 1;
  }
  iVar1 = (**(code **)*DAT_00438414)(DAT_00438414,&DAT_004286d0,&DAT_0043841c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_query_interfa_0042dd70);
  }
  FUN_0040f71c();
  iVar1 = FUN_0040f789(DAT_0042c34c);
  if (iVar1 == 0) {
    FUN_004015a6((byte *)s_could_not_find_mode_0042dda4);
  }
  FUN_004015a6((byte *)s_set_display_mode__dx_dx_d_0042ddbc);
  iVar1 = (**(code **)(*DAT_0043841c + 0x54))
                    (DAT_0043841c,DAT_0042c350,DAT_0042c354,DAT_0042c358,0,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042dde4);
  }
  FUN_0040f7fd(0,0,DAT_0042c350,DAT_0042c354);
  FUN_004037f0();
  FUN_004015a6((byte *)s_screen_update_0042de10);
  FUN_0040337e();
  FUN_004015a6((byte *)s_init_input_0042de20);
  FUN_004015a6((byte *)s_system_info_0042de2c);
  FUN_0040ef12();
  return 1;
}


/*
 * FUN_00404626 at 00404626
 * undefined4 __cdecl FUN_00404626(int param_1)
 * Address ranges: 00404626-00404789
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00404626(int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (0x12 < param_1)) {
    FUN_0040187a((byte *)s__s__d____error_predefined_screen_0042de48);
  }
  iVar1 = FUN_0040f789(DAT_0042c34c);
  if (iVar1 == 0) {
    FUN_0040187a((byte *)s__s__d____mode_is_not_available_0042de98);
  }
  FUN_00403e9a();
  FUN_004015a6((byte *)s_Setting_display_mode_0042debc);
  DAT_0042c34c = param_1;
  DAT_0042c350 = *(int *)(&DAT_0042c368 + param_1 * 0x14);
  DAT_0042c354 = *(int *)(&DAT_0042c36c + param_1 * 0x14);
  DAT_0042c358 = *(undefined4 *)(&DAT_0042c370 + param_1 * 0x14);
  DAT_00438468 = *(undefined4 *)(&DAT_0042c374 + param_1 * 0x14);
  FUN_004015a6((byte *)s_Setting_display_mode___dx_dx_d_0042ded4);
  iVar1 = (**(code **)(*DAT_0043841c + 0x54))
                    (DAT_0043841c,DAT_0042c350,DAT_0042c354,DAT_0042c358,0,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042df00);
  }
  FUN_004015a6((byte *)s_Setting_display_mode_done_0042df2c);
  FUN_0040f7fd(0,0,DAT_0042c350,DAT_0042c354);
  FUN_004037f0();
  return 0;
}


/*
 * FUN_0040478a at 0040478a
 * undefined4 __fastcall FUN_0040478a(undefined4 param_1)
 * Address ranges: 0040478a-004047d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040478a(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_0043841c + 0x4c))(DAT_0043841c,param_1);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042df54);
  }
  return 0;
}


/*
 * FUN_004047e0 at 004047e0
 * undefined4 __stdcall FUN_004047e0(void)
 * Address ranges: 004047e0-00404806
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004047e0(void)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_type__mouse_n_0042dfb4);
  }
  return DAT_0042dfa4;
}


/*
 * FUN_00404807 at 00404807
 * undefined __cdecl FUN_00404807(int param_1)
 * Address ranges: 00404807-00404862
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404807(int param_1)

{
  if (DAT_00438488 != 0) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_type__Can_t_c_0042dff4);
  }
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_type__Unknow_0042e050);
  }
  else {
    DAT_0042dfa4 = param_1;
  }
  return;
}


/*
 * FUN_00404863 at 00404863
 * undefined4 __stdcall FUN_00404863(void)
 * Address ranges: 00404863-004049ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00404863(void)

{
  int iVar1;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_0042c4d0;
  local_c = DAT_0042c4d0;
  if (DAT_0042dfa4 == 1) {
    DAT_004384a8 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    if (DAT_004384a8 == (HCURSOR)0x0) {
      FUN_0040187a((byte *)s__s__d_____init_mouse__Unable_to_l_0042e090);
    }
  }
  else if (DAT_0042dfa4 == 2) {
    if (DAT_0042df9c == -1) {
      FUN_0040187a((byte *)s__s__d_____init_mouse__No_mouse_a_0042e0dc);
    }
    DAT_004384ac = (int *)FUN_004028e3(0x40,0x40);
    if (DAT_0043d754 == 0) {
      local_8 = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_8 = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_8 = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_c = local_8;
    iVar1 = (**(code **)(*DAT_004384ac + 0x74))(DAT_004384ac,8,&local_c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042e11c);
    }
  }
  DAT_00438488 = 1;
  return 1;
}


/*
 * FUN_004049ad at 004049ad
 * undefined4 __stdcall FUN_004049ad(void)
 * Address ranges: 004049ad-00404a0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004049ad(void)

{
  undefined4 uVar1;
  
  if (DAT_00438488 == 0) {
    uVar1 = 0;
  }
  else {
    if (((DAT_0042dfa4 != 1) && (DAT_0042dfa4 == 2)) && (DAT_004384ac != (int *)0x0)) {
      (**(code **)(*DAT_004384ac + 8))(DAT_004384ac);
      DAT_004384ac = (int *)0x0;
    }
    DAT_00438488 = 0;
    uVar1 = 1;
  }
  return uVar1;
}


/*
 * FUN_00404a0d at 00404a0d
 * undefined __stdcall FUN_00404a0d(void)
 * Address ranges: 00404a0d-00404a60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404a0d(void)

{
  int iVar1;
  
  if ((DAT_00438494 != 0) && (DAT_0043848c != 0)) {
    if ((DAT_0042dfa4 != 1) && (DAT_0042dfa4 == 2)) {
      iVar1 = FUN_00412061();
      FUN_004051d7(iVar1);
    }
    ShowCursor(0);
    DAT_00438494 = 0;
  }
  return;
}


/*
 * FUN_00404a61 at 00404a61
 * undefined4 __stdcall FUN_00404a61(void)
 * Address ranges: 00404a61-00404a80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00404a61(void)

{
  undefined4 uVar1;
  
  if ((DAT_0043848c == 0) || (DAT_00438494 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/*
 * FUN_00404a81 at 00404a81
 * undefined __stdcall FUN_00404a81(void)
 * Address ranges: 00404a81-00404aed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404a81(void)

{
  int iVar1;
  void *this;
  int local_8;
  
  if ((DAT_00438494 == 0) && (DAT_0043848c != 0)) {
    FUN_00404de4(&DAT_00438480,&DAT_00438484,&local_8);
    if ((DAT_0042dfa4 != 1) && (DAT_0042dfa4 == 2)) {
      iVar1 = FUN_00412061();
      FUN_0040555a(this,iVar1);
    }
    ShowCursor(1);
    DAT_00438494 = 1;
  }
  return;
}


/*
 * FUN_00404aee at 00404aee
 * undefined __stdcall FUN_00404aee(void)
 * Address ranges: 00404aee-00404b2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404aee(void)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____mouse_on__Mouse_is_not_0042e150);
  }
  if (DAT_0043848c == 0) {
    DAT_0043848c = 1;
    FUN_00404a81();
  }
  return;
}


/*
 * FUN_00404b2d at 00404b2d
 * undefined __stdcall FUN_00404b2d(void)
 * Address ranges: 00404b2d-00404b6b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404b2d(void)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____mouse_off__Mouse_is_no_0042e18c);
  }
  if (DAT_0043848c != 0) {
    FUN_00404a0d();
    DAT_0043848c = 0;
  }
  return;
}


/*
 * FUN_00404b6c at 00404b6c
 * undefined __cdecl FUN_00404b6c(int param_1, int param_2, undefined1 param_3)
 * Address ranges: 00404b6c-00404ced
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404b6c(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__You_ca_0042e1c8);
  }
  if ((param_1 < 0) || (DAT_00434c1c <= param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__illega_0042e21c);
  }
  if ((param_2 < 0) || (*(int *)(DAT_0043d858 + param_1 * 0xc) <= param_2)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__illega_0042e284);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043d858 + 8 + param_1 * 0xc) + 4 + param_2 * 8);
  if ((iVar1 < 0) || (DAT_00431b64 <= iVar1)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__image___0042e2ec);
  }
  if (*(int *)(DAT_0043d6e8 + iVar1 * 0x20) == 0) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__mouse_i_0042e33c);
  }
  if ((0x40 < *(int *)(DAT_0043d6e8 + 8 + iVar1 * 0x20)) ||
     (0x40 < *(int *)(DAT_0043d6e8 + 0xc + iVar1 * 0x20))) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__mouse_a_0042e3a0);
  }
  DAT_0042df9c = param_1;
  DAT_0042dfa0 = param_2;
  DAT_004384a4 = param_3;
  DAT_00438490 = 1;
  return;
}


/*
 * FUN_00404cee at 00404cee
 * undefined __cdecl FUN_00404cee(undefined4 * param_1, undefined4 * param_2, undefined1 * param_3)
 * Address ranges: 00404cee-00404d72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404cee(undefined4 *param_1,undefined4 *param_2,undefined1 *param_3)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_anim__Mouse_i_0042e3fc);
  }
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_anim__window_0042e43c);
  }
  if (DAT_00438490 == 0) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_anim__No_mou_0042e480);
  }
  *param_1 = DAT_0042df9c;
  *param_2 = DAT_0042dfa0;
  *param_3 = DAT_004384a4;
  return;
}


/*
 * FUN_00404d73 at 00404d73
 * undefined __cdecl FUN_00404d73(int param_1, int param_2)
 * Address ranges: 00404d73-00404da5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404d73(int param_1,int param_2)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_pos__Mouse_i_0042e4c4);
  }
  SetCursorPos(param_1,param_2);
  return;
}


/*
 * FUN_00404da6 at 00404da6
 * undefined __stdcall FUN_00404da6(void)
 * Address ranges: 00404da6-00404de3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404da6(void)

{
  int local_8;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____update_mouse_pos__Mous_0042e504);
  }
  FUN_00404de4(&DAT_00438480,&DAT_00438484,&local_8);
  return;
}


/*
 * FUN_00404de4 at 00404de4
 * undefined __cdecl FUN_00404de4(LONG * param_1, LONG * param_2, int * param_3)
 * Address ranges: 00404de4-00404e62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404de4(LONG *param_1,LONG *param_2,int *param_3)

{
  int iVar1;
  tagPOINT local_c;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_pos__Mouse_i_0042e548);
  }
  GetCursorPos(&local_c);
  *param_1 = local_c.x;
  *param_2 = local_c.y;
  *param_3 = 0;
  iVar1 = FUN_004133f0(1);
  if (iVar1 != 0) {
    *param_3 = 1;
  }
  iVar1 = FUN_004133f0(2);
  if (iVar1 != 0) {
    *param_3 = *param_3 + 2;
  }
  return;
}


/*
 * FUN_00404e63 at 00404e63
 * undefined __cdecl FUN_00404e63(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00404e63-00404e98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404e63(undefined4 param_1,undefined4 param_2)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_hotspot__Mou_0042e588);
  }
  DAT_00438498 = param_1;
  DAT_0043849c = param_2;
  return;
}


/*
 * FUN_00404e99 at 00404e99
 * undefined __cdecl FUN_00404e99(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 00404e99-00404ed2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00404e99(undefined4 *param_1,undefined4 *param_2)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_hotspot__Mou_0042e5cc);
  }
  *param_1 = DAT_00438498;
  *param_2 = DAT_0043849c;
  return;
}


/*
 * FUN_00404ed3 at 00404ed3
 * undefined __cdecl FUN_00404ed3(int param_1)
 * Address ranges: 00404ed3-004051d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00404ed3(int param_1)

{
  int iVar1;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_28 = *(int *)(*(int *)(DAT_0043d858 + 8 + DAT_0042df9c * 0xc) + 4 + DAT_0042dfa0 * 8);
  local_20 = DAT_00438480;
  local_24 = DAT_00438484;
  local_18 = DAT_00438480 + *(int *)(DAT_0043d6e8 + 8 + local_28 * 0x20);
  local_1c = DAT_00438484 + *(int *)(DAT_0043d6e8 + 0xc + local_28 * 0x20);
  if ((((-1 < local_18) && (DAT_00438480 <= DAT_0042c350)) && (-1 < local_1c)) &&
     (DAT_00438484 <= DAT_0042c354)) {
    if (DAT_00438480 < 0) {
      local_20 = 0;
    }
    if (DAT_00438484 < 0) {
      local_24 = 0;
    }
    if (DAT_0042c354 < local_1c) {
      local_1c = DAT_0042c354;
    }
    if (DAT_0042c350 < local_18) {
      local_18 = DAT_0042c350;
    }
    if ((local_20 < local_18) && (local_24 < local_1c)) {
      local_38 = local_20;
      local_34 = local_24;
      local_30 = local_18;
      local_2c = local_1c;
      local_14 = 0;
      local_10 = 0;
      local_c = local_18 - local_20;
      local_8 = local_1c - local_24;
      if (param_1 == 0) {
        FUN_004028c2(DAT_00438434);
        iVar1 = (**(code **)(*DAT_004384ac + 0x14))
                          (DAT_004384ac,&local_14,DAT_00438434,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____store_mouse_button__bl_0042e610);
        }
      }
      else if (param_1 == 1) {
        FUN_004028c2(DAT_00438438);
        iVar1 = (**(code **)(*DAT_004384ac + 0x14))
                          (DAT_004384ac,&local_14,DAT_00438438,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____store_mouse_button__bl_0042e6a0);
        }
      }
      else if (param_1 == 2) {
        FUN_004028c2(DAT_00438418);
        iVar1 = (**(code **)(*DAT_004384ac + 0x14))
                          (DAT_004384ac,&local_14,DAT_00438418,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____store_mouse_button__bl_0042e730);
        }
      }
      _DAT_0042df88 = DAT_0042df80;
      _DAT_0042df8c = DAT_0042df84;
      DAT_0042df80 = DAT_00438480;
      DAT_0042df84 = DAT_00438484;
    }
  }
  return;
}


/*
 * FUN_004051d7 at 004051d7
 * undefined __cdecl FUN_004051d7(int param_1)
 * Address ranges: 004051d7-004054ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004051d7(int param_1)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_28 = *(int *)(*(int *)(DAT_0043d858 + 8 + DAT_0042df9c * 0xc) + 4 + DAT_0042dfa0 * 8);
  local_20 = DAT_0042df80;
  local_24 = DAT_0042df84;
  local_18 = DAT_0042df80 + *(int *)(DAT_0043d6e8 + 8 + local_28 * 0x20);
  local_1c = DAT_0042df84 + *(int *)(DAT_0043d6e8 + 0xc + local_28 * 0x20);
  if ((((-1 < local_18) && (DAT_0042df80 <= DAT_0042c350)) && (-1 < local_1c)) &&
     (DAT_0042df84 <= DAT_0042c354)) {
    if (DAT_0042df80 < 0) {
      local_20 = 0;
    }
    if (DAT_0042df84 < 0) {
      local_24 = 0;
    }
    if (DAT_0042c354 < local_1c) {
      local_1c = DAT_0042c354;
    }
    if (DAT_0042c350 < local_18) {
      local_18 = DAT_0042c350;
    }
    if ((local_20 < local_18) && (local_24 < local_1c)) {
      local_38 = 0;
      local_34 = 0;
      local_30 = local_18 - local_20;
      local_2c = local_1c - local_24;
      local_14 = local_20;
      local_10 = local_24;
      local_c = local_18;
      local_8 = local_1c;
      if (param_1 == 0) {
        FUN_004028c2(DAT_00438434);
        iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                          (DAT_00438434,&local_14,DAT_004384ac,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____restore_mouse_button__b_0042e7c0);
        }
      }
      else if (param_1 == 1) {
        FUN_004028c2(DAT_00438438);
        iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                          (DAT_00438438,&local_14,DAT_004384ac,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____restore_mouse_button__b_0042e850);
        }
      }
      else if (param_1 == 2) {
        FUN_004028c2(DAT_00438418);
        iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                          (DAT_00438418,&local_14,DAT_004384ac,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____restore_mouse_button__b_0042e8e0);
        }
      }
    }
  }
  return;
}


/*
 * FUN_004054ad at 004054ad
 * undefined __thiscall FUN_004054ad(void * this, int param_1)
 * Address ranges: 004054ad-00405559
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_004054ad(void *this,int param_1)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__Mouse_is_n_0042e970);
  }
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__You_can_t_c_0042e9ac);
  }
  if ((DAT_0042dfa4 == 2) && (DAT_00438490 == 0)) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__No_mouse_a_0042e9fc);
  }
  if ((DAT_0042df80 != -1) && (DAT_0042df84 != -1)) {
    FUN_004051d7(param_1);
  }
  return;
}


/*
 * FUN_0040555a at 0040555a
 * undefined __thiscall FUN_0040555a(void * this, int param_1)
 * Address ranges: 0040555a-00405613
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0040555a(void *this,int param_1)

{
  int iVar1;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__Mouse_is_n_0042ea3c);
  }
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__You_can_t_c_0042ea78);
  }
  if ((DAT_0042dfa4 == 2) && (DAT_00438490 == 0)) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__No_mouse_a_0042eac8);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043d858 + 8 + DAT_0042df9c * 0xc) + 4 + DAT_0042dfa0 * 8);
  FUN_00404ed3(param_1);
  FUN_004105ee(param_1,iVar1,DAT_00438480,DAT_00438484,3);
  return;
}


/*
 * FUN_00405614 at 00405614
 * undefined4 __stdcall FUN_00405614(void)
 * Address ranges: 00405614-004056c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00405614(void)

{
  int iVar1;
  void *this;
  void *this_00;
  int local_8;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____handle_mouse__Mouse_is_0042eb08);
  }
  FUN_00404de4(&DAT_00438480,&DAT_00438484,&local_8);
  if ((DAT_0043848c != 0) && (DAT_00438494 != 0)) {
    if (DAT_0042dfa4 == 1) {
      SetCursor(DAT_004384a8);
    }
    else if ((DAT_0042dfa4 == 2) &&
            ((DAT_0042df80 != DAT_00438480 || (DAT_0042df84 != DAT_00438484)))) {
      iVar1 = FUN_00412061();
      FUN_004054ad(this,iVar1);
      iVar1 = FUN_00412061();
      FUN_0040555a(this_00,iVar1);
    }
  }
  return 0;
}


/*
 * FUN_004056d0 at 004056d0
 * undefined __cdecl FUN_004056d0(uint * param_1)
 * Address ranges: 004056d0-00405761
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004056d0(uint *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen((char *)param_1);
  if (sVar1 != 0) {
    sVar1 = _strlen((char *)param_1);
    if (sVar1 < 0x10) goto LAB_00405708;
  }
  FUN_0040187a((byte *)s__set_ini_filename___s__d____file_0042eb48);
LAB_00405708:
  FUN_00427ae4((uint *)&DAT_0043d2d0,0x118);
  sVar1 = _strlen(&DAT_0043d2d0);
  if ((&DAT_0043d2cf)[sVar1] != '\\') {
    FUN_0041f7b0((uint *)&DAT_0043d2d0,(uint *)&DAT_0042eb84);
  }
  FUN_0041f7b0((uint *)&DAT_0043d2d0,param_1);
  DAT_0043d3fc = 1;
  return;
}


/*
 * FUN_00405762 at 00405762
 * undefined __cdecl FUN_00405762(char * param_1)
 * Address ranges: 00405762-004057bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00405762(char *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  if (sVar1 != 0) {
    sVar1 = _strlen(param_1);
    if (sVar1 < 0x12d) goto LAB_0040579c;
  }
  FUN_0040187a((byte *)s__set_ini_filename___s__d____file_0042eb94);
LAB_0040579c:
  _strncpy(&DAT_0043d2d0,param_1,299);
  DAT_0043d3fc = 1;
  return;
}


/*
 * FUN_004057be at 004057be
 * undefined __cdecl FUN_004057be(LPCSTR param_1, LPCSTR param_2, LPCSTR param_3)
 * Address ranges: 004057be-004057f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004057be(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

{
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__write_ini_string_setting___s__d_0042ebdc);
  }
  WritePrivateProfileStringA(param_1,param_2,param_3,&DAT_0043d2d0);
  return;
}


/*
 * FUN_004057f7 at 004057f7
 * undefined __cdecl FUN_004057f7(LPCSTR param_1, LPCSTR param_2, uint param_3)
 * Address ranges: 004057f7-00405849
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004057f7(LPCSTR param_1,LPCSTR param_2,uint param_3)

{
  char local_28 [36];
  
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__write_ini_value_setting___s__d__0042ec34);
  }
  FUN_00427bff(param_3,local_28,10);
  WritePrivateProfileStringA(param_1,param_2,local_28,&DAT_0043d2d0);
  return;
}


/*
 * FUN_0040584a at 0040584a
 * undefined __cdecl FUN_0040584a(LPCSTR param_1, LPCSTR param_2)
 * Address ranges: 0040584a-00405883
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040584a(LPCSTR param_1,LPCSTR param_2)

{
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__read_ini_value_setting___s__d____0042ec8c);
  }
  GetPrivateProfileIntA(param_1,param_2,0,&DAT_0043d2d0);
  return;
}


/*
 * FUN_00405884 at 00405884
 * undefined __cdecl FUN_00405884(LPCSTR param_1, LPCSTR param_2, LPSTR param_3, DWORD param_4)
 * Address ranges: 00405884-004058c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00405884(LPCSTR param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4)

{
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__read_ini_string_setting___s__d__0042ece4);
  }
  GetPrivateProfileStringA(param_1,param_2,&DAT_0043d404,param_3,param_4,&DAT_0043d2d0);
  return;
}


/*
 * FUN_004058c9 at 004058c9
 * int __cdecl FUN_004058c9(byte * param_1, uint * param_2)
 * Address ranges: 004058c9-00405a3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_004058c9(byte *param_1,uint *param_2)

{
  uint *puVar1;
  int local_dc;
  uint local_d8 [50];
  ushort local_10 [2];
  int local_c;
  uint local_8;
  
  local_dc = 0;
  local_c = 0;
  local_10[0] = DAT_0042ed30;
  local_8 = DAT_0042ed34;
  if (param_2 == (uint *)0x0) {
    param_2 = &local_8;
  }
  for (; *param_1 != 0; param_1 = param_1 + 1) {
    local_10[0] = (ushort)*param_1;
    puVar1 = FUN_0041fb70(param_2,(char *)local_10);
    if (puVar1 == (uint *)0x0) {
      *(byte *)((int)local_d8 + local_c) = *param_1;
      local_c = local_c + 1;
      if (0xc6 < local_c) {
        FUN_0040187a((byte *)s__get_ini_arguments_online___s__d_0042ed9c);
      }
    }
    else {
      *(undefined1 *)((int)local_d8 + local_c) = 0;
      FUN_0041f7a0((uint *)(&DAT_004384b0 + local_dc * 200),local_d8);
      local_dc = local_dc + 1;
      if (100 < local_dc) {
        FUN_0040187a((byte *)s__get_ini_arguments_online___s__d_0042ed44);
      }
      local_c = 0;
    }
  }
  *(undefined1 *)((int)local_d8 + local_c) = 0;
  FUN_0041f7a0((uint *)(&DAT_004384b0 + local_dc * 200),local_d8);
  DAT_0043d400 = local_dc + 1;
  return local_dc + 1;
}


/*
 * FUN_00405a3c at 00405a3c
 * undefined __thiscall FUN_00405a3c(void * this, int param_1)
 * Address ranges: 00405a3c-00405a8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_00405a3c(void *this,int param_1)

{
  void *extraout_ECX;
  
  if ((param_1 < 0) || (DAT_0043d400 < param_1)) {
    FUN_0040187a((byte *)s__get_ini_argument_value___s__d____0042edfc);
    this = extraout_ECX;
  }
  FUN_0041fc7b(this,&DAT_004384b0 + param_1 * 200);
  return;
}


/*
 * FUN_00405a8b at 00405a8b
 * undefined __cdecl FUN_00405a8b(int param_1, char * param_2, size_t param_3)
 * Address ranges: 00405a8b-00405ae2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00405a8b(int param_1,char *param_2,size_t param_3)

{
  if ((param_1 < 0) || (DAT_0043d400 < param_1)) {
    FUN_0040187a((byte *)s__get_ini_argument_value___s__d____0042ee4c);
  }
  _strncpy(param_2,&DAT_004384b0 + param_1 * 200,param_3);
  return;
}


/*
 * FUN_00405af0 at 00405af0
 * char * __cdecl FUN_00405af0(int param_1)
 * Address ranges: 00405af0-00405bb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_00405af0(int param_1)

{
  if (param_1 < -0x7ffbfeef) {
    if (param_1 == -0x7ffbfef0) {
      return s_object_doesn_t_support_aggregati_0042f080;
    }
    if (param_1 == -0x7fffbfff) {
      return s_this_function_is_not_supported_a_0042f154;
    }
  }
  else if (param_1 < -0x7ff8ffa8) {
    if (param_1 == -0x7ff8ffa9) {
      return s_invalid_parameters_passed_to_thi_0042efec;
    }
    if (param_1 == -0x7ff8fff2) {
      return s_not_enough_memory_free_for_the_d_0042f0a4;
    }
  }
  else {
    switch(param_1) {
    case -0x7787fff6:
      return s_request_failed_because_resources_0042ef78;
    case -0x7787ffce:
      return s_this_function_is_not_valid_for_t_0042f018;
    case -0x7787ffba:
      return s_caller_doesn_t_have_the_priority_0042f0dc;
    case -0x7787ff9c:
      return s_specified_format_is_not_supporte_0042efc8;
    case -0x7787ff88:
      return s_no_sound_driver_is_installed_ava_0042f058;
    case -0x7787ff56:
      return s_unitialized_error___call_the_ini_0042f11c;
    }
  }
  return s_error_unidentified_0042f180;
}


/*
 * FUN_00405c6e at 00405c6e
 * undefined4 __cdecl FUN_00405c6e(int param_1)
 * Address ranges: 00405c6e-00405cd2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00405c6e(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_0043d438 == 0) {
    DAT_0043d41c = LocalAlloc(0x40,param_1 * 0xd8);
    if (DAT_0043d41c == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_re_0042f194);
      uVar1 = 2000;
    }
    else {
      DAT_0043d430 = param_1;
      DAT_0043d434 = 0;
      DAT_0043d438 = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_00405cd3 at 00405cd3
 * int __stdcall FUN_00405cd3(void)
 * Address ranges: 00405cd3-00405cfd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00405cd3(void)

{
  int iVar1;
  
  if (DAT_0043d434 < DAT_0043d430) {
    iVar1 = DAT_0043d434;
    DAT_0043d434 = DAT_0043d434 + 1;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


/*
 * FUN_00405cfe at 00405cfe
 * undefined4 __stdcall FUN_00405cfe(undefined4 * param_1, uint * param_2, uint * param_3)
 * Address ranges: 00405cfe-00405e1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00405cfe(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *_Str1;
  undefined4 *puVar4;
  
  iVar1 = FUN_00405cd3();
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    FUN_004015a6((byte *)s__s___s_0042f1cc);
    FUN_0041f7a0((uint *)(DAT_0043d41c + 0x10 + iVar1 * 0xd8),param_2);
    FUN_0041f7a0((uint *)(DAT_0043d41c + 0x74 + iVar1 * 0xd8),param_3);
    iVar3 = __strcmpi((char *)param_3,s_SB16_VXD_0042f1d4);
    if (iVar3 == 0) {
      FUN_004015a6((byte *)s_sb16_driver_found__d_0042f1e0);
      DAT_0042ef70 = iVar1;
    }
    _Str1 = _strrchr((char *)param_3,0x2e);
    if (_Str1 != (char *)0x0) {
      iVar3 = __strcmpi(_Str1,&DAT_0042f1f8);
      if (iVar3 == 0) {
        FUN_004015a6((byte *)s_secondary_driver_found__d_0042f200);
        DAT_0042ef74 = iVar1;
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      puVar4 = (undefined4 *)(DAT_0043d41c + iVar1 * 0xd8);
      *puVar4 = *param_1;
      puVar4[1] = param_1[1];
      puVar4[2] = param_1[2];
      puVar4[3] = param_1[3];
    }
    uVar2 = 1;
  }
  return uVar2;
}


/*
 * FUN_00405e1d at 00405e1d
 * int __stdcall FUN_00405e1d(void)
 * Address ranges: 00405e1d-00405e4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00405e1d(void)

{
  int iVar1;
  
  iVar1 = FUN_00405c6e(0x14);
  if (iVar1 == 0) {
    Ordinal_2(FUN_00405cfe,0);
    iVar1 = 0;
  }
  return iVar1;
}


/*
 * FUN_00405e4b at 00405e4b
 * undefined4 __cdecl FUN_00405e4b(int param_1, undefined2 param_2, int param_3, int param_4)
 * Address ranges: 00405e4b-00405fa8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00405e4b(int param_1,undefined2 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined2 local_2c;
  short local_2a;
  int local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_c;
  int local_8;
  
  _memset(&local_2c,0,0x10);
  local_2c = 1;
  local_2a = (param_4 != 0) + 1;
  local_28 = param_1;
  local_20 = (undefined2)param_3;
  local_24 = param_3 * param_1;
  local_1e = param_2;
  _memset(&local_1c,0,0x14);
  local_1c = 0x14;
  local_18 = 1;
  local_14 = 0;
  local_c = 0;
  local_8 = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_1c,&DAT_0043d418,0);
  if (local_8 == 0) {
    local_8 = (**(code **)(*DAT_0043d418 + 0x38))(DAT_0043d418,&local_2c);
    if (local_8 == 0) {
      local_8 = (**(code **)(*DAT_0043d418 + 0x30))(DAT_0043d418,0,0,1);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____error_starting_primary_s_0042f294);
      }
      uVar1 = 0;
    }
    else {
      FUN_00405af0(local_8);
      FUN_004015a6((byte *)s__s__d____error_setting_format____0042f260);
      uVar1 = 0x2afa;
    }
  }
  else {
    FUN_00405af0(local_8);
    FUN_004015a6((byte *)s__s__d____error_creating_sound_bu_0042f228);
    uVar1 = 0x2afa;
  }
  return uVar1;
}


/*
 * FUN_00405fa9 at 00405fa9
 * undefined4 __cdecl FUN_00405fa9(int param_1, undefined2 param_2, int param_3, int param_4)
 * Address ranges: 00405fa9-00406106
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00405fa9(int param_1,undefined2 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined2 local_2c;
  short local_2a;
  int local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_c;
  int local_8;
  
  _memset(&local_2c,0,0x10);
  local_2c = 1;
  local_2a = (param_4 != 0) + 1;
  local_28 = param_1;
  local_20 = (undefined2)param_3;
  local_24 = param_3 * param_1;
  local_1e = param_2;
  _memset(&local_1c,0,0x14);
  local_1c = 0x14;
  local_18 = 0x11;
  local_14 = 0;
  local_c = 0;
  local_8 = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_1c,&DAT_0043d418,0);
  if (local_8 == 0) {
    local_8 = (**(code **)(*DAT_0043d418 + 0x38))(DAT_0043d418,&local_2c);
    if (local_8 == 0) {
      local_8 = (**(code **)(*DAT_0043d418 + 0x30))(DAT_0043d418,0,0,1);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____error_starting_primary_s_0042f340);
      }
      uVar1 = 0;
    }
    else {
      FUN_00405af0(local_8);
      FUN_004015a6((byte *)s__s__d____error_setting_format____0042f30c);
      uVar1 = 0x2afa;
    }
  }
  else {
    FUN_00405af0(local_8);
    FUN_004015a6((byte *)s__s__d____error_creating_sound_bu_0042f2d4);
    uVar1 = 0x2afa;
  }
  return uVar1;
}


/*
 * FUN_00406107 at 00406107
 * undefined4 __cdecl FUN_00406107(undefined4 param_1, int param_2, undefined2 param_3, int param_4, int param_5)
 * Address ranges: 00406107-004061ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00406107(undefined4 param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined2 local_30;
  short local_2e;
  int local_2c;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 *local_10;
  int local_c;
  undefined4 local_8;
  
  _memset(&local_30,0,0x10);
  local_30 = 1;
  local_2e = (param_5 != 0) + 1;
  local_2c = param_2;
  local_24 = (undefined2)param_4;
  local_28 = param_4 * param_2;
  local_22 = param_3;
  _memset(&local_20,0,0x14);
  local_20 = 0x14;
  local_1c = 0xe8;
  local_18 = param_1;
  local_10 = &local_30;
  local_c = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_20,&local_8,0);
  if (local_c != 0) {
    FUN_00405af0(local_c);
    FUN_0040187a((byte *)s__s__d____error_creating_sound_bu_0042f380);
  }
  return local_8;
}


/*
 * FUN_004061cb at 004061cb
 * undefined4 __cdecl FUN_004061cb(undefined4 * param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined2 param_5, int param_6, int param_7)
 * Address ranges: 004061cb-004062d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_004061cb(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined2 param_5,int param_6,int param_7)

{
  undefined2 local_2c;
  short local_2a;
  int local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 *local_c;
  int local_8;
  
  _memset(&local_2c,0,0x10);
  local_2c = 1;
  local_2a = (param_7 != 0) + 1;
  local_28 = param_4;
  local_20 = (undefined2)param_6;
  local_24 = param_6 * param_4;
  local_1e = param_5;
  _memset(&local_1c,0,0x14);
  local_1c = 0x14;
  local_18 = 0xb8;
  local_14 = param_3;
  local_c = &local_2c;
  local_8 = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_1c,param_1,0);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_creating_sound_bu_0042f3b8);
  }
  local_8 = (*(code *)**(undefined4 **)*param_1)(*param_1,&DAT_004298c0,param_2);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_creating_3d_sound_0042f3f0);
  }
  return 0;
}


/*
 * FUN_004062d3 at 004062d3
 * undefined4 __cdecl FUN_004062d3(undefined4 param_1)
 * Address ranges: 004062d3-00406326
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004062d3(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = (**(code **)(*DAT_0043d410 + 0x14))(DAT_0043d410,param_1,&local_8);
  if (iVar1 != 0) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_duplicating_sound_0042f42c);
  }
  return local_8;
}


/*
 * FUN_00406327 at 00406327
 * undefined4 __cdecl FUN_00406327(int param_1)
 * Address ranges: 00406327-004063f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00406327(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_0042f468);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      uVar1 = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____getting_sound_status_fa_0042f4a8);
      }
      if ((local_c & 1) == 1) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_004063fa at 004063fa
 * undefined4 __cdecl FUN_004063fa(int param_1)
 * Address ranges: 004063fa-00406649
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004063fa(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_0042f4e4);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      uVar1 = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____getting_sound_status_fa_0042f524);
      }
      if ((local_c & 1) == 1) {
        if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 1) {
          local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x48))
                              (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
          if (local_8 != 0) {
            FUN_00405af0(local_8);
            FUN_0040187a((byte *)s__s__d____error_stopping_sound_bu_0042f560);
          }
          if ((local_c & 4) == 0) {
            *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 2;
          }
          else {
            *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 3;
          }
        }
        else {
          if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 3) {
            local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x30))
                                (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0,0,1);
            if (local_8 != 0) {
              FUN_00405af0(local_8);
              FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_0042f598);
            }
          }
          else {
            local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x30))
                                (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0,0,0);
            if (local_8 != 0) {
              FUN_00405af0(local_8);
              FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_0042f5d4);
            }
          }
          *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 1;
        }
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_0040664a at 0040664a
 * undefined4 __stdcall FUN_0040664a(void)
 * Address ranges: 0040664a-0040669f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040664a(void)

{
  undefined4 local_8;
  
  if (DAT_0043d43c != 0) {
    for (local_8 = 0; local_8 < DAT_0043d414; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) {
        FUN_004063fa(local_8);
      }
    }
  }
  return 0;
}


/*
 * FUN_004066a0 at 004066a0
 * undefined4 __cdecl FUN_004066a0(int param_1)
 * Address ranges: 004066a0-0040681c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004066a0(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_0042f610);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      uVar1 = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____getting_sound_status_fa_0042f650);
      }
      if ((local_c & 1) == 1) {
        local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x48))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
        if (local_8 != 0) {
          FUN_00405af0(local_8);
          FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_0042f68c);
        }
        local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x34))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0);
        if (local_8 != 0) {
          FUN_00405af0(local_8);
          FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_0042f6c8);
        }
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_0040681d at 0040681d
 * undefined4 __stdcall FUN_0040681d(void)
 * Address ranges: 0040681d-00406872
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040681d(void)

{
  undefined4 local_8;
  
  if (DAT_0043d43c != 0) {
    for (local_8 = 0; local_8 < DAT_0043d414; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) {
        FUN_004066a0(local_8);
      }
    }
  }
  return 0;
}


/*
 * FUN_00406873 at 00406873
 * undefined4 __stdcall FUN_00406873(void)
 * Address ranges: 00406873-00406950
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00406873(void)

{
  undefined4 local_8;
  
  if (DAT_0043d43c != 0) {
    FUN_0040681d();
    for (local_8 = 0; local_8 < DAT_0043d414; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) {
        if (*(int *)(DAT_0043d420 + 0x34 + local_8 * 0x44) == 1) {
          (**(code **)(**(int **)(DAT_0043d420 + 0x2c + local_8 * 0x44) + 8))
                    (*(undefined4 *)(DAT_0043d420 + 0x2c + local_8 * 0x44));
        }
        (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_8 * 0x44) + 8))
                  (*(undefined4 *)(DAT_0043d420 + 0x28 + local_8 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_8 * 0x44) = 0;
        *(undefined4 *)(DAT_0043d420 + 0x38 + local_8 * 0x44) = 0;
      }
    }
  }
  return 0;
}


/*
 * FUN_00406951 at 00406951
 * undefined4 __cdecl FUN_00406951(int param_1)
 * Address ranges: 00406951-00406a0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00406951(int param_1)

{
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_0042f704);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      FUN_004066a0(param_1);
      (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 8))
                (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
      *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 0;
      *(undefined4 *)(DAT_0043d420 + 0x38 + param_1 * 0x44) = 0;
    }
  }
  return 0;
}


/*
 * FUN_00406a0b at 00406a0b
 * int __cdecl FUN_00406a0b(char * param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00406a0b-00406a84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00406a0b(char *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_3;
  do {
    if (DAT_0043d414 <= local_8) {
      return -1;
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) &&
       (iVar1 = __strcmpi((char *)(DAT_0043d420 + local_8 * 0x44),param_1), iVar1 == 0)) {
      if (param_4 == 0) {
        return local_8;
      }
      iVar1 = FUN_00406327(local_8);
      if (iVar1 == 0) {
        return local_8;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


/*
 * FUN_00406a85 at 00406a85
 * int __stdcall FUN_00406a85(void)
 * Address ranges: 00406a85-00406ae7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00406a85(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0043d414 <= local_8) {
      return -1;
    }
    if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) == 0) break;
    FUN_004015a6((byte *)s__d_used__d_0042f738);
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_00406ae8 at 00406ae8
 * int __cdecl FUN_00406ae8(int param_1)
 * Address ranges: 00406ae8-00406b5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00406ae8(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0043d414 <= local_8) {
      return -1;
    }
    if ((*(int *)(DAT_0043d420 + 0x34 + local_8 * 0x44) == param_1) &&
       (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) == 0)) break;
    FUN_004015a6((byte *)s__d_used__d_0042f744);
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_00406b5f at 00406b5f
 * uint __cdecl FUN_00406b5f(uint param_1)
 * Address ranges: 00406b5f-00406d13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_00406b5f(uint param_1)

{
  int iVar1;
  uint local_10;
  uint local_c;
  
  local_c = (uint)(param_1 == 0);
  for (local_10 = 0; (int)local_10 < DAT_0043d414; local_10 = local_10 + 1) {
    if ((((local_10 != local_c) && (local_10 != param_1)) &&
        (iVar1 = FUN_00406327(local_10), iVar1 == 0)) &&
       (*(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) <
        *(int *)(DAT_0043d420 + 0x38 + local_c * 0x44))) {
      local_c = local_10;
    }
  }
  FUN_004015a6((byte *)s_deleting__d_0042f750);
  iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 0x48))
                    (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44));
  if (iVar1 != 0) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_0042f76c);
  }
  (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 8))
            (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44));
  *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 0;
  *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = 0;
  for (local_10 = 0; (int)local_10 < DAT_0043d414; local_10 = local_10 + 1) {
    if (((*(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) != 10000) && (local_10 != local_c)) &&
       (1 < *(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44))) {
      *(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) =
           *(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) + -1;
    }
  }
  return local_c;
}


/*
 * FUN_00406d14 at 00406d14
 * undefined __stdcall FUN_00406d14(void)
 * Address ranges: 00406d14-00406d7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406d14(void)

{
  if (DAT_0043d43c != 0) {
    FUN_00406873();
    (**(code **)(*DAT_0043d410 + 8))(DAT_0043d410);
    LocalReAlloc(DAT_0043d420,0,2);
    DAT_0043d43c = 0;
    DAT_0043d440 = 0;
    DAT_0043d444 = 0;
    DAT_0043d448 = 0;
    DAT_0043d44c = 0;
  }
  return;
}


/*
 * FUN_00406d7c at 00406d7c
 * undefined4 __cdecl FUN_00406d7c(int param_1)
 * Address ranges: 00406d7c-00406e0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00406d7c(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0xd;
  while( true ) {
    if (local_8 < 1) {
      return 0;
    }
    iVar1 = FUN_00406e0e(param_1,local_8);
    if (iVar1 == 0x2af9) break;
    if (iVar1 != 0x2afa) {
      FUN_004015a6((byte *)s_Sound_mode_used___d___freq__d__b_0042f79c);
      return 1;
    }
    local_8 = local_8 + -1;
  }
  return 0;
}


/*
 * FUN_00406e0e at 00406e0e
 * undefined4 __cdecl FUN_00406e0e(int param_1, int param_2)
 * Address ranges: 00406e0e-004071b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00406e0e(int param_1,int param_2)

{
  int iVar1;
  int local_c;
  
  FUN_00405e1d();
  if (DAT_0043d43c != 0) {
    return 0;
  }
  if (DAT_0043d440 == 0) {
    if (DAT_0042ef70 == -1) {
      if (DAT_0042ef74 == -1) {
        FUN_004015a6((byte *)s_Using_default_driver_0042f8e8);
        iVar1 = Ordinal_1(0,&DAT_0043d410,0);
        if (iVar1 != 0) {
          FUN_00405af0(iVar1);
          FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042f90c);
          return 0x2af9;
        }
        DAT_0043d440 = 1;
        FUN_004015a6((byte *)s_Default_driver_init_failure___No_0042f938);
      }
      else {
        FUN_004015a6((byte *)s_Attempting_to_use_secondary_driv_0042f854);
        iVar1 = Ordinal_1(DAT_0043d41c + DAT_0042ef74 * 0xd8,&DAT_0043d410,0);
        if (iVar1 != 0) {
          FUN_00405af0(iVar1);
          FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042f884);
          return 0x2af9;
        }
        DAT_0043d440 = 1;
        FUN_004015a6((byte *)s_Attempting_to_use_secondary__unk_0042f8b0);
      }
    }
    else {
      FUN_004015a6((byte *)s_Attempting_to_use_sb16_driver_0042f7d0);
      iVar1 = Ordinal_1(DAT_0043d41c + DAT_0042ef70 * 0xd8,&DAT_0043d410,0);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042f7fc);
        return 0x2af9;
      }
      DAT_0043d440 = 1;
      FUN_004015a6((byte *)s_Attempting_to_use_sb16_driver_su_0042f828);
    }
  }
  if (DAT_0043d444 == 0) {
    iVar1 = (**(code **)(*DAT_0043d410 + 0x18))(DAT_0043d410,DAT_0043842c,3);
    if ((iVar1 != 0) != 0) {
      FUN_00405af0((uint)(iVar1 != 0));
      FUN_004015a6((byte *)s__s__d____error_setting_the_coop_l_0042f96c);
      return 0x2af9;
    }
    DAT_0043d444 = 1;
  }
  if (DAT_0043d448 == 0) {
    DAT_0043d420 = LocalAlloc(0x40,param_1 * 0x44);
    if (DAT_0043d420 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_cr_0042f9a8);
    }
    DAT_0043d448 = 1;
  }
  DAT_0043d414 = param_1;
  for (local_c = 0; local_c < param_1; local_c = local_c + 1) {
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x30) = 0;
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x38) = 0;
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x34) = 0;
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x40) = 0xffffffff;
  }
  if ((param_2 < 0) || (0xd < param_2)) {
    FUN_0040187a((byte *)s__s__d____error_illegal_sound_mod_0042f9e0);
  }
  if ((param_2 != 0xe) && (DAT_0043d44c == 0)) {
    iVar1 = FUN_00405e4b(*(int *)(&DAT_0042ee90 + param_2 * 0x10),
                         (short)*(undefined4 *)(&DAT_0042ee94 + param_2 * 0x10),
                         *(int *)(&DAT_0042ee9c + param_2 * 0x10),
                         *(int *)(&DAT_0042ee98 + param_2 * 0x10));
    if (iVar1 != 0) {
      return 0x2afa;
    }
    FUN_004015a6((byte *)s_setting_sound_format__dHz__dbits_0042fa20);
    DAT_0043d44c = 1;
  }
  DAT_0043d43c = 1;
  return 0;
}


/*
 * FUN_004071b3 at 004071b3
 * undefined4 __cdecl FUN_004071b3(int param_1, int param_2, int param_3)
 * Address ranges: 004071b3-004075e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004071b3(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_c;
  
  FUN_00405e1d();
  if (DAT_0043d43c != 0) {
    return 0;
  }
  if (DAT_0043d440 == 0) {
    if (DAT_0042ef70 == -1) {
      if (DAT_0042ef74 == -1) {
        FUN_004015a6((byte *)s_Using_default_driver_0042fb60);
        iVar1 = Ordinal_1(0,&DAT_0043d410,0);
        if (iVar1 != 0) {
          FUN_00405af0(iVar1);
          FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042fb84);
          return 0x2af9;
        }
        DAT_0043d440 = 1;
        FUN_004015a6((byte *)s_Default_driver_init_failure___No_0042fbb0);
      }
      else {
        FUN_004015a6((byte *)s_Attempting_to_use_secondary_driv_0042facc);
        iVar1 = Ordinal_1(DAT_0043d41c + DAT_0042ef74 * 0xd8,&DAT_0043d410,0);
        if (iVar1 != 0) {
          FUN_00405af0(iVar1);
          FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042fafc);
          return 0x2af9;
        }
        DAT_0043d440 = 1;
        FUN_004015a6((byte *)s_Attempting_to_use_secondary__unk_0042fb28);
      }
    }
    else {
      FUN_004015a6((byte *)s_Attempting_to_use_sb16_driver_0042fa48);
      iVar1 = Ordinal_1(DAT_0043d41c + DAT_0042ef70 * 0xd8,&DAT_0043d410,0);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042fa74);
        return 0x2af9;
      }
      DAT_0043d440 = 1;
      FUN_004015a6((byte *)s_Attempting_to_use_sb16_driver_su_0042faa0);
    }
  }
  if (DAT_0043d444 == 0) {
    iVar1 = (**(code **)(*DAT_0043d410 + 0x18))(DAT_0043d410,DAT_0043842c,3);
    if ((iVar1 != 0) != 0) {
      FUN_00405af0((uint)(iVar1 != 0));
      FUN_004015a6((byte *)s__s__d____error_setting_the_coop_l_0042fbe4);
      return 0x2af9;
    }
    DAT_0043d444 = 1;
  }
  if (DAT_0043d448 == 0) {
    DAT_0043d414 = param_1 + param_2;
    DAT_0043d420 = LocalAlloc(0x40,DAT_0043d414 * 0x44);
    if (DAT_0043d420 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_cr_0042fc20);
    }
    DAT_0043d448 = 1;
  }
  FUN_004015a6((byte *)s_sound_init_0042fc58);
  for (local_c = 0; local_c < DAT_0043d414; local_c = local_c + 1) {
    if (local_c < param_2) {
      *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x34) = 1;
    }
    else {
      *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x34) = 0;
    }
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x30) = 0;
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x38) = 0;
  }
  if ((param_3 < 0) || (0xd < param_3)) {
    FUN_0040187a((byte *)s__s__d____error_illegal_sound_mod_0042fc64);
  }
  if ((param_3 != 0xe) &&
     (FUN_004015a6((byte *)s_setting_3d_output_format_0042fc94), DAT_0043d44c == 0)) {
    iVar1 = FUN_00405fa9(*(int *)(&DAT_0042ee90 + param_3 * 0x10),
                         (short)*(undefined4 *)(&DAT_0042ee94 + param_3 * 0x10),
                         *(int *)(&DAT_0042ee9c + param_3 * 0x10),
                         *(int *)(&DAT_0042ee98 + param_3 * 0x10));
    if (iVar1 != 0) {
      return 0x2afa;
    }
    FUN_004015a6((byte *)s_setting_sound_format__dHz__dbits_0042fcc0);
    DAT_0043d44c = 1;
  }
  FUN_004015a6((byte *)s_query_interface_0042fce8);
  iVar1 = (**(code **)*DAT_0043d418)(DAT_0043d418,&DAT_004298b0,&DAT_0043d408);
  if (iVar1 != 0) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_query_interfa_0042fd08);
  }
  FUN_004015a6((byte *)s_done_0042fd44);
  DAT_0043d43c = 1;
  return 0;
}


/*
 * FUN_004075e7 at 004075e7
 * undefined4 __thiscall FUN_004075e7(void * this, int param_1, int param_2)
 * Address ranges: 004075e7-004076d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_004075e7(void *this,int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fd58);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      if (((param_2 < 100) || (100000 < param_2)) && (param_2 != 0)) {
        FUN_0040187a((byte *)s__s__d____attempt_at_setting_buff_0042fd90);
      }
      iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x44))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),param_2,this);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fde4);
      }
    }
  }
  return 0;
}


/*
 * FUN_004076d5 at 004076d5
 * undefined4 __cdecl FUN_004076d5(int param_1)
 * Address ranges: 004076d5-0040778c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004076d5(int param_1)

{
  undefined4 local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    local_c = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fe20);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      local_c = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x20))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fe58);
      }
    }
  }
  return local_c;
}


/*
 * FUN_0040778d at 0040778d
 * undefined4 __thiscall FUN_0040778d(void * this, int param_1, int param_2)
 * Address ranges: 0040778d-00407874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040778d(void *this,int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fe94);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      if ((param_2 < -10000) || (-100 < param_2)) {
        FUN_0040187a((byte *)s__s__d____attempt_at_setting_buff_0042fecc);
      }
      iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x3c))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),param_2,this);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ff18);
      }
    }
  }
  return 0;
}


/*
 * FUN_00407875 at 00407875
 * undefined4 __cdecl FUN_00407875(int param_1)
 * Address ranges: 00407875-0040792c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00407875(int param_1)

{
  undefined4 local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    local_c = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ff54);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      local_c = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x18))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ff8c);
      }
    }
  }
  return local_c;
}


/*
 * FUN_0040792d at 0040792d
 * undefined4 __thiscall FUN_0040792d(void * this, int param_1, int param_2)
 * Address ranges: 0040792d-00407a44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040792d(void *this,int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ffc8);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) == 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430000);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      if ((param_2 < -10000) || (10000 < param_2)) {
        FUN_0040187a((byte *)s__s__d____attempt_at_setting_buff_00430048);
      }
      iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x40))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),param_2,this);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430088);
      }
    }
  }
  return 0;
}


/*
 * FUN_00407a45 at 00407a45
 * undefined4 __cdecl FUN_00407a45(int param_1)
 * Address ranges: 00407a45-00407b29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00407a45(int param_1)

{
  undefined4 local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    local_c = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004300c4);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) == 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_004300fc);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      local_c = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x1c))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430144);
      }
    }
  }
  return local_c;
}


/*
 * FUN_00407b2a at 00407b2a
 * undefined4 __cdecl FUN_00407b2a(int param_1, int * param_2, undefined4 param_3, int param_4)
 * Address ranges: 00407b2a-00407c84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00407b2a(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  char *local_18;
  char *local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if ((param_4 != -1) && (iVar1 = FUN_00409b18(param_2,param_4,0), iVar1 != 0)) {
    return 0x3e9;
  }
  local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x2c))
                      (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0,param_3,&local_14,
                       &local_10,&local_18,&local_c,1);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_locking_sound_buf_00430180);
  }
  if ((local_10 != 0) && (uVar2 = FUN_0041f3be(local_14,local_10,1,param_2), uVar2 != 1)) {
    return 0x3e9;
  }
  if ((local_c != 0) && (uVar2 = FUN_0041f3be(local_18,local_c,1,param_2), uVar2 != 1)) {
    return 0x3e9;
  }
  local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x4c))
                      (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),local_14,local_10,
                       local_18,local_c);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_unlocking_sound_b_004301bc);
  }
  return 0;
}


/*
 * FUN_00407c85 at 00407c85
 * undefined4 __cdecl FUN_00407c85(LPCSTR param_1, int param_2)
 * Address ranges: 00407c85-00407e4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00407c85(LPCSTR param_1,int param_2)

{
  undefined4 uVar1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  char local_38 [22];
  short local_22;
  int local_20;
  short local_18;
  undefined2 local_16;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    pFVar2 = (FILE *)FUN_00409d69(param_1);
    if (pFVar2 == (FILE *)0x0) {
      FUN_004015a6((byte *)s___s__004301f0);
      uVar1 = 1000;
    }
    else {
      uVar3 = FUN_0041f3be(local_38,0x2c,1,(int *)pFVar2);
      if (uVar3 == 1) {
        local_8 = local_10;
        local_c = (uint)(1 < local_22);
        FUN_004015a6((byte *)s_file____s_004301f8);
        FUN_004015a6((byte *)s_bufferlength__d_0043020c);
        FUN_004015a6((byte *)s_samplerate___d_00430220);
        FUN_004015a6((byte *)s_bpps___d_00430234);
        FUN_004015a6((byte *)s_align___d_stereo__d_00430248);
        *(undefined4 *)(DAT_0043d420 + 0x3c + param_2 * 0x44) = local_8;
        if (*(int *)(DAT_0043d420 + 0x34 + param_2 * 0x44) == 0) {
          uVar1 = FUN_00406107(local_8,local_20,local_16,(int)local_18,local_c);
          *(undefined4 *)(DAT_0043d420 + 0x28 + param_2 * 0x44) = uVar1;
          if (*(int *)(DAT_0043d420 + 0x28 + param_2 * 0x44) == 0) {
            return 2000;
          }
        }
        else {
          iVar4 = FUN_004061cb((undefined4 *)(DAT_0043d420 + 0x28 + param_2 * 0x44),
                               DAT_0043d420 + 0x2c + param_2 * 0x44,local_8,local_20,local_16,
                               (int)local_18,local_c);
          if (iVar4 != 0) {
            return 2000;
          }
        }
        FUN_00407b2a(param_2,(int *)pFVar2,local_8,0x2c);
        FUN_00409f20(pFVar2);
        uVar1 = 0;
      }
      else {
        FUN_00409f20(pFVar2);
        uVar1 = 0x3e9;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_00407e4b at 00407e4b
 * undefined4 __cdecl FUN_00407e4b(int param_1, undefined4 param_2)
 * Address ranges: 00407e4b-00407f2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00407e4b(int param_1,undefined4 param_2)

{
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c != 0) {
    local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
    if (local_8 != 0) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_playing_sound__d___00430270);
    }
    if (((local_c & 1) != 1) &&
       (local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x30))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0,0,param_2),
       local_8 != 0)) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_playing_sound__d___004302a4);
    }
  }
  return 0;
}


/*
 * FUN_00407f2c at 00407f2c
 * uint __cdecl FUN_00407f2c(uint * param_1, uint param_2)
 * Address ranges: 00407f2c-004081a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_00407f2c(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_c;
  
  if (DAT_0043d43c == 0) {
    local_c = 0xffffffff;
  }
  else {
    uVar2 = FUN_00406a0b((char *)param_1,0,0,0);
    if (uVar2 == 0xffffffff) {
      local_c = FUN_00406ae8(0);
      if (local_c == 0xffffffff) {
        local_c = FUN_00406b5f(0xffffffff);
      }
      FUN_004015a6((byte *)s_new_buffer_used__d_004302cc);
      iVar3 = FUN_00407c85((LPCSTR)param_1,local_c);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 1;
      FUN_0041f7a0((uint *)(DAT_0043d420 + local_c * 0x44),param_1);
    }
    else {
      bVar1 = true;
      iVar3 = FUN_00406327(uVar2);
      local_c = uVar2;
      if ((iVar3 != 0) &&
         (local_c = FUN_00406a0b((char *)param_1,0,uVar2 + 1,1), local_c == 0xffffffff)) {
        local_c = FUN_00406ae8(0);
        if (local_c == 0xffffffff) {
          local_c = FUN_00406b5f(uVar2);
        }
        bVar1 = false;
      }
      if (!bVar1) {
        if (local_c == uVar2) {
          FUN_0040187a((byte *)s__s__d____duplicate_buffers_004302ec);
        }
        FUN_004015a6((byte *)s_duplicate_used__d_0043030c);
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + local_c * 0x44),param_1);
        uVar4 = FUN_004062d3(*(undefined4 *)(DAT_0043d420 + 0x28 + uVar2 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44) = uVar4;
      }
    }
    if ((param_2 & 4) == 0) {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = DAT_0043d414;
    }
    else {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = 1000000;
      param_2 = param_2 - 4;
    }
    iVar3 = FUN_00406327(local_c);
    if ((iVar3 == 0) &&
       (iVar3 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 0x30))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44),0,0,param_2),
       iVar3 != 0)) {
      FUN_00405af0(iVar3);
      FUN_0040187a((byte *)s__s__d____error_playing_sound__d___0043032c);
    }
    FUN_004015a6((byte *)s_playing__s_buffer__d_00430354);
  }
  return local_c;
}


/*
 * FUN_004081a4 at 004081a4
 * uint __cdecl FUN_004081a4(uint * param_1, int param_2, uint param_3)
 * Address ranges: 004081a4-00408429
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_004081a4(uint *param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  void *this;
  uint local_c;
  
  if (DAT_0043d43c == 0) {
    local_c = 0xffffffff;
  }
  else {
    uVar2 = FUN_00406a0b((char *)param_1,0,0,0);
    if (uVar2 == 0xffffffff) {
      local_c = FUN_00406ae8(0);
      if (local_c == 0xffffffff) {
        local_c = FUN_00406b5f(0xffffffff);
      }
      FUN_004015a6((byte *)s_new_buffer_used__d_0043036c);
      iVar3 = FUN_00407c85((LPCSTR)param_1,local_c);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 1;
      FUN_0041f7a0((uint *)(DAT_0043d420 + local_c * 0x44),param_1);
    }
    else {
      bVar1 = true;
      iVar3 = FUN_00406327(uVar2);
      local_c = uVar2;
      if ((iVar3 != 0) &&
         (local_c = FUN_00406a0b((char *)param_1,0,uVar2 + 1,1), local_c == 0xffffffff)) {
        local_c = FUN_00406ae8(0);
        if (local_c == 0xffffffff) {
          local_c = FUN_00406b5f(uVar2);
        }
        bVar1 = false;
      }
      if (!bVar1) {
        if (local_c == uVar2) {
          FUN_0040187a((byte *)s__s__d____duplicate_buffers_0043038c);
        }
        FUN_004015a6((byte *)s_duplicate_used__d_004303ac);
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + local_c * 0x44),param_1);
        uVar4 = FUN_004062d3(*(undefined4 *)(DAT_0043d420 + 0x28 + uVar2 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44) = uVar4;
      }
    }
    if ((param_3 & 4) == 0) {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = DAT_0043d414;
    }
    else {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = 1000000;
      param_3 = param_3 - 4;
    }
    iVar3 = FUN_00406327(local_c);
    if (iVar3 == 0) {
      FUN_0040778d(this,local_c,param_2);
      iVar3 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 0x30))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44),0,0,param_3);
      if (iVar3 != 0) {
        FUN_00405af0(iVar3);
        FUN_0040187a((byte *)s__s__d____error_playing_sound__d___004303cc);
      }
    }
    FUN_004015a6((byte *)s_playing__s_buffer__d_004303f4);
  }
  return local_c;
}


/*
 * FUN_0040842a at 0040842a
 * uint __cdecl FUN_0040842a(uint * param_1, uint param_2)
 * Address ranges: 0040842a-00408615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0040842a(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_8;
  
  if (DAT_0043d43c == 0) {
    local_8 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00406a0b((char *)param_1,0,0,0);
    if (uVar2 == 0xffffffff) {
      local_8 = FUN_00406ae8(0);
      if (local_8 == 0xffffffff) {
        local_8 = FUN_00406b5f(0xffffffff);
      }
      FUN_004015a6((byte *)s_new_buffer_used__d_0043040c);
      iVar3 = FUN_00407c85((LPCSTR)param_1,local_8);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(DAT_0043d420 + 0x30 + local_8 * 0x44) = 1;
      FUN_0041f7a0((uint *)(DAT_0043d420 + local_8 * 0x44),param_1);
    }
    else {
      bVar1 = true;
      iVar3 = FUN_00406327(uVar2);
      local_8 = uVar2;
      if ((iVar3 != 0) &&
         (local_8 = FUN_00406a0b((char *)param_1,0,uVar2 + 1,1), local_8 == 0xffffffff)) {
        local_8 = FUN_00406ae8(0);
        if (local_8 == 0xffffffff) {
          local_8 = FUN_00406b5f(uVar2);
        }
        bVar1 = false;
      }
      if (!bVar1) {
        if (local_8 == uVar2) {
          FUN_0040187a((byte *)s__s__d____duplicate_buffers_0043042c);
        }
        FUN_004015a6((byte *)s_duplicate_used__d_0043044c);
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_8 * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + local_8 * 0x44),param_1);
        uVar4 = FUN_004062d3(*(undefined4 *)(DAT_0043d420 + 0x28 + uVar2 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x28 + local_8 * 0x44) = uVar4;
      }
    }
    if ((param_2 & 4) == 0) {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_8 * 0x44) = DAT_0043d414;
    }
    else {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_8 * 0x44) = 1000000;
    }
  }
  return local_8;
}


/*
 * FUN_00408616 at 00408616
 * undefined __cdecl FUN_00408616(int param_1, undefined4 param_2)
 * Address ranges: 00408616-00408658
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00408616(int param_1,undefined4 param_2)

{
  if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
    FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0043046c);
  }
  *(undefined4 *)(DAT_0043d420 + 0x40 + param_1 * 0x44) = param_2;
  return;
}


/*
 * FUN_00408659 at 00408659
 * undefined4 __cdecl FUN_00408659(int param_1)
 * Address ranges: 00408659-00408698
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00408659(int param_1)

{
  if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
    FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004304a4);
  }
  return *(undefined4 *)(DAT_0043d420 + 0x40 + param_1 * 0x44);
}


/*
 * FUN_00408699 at 00408699
 * undefined4 __thiscall FUN_00408699(void * this, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 00408699-00408786
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall
FUN_00408699(void *this,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004304dc);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430514);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x4c))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),param_2,param_3,
                           param_4,0,this), iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_setting_sound_pos_0043055c);
    }
  }
  return 0;
}


/*
 * FUN_00408787 at 00408787
 * undefined4 __thiscall FUN_00408787(void * this, int param_1, undefined4 * param_2)
 * Address ranges: 00408787-0040887c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408787(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430598);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_004305d0);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x4c))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),*param_2,param_2[1]
                           ,param_2[2],0,this), iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_setting_sound_pos_00430618);
    }
  }
  return 0;
}


/*
 * FUN_0040887d at 0040887d
 * undefined4 __thiscall FUN_0040887d(void * this, int param_1, undefined4 * param_2)
 * Address ranges: 0040887d-00408972
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040887d(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430654);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_0043068c);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x50))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),*param_2,param_2[1]
                           ,param_2[2],0,this), iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_setting_sound_vel_004306d4);
    }
  }
  return 0;
}


/*
 * FUN_00408973 at 00408973
 * undefined4 __thiscall FUN_00408973(void * this, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 00408973-00408a60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall
FUN_00408973(void *this,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430710);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430748);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x50))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),param_2,param_3,
                           param_4,0,this), iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_setting_sound_vel_00430790);
    }
  }
  return 0;
}


/*
 * FUN_00408a61 at 00408a61
 * undefined4 __cdecl FUN_00408a61(int param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 00408a61-00408b64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00408a61(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_00409770(&local_14);
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004307cc);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430804);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x28))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),&local_14);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____error_getting_sound_pos_0043084c);
      }
      *param_2 = local_14;
      *param_3 = local_10;
      *param_4 = local_c;
    }
  }
  return 0;
}


/*
 * FUN_00408b65 at 00408b65
 * undefined4 __thiscall FUN_00408b65(void * this, int param_1, undefined4 param_2)
 * Address ranges: 00408b65-00408c46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408b65(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430888);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_004308c0);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x28))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),param_2,this),
       iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_getting_sound_pos_00430908);
    }
  }
  return 0;
}


/*
 * FUN_00408c47 at 00408c47
 * undefined4 __thiscall FUN_00408c47(void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00408c47-00408ca9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall
FUN_00408c47(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x38))(DAT_0043d408,param_1,param_2,param_3,0,this),
     iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_posi_00430944);
  }
  return 0;
}


/*
 * FUN_00408caa at 00408caa
 * undefined4 __thiscall FUN_00408caa(void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00408caa-00408d0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall
FUN_00408caa(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x40))(DAT_0043d408,param_1,param_2,param_3,0,this),
     iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_posi_00430978);
  }
  return 0;
}


/*
 * FUN_00408d0d at 00408d0d
 * undefined4 __thiscall FUN_00408d0d(void * this, undefined4 * param_1)
 * Address ranges: 00408d0d-00408d77
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408d0d(void *this,undefined4 *param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x38))
                        (DAT_0043d408,*param_1,param_1[1],param_1[2],0,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_posi_004309ac);
  }
  return 0;
}


/*
 * FUN_00408d78 at 00408d78
 * undefined4 __thiscall FUN_00408d78(void * this, undefined4 * param_1)
 * Address ranges: 00408d78-00408de2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408d78(void *this,undefined4 *param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x40))
                        (DAT_0043d408,*param_1,param_1[1],param_1[2],0,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_velo_004309e0);
  }
  return 0;
}


/*
 * FUN_00408de3 at 00408de3
 * undefined4 __thiscall FUN_00408de3(void * this, undefined4 param_1)
 * Address ranges: 00408de3-00408e3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408de3(void *this,undefined4 param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x1c))(DAT_0043d408,param_1,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_position___00430a14);
  }
  return 0;
}


/*
 * FUN_00408e3c at 00408e3c
 * undefined4 __thiscall FUN_00408e3c(void * this, undefined4 param_1)
 * Address ranges: 00408e3c-00408e94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408e3c(void *this,undefined4 param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x24))(DAT_0043d408,param_1,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_velocity___00430a48);
  }
  return 0;
}


/*
 * FUN_00408e95 at 00408e95
 * undefined4 __cdecl FUN_00408e95(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3)
 * Address ranges: 00408e95-00408f0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00408e95(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_00409770(&local_14);
  if (DAT_0043d43c != 0) {
    local_8 = (**(code **)(*DAT_0043d408 + 0x1c))(DAT_0043d408,&local_14);
    if (local_8 != 0) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_get_listener_posi_00430a7c);
    }
    *param_1 = local_14;
    *param_2 = local_10;
    *param_3 = local_c;
  }
  return 0;
}


/*
 * FUN_00408f10 at 00408f10
 * undefined4 __cdecl FUN_00408f10(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3)
 * Address ranges: 00408f10-00408f8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00408f10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_00409770(&local_14);
  if (DAT_0043d43c != 0) {
    local_8 = (**(code **)(*DAT_0043d408 + 0x24))(DAT_0043d408,&local_14);
    if (local_8 != 0) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_get_listener_velo_00430ab0);
    }
    *param_1 = local_14;
    *param_2 = local_10;
    *param_3 = local_c;
  }
  return 0;
}


/*
 * FUN_00408f8b at 00408f8b
 * undefined4 __thiscall FUN_00408f8b(void * this, undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 00408f8b-00409009
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00408f8b(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x34))
                        (DAT_0043d408,*param_1,param_1[1],param_1[2],*param_2,param_2[1],param_2[2],
                         0,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430ae4);
  }
  return 0;
}


/*
 * FUN_0040900a at 0040900a
 * undefined4 __thiscall FUN_0040900a(void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 0040900a-00409078
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall
FUN_0040900a(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x34))
                        (DAT_0043d408,param_1,param_2,param_3,param_4,param_5,param_6,0,this),
     iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430b1c);
  }
  return 0;
}


/*
 * FUN_00409079 at 00409079
 * undefined4 __thiscall FUN_00409079(void * this, float param_1)
 * Address ranges: 00409079-00409101
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00409079(void *this,float param_1)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
    if (10.0 < param_1) {
      param_1 = 10.0;
    }
    iVar1 = (**(code **)(*DAT_0043d408 + 0x30))(DAT_0043d408,param_1,0,this);
    if (iVar1 != 0) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430b54);
    }
  }
  return 0;
}


/*
 * FUN_00409102 at 00409102
 * undefined4 __thiscall FUN_00409102(void * this, float param_1)
 * Address ranges: 00409102-0040918a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_00409102(void *this,float param_1)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
    if (10.0 < param_1) {
      param_1 = 10.0;
    }
    iVar1 = (**(code **)(*DAT_0043d408 + 0x2c))(DAT_0043d408,param_1,0,this);
    if (iVar1 != 0) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430b8c);
    }
  }
  return 0;
}


/*
 * FUN_0040918b at 0040918b
 * undefined4 __thiscall FUN_0040918b(void * this, float param_1)
 * Address ranges: 0040918b-00409213
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040918b(void *this,float param_1)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
    if (10.0 < param_1) {
      param_1 = 10.0;
    }
    iVar1 = (**(code **)(*DAT_0043d408 + 0x3c))(DAT_0043d408,param_1,0,this);
    if (iVar1 != 0) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430bc4);
    }
  }
  return 0;
}


/*
 * FUN_00409214 at 00409214
 * undefined __fastcall FUN_00409214(undefined4 param_1)
 * Address ranges: 00409214-00409264
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00409214(undefined4 param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x44))(DAT_0043d408,param_1), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430bfc);
  }
  return;
}


/*
 * FUN_00409265 at 00409265
 * int __cdecl FUN_00409265(uint * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00409265-00409534
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl
FUN_00409265(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0043d43c == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00406ae8(1);
    if (iVar1 == -1) {
      iVar1 = -1;
    }
    else {
      FUN_004015a6((byte *)s_new_3d_buffer_used__d_00430c28);
      iVar2 = FUN_00407c85((LPCSTR)param_1,iVar1);
      if (iVar2 == 0) {
        *(undefined4 *)(DAT_0043d420 + 0x30 + iVar1 * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + iVar1 * 0x44),param_1);
        *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) =
             *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) + 1;
        iVar2 = FUN_00406327(iVar1);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + iVar1 * 0x44) + 0x30))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + iVar1 * 0x44),0,0,param_2);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_playing_sound__d___00430c4c);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x4c))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),param_3,param_4,
                             param_5,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430c80);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x44))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),0x41200000,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430cb8);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x40))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),0x461c4000,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430cf0);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x48))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),1,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430d28);
          }
        }
        else {
          FUN_0040187a((byte *)s__s__d____sound_buffer__d_type__d_00430d60);
        }
      }
      else {
        iVar1 = -1;
      }
    }
  }
  return iVar1;
}


/*
 * FUN_00409535 at 00409535
 * int __cdecl FUN_00409535(uint * param_1)
 * Address ranges: 00409535-004095e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00409535(uint *param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0043d43c == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00406ae8(1);
    if (iVar1 == -1) {
      iVar1 = -1;
    }
    else {
      FUN_004015a6((byte *)s_new_3d_buffer_used__d_00430d98);
      iVar2 = FUN_00407c85((LPCSTR)param_1,iVar1);
      if (iVar2 == 0) {
        *(undefined4 *)(DAT_0043d420 + 0x30 + iVar1 * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + iVar1 * 0x44),param_1);
        *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) =
             *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) + 1;
      }
      else {
        iVar1 = -1;
      }
    }
  }
  return iVar1;
}


/*
 * FUN_004095e3 at 004095e3
 * undefined4 __cdecl FUN_004095e3(int param_1)
 * Address ranges: 004095e3-0040976a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004095e3(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_00430dbc);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      uVar1 = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____getting_sound_status_fa_00430dfc);
      }
      if ((local_c & 1) == 1) {
        local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x48))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
        if (local_8 != 0) {
          FUN_00405af0(local_8);
          FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_00430e38);
        }
        (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 8))
                  (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44));
        (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 8))
                  (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 0;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_00409770 at 00409770
 * undefined4 __fastcall FUN_00409770(undefined4 param_1)
 * Address ranges: 00409770-0040977d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00409770(undefined4 param_1)

{
  return param_1;
}


/*
 * FUN_00409780 at 00409780
 * undefined4 __cdecl FUN_00409780(LPCSTR param_1, LPCSTR param_2)
 * Address ranges: 00409780-00409ad9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00409780(LPCSTR param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_24;
  short local_20 [2];
  int local_1c;
  uint local_18 [5];
  
  if (DAT_0043d468 == 0) {
    DAT_0043d454 = (FILE *)FUN_0041f4c6(param_1,&DAT_00430eb8);
    if (DAT_0043d454 == (FILE *)0x0) {
      FUN_0040187a((byte *)s__s__d____could_not_open_<_s>_00430ec8);
      uVar1 = 1000;
    }
    else {
      FUN_0041f3be((char *)local_20,2,1,(int *)DAT_0043d454);
      if (local_20[0] < 1) {
        FUN_0040187a((byte *)s__s__d____could_not_open_<_s>_00430ef4);
        uVar1 = 0x3e9;
      }
      else {
        DAT_0043d45c = (int)local_20[0];
        DAT_0043d460 = LocalAlloc(0x40,DAT_0043d45c * 0x1c);
        if (DAT_0043d460 == (HLOCAL)0x0) {
          FUN_0040187a((byte *)s__s__d____error_not_enough_memory_00430f20);
          uVar1 = 2000;
        }
        else {
          for (local_1c = 0; local_1c < DAT_0043d45c; local_1c = local_1c + 1) {
            FUN_0041f3be((char *)local_18,0x14,1,(int *)DAT_0043d454);
            FUN_0041f3be((char *)&local_24,1,4,(int *)DAT_0043d454);
            FUN_0041f7a0((uint *)((int)DAT_0043d460 + local_1c * 0x1c),local_18);
            *(undefined4 *)((int)DAT_0043d460 + local_1c * 0x1c + 0x14) = local_24;
            if ((DAT_0043d454->_flag & 0x20U) != 0) {
              FUN_0040187a((byte *)s__s__d____error_while_reading_fil_00430f68);
              return 0x3e9;
            }
          }
          FUN_0041f368(DAT_0043d454);
          DAT_0043d458 = FUN_0041f4c6(param_2,&DAT_00430f94);
          if (DAT_0043d458 == 0) {
            FUN_0040187a((byte *)s__s__d____could_not_open_<_s>_00430fa4);
            uVar1 = 1000;
          }
          else {
            uVar2 = FUN_00427d94(DAT_0043d458);
            DAT_0043d450 = FUN_00427d1c(uVar2);
            FUN_004015a6(&DAT_00430fc4);
            FUN_004015a6((byte *)s______s______s_00430fdc);
            FUN_004015a6((byte *)s______s_00431020);
            for (local_1c = 0; local_1c < DAT_0043d45c + -1; local_1c = local_1c + 1) {
              *(int *)((int)DAT_0043d460 + local_1c * 0x1c + 0x18) =
                   *(int *)((int)DAT_0043d460 + (local_1c + 1) * 0x1c + 0x14) -
                   *(int *)((int)DAT_0043d460 + local_1c * 0x1c + 0x14);
              FUN_004015a6((byte *)s______s____d_00431028);
            }
            *(DWORD *)((int)DAT_0043d460 + local_1c * 0x1c + 0x18) =
                 DAT_0043d450 - *(int *)((int)DAT_0043d460 + local_1c * 0x1c + 0x14);
            FUN_004015a6((byte *)s______s____d_00431038);
            FUN_004015a6((byte *)s______s_0043107c);
            DAT_0043d468 = 1;
            uVar1 = 0;
          }
        }
      }
    }
  }
  else {
    FUN_004015a6((byte *)s__s__d____warning___double_call_t_00430e74);
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_00409ada at 00409ada
 * undefined __cdecl FUN_00409ada(int param_1)
 * Address ranges: 00409ada-00409b17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00409ada(int param_1)

{
  if ((param_1 < 0) || (1 < param_1)) {
    FUN_0040187a((byte *)s_trying_to_set_an_invalid_check_s_00431090);
  }
  else {
    DAT_0043d46c = param_1;
  }
  return;
}


/*
 * FUN_00409b18 at 00409b18
 * int __cdecl FUN_00409b18(int * param_1, int param_2, DWORD param_3)
 * Address ranges: 00409b18-00409cb1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00409b18(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_0040187a((byte *)s__s__d____null_ptr_assignment___00431100);
  }
  if (DAT_0043d468 == 0) {
    iVar1 = FUN_0041fd07(param_1,param_2,param_3);
  }
  else {
    iVar1 = FUN_00427d94((int)param_1);
    iVar2 = FUN_00427d94((int)DAT_0043d458);
    if (iVar1 == iVar2) {
      if (param_3 == 0) {
        if ((DAT_0043d450 < DAT_0043d464 + param_2) || (DAT_0043d464 + param_2 < DAT_0043d464)) {
          FUN_0040187a((byte *)s__s__d____fseeking_past_end_or_be_0043112c);
          iVar1 = 0x3e9;
        }
        else {
          iVar1 = FUN_0041fd07(DAT_0043d458,DAT_0043d464 + param_2,0);
        }
      }
      else if (param_3 == 1) {
        iVar1 = FUN_0041fd07(DAT_0043d458,DAT_0043d464 + param_2,0);
      }
      else if (param_3 == 2) {
        if (DAT_0043d450 < DAT_0043d450 + param_2) {
          FUN_0040187a((byte *)s__s__d____fseeking_past_end_file__00431168);
          iVar1 = 0x3e9;
        }
        else {
          iVar1 = FUN_0041fd07(DAT_0043d458,DAT_0043d450 + param_2,0);
        }
      }
      else {
        FUN_0040187a((byte *)s__s__d____illegal_fseek_cmd__004311a0);
        iVar1 = 0x3e9;
      }
    }
    else {
      iVar1 = FUN_0041fd07(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


/*
 * FUN_00409cb2 at 00409cb2
 * DWORD __cdecl FUN_00409cb2(int param_1)
 * Address ranges: 00409cb2-00409d68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


DWORD __cdecl FUN_00409cb2(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    FUN_0040187a((byte *)s__s__d____null_ptr_assignment___004311cc);
  }
  if (DAT_0043d468 == 0) {
    uVar1 = FUN_00427d94(param_1);
    DVar2 = FUN_00427d1c(uVar1);
  }
  else {
    iVar3 = FUN_00427d94(param_1);
    iVar4 = FUN_00427d94(DAT_0043d458);
    if (iVar3 == iVar4) {
      if (DAT_0043d468 == 0) {
        FUN_0040187a((byte *)s__s__d____attempt_at_reading_unop_004311f8);
      }
      DVar2 = DAT_0043d450 - DAT_0043d464;
    }
    else {
      uVar1 = FUN_00427d94(param_1);
      DVar2 = FUN_00427d1c(uVar1);
    }
  }
  return DVar2;
}


/*
 * FUN_00409d69 at 00409d69
 * int * __cdecl FUN_00409d69(LPCSTR param_1)
 * Address ranges: 00409d69-00409f1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00409d69(LPCSTR param_1)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  if ((DAT_0043d468 == 0) || (DAT_0043d46c == 1)) {
    piVar1 = (int *)FUN_0041f4c6(param_1,&DAT_0043122c);
    if (piVar1 == (int *)0x0) {
      FUN_004015a6((byte *)s__s__d____file_open_failed___s__0043123c);
      piVar1 = (int *)0x0;
    }
    else {
      FUN_004015a6((byte *)s__s__d____file_open_succeeded___s_0043126c);
    }
  }
  else {
    for (local_8 = 0; local_8 < DAT_0043d45c; local_8 = local_8 + 1) {
      iVar2 = __strcmpi((char *)(DAT_0043d460 + local_8 * 0x1c),param_1);
      if (iVar2 == 0) {
        DAT_0043d464 = *(int *)(DAT_0043d460 + 0x14 + local_8 * 0x1c);
        DAT_0043d450 = DAT_0043d464 + *(int *)(DAT_0043d460 + 0x18 + local_8 * 0x1c);
        break;
      }
    }
    if (local_8 == (short)DAT_0043d45c) {
      piVar1 = (int *)FUN_0041f4c6(param_1,&DAT_00431294);
      if (piVar1 == (int *)0x0) {
        FUN_004015a6((byte *)s__s__d____file_open_failed___s__004312a4);
        piVar1 = (int *)0x0;
      }
      else {
        FUN_004015a6((byte *)s__s__d____file_open_succeeded___s_004312d4);
      }
    }
    else {
      FUN_0041fd07(DAT_0043d458,DAT_0043d464,0);
      FUN_00427d94((int)DAT_0043d458);
      FUN_004015a6((byte *)s__s__d____file_open_succeeded___s_00431308);
      piVar1 = DAT_0043d458;
    }
  }
  return piVar1;
}


/*
 * FUN_00409f20 at 00409f20
 * undefined __cdecl FUN_00409f20(FILE * param_1)
 * Address ranges: 00409f20-00409fc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00409f20(FILE *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (FILE *)0x0) {
    FUN_0040187a((byte *)s__s__d____null_ptr_assignment___0043134c);
  }
  else if (DAT_0043d468 == 0) {
    FUN_004015a6((byte *)s__s__d____file_close_00431378);
    FUN_0041f368(param_1);
  }
  else {
    iVar1 = FUN_00427d94((int)param_1);
    iVar2 = FUN_00427d94(DAT_0043d458);
    if (iVar1 == iVar2) {
      if (DAT_0043d468 == 0) {
        FUN_0040187a((byte *)s__s__d____unopened_resource_file_a_0043139c);
      }
    }
    else {
      FUN_0041f368(param_1);
    }
  }
  return;
}


/*
 * FUN_00409fc5 at 00409fc5
 * undefined4 __cdecl FUN_00409fc5(LPCSTR param_1)
 * Address ranges: 00409fc5-0040a087
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00409fc5(LPCSTR param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if ((DAT_0043d468 == 0) || (DAT_0043d46c == 1)) {
    pFVar1 = (FILE *)FUN_0041f4c6(param_1,&DAT_004313c8);
    if (pFVar1 == (FILE *)0x0) {
      uVar2 = 0;
    }
    else {
      FUN_0041f368(pFVar1);
      uVar2 = 1;
    }
  }
  else {
    for (local_8 = 0; local_8 < DAT_0043d45c; local_8 = local_8 + 1) {
      iVar3 = __strcmpi((char *)(DAT_0043d460 + local_8 * 0x1c),param_1);
      if (iVar3 == 0) {
        return 1;
      }
    }
    pFVar1 = (FILE *)FUN_0041f4c6(param_1,&DAT_004313cc);
    if (pFVar1 == (FILE *)0x0) {
      uVar2 = 0;
    }
    else {
      FUN_0041f368(pFVar1);
      uVar2 = 1;
    }
  }
  return uVar2;
}


/*
 * FUN_0040a088 at 0040a088
 * undefined __stdcall FUN_0040a088(void)
 * Address ranges: 0040a088-0040a0d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040a088(void)

{
  HLOCAL pvVar1;
  
  if (DAT_0043d468 != 0) {
    pvVar1 = LocalFree(DAT_0043d460);
    if (pvVar1 == (HLOCAL)0x0) {
      FUN_0041f368(DAT_0043d458);
      DAT_0043d468 = 0;
    }
    else {
      FUN_0040187a((byte *)s__s__d____failure_to_free_file_li_004313dc);
    }
  }
  return;
}


/*
 * FUN_0040a0e0 at 0040a0e0
 * undefined4 __cdecl FUN_0040a0e0(int param_1)
 * Address ranges: 0040a0e0-0040a189
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040a0e0(int param_1)

{
  char cVar1;
  
  if (DAT_0043d514 == 0) {
    if (param_1 == 0) {
      cVar1 = _SmackSoundUseDirectSound_4(0);
      if (cVar1 == '\0') {
        FUN_0040187a((byte *)s__s__d____failed_to_set_directsou_0043144c);
      }
    }
    else {
      cVar1 = _SmackSoundUseDirectSound_4(param_1);
      if (cVar1 == '\0') {
        FUN_0040187a((byte *)s__s__d____failed_to_set_directsou_00431410);
      }
    }
    FUN_0040a80c();
    FUN_0040a83c(1,0x1b);
    FUN_0040a83c(1,0xd);
    FUN_0040a83c(1,0x20);
    FUN_0040a83c(1,1);
    DAT_0043d514 = 1;
  }
  return 0;
}


/*
 * FUN_0040a18a at 0040a18a
 * undefined __cdecl FUN_0040a18a(int param_1)
 * Address ranges: 0040a18a-0040a24d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040a18a(int param_1)

{
  int local_8;
  
  if (param_1 == 0) {
    for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
      *(char *)((int)DAT_0043d760 + local_8 * 4) = *(char *)(DAT_0043d510 + 0x6c + local_8 * 3) << 2
      ;
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 1) =
           *(char *)(DAT_0043d510 + 0x6d + local_8 * 3) << 2;
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 2) =
           *(char *)(DAT_0043d510 + 0x6e + local_8 * 3) << 2;
    }
    FUN_0040e96f(DAT_0043d760,DAT_0043d760,0,0x100);
  }
  else {
    _SmackColorRemap_16(DAT_0043d510,DAT_0043d760,0x100,3);
  }
  return;
}


/*
 * FUN_0040a24e at 0040a24e
 * undefined __stdcall FUN_0040a24e(void)
 * Address ranges: 0040a24e-0040a2cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040a24e(void)

{
  int iVar1;
  
  if (*(int *)(DAT_0043d510 + 0x370) == *(int *)(DAT_0043d510 + 0xc) + -1) {
    DAT_0043d51c = 0;
  }
  else {
    _SmackNextFrame_4(DAT_0043d510);
    FUN_0040a566();
    if ((DAT_0043d51c & (DAT_0043d520 & 1) == 0) != 0) {
      while( true ) {
        iVar1 = _SmackWait_4(DAT_0043d510);
        if (((iVar1 == 0) || (DAT_0043d51c == 0)) || (DAT_0043d518 != 0)) break;
        FUN_0040a566();
      }
    }
  }
  return;
}


/*
 * FUN_0040a2cc at 0040a2cc
 * undefined4 __cdecl FUN_0040a2cc(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040a2cc-0040a407
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040a2cc(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_28 = 0;
  local_24 = 0;
  local_1c = *(undefined4 *)(DAT_0043d510 + 8);
  local_20 = *(undefined4 *)(DAT_0043d510 + 4);
  local_18 = 0;
  local_14 = 0;
  local_c = *(undefined4 *)(DAT_0043d510 + 8);
  local_10 = *(undefined4 *)(DAT_0043d510 + 4);
  while (DAT_0043d51c != 0) {
    if (*(int *)(DAT_0043d510 + 0x68) != 0) {
      FUN_0040a18a(param_3);
    }
    local_8 = FUN_0040235c(DAT_00438418);
    _SmackToBuffer_28(DAT_0043d510,0,0,DAT_0042c350,DAT_0042c354,local_8,0);
    _SmackDoFrame_4(DAT_0043d510);
    FUN_004027f9(DAT_00438418,local_8);
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_18,DAT_00438418,&local_28,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___00431488);
    }
    FUN_0040a24e();
  }
  return 0;
}


/*
 * FUN_0040a408 at 0040a408
 * undefined4 __cdecl FUN_0040a408(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5)
 * Address ranges: 0040a408-0040a565
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_0040a408(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_0043d520 = 0;
  local_28 = 0;
  local_24 = 0;
  local_1c = *(undefined4 *)(DAT_0043d510 + 8);
  local_20 = *(undefined4 *)(DAT_0043d510 + 4);
  local_14 = param_1;
  local_10 = param_2;
  local_8 = param_4;
  local_c = param_3;
  while (DAT_0043d51c != 0) {
    if (*(int *)(DAT_0043d510 + 0x68) != 0) {
      FUN_0040a18a(param_5);
    }
    local_18 = FUN_0040235c(DAT_00438418);
    _SmackToBuffer_28(DAT_0043d510,0,0,DAT_0042c350,DAT_0042c354,local_18,0);
    _SmackDoFrame_4(DAT_0043d510);
    FUN_004027f9(DAT_00438418,local_18);
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                      (DAT_00438438,&local_14,DAT_00438418,&local_28,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___004314b4);
    }
    FUN_0040a24e();
    FUN_00401cf3();
    DAT_0043d520 = DAT_0043d520 + 1;
  }
  if ((DAT_0043d520 & 1) != 0) {
    FUN_00401cf3();
  }
  return 0;
}


/*
 * FUN_0040a566 at 0040a566
 * undefined __stdcall FUN_0040a566(void)
 * Address ranges: 0040a566-0040a615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040a566(void)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  do {
    if (0x13 < local_8) {
      return;
    }
    if ((*(int *)(&DAT_0043d470 + local_8 * 8) != -1) &&
       (iVar1 = FUN_004133f0(*(uint *)(&DAT_0043d470 + local_8 * 8)), iVar1 != 0)) {
      if (*(int *)(&DAT_0043d474 + local_8 * 8) == 1) {
        DAT_0043d51c = 0;
        return;
      }
      if (*(int *)(&DAT_0043d474 + local_8 * 8) == 2) {
        DAT_0043d518 = (uint)(DAT_0043d518 == 0);
        return;
      }
      do {
        iVar1 = FUN_004133f0(*(uint *)(&DAT_0043d470 + local_8 * 8));
      } while (iVar1 != 0);
    }
    local_8 = local_8 + 1;
  } while( true );
}


/*
 * FUN_0040a616 at 0040a616
 * undefined4 __cdecl FUN_0040a616(undefined4 param_1, int param_2, int param_3, int param_4, int param_5, undefined4 param_6, int param_7)
 * Address ranges: 0040a616-0040a7d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_0040a616(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  if (DAT_0043d514 == 0) {
    FUN_0040187a((byte *)s__s__d_____playing_smacker__Smack_004314e0);
  }
  DAT_0043d510 = _SmackOpen_12(param_1,0xfe000,0xffffffff);
  if (DAT_0043d510 == 0) {
    FUN_004015a6((byte *)s_failed_to_open_smacker_file__s__00431518);
  }
  else {
    if (param_4 == -1) {
      param_4 = *(int *)(DAT_0043d510 + 4);
    }
    if (param_5 == -1) {
      param_5 = *(int *)(DAT_0043d510 + 8);
    }
    if (param_2 == -1) {
      param_2 = (DAT_0042c350 - param_4) / 2;
    }
    if (param_3 == -1) {
      param_3 = (DAT_0042c354 - param_5) / 2;
    }
    if ((((param_2 < 0) || (param_3 < 0)) || (param_4 < 1)) || (param_5 < 1)) {
      FUN_0040187a((byte *)s__s__d____x_or_y_is_not_on_the_sc_00431548);
    }
    if ((DAT_0042c350 < param_2 + param_4) || (DAT_0042c354 < param_3 + param_5)) {
      FUN_0040187a((byte *)s__s__d____the_smacker_is_bigger_t_0043159c);
    }
    DAT_0043d51c = 1;
    DAT_0043d518 = 0;
    if ((param_4 == *(int *)(DAT_0043d510 + 4)) && (param_5 == *(int *)(DAT_0043d510 + 8))) {
      FUN_0040a408(param_2,param_3,param_4,param_5,param_7);
    }
    else {
      FUN_0040a408(param_2,param_3,param_4,param_5,param_7);
    }
    FUN_004015a6((byte *)s_closing_smacker_004315e0);
    _SmackClose_4(DAT_0043d510);
    FUN_004015a6((byte *)s_closing_smacker_done_004315f4);
  }
  return 0;
}


/*
 * FUN_0040a7d5 at 0040a7d5
 * int __stdcall FUN_0040a7d5(void)
 * Address ranges: 0040a7d5-0040a80b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0040a7d5(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x13 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_0043d470 + local_8 * 8) == -1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_0040a80c at 0040a80c
 * undefined __stdcall FUN_0040a80c(void)
 * Address ranges: 0040a80c-0040a83b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040a80c(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0043d470 + local_8 * 8) = 0xffffffff;
  }
  return;
}


/*
 * FUN_0040a83c at 0040a83c
 * undefined __cdecl FUN_0040a83c(int param_1, undefined4 param_2)
 * Address ranges: 0040a83c-0040a8b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040a83c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_smacker_key__Unkno_00431664);
  }
  else {
    iVar1 = FUN_0040a7d5();
    if (iVar1 == -1) {
      FUN_0040187a((byte *)s__s__d_____set_smacker_key__No_fr_00431618);
    }
    else {
      *(undefined4 *)(&DAT_0043d470 + iVar1 * 8) = param_2;
      *(int *)(&DAT_0043d474 + iVar1 * 8) = param_1;
    }
  }
  return;
}


/*
 * FUN_0040a8c0 at 0040a8c0
 * undefined __cdecl FUN_0040a8c0(undefined4 param_1)
 * Address ranges: 0040a8c0-0040a8d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040a8c0(undefined4 param_1)

{
  DAT_0043d528 = param_1;
  DAT_0043d53c = 1;
  return;
}


/*
 * FUN_0040a8d7 at 0040a8d7
 * undefined4 __stdcall FUN_0040a8d7(void)
 * Address ranges: 0040a8d7-0040a92c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040a8d7(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  do {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
    if (local_20.message == 0x12) {
      if (DAT_0043d53c == 0) {
        return 1;
      }
      (*DAT_0043d528)();
    }
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  } while( true );
}


/*
 * FUN_0040a92d at 0040a92d
 * undefined4 __stdcall FUN_0040a92d(void)
 * Address ranges: 0040a92d-0040a97c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040a92d(void)

{
  tagMSG local_20;
  
  PeekMessageA(&local_20,(HWND)0x0,0,0,1);
  if (local_20.message == 0x12) {
    if (DAT_0043d53c == 0) {
      return 1;
    }
    (*DAT_0043d528)();
  }
  TranslateMessage(&local_20);
  DispatchMessageA(&local_20);
  return 0;
}


/*
 * FUN_0040a97d at 0040a97d
 * undefined4 __stdcall FUN_0040a97d(void)
 * Address ranges: 0040a97d-0040a9d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040a97d(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  do {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
    if (local_20.message == 0x12) {
      if (DAT_0043d53c == 0) {
        return 1;
      }
      (*DAT_0043d528)();
    }
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  } while( true );
}


/*
 * FUN_0040a9d3 at 0040a9d3
 * undefined4 __stdcall FUN_0040a9d3(void)
 * Address ranges: 0040a9d3-0040aa1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040a9d3(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
  if (BVar1 == 0) {
    FUN_00405614();
  }
  else {
    if (local_20.message == 0x12) {
      FUN_0041f6c8(0);
    }
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  }
  return 0;
}


/*
 * FUN_0040aa20 at 0040aa20
 * LRESULT __stdcall FUN_0040aa20(HWND param_1, uint param_2, uint param_3, int param_4)
 * Address ranges: 0040aa20-0040b1e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0040aa20(HWND param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  BOOL BVar2;
  LRESULT LVar3;
  tagPAINTSTRUCT local_54;
  tagRECT local_14;
  
  if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_0043d534 = param_3 & 0xffff;
      _DAT_0043d538 = param_3 >> 0x10;
      return 0;
    }
    switch(param_2) {
    case 1:
      break;
    case 2:
      FUN_004015a6((byte *)s__s__d____DESTROY_MESSAGE_004316a0);
      PostQuitMessage(0);
      break;
    case 6:
      _DAT_0043d52c = param_3 & 0xffff;
      _DAT_0043d530 = param_3 >> 0x10;
      return 0;
    case 7:
      if (DAT_0043d568 != (code *)0x0) {
        (*DAT_0043d568)(param_1,param_2,param_3,param_4);
        return 0;
      }
      break;
    case 8:
      if (DAT_0043d564 != (code *)0x0) {
        (*DAT_0043d564)(param_1,param_2,param_3,param_4);
        return 0;
      }
      break;
    case 0xf:
      if (DAT_0043d570 != (code *)0x0) {
        (*DAT_0043d570)(param_1,param_2,param_3,param_4);
        return 0;
      }
      BVar2 = GetUpdateRect(param_1,&local_14,0);
      if (BVar2 != 0) {
        BeginPaint(param_1,&local_54);
        EndPaint(param_1,&local_54);
      }
      return 0;
    case 0x12:
      FUN_004015a6((byte *)s__s__d____QUIT_MESSAGE_004316c4);
      break;
    case 0x14:
      return 1;
    }
  }
  else if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      if (DAT_0043d580 != (code *)0x0) {
        (*DAT_0043d580)(param_1,0x2b,param_3,param_4);
        return 0;
      }
      if (*(int *)(param_4 + 0x14) != DAT_0043842c) {
        LVar3 = FUN_00411cc0(*(int *)(param_4 + 0x14),0x2b,param_3,param_4);
        return LVar3;
      }
    }
    else if (param_2 == 0x20) {
      if ((DAT_00438488 == 0) || (iVar1 = FUN_00404a61(), iVar1 == 0)) {
        SetCursor((HCURSOR)0x0);
      }
      else {
        iVar1 = FUN_004047e0();
        if (iVar1 == 2) {
          SetCursor((HCURSOR)0x0);
        }
      }
      if (DAT_0043d56c != (code *)0x0) {
        (*DAT_0043d56c)(param_1,0x20,param_3,param_4);
        return 0;
      }
      return 1;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (DAT_0043d574 != (code *)0x0) {
        (*DAT_0043d574)(param_1,0x100,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 0x2c) && (DAT_0043d584 != (code *)0x0)) {
      (*DAT_0043d584)(param_1,0x2c,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      if (DAT_0043d540 != (code *)0x0) {
        (*DAT_0043d540)(param_1,0x111,param_3,param_4);
        return 0;
      }
    }
    else if (param_2 == 0x102) {
      if (DAT_0043d544 != (code *)0x0) {
        (*DAT_0043d544)(param_1,0x102,param_3,param_4);
        return 0;
      }
    }
    else if (param_2 == 0x104) {
      if (DAT_0043d54c != (code *)0x0) {
        (*DAT_0043d54c)(param_1,0x104,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 0x106) && (DAT_0043d548 != (code *)0x0)) {
      (*DAT_0043d548)(param_1,0x106,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x117) {
    if (param_2 == 0x116) {
      if (DAT_0043d578 != (code *)0x0) {
        (*DAT_0043d578)(param_1,0x116,param_3,param_4);
        return 0;
      }
    }
    else if (param_2 == 0x113) {
      FUN_0040b5c6(param_3);
    }
  }
  else if (param_2 < 0x133) {
    if (param_2 == 0x132) {
      if (DAT_0043d5a0 != (code *)0x0) {
        (*DAT_0043d5a0)(param_1,0x132,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 0x11f) && (DAT_0043d57c != (code *)0x0)) {
      (*DAT_0043d57c)(param_1,0x11f,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
      if (DAT_0043d550 != (code *)0x0) {
        (*DAT_0043d550)(param_1,0x200,param_3,param_4);
        return 0;
      }
    }
    else {
      switch(param_2) {
      case 0x133:
        if (DAT_0043d598 != (code *)0x0) {
          (*DAT_0043d598)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x134:
        if (DAT_0043d59c != (code *)0x0) {
          (*DAT_0043d59c)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x135:
        if (DAT_0043d590 != (code *)0x0) {
          (*DAT_0043d590)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x136:
        if (DAT_0043d594 != (code *)0x0) {
          (*DAT_0043d594)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x137:
        if (DAT_0043d5a4 != (code *)0x0) {
          (*DAT_0043d5a4)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x138:
        if (DAT_0043d5a8 != (code *)0x0) {
          (*DAT_0043d5a8)(param_1,param_2,param_3,param_4);
          return 0;
        }
      }
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
      if (DAT_0043d58c != (code *)0x0) {
        (*DAT_0043d58c)(param_1,0x30f,param_3,param_4);
        return 0;
      }
    }
    else {
      switch(param_2) {
      case 0x201:
        if (DAT_0043d554 != (code *)0x0) {
          (*DAT_0043d554)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x202:
        if (DAT_0043d558 != (code *)0x0) {
          (*DAT_0043d558)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x204:
        if (DAT_0043d55c != (code *)0x0) {
          (*DAT_0043d55c)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x205:
        if (DAT_0043d560 != (code *)0x0) {
          (*DAT_0043d560)(param_1,param_2,param_3,param_4);
          return 0;
        }
      }
    }
  }
  else if ((param_2 == 0x311) && (DAT_0043d588 != (code *)0x0)) {
    (*DAT_0043d588)(param_1,0x311,param_3,param_4);
    return 0;
  }
  LVar3 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar3;
}


/*
 * FUN_0040b24c at 0040b24c
 * undefined4 __cdecl FUN_0040b24c(int param_1, undefined4 param_2)
 * Address ranges: 0040b24c-0040b296
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040b24c(int param_1,undefined4 param_2)

{
  if ((param_1 < 0) || (0x1a < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_message_funtion__t_004316e4);
  }
  else {
    (&DAT_0043d540)[param_1] = param_2;
  }
  return 1;
}


/*
 * FUN_0040b2a0 at 0040b2a0
 * undefined4 __cdecl FUN_0040b2a0(int param_1)
 * Address ranges: 0040b2a0-0040b35a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040b2a0(int param_1)

{
  int local_8;
  
  DAT_0043d5ac = LocalAlloc(0x40,param_1 * 0xc);
  if (DAT_0043d5ac == (HLOCAL)0x0) {
    FUN_0040187a((byte *)s__s__d____error_not_enough_memory_0043173c);
  }
  DAT_0043d5b0 = param_1;
  for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
    *(undefined4 *)((int)DAT_0043d5ac + local_8 * 0xc) = 0xffffffff;
    *(undefined4 *)((int)DAT_0043d5ac + local_8 * 0xc + 4) = 0xffffffff;
    *(undefined4 *)((int)DAT_0043d5ac + local_8 * 0xc + 8) = 0;
  }
  DAT_0043d5b4 = 1;
  FUN_004015a6((byte *)s_timer_init_ok____d_00431780);
  return 0;
}


/*
 * FUN_0040b35b at 0040b35b
 * int __stdcall FUN_0040b35b(void)
 * Address ranges: 0040b35b-0040b3dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0040b35b(void)

{
  int local_8;
  
  if (DAT_0043d5b4 == 0) {
    FUN_0040187a((byte *)s__s__d____trying_to_reference_uni_004317a0);
  }
  local_8 = 0;
  while( true ) {
    if (DAT_0043d5b0 <= local_8) {
      return -1;
    }
    if (((*(int *)(DAT_0043d5ac + local_8 * 0xc) == -1) &&
        (*(int *)(DAT_0043d5ac + 4 + local_8 * 0xc) == -1)) &&
       (*(int *)(DAT_0043d5ac + 8 + local_8 * 0xc) == 0)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_0040b3de at 0040b3de
 * undefined4 __cdecl FUN_0040b3de(undefined4 param_1, UINT param_2, UINT_PTR param_3)
 * Address ranges: 0040b3de-0040b49f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040b3de(undefined4 param_1,UINT param_2,UINT_PTR param_3)

{
  int iVar1;
  UINT_PTR UVar2;
  undefined4 uVar3;
  
  if (DAT_0043d5b4 == 0) {
    FUN_0040187a((byte *)s__s__d____trying_to_reference_uni_004317f0);
  }
  iVar1 = FUN_0040b35b();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____out_of_timer_place_hold_00431840);
  }
  UVar2 = SetTimer(DAT_0043842c,param_3,param_2,(TIMERPROC)0x0);
  *(UINT_PTR *)(DAT_0043d5ac + iVar1 * 0xc) = UVar2;
  if (*(int *)(DAT_0043d5ac + iVar1 * 0xc) == 0) {
    uVar3 = 10000;
  }
  else {
    *(UINT *)(DAT_0043d5ac + 4 + iVar1 * 0xc) = param_2;
    *(undefined4 *)(DAT_0043d5ac + 8 + iVar1 * 0xc) = param_1;
    FUN_004015a6((byte *)s_timer_set____d_00431870);
    uVar3 = 0;
  }
  return uVar3;
}


/*
 * FUN_0040b4a0 at 0040b4a0
 * undefined4 __cdecl FUN_0040b4a0(int param_1)
 * Address ranges: 0040b4a0-0040b541
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040b4a0(int param_1)

{
  undefined4 local_8;
  
  if (DAT_0043d5b4 != 0) {
    for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d5ac + local_8 * 0xc) == param_1) {
        *(undefined4 *)(DAT_0043d5ac + local_8 * 0xc) = 0xffffffff;
        *(undefined4 *)(DAT_0043d5ac + 4 + local_8 * 0xc) = 0xffffffff;
        *(undefined4 *)(DAT_0043d5ac + 8 + local_8 * 0xc) = 0;
        KillTimer(DAT_0043842c,*(UINT_PTR *)(DAT_0043d5ac + local_8 * 0xc));
      }
    }
  }
  return 0;
}


/*
 * FUN_0040b542 at 0040b542
 * undefined4 __stdcall FUN_0040b542(void)
 * Address ranges: 0040b542-0040b5c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040b542(void)

{
  int local_8;
  
  if (DAT_0043d5b4 != 0) {
    for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
      if (((*(int *)(DAT_0043d5ac + local_8 * 0xc) != -1) &&
          (*(int *)(DAT_0043d5ac + 4 + local_8 * 0xc) != -1)) &&
         (*(int *)(DAT_0043d5ac + 8 + local_8 * 0xc) != 0)) {
        FUN_0040b4a0(*(int *)(DAT_0043d5ac + local_8 * 0xc));
      }
    }
  }
  return 0;
}


/*
 * FUN_0040b5c6 at 0040b5c6
 * undefined4 __cdecl FUN_0040b5c6(int param_1)
 * Address ranges: 0040b5c6-0040b643
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040b5c6(int param_1)

{
  int local_8;
  
  if (DAT_0043d5b4 != 0) {
    for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
      if (((*(int *)(DAT_0043d5ac + local_8 * 0xc) == param_1) &&
          (*(int *)(DAT_0043d5ac + 4 + local_8 * 0xc) != -1)) &&
         (*(int *)(DAT_0043d5ac + 8 + local_8 * 0xc) != 0)) {
        (**(code **)(DAT_0043d5ac + 8 + local_8 * 0xc))();
      }
    }
  }
  return 0;
}


/*
 * FUN_0040b650 at 0040b650
 * undefined4 __thiscall FUN_0040b650(void * this, undefined4 param_1, uint param_2)
 * Address ranges: 0040b650-0040b7df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040b650(void *this,undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DirectInputCreateA(param_1,0x500,&DAT_0043d6c4,0,this);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____failed_to_create_direct_0043188c);
  }
  if ((param_2 & 1) != 0) {
    FUN_0040187a((byte *)s__s__d____not_yet_implemented_004318d0);
  }
  if ((param_2 & 2) != 0) {
    iVar1 = (**(code **)(*DAT_0043d6c4 + 0xc))(DAT_0043d6c4,&DAT_00429500,&DAT_0043d6c0,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_create_keyboa_004318fc);
    }
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x2c))(DAT_0043d6c0,&DAT_0041e410);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_data_form_0043193c);
    }
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x34))(DAT_0043d6c0,DAT_0043842c,6);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_coop_leve_0043198c);
    }
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x1c))(DAT_0043d6c0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_Acquire_the_k_004319dc);
    }
    DAT_0043d6cc = 1;
  }
  DAT_0043d6c8 = 1;
  return 0;
}


/*
 * FUN_0040b7e0 at 0040b7e0
 * undefined __thiscall FUN_0040b7e0(void * this, uint param_1)
 * Address ranges: 0040b7e0-0040b8a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0040b7e0(void *this,uint param_1)

{
  int iVar1;
  
  if (DAT_0043d6c8 == 0) {
    FUN_0040187a((byte *)s__s__d____error_input_devices_hav_00431a20);
  }
  if ((param_1 & 2) != 0) {
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x40))(DAT_0043d6c0,DAT_0043842c,0,this);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____error_running_keyboard_c_00431a68);
    }
  }
  if ((param_1 & 1) != 0) {
    iVar1 = (**(code **)(*DAT_0043d5b8 + 0x40))(DAT_0043d5b8,DAT_0043842c,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____error_running_mouse_con_00431aac);
    }
  }
  return;
}


/*
 * FUN_0040b8a3 at 0040b8a3
 * undefined1 __thiscall FUN_0040b8a3(void * this, int param_1)
 * Address ranges: 0040b8a3-0040b917
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __thiscall FUN_0040b8a3(void *this,int param_1)

{
  int iVar1;
  
  if (DAT_0043d6cc == 0) {
    FUN_0040187a((byte *)s__s__d____error_keyboard_device_w_00431aec);
  }
  iVar1 = (**(code **)(*DAT_0043d6c0 + 0x24))(DAT_0043d6c0,0x100,&DAT_0043d5c0,this);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_keyboard_d_00431b2c);
  }
  return (&DAT_0043d5c0)[param_1];
}


/*
 * FUN_0040b918 at 0040b918
 * undefined __stdcall FUN_0040b918(void)
 * Address ranges: 0040b918-0040b9af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040b918(void)

{
  if (DAT_0043d6c8 != 0) {
    if (DAT_0043d6cc != 0) {
      DAT_0043d6cc = 0;
      (**(code **)(*DAT_0043d6c0 + 0x20))(DAT_0043d6c0);
      (**(code **)(*DAT_0043d6c0 + 8))(DAT_0043d6c0);
    }
    if (DAT_0043d6d0 != 0) {
      DAT_0043d6d0 = 0;
      (**(code **)(*DAT_0043d5b8 + 0x20))(DAT_0043d5b8);
      (**(code **)(*DAT_0043d5b8 + 8))(DAT_0043d5b8);
    }
    (**(code **)(*DAT_0043d6c4 + 8))(DAT_0043d6c4);
    DAT_0043d6c8 = 0;
  }
  return;
}


/*
 * FUN_0040b9b0 at 0040b9b0
 * int __cdecl FUN_0040b9b0(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040b9b0-0040ba4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040b9b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431b68);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_xsize_of_mem_image_w_00431ba8);
  }
  if (*(int *)(DAT_0043d6e8 + 8 + param_3 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____suspect_illegal_image_x_00431be0);
  }
  return DAT_0043d6e8 + 8 + param_3 * 0x20;
}


/*
 * FUN_0040ba4c at 0040ba4c
 * int __cdecl FUN_0040ba4c(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040ba4c-0040bae7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040ba4c(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431c0c);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_ysize_of_mem_image_w_00431c4c);
  }
  if (*(int *)(DAT_0043d6e8 + 0xc + param_3 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____suspect_illegal_image_y_00431c84);
  }
  return DAT_0043d6e8 + 0xc + param_3 * 0x20;
}


/*
 * FUN_0040bae8 at 0040bae8
 * int __cdecl FUN_0040bae8(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040bae8-0040bb4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040bae8(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431cb0);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_mx_of_mem_image_whi_00431cec);
  }
  return DAT_0043d6e8 + 0x10 + param_3 * 0x20;
}


/*
 * FUN_0040bb4c at 0040bb4c
 * int __cdecl FUN_0040bb4c(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040bb4c-0040bbaf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040bb4c(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431d24);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_my_of_mem_image_whi_00431d60);
  }
  return DAT_0043d6e8 + 0x14 + param_3 * 0x20;
}


/*
 * FUN_0040bbb0 at 0040bbb0
 * undefined __cdecl FUN_0040bbb0(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0040bbb0-0040bbcf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040bbb0(undefined4 param_1,undefined4 param_2)

{
  _DAT_0043d6e0 = param_1;
  DAT_0043d6e4 = param_2;
  DAT_0043d6dc = 1;
  return;
}


/*
 * FUN_0040bbd0 at 0040bbd0
 * undefined __stdcall FUN_0040bbd0(void)
 * Address ranges: 0040bbd0-0040bbde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040bbd0(void)

{
  DAT_0043d6dc = 0;
  return;
}


/*
 * FUN_0040bbdf at 0040bbdf
 * undefined __stdcall FUN_0040bbdf(void)
 * Address ranges: 0040bbdf-0040bc0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040bbdf(void)

{
  if ((DAT_0043d6f8 != 0) && (DAT_0043d6f8 = 0, DAT_0043d6d4 != (LPVOID)0x0)) {
    FUN_0041fd93(DAT_0043d6d4);
  }
  return;
}


/*
 * FUN_0040bc0e at 0040bc0e
 * undefined4 __cdecl FUN_0040bc0e(int param_1)
 * Address ranges: 0040bc0e-0040bce0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040bc0e(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  if (DAT_0043d6f8 != 0) {
    FUN_0040bbdf();
  }
  DAT_0043d6d4 = LocalAlloc(0x40,param_1 * 0x18);
  if (DAT_0043d6d4 == (HLOCAL)0x0) {
    uVar1 = 2000;
  }
  else {
    DAT_0043d6d8 = param_1;
    for (local_8 = 0; local_8 < DAT_0043d6d8; local_8 = local_8 + 1) {
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 8) = 0;
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 0xc) = 0;
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 0x10) = 0;
      *(int *)((int)DAT_0043d6d4 + local_8 * 0x18 + 0x14) = local_8;
      *(undefined4 *)((int)DAT_0043d6d4 + local_8 * 0x18 + 4) = 0;
    }
    DAT_0043d6f8 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_0040bce1 at 0040bce1
 * undefined __cdecl FUN_0040bce1(int param_1, int param_2)
 * Address ranges: 0040bce1-0040bd50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040bce1(int param_1,int param_2)

{
  if ((param_1 < 0) || (DAT_0043d6d8 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_sprite_index__d_00431da4);
  }
  if ((param_2 < 0) || (DAT_00431b64 <= param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_index_00431dd4);
  }
  *(int *)(DAT_0043d6d4 + 0x10 + param_1 * 0x18) = param_2;
  return;
}


/*
 * FUN_0040bd51 at 0040bd51
 * int __cdecl FUN_0040bd51(int param_1)
 * Address ranges: 0040bd51-0040bdc5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040bd51(int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (DAT_0043d6d8 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_sprite_index__d_00431e08);
  }
  iVar1 = *(int *)(DAT_0043d6d4 + 0x10 + param_1 * 0x18);
  if ((iVar1 < 0) || (DAT_00431b64 <= iVar1)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_index_00431e38);
  }
  return iVar1;
}


/*
 * FUN_0040bdc6 at 0040bdc6
 * undefined4 __cdecl FUN_0040bdc6(int param_1)
 * Address ranges: 0040bdc6-0040be71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040bdc6(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  if (param_1 < 1) {
    uVar1 = 2000;
  }
  else {
    DAT_00431b64 = param_1;
    DAT_0043d6e8 = LocalAlloc(0x40,param_1 << 5);
    if (DAT_0043d6e8 == (HLOCAL)0x0) {
      uVar1 = 2000;
    }
    else {
      for (local_8 = 0; local_8 < DAT_00431b64; local_8 = local_8 + 1) {
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20) = 0;
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x18) = 4;
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x1c) = 0;
      }
      DAT_0043d6f0 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}


/*
 * FUN_0040be72 at 0040be72
 * undefined4 __cdecl FUN_0040be72(int param_1, int param_2)
 * Address ranges: 0040be72-0040bf51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040be72(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_8;
  
  if (param_1 < 1) {
    uVar1 = 2000;
  }
  else {
    DAT_00431b64 = param_1;
    DAT_0043d6e8 = LocalAlloc(0x40,param_1 << 5);
    if (DAT_0043d6e8 == (HLOCAL)0x0) {
      uVar1 = 2000;
    }
    else {
      if ((param_2 != 2) && (param_2 != 4)) {
        FUN_0040187a((byte *)s__s__d____alloc_mem_images___unko_00431e6c);
      }
      for (local_8 = 0; local_8 < DAT_00431b64; local_8 = local_8 + 1) {
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20) = 0;
        *(int *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x18) = param_2;
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x1c) = 0;
      }
      DAT_0043d6f0 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}


/*
 * FUN_0040bf52 at 0040bf52
 * undefined4 __stdcall FUN_0040bf52(void)
 * Address ranges: 0040bf52-0040bfeb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040bf52(void)

{
  void *local_8;
  
  if ((DAT_0043d6f0 != 0) && (DAT_0043d6f4 != 0)) {
    for (local_8 = (void *)0x0; (int)local_8 < DAT_00431b64; local_8 = (void *)((int)local_8 + 1)) {
      FUN_0040c32a(local_8,(int)local_8);
    }
    if (DAT_0043d6f0 != 0) {
      if (DAT_0043d6e8 != (LPVOID)0x0) {
        FUN_0041fd93(DAT_0043d6e8);
      }
      DAT_0043d6f0 = 0;
    }
    DAT_00431b64 = -1;
    DAT_0043d6e8 = (LPVOID)0x0;
    DAT_0043d6f4 = 0;
  }
  return 0;
}


/*
 * FUN_0040bfec at 0040bfec
 * undefined4 __cdecl FUN_0040bfec(int param_1)
 * Address ranges: 0040bfec-0040c329
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040bfec(int param_1)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_10;
  uint local_c;
  SIZE_T local_8;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00431eac);
  }
  if (*(int *)(DAT_0043d6e8 + 8 + param_1 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_xsize____d___00431eec);
  }
  if (*(int *)(DAT_0043d6e8 + 0xc + param_1 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_ysize____d___00431f24);
  }
  local_8 = *(int *)(DAT_0043d6e8 + 8 + param_1 * 0x20) *
            *(int *)(DAT_0043d6e8 + 0xc + param_1 * 0x20);
  iVar3 = *(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20);
  if (iVar3 == 2) {
    if (DAT_0043d6dc == 0) {
      uVar2 = FUN_004028e3(*(undefined4 *)(DAT_0043d6e8 + 8 + param_1 * 0x20),
                           *(undefined4 *)(DAT_0043d6e8 + 0xc + param_1 * 0x20));
      *(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20) = uVar2;
      if (*(int *)(DAT_0043d6e8 + 4 + param_1 * 0x20) == 0) {
        return 2000;
      }
    }
    else {
      uVar2 = FUN_004028e3(*(undefined4 *)(DAT_0043d6e8 + 8 + param_1 * 0x20),
                           *(undefined4 *)(DAT_0043d6e8 + 0xc + param_1 * 0x20));
      *(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20) = uVar2;
      if (DAT_0043d6e4 == 0) {
        return 2000;
      }
    }
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar3 = (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20) + 0x74))
                      (*(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20),8,&local_10);
    if (iVar3 != 0) {
      FUN_00401f61(iVar3);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_00431f9c);
    }
    *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 1;
  }
  else if (iVar3 == 4) {
    if ((int)local_8 < 1) {
      FUN_0040187a((byte *)s__s__d____error_illegal_mem_image_00431f5c);
    }
    pvVar1 = LocalAlloc(0x40,local_8);
    *(HLOCAL *)(DAT_0043d6e8 + param_1 * 0x20) = pvVar1;
    if (*(int *)(DAT_0043d6e8 + param_1 * 0x20) == 0) {
      return 2000;
    }
    *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 1;
  }
  else {
    FUN_0040187a((byte *)s__s__d____illegal_alloc_type__d_f_00431fd0);
  }
  return 0;
}


/*
 * FUN_0040c32a at 0040c32a
 * undefined4 __thiscall FUN_0040c32a(void * this, int param_1)
 * Address ranges: 0040c32a-0040c43c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040c32a(void *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00432010);
  }
  iVar1 = *(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20);
  if (iVar1 == 2) {
    if (*(int *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) != 0) {
      *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 0;
      (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20) + 8))
                (*(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20));
    }
  }
  else if (iVar1 == 4) {
    if (*(int *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) != 0) {
      *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 0;
      FUN_0041fd93(*(LPVOID *)(DAT_0043d6e8 + param_1 * 0x20));
    }
  }
  else {
    FUN_0040187a((byte *)s__s__d____illegal_alloc_type__d_f_00432050);
  }
  return 0;
}


/*
 * FUN_0040c43d at 0040c43d
 * undefined4 __cdecl FUN_0040c43d(int param_1)
 * Address ranges: 0040c43d-0040c4a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040c43d(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00432090);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20) == 2) {
    uVar1 = FUN_0040235c(*(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20));
    *(undefined4 *)(DAT_0043d6e8 + param_1 * 0x20) = uVar1;
  }
  return 0;
}


/*
 * FUN_0040c4aa at 0040c4aa
 * undefined4 __cdecl FUN_0040c4aa(int param_1, undefined4 * param_2)
 * Address ranges: 0040c4aa-0040c530
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040c4aa(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_004320d0);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20) == 2) {
    uVar1 = FUN_00402631(*(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20),param_2);
    *(undefined4 *)(DAT_0043d6e8 + param_1 * 0x20) = uVar1;
  }
  else {
    *param_2 = *(undefined4 *)(DAT_0043d6e8 + 8 + param_1 * 0x20);
  }
  return 0;
}


/*
 * FUN_0040c531 at 0040c531
 * undefined4 __cdecl FUN_0040c531(int param_1)
 * Address ranges: 0040c531-0040c59e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040c531(int param_1)

{
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00432110);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20) == 2) {
    FUN_004027f9(*(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20),
                 *(undefined4 *)(DAT_0043d6e8 + param_1 * 0x20));
  }
  return 0;
}


/*
 * FUN_0040c59f at 0040c59f
 * undefined4 __cdecl FUN_0040c59f(LPCSTR param_1, LPCSTR param_2, int param_3)
 * Address ranges: 0040c59f-0040cae2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040c59f(LPCSTR param_1,LPCSTR param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  short *local_58;
  int local_54;
  uint local_50;
  short *local_4c;
  int local_48;
  uint local_44;
  short *local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  short local_2c [2];
  FILE *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  FILE *local_c;
  short *local_8;
  
  if (DAT_0043d6f4 == 0) {
    uVar1 = 0;
  }
  else {
    local_28 = (FILE *)FUN_0041f4c6(param_1,&DAT_00432144);
    if (local_28 == (FILE *)0x0) {
      uVar1 = 1000;
    }
    else {
      local_c = (FILE *)FUN_0041f4c6(param_2,&DAT_00432148);
      if (local_c == (FILE *)0x0) {
        FUN_0041f368(local_28);
        uVar1 = 1000;
      }
      else {
        DAT_0043d6ec = 0;
        for (local_20 = 0; -1 < *(int *)(param_3 + local_20 * 4); local_20 = local_20 + 1) {
          FUN_0041fd07((int *)local_c,*(int *)(param_3 + local_20 * 4) * 4 + -2,0);
          if ((local_c->_flag & 0x20U) != 0) {
            FUN_0040187a((byte *)s__s__d____index_file_seek_error___00432158);
          }
          FUN_0041f3be((char *)&local_1c,1,4,(int *)local_c);
          if ((local_c->_flag & 0x20U) != 0) {
            FUN_0041f368(local_28);
            return 0x3e9;
          }
          FUN_0041fd07((int *)local_28,local_1c,0);
          if ((local_28->_flag & 0x20U) != 0) {
            FUN_0041f368(local_28);
            return 0x3e9;
          }
          local_18 = *(int *)(param_3 + local_20 * 4);
          FUN_0041f3be((char *)(DAT_0043d6e8 + 8 + local_18 * 0x20),1,2,(int *)local_28);
          FUN_0041f3be((char *)(DAT_0043d6e8 + 0xc + local_18 * 0x20),1,2,(int *)local_28);
          FUN_0041f3be((char *)local_2c,1,2,(int *)local_28);
          *(int *)(DAT_0043d6e8 + 0x10 + local_18 * 0x20) = (int)local_2c[0];
          FUN_0041f3be((char *)local_2c,1,2,(int *)local_28);
          *(int *)(DAT_0043d6e8 + 0x14 + local_18 * 0x20) = (int)local_2c[0];
          local_10 = *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20) *
                     *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
          DAT_0043d6ec = DAT_0043d6ec + local_10;
          FUN_0040bfec(local_18);
          FUN_0040c4aa(local_18,&local_24);
          local_8 = *(short **)(DAT_0043d6e8 + local_18 * 0x20);
          switch(DAT_0043d754) {
          case 0:
            FUN_004015a6((byte *)s_pf_none_004321e4);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              FUN_0041f3be((char *)local_8,1,*(uint *)(DAT_0043d6e8 + 8 + local_18 * 0x20),
                           (int *)local_28);
              local_8 = (short *)((int)local_8 + local_24);
            }
            break;
          case 1:
            FUN_004015a6((byte *)s_converting_to_16_bits_004321b4);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              local_4c = local_8;
              for (local_48 = 0; local_48 < *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20);
                  local_48 = local_48 + 1) {
                FUN_0041f3be((char *)&local_44,1,1,(int *)local_28);
                uVar2 = FUN_0040de93(local_44 & 0xff,8);
                *local_4c = (short)uVar2;
                local_4c = local_4c + 1;
              }
              local_8 = (short *)((int)local_8 + local_24);
            }
            break;
          case 2:
            FUN_004015a6((byte *)s_converting_to_24_bits_004321cc);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              local_58 = local_8;
              for (local_54 = 0; local_54 < *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20);
                  local_54 = local_54 + 1) {
                FUN_0041f3be((char *)&local_50,1,1,(int *)local_28);
                FUN_0040e0c3(local_50 & 0xff,8,local_58);
                local_58 = (short *)((int)local_58 + 3);
              }
              local_8 = (short *)((int)local_8 + local_24);
            }
            break;
          case 4:
            FUN_004015a6((byte *)s_converting_from_24_to_16_bits_00432194);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              local_40 = local_8;
              for (local_3c = 0; local_3c < *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20);
                  local_3c = local_3c + 1) {
                FUN_0041f3be((char *)&local_34,1,1,(int *)local_28);
                FUN_0041f3be((char *)&local_38,1,1,(int *)local_28);
                FUN_0041f3be((char *)&local_30,1,1,(int *)local_28);
                uVar2 = FUN_0040de93(local_34 & 0xff | (local_38 & 0xff) << 8 |
                                     (local_30 & 0xff) << 0x10,0x18);
                *local_40 = (short)uVar2;
                local_40 = local_40 + 1;
              }
              local_8 = (short *)((int)local_8 + local_24);
            }
          }
          FUN_0040c531(local_18);
        }
        FUN_0041f368(local_c);
        FUN_0041f368(local_28);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_0040caf7 at 0040caf7
 * undefined4 __cdecl FUN_0040caf7(void * param_1)
 * Address ranges: 0040caf7-0040cb3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040caf7(void *param_1)

{
  undefined4 local_8;
  
  if (DAT_0043d6f4 != 0) {
    for (local_8 = 0; -1 < *(int *)((int)param_1 + local_8 * 4); local_8 = local_8 + 1) {
      FUN_0040c32a(param_1,*(int *)((int)param_1 + local_8 * 4));
    }
  }
  return 0;
}


/*
 * FUN_0040cb40 at 0040cb40
 * undefined4 __stdcall FUN_0040cb40(void)
 * Address ranges: 0040cb40-0040cb81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040cb40(void)

{
  undefined4 local_8;
  
  if (DAT_0043d6f4 != 0) {
    for (local_8 = (void *)0x0; (int)local_8 < DAT_00431b64; local_8 = (void *)((int)local_8 + 1)) {
      FUN_0040c32a(local_8,(int)local_8);
    }
  }
  return 0;
}


/*
 * FUN_0040cb82 at 0040cb82
 * undefined4 __stdcall FUN_0040cb82(void)
 * Address ranges: 0040cb82-0040cc46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040cb82(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int local_c;
  
  if (DAT_0043d6f4 != 0) {
    FUN_004015a6((byte *)s_starting_to_show_images_2_004321f0);
    for (local_c = 0; local_c < DAT_00431b64; local_c = local_c + 1) {
      if (*(int *)(DAT_0043d6e8 + local_c * 0x20) != 0) {
        uVar3 = 1;
        uVar1 = FUN_0041f8f2();
        iVar2 = (int)uVar1 % DAT_0042c354;
        uVar1 = FUN_0041f8f2();
        FUN_004105ee(0,local_c,(int)uVar1 % DAT_0042c350,iVar2,uVar3);
        iVar2 = FUN_004133f0(0xd);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_004133f0(0x20);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_004133f0(0x1b);
        if (iVar2 != 0) {
          return 0;
        }
      }
    }
    FUN_004015a6((byte *)s_done_show_images_0043220c);
  }
  return 0;
}


/*
 * FUN_0040cc47 at 0040cc47
 * undefined4 __cdecl FUN_0040cc47(LPCSTR param_1, uint param_2)
 * Address ranges: 0040cc47-0040d17a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040cc47(LPCSTR param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  short *local_64;
  int local_60;
  uint local_5c;
  short *local_58;
  int local_54;
  uint local_50;
  short *local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  short local_38 [2];
  FILE *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  short local_20 [2];
  short local_1c [2];
  short local_18 [2];
  int local_14;
  short *local_10;
  short local_c [2];
  uint local_8;
  
  local_8 = 0;
  local_24 = 4;
  local_34 = (FILE *)FUN_0041f4c6(param_1,&DAT_00432220);
  if (local_34 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_0041fdc2((int *)local_34);
    FUN_0041f3be((char *)local_18,1,2,(int *)local_34);
    DAT_00431b64 = local_18[0] + 1;
    FUN_004015a6((byte *)s__s_maxmemimages____d_00432224);
    local_8 = (uint)((param_2 & 1) == 1);
    local_24 = param_2 - local_8;
    iVar2 = FUN_0040be72(DAT_00431b64,local_24);
    if (iVar2 == 0) {
      if (local_8 == 0) {
        if (DAT_0043d6f0 != 0) {
          for (local_2c = 0; local_2c < DAT_00431b64; local_2c = local_2c + 1) {
            *(undefined4 *)(DAT_0043d6e8 + local_2c * 0x20) = 0;
            *(undefined4 *)(DAT_0043d6e8 + 0x1c + local_2c * 0x20) = 0;
            *(int *)(DAT_0043d6e8 + 0x18 + local_2c * 0x20) = local_24;
          }
        }
      }
      else {
        DAT_0043d6f4 = 1;
        FUN_004015a6((byte *)s__s_allocating_images_0043223c);
        for (local_2c = 0; local_2c < DAT_00431b64; local_2c = local_2c + 1) {
          FUN_004015a6((byte *)s__s_allocating_image__d_00432254);
          FUN_0041f3be((char *)local_38,1,2,(int *)local_34);
          FUN_0041f3be((char *)local_20,1,2,(int *)local_34);
          FUN_0041f3be((char *)local_1c,1,2,(int *)local_34);
          FUN_0041f3be((char *)local_c,1,2,(int *)local_34);
          *(int *)(DAT_0043d6e8 + 8 + local_2c * 0x20) = (int)local_38[0];
          *(int *)(DAT_0043d6e8 + 0xc + local_2c * 0x20) = (int)local_20[0];
          *(int *)(DAT_0043d6e8 + 0x10 + local_2c * 0x20) = (int)local_1c[0];
          *(int *)(DAT_0043d6e8 + 0x14 + local_2c * 0x20) = (int)local_c[0];
          local_14 = *(int *)(DAT_0043d6e8 + 8 + local_2c * 0x20) *
                     *(int *)(DAT_0043d6e8 + 0xc + local_2c * 0x20);
          FUN_0040bfec(local_2c);
          FUN_0040c4aa(local_2c,&local_30);
          local_10 = *(short **)(DAT_0043d6e8 + local_2c * 0x20);
          switch(DAT_0043d754) {
          case 0:
            for (local_28 = 0; local_28 < local_20[0]; local_28 = local_28 + 1) {
              FUN_0041f3be((char *)local_10,1,(int)local_38[0],(int *)local_34);
              local_10 = (short *)((int)local_10 + local_30);
            }
            break;
          case 1:
            for (local_28 = 0; local_28 < local_20[0]; local_28 = local_28 + 1) {
              local_58 = local_10;
              for (local_54 = 0; local_54 < local_38[0]; local_54 = local_54 + 1) {
                FUN_0041f3be((char *)&local_50,1,1,(int *)local_34);
                uVar3 = FUN_0040de93(local_50 & 0xff,8);
                *local_58 = (short)uVar3;
                local_58 = local_58 + 1;
              }
              local_10 = (short *)((int)local_10 + local_30);
            }
            break;
          case 2:
            for (local_28 = 0; local_28 < local_20[0]; local_28 = local_28 + 1) {
              local_64 = local_10;
              for (local_60 = 0; local_60 < local_38[0]; local_60 = local_60 + 1) {
                FUN_0041f3be((char *)&local_5c,1,1,(int *)local_34);
                FUN_0040e0c3(local_5c & 0xff,8,local_64);
                local_64 = (short *)((int)local_64 + 3);
              }
              local_10 = (short *)((int)local_10 + local_30);
            }
            break;
          case 4:
            FUN_004015a6((byte *)s_converting_from_24_to_16_bits_0043226c);
            for (local_28 = 0; local_28 < *(int *)(DAT_0043d6e8 + 0xc + local_2c * 0x20);
                local_28 = local_28 + 1) {
              local_4c = local_10;
              for (local_48 = 0; local_48 < *(int *)(DAT_0043d6e8 + 8 + local_2c * 0x20);
                  local_48 = local_48 + 1) {
                FUN_0041f3be((char *)&local_40,1,1,(int *)local_34);
                FUN_0041f3be((char *)&local_44,1,1,(int *)local_34);
                FUN_0041f3be((char *)&local_3c,1,1,(int *)local_34);
                uVar3 = FUN_0040de93(local_40 & 0xff | (local_44 & 0xff) << 8 |
                                     (local_3c & 0xff) << 0x10,0x18);
                *local_4c = (short)uVar3;
                local_4c = local_4c + 1;
              }
              local_10 = (short *)((int)local_10 + local_30);
            }
          }
          FUN_0040c531(local_2c);
          if ((local_34->_flag & 0x20U) != 0) {
            DAT_0043d6f4 = 0;
            FUN_0041f368(local_34);
            return 0x3e9;
          }
        }
        FUN_004015a6((byte *)s__s_allocating_images_done_0043228c);
      }
      FUN_0041f368(local_34);
      DAT_0043d6f4 = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 2000;
    }
  }
  return uVar1;
}


/*
 * FUN_0040d190 at 0040d190
 * undefined __stdcall FUN_0040d190(void)
 * Address ranges: 0040d190-0040d1b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040d190(void)

{
  if (DAT_0043d6fc != (int *)0x0) {
    (**(code **)(*DAT_0043d6fc + 8))(DAT_0043d6fc);
    DAT_0043d6fc = (int *)0x0;
  }
  return;
}


/*
 * FUN_0040d1b9 at 0040d1b9
 * undefined __stdcall FUN_0040d1b9(void)
 * Address ranges: 0040d1b9-0040d38c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040d1b9(void)

{
  uint uVar1;
  int local_28;
  int local_24;
  undefined2 *local_20;
  undefined2 *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  undefined2 *local_8;
  
  DAT_0043d6fc = (int *)FUN_004028e3(8,8);
  if (DAT_0043d754 == 0) {
    local_c = DAT_0042c4d0;
    local_10 = DAT_0042c4d0;
  }
  else {
    if (DAT_0043d754 != 1) {
      if (DAT_0043d754 != 4) goto LAB_0040d230;
      local_10 = FUN_0040de93(DAT_00438474,0x18);
      local_c = local_10;
    }
    local_10 = FUN_0040de93(DAT_0042c4d0,8);
    local_c = local_10;
  }
LAB_0040d230:
  local_24 = (**(code **)(*DAT_0043d6fc + 0x74))(DAT_0043d6fc,8,&local_10);
  if (local_24 != 0) {
    FUN_00401f61(local_24);
    FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_00432330);
  }
  local_8 = (undefined2 *)FUN_00402631(DAT_0043d6fc,&local_28);
  for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
    local_20 = local_8;
    local_1c = local_8;
    for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
      if (DAT_0043d754 == 0) {
        *(undefined *)local_1c = (&DAT_004322a8)[local_18 * 8 + local_14];
        local_1c = (undefined2 *)((int)local_1c + 1);
      }
      else if (DAT_0043d754 == 1) {
        uVar1 = FUN_0040de93((uint)(byte)(&DAT_004322a8)[local_18 * 8 + local_14],8);
        *local_20 = (short)uVar1;
        local_20 = local_20 + 1;
      }
      else if (DAT_0043d754 == 4) {
        uVar1 = FUN_0040de93(-(uint)((&DAT_004322a8)[local_18 * 8 + local_14] != '\0') &
                             DAT_00438474,0x18);
        *local_20 = (short)uVar1;
        local_20 = local_20 + 1;
      }
    }
    local_8 = (undefined2 *)((int)local_8 + local_28);
  }
  FUN_004027f9(DAT_0043d6fc,local_8);
  return;
}


/*
 * FUN_0040d38d at 0040d38d
 * undefined __cdecl FUN_0040d38d(int param_1)
 * Address ranges: 0040d38d-0040d64e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040d38d(int param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 0;
  local_1c = 0;
  if (DAT_0043d6fc != 0) {
    local_2c = 0;
    local_24 = 8;
    local_28 = 0;
    local_20 = 8;
    if (param_1 == 0) {
      FUN_004028c2(DAT_00438434);
      for (local_1c = 0; local_1c < DAT_0042c354; local_1c = local_1c + 8) {
        local_10 = local_1c;
        local_8 = local_1c + 8;
        for (local_18 = 0; local_18 < DAT_0042c350; local_18 = local_18 + 8) {
          local_14 = local_18;
          local_c = local_18 + 8;
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_14,DAT_0043d6fc,&local_2c,0x1008000,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____help_grid_blitting_erro_00432364);
          }
        }
      }
    }
    else if (param_1 == 1) {
      FUN_004028c2(DAT_00438438);
      for (local_1c = 0; local_1c < DAT_0042c354; local_1c = local_1c + 8) {
        local_10 = local_1c;
        local_8 = local_1c + 8;
        for (local_18 = 0; local_18 < DAT_0042c350; local_18 = local_18 + 8) {
          local_14 = local_18;
          local_c = local_18 + 8;
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_14,DAT_0043d6fc,&local_2c,0x1008000,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____help_grid_blitting_erro_00432394);
          }
        }
      }
    }
    else if (param_1 == 2) {
      FUN_004028c2(DAT_00438418);
      for (local_1c = 0; local_1c < DAT_0042c354; local_1c = local_1c + 8) {
        local_10 = local_1c;
        local_8 = local_1c + 8;
        for (local_18 = 0; local_18 < DAT_0042c350; local_18 = local_18 + 8) {
          local_14 = local_18;
          local_c = local_18 + 8;
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_14,DAT_0043d6fc,&local_2c,0x1008000,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____help_grid_blitting_erro_004323c4);
          }
        }
      }
    }
  }
  return;
}


/*
 * FUN_0040d64f at 0040d64f
 * undefined __cdecl FUN_0040d64f(int param_1, int param_2)
 * Address ranges: 0040d64f-0040d82c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040d64f(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  HWND hWnd;
  int iVar3;
  uint local_18;
  int local_c;
  
  local_c = 0;
  bVar1 = false;
  FUN_00404b2d();
  iVar2 = FUN_00412061();
  if (iVar2 == 1) {
    param_2 = 2;
  }
  hWnd = GetFocus();
  SetFocus(DAT_0043842c);
  FUN_0040f8b1(0,param_2,0,0,DAT_0042c350,DAT_0042c354,0);
  iVar2 = FUN_0041289c();
  if (iVar2 == 0) {
    FUN_0040187a((byte *)s__s__d_____play_help__empty_form_o_004323f4);
  }
  do {
    if ((*(int *)(param_1 + local_c * 8) == -1) || (bVar1)) {
      FUN_004066a0(local_18);
      iVar2 = FUN_00412061();
      if (iVar2 == 0) {
        FUN_0040f8b1(param_2,0,0,0,DAT_0042c350,DAT_0042c354,0);
      }
      else if (iVar2 == 1) {
        FUN_0040f8b1(param_2,1,0,0,DAT_0042c350,DAT_0042c354,0);
        FUN_00401cf3();
      }
      SetFocus(hWnd);
      FUN_00404aee();
      return;
    }
    iVar3 = FUN_00412061();
    FUN_0040d38d(iVar3);
    if ((*(int *)(param_1 + local_c * 8) < 0) || (iVar2 < *(int *)(param_1 + local_c * 8))) {
      FUN_0040187a((byte *)s__s__d_____play_help__illegal_for_00432438);
    }
    local_18 = FUN_00407f2c(*(uint **)(param_1 + 4 + local_c * 8),0);
    FUN_00412bb8(*(int *)(param_1 + local_c * 8));
    iVar3 = FUN_00412061();
    if (iVar3 == 1) {
      FUN_00401cf3();
    }
    do {
      iVar3 = FUN_00406327(local_18);
      if (iVar3 == 0) goto LAB_0040d7a1;
      iVar3 = FUN_0040d82d();
    } while (iVar3 == 0);
    bVar1 = true;
LAB_0040d7a1:
    local_c = local_c + 1;
  } while( true );
}


/*
 * FUN_0040d82d at 0040d82d
 * undefined4 __stdcall FUN_0040d82d(void)
 * Address ranges: 0040d82d-0040d899
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040d82d(void)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (9 < local_8) {
      return 0;
    }
    if ((*(int *)(&DAT_004322f0 + local_8 * 4) != -1) &&
       (iVar1 = FUN_004133f0(*(uint *)(&DAT_004322f0 + local_8 * 4)), iVar1 != 0)) break;
    local_8 = local_8 + 1;
  }
  while (iVar1 = FUN_004133f0(*(uint *)(&DAT_004322f0 + local_8 * 4)), iVar1 != 0) {
    FUN_0040a97d();
  }
  return 1;
}


/*
 * FUN_0040d89a at 0040d89a
 * int __stdcall FUN_0040d89a(void)
 * Address ranges: 0040d89a-0040d8d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0040d89a(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (9 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_004322f0 + local_8 * 4) == -1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_0040d8d1 at 0040d8d1
 * undefined __stdcall FUN_0040d8d1(void)
 * Address ranges: 0040d8d1-0040d900
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040d8d1(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004322f0 + local_8 * 4) = 0xffffffff;
  }
  return;
}


/*
 * FUN_0040d901 at 0040d901
 * undefined __cdecl FUN_0040d901(undefined4 param_1)
 * Address ranges: 0040d901-0040d93e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040d901(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040d89a();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____set_help_key__No_free_k_00432478);
  }
  else {
    *(undefined4 *)(&DAT_004322f0 + iVar1 * 4) = param_1;
  }
  return;
}


/*
 * FUN_0040d940 at 0040d940
 * undefined __cdecl FUN_0040d940(undefined4 param_1)
 * Address ranges: 0040d940-0040d94c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040d940(undefined4 param_1)

{
  DAT_0043d754 = param_1;
  return;
}


/*
 * FUN_0040d94d at 0040d94d
 * undefined4 __stdcall FUN_0040d94d(void)
 * Address ranges: 0040d94d-0040d956
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040d94d(void)

{
  return DAT_0043d754;
}


/*
 * FUN_0040d957 at 0040d957
 * undefined __cdecl FUN_0040d957(int param_1, int param_2, int param_3, COLORREF param_4)
 * Address ranges: 0040d957-0040da04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040d957(int param_1,int param_2,int param_3,COLORREF param_4)

{
  int iVar1;
  int *local_10;
  HDC local_8;
  
  if (param_1 == 0) {
    local_10 = DAT_00438434;
  }
  else if (param_1 == 1) {
    local_10 = DAT_00438438;
  }
  else if (param_1 == 2) {
    local_10 = DAT_00438418;
  }
  FUN_004028c2(local_10);
  iVar1 = (**(code **)(*local_10 + 0x44))(local_10,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_004324c0);
  }
  SetPixel(local_8,param_2,param_3,param_4);
  (**(code **)(*local_10 + 0x68))(local_10,local_8);
  return;
}


/*
 * FUN_0040da05 at 0040da05
 * undefined __cdecl FUN_0040da05(int * param_1, int param_2, int param_3, COLORREF param_4)
 * Address ranges: 0040da05-0040da7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040da05(int *param_1,int param_2,int param_3,COLORREF param_4)

{
  int iVar1;
  HDC local_8;
  
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_004324f8);
  }
  SetPixel(local_8,param_2,param_3,param_4);
  (**(code **)(*param_1 + 0x68))(param_1,local_8);
  return;
}


/*
 * FUN_0040da7b at 0040da7b
 * COLORREF __cdecl FUN_0040da7b(int param_1, int param_2, int param_3)
 * Address ranges: 0040da7b-0040db2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


COLORREF __cdecl FUN_0040da7b(int param_1,int param_2,int param_3)

{
  int iVar1;
  COLORREF CVar2;
  int *local_14;
  HDC local_8;
  
  if (param_1 == 0) {
    local_14 = DAT_00438434;
  }
  else if (param_1 == 1) {
    local_14 = DAT_00438438;
  }
  else if (param_1 == 2) {
    local_14 = DAT_00438418;
  }
  FUN_004028c2(local_14);
  iVar1 = (**(code **)(*local_14 + 0x44))(local_14,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_00432530);
  }
  CVar2 = GetPixel(local_8,param_2,param_3);
  (**(code **)(*local_14 + 0x68))(local_14,local_8);
  return CVar2;
}


/*
 * FUN_0040db2b at 0040db2b
 * COLORREF __cdecl FUN_0040db2b(int * param_1, int param_2, int param_3)
 * Address ranges: 0040db2b-0040dba5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


COLORREF __cdecl FUN_0040db2b(int *param_1,int param_2,int param_3)

{
  int iVar1;
  COLORREF CVar2;
  HDC local_8;
  
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_00432568);
  }
  CVar2 = GetPixel(local_8,param_2,param_3);
  (**(code **)(*param_1 + 0x68))(param_1,local_8);
  return CVar2;
}


/*
 * FUN_0040dba6 at 0040dba6
 * uint __cdecl FUN_0040dba6(int * param_1, int param_2)
 * Address ranges: 0040dba6-0040dc67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0040dba6(int *param_1,int param_2)

{
  int iVar1;
  uint local_7c;
  COLORREF local_74;
  undefined4 local_70 [9];
  uint *local_4c;
  undefined4 local_1c;
  
  local_7c = 0xffffffff;
  FUN_004028c2(param_1);
  if (param_2 != -1) {
    local_74 = FUN_0040db2b(param_1,0,0);
  }
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  do {
    iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,0,0);
  } while (iVar1 == -0x7789fde4);
  if (iVar1 == 0) {
    local_7c = *local_4c & (1 << ((byte)local_1c & 0x1f)) - 1U;
    (**(code **)(*param_1 + 0x80))(param_1,0);
  }
  if (param_2 != -1) {
    FUN_0040da05(param_1,0,0,local_74);
  }
  return local_7c;
}


/*
 * FUN_0040dc68 at 0040dc68
 * undefined __cdecl FUN_0040dc68(int * param_1, int param_2)
 * Address ranges: 0040dc68-0040dcd5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040dc68(int *param_1,int param_2)

{
  int iVar1;
  uint local_c;
  uint local_8;
  
  local_c = FUN_0040dba6(param_1,param_2);
  local_8 = local_c;
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x74))(param_1,8,&local_c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_color_key_004325a0);
  }
  return;
}


/*
 * FUN_0040dcd6 at 0040dcd6
 * undefined __cdecl FUN_0040dcd6(undefined4 param_1)
 * Address ranges: 0040dcd6-0040dce2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040dcd6(undefined4 param_1)

{
  DAT_0043d758 = param_1;
  return;
}


/*
 * FUN_0040dce3 at 0040dce3
 * int __cdecl FUN_0040dce3(uint param_1)
 * Address ranges: 0040dce3-0040de92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040dce3(uint param_1)

{
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (DAT_0043d720 == 0) {
    FUN_0040187a((byte *)s__s__d____error_please_use_get_xv_004325d4);
  }
  if (DAT_0042c358 == 8) {
    FUN_0040187a((byte *)s__s___d___Translation_from_24_bit_00432618);
  }
  else if ((DAT_0042c358 == 0x10) || (DAT_0042c358 == 0x18)) {
    if (param_1 == DAT_00438474) {
      local_10 = DAT_0043db60;
      local_14 = DAT_0043db64;
      local_c = DAT_0043db68;
    }
    else {
      local_10 = param_1 & 0xff;
      if (DAT_0043d758 != 0) {
        local_10 = (int)(local_10 * local_10) >> 8;
      }
      local_10 = (int)local_10 >> ((byte)DAT_0043d73c & 0x1f);
      local_14 = (int)(param_1 & 0xff00) >> 8;
      if (DAT_0043d758 != 0) {
        local_14 = local_14 * local_14 >> 8;
      }
      local_14 = local_14 >> ((byte)DAT_0043d740 & 0x1f);
      local_c = (int)(param_1 & 0xff0000) >> 0x10;
      if (DAT_0043d758 != 0) {
        local_c = local_c * local_c >> 8;
      }
      local_c = local_c >> ((byte)DAT_0043d744 & 0x1f);
    }
    if ((((local_10 == DAT_0043db60) && (local_14 == DAT_0043db64)) && (local_c == DAT_0043db68)) &&
       (param_1 != DAT_00438474)) {
      if (local_10 == 0) {
        local_10 = 1;
      }
      else {
        local_10 = local_10 + -1;
      }
    }
    local_8 = (local_10 << ((byte)DAT_0043d748 & 0x1f)) + (local_14 << ((byte)DAT_0043d74c & 0x1f))
              + (local_c << ((byte)DAT_0043d750 & 0x1f));
  }
  return local_8;
}


/*
 * FUN_0040de93 at 0040de93
 * uint __cdecl FUN_0040de93(uint param_1, int param_2)
 * Address ranges: 0040de93-0040e0c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0040de93(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (DAT_0043d720 == 0) {
    FUN_0040187a((byte *)s__s__d____error_please_use_get_xv_0043266c);
  }
  if (param_2 == 8) {
    if (DAT_0042c358 == 8) {
      return param_1;
    }
    if (DAT_0042c358 == 0x10) {
      local_c = (uint)*(byte *)(DAT_0043d760 + param_1 * 4);
      if (DAT_0043d758 != 0) {
        local_c = (int)(local_c * local_c) >> 8;
      }
      local_10 = (uint)*(byte *)(DAT_0043d760 + 1 + param_1 * 4);
      if (DAT_0043d758 != 0) {
        local_10 = (int)(local_10 * local_10) >> 8;
      }
      local_8 = (uint)*(byte *)(DAT_0043d760 + 2 + param_1 * 4);
      if (DAT_0043d758 != 0) {
        local_8 = (int)(local_8 * local_8) >> 8;
      }
      local_c = (int)local_c >> ((byte)DAT_0043d73c & 0x1f);
      iVar1 = (int)local_10 >> ((byte)DAT_0043d740 & 0x1f);
      iVar2 = (int)local_8 >> ((byte)DAT_0043d744 & 0x1f);
      if ((((param_1 != DAT_00434c50) && (local_c == DAT_0043db60)) && (iVar1 == DAT_0043db64)) &&
         (iVar2 == DAT_0043db68)) {
        local_c = DAT_0043db60 + 1;
      }
      return (local_c << ((byte)DAT_0043d748 & 0x1f)) + (iVar1 << ((byte)DAT_0043d74c & 0x1f)) +
             (iVar2 << ((byte)DAT_0043d750 & 0x1f));
    }
    if (DAT_0042c358 == 0x18) {
      return (uint)*(byte *)(DAT_0043d760 + param_1 * 4) << 0x10 |
             (uint)*(byte *)(DAT_0043d760 + 1 + param_1 * 4) << 8 |
             (uint)*(byte *)(DAT_0043d760 + 2 + param_1 * 4);
    }
  }
  else if (param_2 == 0x10) {
    if (DAT_0042c358 == 8) {
      FUN_0040187a((byte *)s_not_yet_supported_004326a4);
      return param_1;
    }
    if (DAT_0042c358 == 0x10) {
      return param_1;
    }
    if (DAT_0042c358 == 0x18) {
      return param_1;
    }
  }
  else if (param_2 == 0x18) {
    iVar1 = FUN_0040dce3(param_1);
    return (int)(short)iVar1;
  }
  return 0;
}


/*
 * FUN_0040e0c3 at 0040e0c3
 * undefined __cdecl FUN_0040e0c3(uint param_1, int param_2, short * param_3)
 * Address ranges: 0040e0c3-0040e320
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040e0c3(uint param_1,int param_2,short *param_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar5;
  short local_14;
  byte bVar4;
  
  if (DAT_0043d720 == 0) {
    FUN_0040187a((byte *)s__s__d____error_please_use_get_xv_004326d8);
  }
  bVar3 = (byte)DAT_0043d74c;
  bVar4 = (byte)DAT_0043d750;
  if (param_2 == 8) {
    if (DAT_0042c358 == 8) {
      *(undefined1 *)param_3 = (undefined1)param_1;
    }
    else if (DAT_0042c358 == 0x10) {
      local_14 = (short)(((int)(uint)*(byte *)(DAT_0043d760 + param_1 * 4) >>
                         ((byte)DAT_0043d73c & 0x1f)) << ((byte)DAT_0043d748 & 0x1f)) +
                 (short)(((int)(uint)*(byte *)(DAT_0043d760 + 1 + param_1 * 4) >>
                         ((byte)DAT_0043d740 & 0x1f)) << (bVar3 & 0x1f)) +
                 (short)(((int)(uint)*(byte *)(DAT_0043d760 + 2 + param_1 * 4) >>
                         ((byte)DAT_0043d744 & 0x1f)) << (bVar4 & 0x1f));
      *param_3 = local_14;
    }
    else if (DAT_0042c358 == 0x18) {
      *(undefined1 *)(param_3 + 1) = *(undefined1 *)(DAT_0043d760 + param_1 * 4);
      *(undefined1 *)((int)param_3 + 1) = *(undefined1 *)(DAT_0043d760 + 1 + param_1 * 4);
      *(undefined1 *)param_3 = *(undefined1 *)(DAT_0043d760 + 2 + param_1 * 4);
    }
  }
  else if (param_2 == 0x10) {
    if (DAT_0042c358 == 8) {
      FUN_0040187a((byte *)s_not_yet_supported_00432710);
    }
    else if (DAT_0042c358 == 0x10) {
      *param_3 = (short)param_1;
    }
    else if (DAT_0042c358 == 0x18) {
      uVar1 = param_1 & _DAT_0043d734;
      uVar5 = param_1 & _DAT_0043d738;
      *(char *)(param_3 + 1) =
           (char)(((int)(param_1 & _DAT_0043d730) >> ((byte)DAT_0043d748 & 0x1f)) <<
                 ((byte)DAT_0043d73c & 0x1f));
      *(char *)((int)param_3 + 1) =
           (char)(((int)uVar1 >> (bVar3 & 0x1f)) << ((byte)DAT_0043d740 & 0x1f));
      *(char *)param_3 = (char)(((int)uVar5 >> (bVar4 & 0x1f)) << ((byte)DAT_0043d744 & 0x1f));
    }
  }
  else if (param_2 == 0x18) {
    if (DAT_0042c358 == 0x10) {
      iVar2 = FUN_0040dce3(param_1);
      *param_3 = (short)iVar2;
    }
    else {
      FUN_0040187a((byte *)s__s___d___Translation_from_24_bit_00432730);
    }
  }
  return;
}


/*
 * FUN_0040e321 at 0040e321
 * undefined __stdcall FUN_0040e321(void)
 * Address ranges: 0040e321-0040e543
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040e321(void)

{
  int iVar1;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004028c2(DAT_00438434);
  _memset(&DAT_0043d700,0,0x20);
  _DAT_0043d700 = 0x20;
  iVar1 = (**(code **)(*DAT_00438434 + 0x54))(DAT_00438434,&DAT_0043d700);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____unable_to_get_pixelform_0043278c);
  }
  if ((DAT_0043d704 & 0x20) == 0) {
    local_c = 0;
    for (local_14 = DAT_0043d710; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d748 = local_c;
    local_c = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d724 = local_c;
    DAT_0043d73c = 8 - local_c;
    _DAT_0043d730 = DAT_0043d710;
    local_10 = 0;
    for (local_14 = DAT_0043d714; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d74c = local_10;
    local_10 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d728 = local_10;
    DAT_0043d740 = 8 - local_10;
    _DAT_0043d734 = DAT_0043d714;
    local_8 = 0;
    for (local_14 = DAT_0043d718; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d750 = local_8;
    local_8 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d72c = local_8;
    DAT_0043d744 = 8 - local_8;
    _DAT_0043d738 = DAT_0043d718;
  }
  else {
    DAT_0043d754 = 0;
  }
  DAT_0043d720 = 1;
  return;
}


/*
 * FUN_0040e544 at 0040e544
 * undefined __cdecl FUN_0040e544(undefined4 param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint param_5, uint param_6, uint param_7)
 * Address ranges: 0040e544-0040e6ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040e544(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            uint param_6,uint param_7)

{
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_2 & 0x20) == 0) {
    local_c = 0;
    for (local_14 = param_5; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d748 = local_c;
    local_c = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d724 = local_c;
    DAT_0043d73c = 8 - local_c;
    _DAT_0043d730 = param_5;
    local_10 = 0;
    for (local_14 = param_6; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d74c = local_10;
    local_10 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d728 = local_10;
    DAT_0043d740 = 8 - local_10;
    _DAT_0043d734 = param_6;
    local_8 = 0;
    for (local_14 = param_7; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d750 = local_8;
    local_8 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d72c = local_8;
    DAT_0043d744 = 8 - local_8;
    _DAT_0043d738 = param_7;
    FUN_004015a6((byte *)s_RGB___d__d__d_004327b8);
  }
  return;
}


/*
 * FUN_0040e6f0 at 0040e6f0
 * undefined4 __stdcall FUN_0040e6f0(void)
 * Address ranges: 0040e6f0-0040e6f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040e6f0(void)

{
  return DAT_0043d768;
}


/*
 * FUN_0040e6fa at 0040e6fa
 * undefined4 __stdcall FUN_0040e6fa(void)
 * Address ranges: 0040e6fa-0040e7df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040e6fa(void)

{
  int iVar1;
  
  if (DAT_0043d764 == 0) {
    DAT_0043d760 = LocalAlloc(0x40,0x400);
    if (DAT_0043d760 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____error_not_enough_memory_004327d0);
    }
    if (DAT_0042c358 < 9) {
      iVar1 = (**(code **)(*DAT_00438414 + 0x14))(DAT_00438414,0x44,DAT_0043d760,&DAT_0043d75c,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_create_a_pale_0043284c);
      }
      DAT_0043d764 = 1;
      FUN_0040e809(0);
      FUN_0040e809(1);
      FUN_0040e809(2);
    }
    else {
      FUN_004015a6((byte *)s__s__d____16_bit_screen_mode__>_i_00432814);
      DAT_0043d768 = 1;
    }
  }
  return 0;
}


/*
 * FUN_0040e7e0 at 0040e7e0
 * undefined __stdcall FUN_0040e7e0(void)
 * Address ranges: 0040e7e0-0040e808
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040e7e0(void)

{
  if (DAT_0043d764 != 0) {
    (**(code **)(*DAT_0043d75c + 8))(DAT_0043d75c);
    DAT_0043d764 = 0;
  }
  return;
}


/*
 * FUN_0040e809 at 0040e809
 * undefined __cdecl FUN_0040e809(int param_1)
 * Address ranges: 0040e809-0040e96e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040e809(int param_1)

{
  int iVar1;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432880);
    }
    if (param_1 == 0) {
      FUN_004028c2(DAT_00438434);
      iVar1 = (**(code **)(*DAT_00438434 + 0x7c))(DAT_00438434,DAT_0043d75c);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_set_the_palet_004328b0);
      }
    }
    else if (param_1 == 1) {
      FUN_004028c2(DAT_00438438);
      iVar1 = (**(code **)(*DAT_00438438 + 0x7c))(DAT_00438438,DAT_0043d75c);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_set_the_palet_004328e4);
      }
    }
    else if (param_1 == 2) {
      FUN_004028c2(DAT_00438418);
      iVar1 = (**(code **)(*DAT_00438418 + 0x7c))(DAT_00438418,DAT_0043d75c);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_set_the_palet_00432918);
      }
    }
    else {
      FUN_0040187a((byte *)s__s__d____unknown_focus_defined_0043294c);
    }
  }
  return;
}


/*
 * FUN_0040e96f at 0040e96f
 * undefined4 __thiscall FUN_0040e96f(void * this, undefined4 param_1, int param_2, int param_3)
 * Address ranges: 0040e96f-0040ea4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040e96f(void *this,undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432978);
    }
    if (param_2 < 0) {
      FUN_0040187a((byte *)s__s__d____illegal_palette_base_en_004329a8);
    }
    if ((param_2 + param_3 < 0) || (0x100 < param_2 + param_3)) {
      FUN_0040187a((byte *)s__s__d____trying_to_reference_an_i_004329dc);
    }
    iVar1 = (**(code **)(*DAT_0043d75c + 0x18))(DAT_0043d75c,0,param_2,param_3,param_1,this);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_set_entries___s__00432a24);
    }
  }
  return 0;
}


/*
 * FUN_0040ea4c at 0040ea4c
 * undefined4 __thiscall FUN_0040ea4c(void * this, undefined4 param_1, int param_2, int param_3)
 * Address ranges: 0040ea4c-0040eb28
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0040ea4c(void *this,undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432a50);
    }
    if (param_2 < 0) {
      FUN_0040187a((byte *)s__s__d____illegal_palette_base_en_00432a80);
    }
    if ((param_2 + param_3 < 0) || (0x100 < param_2 + param_3)) {
      FUN_0040187a((byte *)s__s__d____trying_to_reference_an_i_00432ab4);
    }
    iVar1 = (**(code **)(*DAT_0043d75c + 0x10))(DAT_0043d75c,0,param_2,param_3,param_1,this);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_set_entries___s__00432afc);
    }
  }
  return 0;
}


/*
 * FUN_0040eb29 at 0040eb29
 * undefined __cdecl FUN_0040eb29(void * param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 0040eb29-0040ec2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040eb29(void *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int local_8;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432b28);
    }
    if (param_2 < 0) {
      FUN_0040187a((byte *)s__s__d____illegal_palette_base_en_00432b58);
    }
    if ((param_2 + param_3 < 0) || (0x100 < param_2 + param_3)) {
      FUN_0040187a((byte *)s__s__d____trying_to_reference_an_i_00432b8c);
    }
    if (((param_4 != 0) && (param_4 != 0x40)) && (param_4 != 0x80)) {
      FUN_0040187a((byte *)s__s__d____illegal_flag_value__d_00432bd4);
    }
    for (local_8 = param_2; local_8 < param_2 + param_3; local_8 = local_8 + 1) {
      *(undefined1 *)((int)param_1 + local_8 * 4 + 3) = (undefined1)param_4;
    }
    if (param_5 != 0) {
      FUN_0040e96f(param_1,param_1,param_2,param_3);
    }
  }
  return;
}


/*
 * FUN_0040ec30 at 0040ec30
 * int __stdcall FUN_0040ec30(void)
 * Address ranges: 0040ec30-0040ec8d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0040ec30(void)

{
  int local_8;
  
  if (DAT_0043d7ec == 0) {
    FUN_0040187a((byte *)s_s__d____error_attempting_to_find_00432c10);
  }
  local_8 = 0;
  while( true ) {
    if (DAT_0043d79c <= local_8) {
      return -1;
    }
    if (*(int *)(DAT_0043d798 + 4 + local_8 * 8) == 3) break;
    local_8 = local_8 + 1;
  }
  return local_8 + 0x41;
}


/*
 * FUN_0040ec8e at 0040ec8e
 * int __cdecl FUN_0040ec8e(int param_1)
 * Address ranges: 0040ec8e-0040ed2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Removing unreachable block (ram,0x0040ed2a) */

int __cdecl FUN_0040ec8e(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = 1;
  }
  else {
    if (DAT_0043d7ec == 0) {
      FUN_0040187a((byte *)s_s__d____error_attempting_to_find_00432c60);
    }
    for (; DAT_0043d7fc != DAT_0043d79c; DAT_0043d7fc = DAT_0043d7fc + 1) {
      if (*(int *)(DAT_0043d798 + 4 + DAT_0043d7fc * 8) == 3) {
        iVar1 = DAT_0043d7fc + 0x41;
        DAT_0043d7fc = DAT_0043d7fc + 1;
        return iVar1;
      }
    }
    iVar1 = -1;
  }
  DAT_0043d7fc = 0;
  return iVar1;
}


/*
 * FUN_0040ed2f at 0040ed2f
 * undefined4 __cdecl FUN_0040ed2f(int param_1)
 * Address ranges: 0040ed2f-0040eef5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040ed2f(int param_1)

{
  UINT UVar1;
  int local_6c;
  CHAR local_68 [100];
  
  if (DAT_0043d7ec == 0) {
    DAT_0043d798 = LocalAlloc(0x40,param_1 << 3);
    if (DAT_0043d798 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____error_not_enough_memory_00432cb0);
    }
    DAT_0043d79c = param_1;
    for (local_6c = 0; local_6c < param_1; local_6c = local_6c + 1) {
      FUN_0041fe16(local_68,&DAT_00432cec);
      *(int *)((int)DAT_0043d798 + local_6c * 8) = local_6c;
      UVar1 = GetDriveTypeA(local_68);
      switch(UVar1) {
      case 0:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 0;
        FUN_004015a6((byte *)s__s___UNAVAILABLE_00432cf4);
        break;
      case 1:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 0;
        FUN_004015a6((byte *)s__s___UNAVAILABLE_00432d08);
        break;
      case 2:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 1;
        FUN_004015a6((byte *)s__s___FLOPPY_00432d50);
        break;
      case 3:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 2;
        FUN_004015a6((byte *)s__s___HDD_00432d38);
        break;
      case 4:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 4;
        FUN_004015a6((byte *)s__s___NETWORK_00432d1c);
        break;
      case 5:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 3;
        FUN_004015a6((byte *)s__s___CDROM_00432d2c);
        break;
      case 6:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 5;
        FUN_004015a6((byte *)s__s___RAM_00432d44);
      }
    }
    DAT_0043d7ec = 1;
  }
  return 0;
}


/*
 * FUN_0040ef12 at 0040ef12
 * undefined4 __stdcall FUN_0040ef12(void)
 * Address ranges: 0040ef12-0040f144
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040ef12(void)

{
  BOOL BVar1;
  int iVar2;
  _MEMORYSTATUS local_4c;
  DWORD local_2c;
  _SYSTEM_INFO local_28;
  
  FUN_004015a6((byte *)s_Getting_system_information_00432d60);
  local_2c = 0x27;
  BVar1 = GetComputerNameA(&DAT_0043d770,&local_2c);
  if (BVar1 != 0) {
    FUN_004015a6((byte *)s_Computername____s_00432d7c);
  }
  local_2c = 0x27;
  BVar1 = GetUserNameA(&DAT_0043d7a0,&local_2c);
  if (BVar1 != 0) {
    FUN_004015a6((byte *)s_Username____s_00432d90);
  }
  FUN_0040ed2f(0x1b);
  GlobalMemoryStatus(&local_4c);
  DAT_0043d7e0 = local_4c.dwTotalPhys;
  DAT_0043d7e4 = local_4c.dwAvailPhys;
  DAT_0043d7e8 = local_4c.dwMemoryLoad;
  FUN_004015a6((byte *)s_Total_Physical_Memory____d_Kb_00432da0);
  FUN_004015a6((byte *)s_Available_Physical_Memory____d_K_00432dc4);
  FUN_004015a6((byte *)s_Memory_Load__of_total_____d_00432de8);
  GetSystemInfo(&local_28);
  DAT_0043d7dc = local_28.dwProcessorType;
  if (local_28.dwProcessorType == 0x182) {
    FUN_004015a6((byte *)s_386_processor_installed_00432e08);
  }
  else if (local_28.dwProcessorType == 0x1e6) {
    FUN_004015a6((byte *)s_486_processor_installed_00432e24);
  }
  else if (local_28.dwProcessorType == 0x24a) {
    FUN_004015a6((byte *)s_Pentium_processor_installed_00432e40);
  }
  else {
    FUN_004015a6((byte *)s_Unknown_processor_installed_00432e60);
  }
  iVar2 = GetSystemMetrics(0x43);
  if (iVar2 == 0) {
    _DAT_0043d7d8 = 0;
    FUN_004015a6((byte *)s_Startup___Normal_Boot_00432e80);
  }
  else if (iVar2 == 1) {
    _DAT_0043d7d8 = 1;
    FUN_004015a6((byte *)s_Startup___Safe_Mode_Boot_00432e98);
  }
  else if (iVar2 == 2) {
    _DAT_0043d7d8 = 1;
    FUN_004015a6((byte *)s_Startup___Safe_Mode_Boot_With_Ne_00432eb4);
  }
  iVar2 = GetSystemMetrics(0x13);
  if (iVar2 != 0) {
    FUN_004015a6((byte *)s_Mouse_is_present_00432edc);
    _DAT_0043d7cc = 1;
  }
  iVar2 = GetSystemMetrics(0x3f);
  if (iVar2 != 0) {
    FUN_004015a6((byte *)s_Network_is_present_00432ef0);
    _DAT_0043d7d0 = 1;
  }
  iVar2 = GetSystemMetrics(0x49);
  if (iVar2 != 0) {
    FUN_004015a6((byte *)s_Windows_95_thinks_this_is_a_slow_00432f04);
    _DAT_0043d7d4 = 1;
  }
  return 0;
}


/*
 * FUN_0040f145 at 0040f145
 * int __cdecl FUN_0040f145(int param_1, int param_2, int param_3)
 * Address ranges: 0040f145-0040f1a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040f145(int param_1,int param_2,int param_3)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x11 < local_8) {
      return -1;
    }
    if (((*(int *)(&DAT_0042c368 + local_8 * 0x14) == param_1) &&
        (*(int *)(&DAT_0042c36c + local_8 * 0x14) == param_2)) &&
       (*(int *)(&DAT_0042c370 + local_8 * 0x14) == param_3)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_0040f1a2 at 0040f1a2
 * undefined4 __stdcall FUN_0040f1a2(void)
 * Address ranges: 0040f1a2-0040f1db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040f1a2(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x11 < local_8) {
      return 0;
    }
    if (*(int *)(&DAT_0042c378 + local_8 * 0x14) == 0) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


/*
 * FUN_0040f1dc at 0040f1dc
 * undefined4 __cdecl FUN_0040f1dc(int param_1)
 * Address ranges: 0040f1dc-0040f240
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040f1dc(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_0043d7f8 == 0) {
    DAT_0043d7c8 = LocalAlloc(0x40,param_1 * 0xd8);
    if (DAT_0043d7c8 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_re_00432f30);
      uVar1 = 2000;
    }
    else {
      DAT_0043d7f0 = param_1;
      DAT_0043d7f4 = 0;
      DAT_0043d7f8 = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_0040f241 at 0040f241
 * int __stdcall FUN_0040f241(void)
 * Address ranges: 0040f241-0040f26b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0040f241(void)

{
  int iVar1;
  
  if (DAT_0043d7f4 < DAT_0043d7f0) {
    iVar1 = DAT_0043d7f4;
    DAT_0043d7f4 = DAT_0043d7f4 + 1;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


/*
 * FUN_0040f26c at 0040f26c
 * undefined __cdecl FUN_0040f26c(undefined4 * param_1, uint * param_2, uint * param_3)
 * Address ranges: 0040f26c-0040f30f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040f26c(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_0040f241();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____Unable_to_allocate_new_D_00432f74);
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)(DAT_0043d7c8 + iVar1 * 0xd8);
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = param_1[2];
    puVar2[3] = param_1[3];
  }
  FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x10 + iVar1 * 0xd8),param_2);
  FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x74 + iVar1 * 0xd8),param_3);
  DAT_00432c00 = iVar1;
  return;
}


/*
 * FUN_0040f310 at 0040f310
 * undefined4 __stdcall FUN_0040f310(undefined4 * param_1, uint * param_2, uint * param_3)
 * Address ranges: 0040f310-0040f522
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040f310(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_48 [16];
  char *local_8;
  
  iVar1 = FUN_0040f241();
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    _strncpy((char *)local_48,(char *)param_3,0x3f);
    FUN_00427e4d(local_48);
    FUN_004015a6((byte *)s__s___s_00432fac);
    FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x10 + iVar1 * 0xd8),param_2);
    FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x74 + iVar1 * 0xd8),param_3);
    puVar3 = FUN_0041fb70(local_48,&DAT_00432fb4);
    if (puVar3 != (uint *)0x0) {
      FUN_004015a6((byte *)s_3dfx_driver_found__d_00432fbc);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,s_DD3Dfx_00432fd4,(void *)0x6);
    if (iVar4 == 0) {
      FUN_004015a6((byte *)s_dd3ddfx_driver_found__d_00432fdc);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,&DAT_00432ff8,(void *)0x3);
    if (iVar4 == 0) {
      FUN_004015a6((byte *)s_Righteous_dd3ddfx_driver_found___00432ffc);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,s_mnstr2_00433020,(void *)0x6);
    if (iVar4 == 0) {
      FUN_004015a6((byte *)s_Monster_2_driver_found__d_00433028);
      DAT_00432bfc = iVar1;
    }
    iVar4 = FUN_00427da0((byte *)param_3,s_display_00433044,(void *)0x6);
    if (iVar4 != 0) {
      iVar4 = __strcmpi((char *)param_3,&DAT_0043304c);
      if (iVar4 == 0) {
        FUN_004015a6((byte *)s_secondary_driver_found__d_00433054);
        DAT_00432bf8 = iVar1;
      }
    }
    local_8 = _strrchr((char *)param_3,0x2e);
    if (local_8 != (char *)0x0) {
      iVar4 = __strcmpi((char *)param_3,&DAT_00433070);
      if (iVar4 == 0) {
        FUN_004015a6((byte *)s_secondary_driver_found__d_00433078);
        DAT_00432bf8 = iVar1;
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)(DAT_0043d7c8 + iVar1 * 0xd8);
      *puVar5 = *param_1;
      puVar5[1] = param_1[1];
      puVar5[2] = param_1[2];
      puVar5[3] = param_1[3];
    }
    uVar2 = 1;
  }
  return uVar2;
}


/*
 * FUN_0040f523 at 0040f523
 * int __stdcall FUN_0040f523(void)
 * Address ranges: 0040f523-0040f550
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0040f523(void)

{
  int iVar1;
  
  iVar1 = FUN_0040f1dc(0x14);
  if (iVar1 == 0) {
    DirectDrawEnumerateA(FUN_0040f310,0);
    iVar1 = 0;
  }
  return iVar1;
}


/*
 * FUN_0040f551 at 0040f551
 * int __cdecl FUN_0040f551(undefined4 param_1)
 * Address ranges: 0040f551-0040f692
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040f551(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 1:
    if (DAT_00432bfc == -1) {
      if (DAT_00432bf8 == -1) {
        iVar1 = 0;
      }
      else {
        FUN_004015a6((byte *)s_using_unknown_secondary_driver___004330e8);
        iVar1 = DAT_00432bf8 * 0xd8 + DAT_0043d7c8;
      }
    }
    else {
      FUN_004015a6((byte *)s_using_3dfx_driver__d_004330d0);
      iVar1 = DAT_00432bfc * 0xd8 + DAT_0043d7c8;
    }
    break;
  case 2:
    if (DAT_00432bf8 == -1) {
      iVar1 = 0;
    }
    else {
      FUN_004015a6((byte *)s_using_unknown_secondary_driver___004330ac);
      iVar1 = DAT_00432bf8 * 0xd8 + DAT_0043d7c8;
    }
    break;
  case 3:
    if (DAT_00432bfc == -1) {
      iVar1 = 0;
    }
    else {
      FUN_004015a6((byte *)s_using_3dfx_driver__d_00433094);
      iVar1 = DAT_0043d7c8 + DAT_00432bfc * 0xd8;
    }
    break;
  case 4:
    if (DAT_00432c00 == -1) {
      iVar1 = 0;
    }
    else {
      FUN_004015a6((byte *)s_using_user_defined_driver__d_0043310c);
      iVar1 = DAT_00432c00 * 0xd8 + DAT_0043d7c8;
    }
    break;
  default:
    iVar1 = 0;
  }
  return iVar1;
}


/*
 * FUN_0040f6a3 at 0040f6a3
 * undefined4 __stdcall FUN_0040f6a3(int param_1)
 * Address ranges: 0040f6a3-0040f71b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040f6a3(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x54);
  FUN_004015a6((byte *)s_mode__d__d__d_0043312c);
  iVar3 = FUN_0040f145(iVar3,iVar1,iVar2);
  if (iVar3 != -1) {
    *(undefined4 *)(&DAT_0042c378 + iVar3 * 0x14) = 1;
  }
  return 1;
}


/*
 * FUN_0040f71c at 0040f71c
 * undefined4 __stdcall FUN_0040f71c(void)
 * Address ranges: 0040f71c-0040f788
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0040f71c(void)

{
  int iVar1;
  
  FUN_004015a6((byte *)s_getting_screen_mode_info_0043313c);
  iVar1 = (**(code **)(*DAT_00438414 + 0x20))(DAT_00438414,0,0,0,FUN_0040f6a3);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_get_mode_info_00433164);
  }
  FUN_004015a6((byte *)s_done_getting_screen_mode_info_00433194);
  return 0;
}


/*
 * FUN_0040f789 at 0040f789
 * undefined4 __cdecl FUN_0040f789(int param_1)
 * Address ranges: 0040f789-0040f7bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040f789(int param_1)

{
  if ((param_1 < 0) || (0x11 < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_mode_index__und_004331c0);
  }
  return *(undefined4 *)(&DAT_0042c378 + param_1 * 0x14);
}


/*
 * FUN_0040f7c0 at 0040f7c0
 * undefined __cdecl FUN_0040f7c0(undefined4 param_1)
 * Address ranges: 0040f7c0-0040f7cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040f7c0(undefined4 param_1)

{
  DAT_004331f8 = param_1;
  return;
}


/*
 * FUN_0040f7cd at 0040f7cd
 * undefined __cdecl FUN_0040f7cd(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 0040f7cd-0040f7fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_0040f7cd(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_1 = DAT_0043d808;
  *param_2 = DAT_0043d80c;
  *param_3 = DAT_0043d804;
  *param_4 = DAT_0043d800;
  return;
}


/*
 * FUN_0040f7fd at 0040f7fd
 * undefined __cdecl FUN_0040f7fd(int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 0040f7fd-0040f8b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040f7fd(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_1 < 0) || (param_3 < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_t_0043320c);
  }
  if ((param_2 < 0) || (param_4 < param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_t_00433244);
  }
  if (DAT_0042c350 < param_3) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_b_0043327c);
  }
  if (DAT_0042c354 < param_4) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_b_004332b8);
  }
  DAT_0043d808 = param_1;
  DAT_0043d80c = param_2;
  DAT_0043d804 = param_3;
  DAT_0043d800 = param_4;
  DAT_0043d814 = 1;
  return;
}


/*
 * FUN_0040f8b1 at 0040f8b1
 * undefined __cdecl FUN_0040f8b1(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, uint param_7)
 * Address ranges: 0040f8b1-0040fc84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_0040f8b1(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,uint param_7)

{
  int iVar1;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0x1000000;
  if ((param_7 & 8) != 0) {
    local_8 = 0x1008000;
  }
  if ((((-1 < param_5) && (param_3 <= DAT_0042c350)) && (-1 < param_6)) &&
     ((param_4 <= DAT_0042c354 && (param_1 != param_2)))) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (DAT_0042c354 < param_6) {
      param_6 = DAT_0042c354;
    }
    if (DAT_0042c350 < param_5) {
      param_5 = DAT_0042c350;
    }
    if ((param_3 < param_5) && (param_4 < param_6)) {
      local_18 = param_3;
      local_10 = param_5;
      local_14 = param_4;
      local_c = param_6;
      local_28 = param_3;
      local_20 = param_5;
      local_24 = param_4;
      local_1c = param_6;
      local_38 = param_3;
      local_30 = param_5;
      local_34 = param_4;
      local_2c = param_6;
      if (param_2 == 0) {
        FUN_004028c2(DAT_00438434);
        if (param_1 == 1) {
          FUN_004028c2(DAT_00438438);
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_28,DAT_00438438,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004332f4);
          }
        }
        else {
          FUN_004028c2(DAT_00438418);
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_28,DAT_00438418,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433324);
          }
        }
      }
      else if (param_2 == 1) {
        FUN_004028c2(DAT_00438438);
        if (param_1 == 0) {
          FUN_004028c2(DAT_00438434);
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_28,DAT_00438434,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433354);
          }
        }
        else {
          FUN_004028c2(DAT_00438418);
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_28,DAT_00438418,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433384);
          }
        }
      }
      else if (param_2 == 2) {
        FUN_004028c2(DAT_00438418);
        if (param_1 == 0) {
          FUN_004028c2(DAT_00438434);
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_28,DAT_00438434,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004333b4);
          }
        }
        else {
          FUN_004028c2(DAT_00438438);
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_28,DAT_00438438,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004333e4);
          }
        }
      }
      else {
        FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433414);
      }
    }
  }
  return;
}


/*
 * FUN_0040fc85 at 0040fc85
 * undefined __cdecl FUN_0040fc85(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, undefined4 param_7, undefined4 param_8, undefined4 param_9, undefined4 param_10, uint param_11)
 * Address ranges: 0040fc85-0041018a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_0040fc85(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
            uint param_11)

{
  int iVar1;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x1000000;
  if ((param_11 & 8) != 0) {
    local_8 = 0x1008000;
  }
  if ((((-1 < param_5) && (param_3 <= DAT_0042c350)) && (-1 < param_6)) && (param_4 <= DAT_0042c354)
     ) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (DAT_0042c354 < param_6) {
      param_6 = DAT_0042c354;
    }
    if (DAT_0042c350 < param_5) {
      param_5 = DAT_0042c350;
    }
    if ((param_3 < param_5) && (param_4 < param_6)) {
      local_18 = param_7;
      local_10 = param_9;
      local_14 = param_8;
      local_c = param_10;
      local_28 = param_3;
      local_20 = param_5;
      local_24 = param_4;
      local_1c = param_6;
      if (param_2 == 0) {
        FUN_004028c2(DAT_00438434);
        if (param_1 == 0) {
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_18,DAT_00438434,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433450);
          }
        }
        else if (param_1 == 1) {
          FUN_004028c2(DAT_00438438);
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_18,DAT_00438438,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433480);
          }
        }
        else if (param_1 == 2) {
          FUN_004028c2(DAT_00438418);
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_18,DAT_00438418,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004334b0);
          }
        }
      }
      else if (param_2 == 1) {
        FUN_004028c2(DAT_00438438);
        if (param_1 == 0) {
          FUN_004028c2(DAT_00438434);
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_18,DAT_00438434,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433570);
          }
        }
        else if (param_1 == 1) {
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_18,DAT_00438438,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004335a0);
          }
        }
        else if (param_1 == 2) {
          FUN_004028c2(DAT_00438418);
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_18,DAT_00438418,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004335d0);
          }
        }
      }
      else if (param_2 == 2) {
        FUN_004028c2(DAT_00438418);
        if (param_1 == 0) {
          FUN_004028c2(DAT_00438434);
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_18,DAT_00438434,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004334e0);
          }
        }
        else if (param_1 == 1) {
          FUN_004028c2(DAT_00438438);
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_18,DAT_00438438,&local_28,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433510);
          }
        }
        else if ((param_1 == 2) &&
                (iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                                   (DAT_00438418,&local_18,DAT_00438418,&local_28,local_8,0),
                iVar1 != 0)) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d____blitting_error___s___00433540);
        }
      }
      else {
        FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433600);
      }
    }
  }
  return;
}


/*
 * FUN_0041018b at 0041018b
 * undefined __cdecl FUN_0041018b(int param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
 * Address ranges: 0041018b-00410439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_0041018b(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_0040235c(DAT_00438434);
  }
  else if (param_1 == 1) {
    local_8 = FUN_0040235c(DAT_00438438);
  }
  else if (param_1 == 2) {
    local_8 = FUN_0040235c(DAT_00438418);
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0043363c);
  }
  if (param_7 == 0) {
    FUN_004150a0();
  }
  else {
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_00433678);
    }
    if (param_3 + param_5 < DAT_0043d808) {
      return;
    }
    if (DAT_0043d804 < param_3) {
      return;
    }
    if (param_4 + param_6 < DAT_0043d80c) {
      return;
    }
    if (DAT_0043d800 < param_4) {
      return;
    }
    if (param_4 < DAT_0043d80c) {
      param_6 = param_6 - (DAT_0043d80c - param_4);
      param_4 = DAT_0043d80c;
      if (param_6 < 1) {
        return;
      }
    }
    if ((DAT_0043d800 < param_4 + param_6) && (DAT_0043d800 - param_4 < 1)) {
      return;
    }
    if (param_3 < DAT_0043d808) {
      param_5 = param_5 - (DAT_0043d808 - param_3);
      param_3 = DAT_0043d808;
      if (param_5 < 1) {
        return;
      }
    }
    if ((DAT_0043d804 < param_3 + param_5) && (DAT_0043d804 - param_3 < 1)) {
      return;
    }
    FUN_004150a0();
  }
  if (param_1 == 0) {
    FUN_004027f9(DAT_00438434,local_8);
  }
  else if (param_1 == 1) {
    FUN_004027f9(DAT_00438438,local_8);
  }
  else if (param_1 == 2) {
    FUN_004027f9(DAT_00438418,local_8);
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_004336ac);
  }
  return;
}


/*
 * FUN_0041043a at 0041043a
 * undefined __cdecl FUN_0041043a(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
 * Address ranges: 0041043a-004105ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_0041043a(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  if (param_7 == 0) {
    FUN_004150a0();
  }
  else {
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_004336e8);
    }
    if ((((DAT_0043d808 <= param_3 + param_5) && (param_3 <= DAT_0043d804)) &&
        (DAT_0043d80c <= param_4 + param_6)) && (param_4 <= DAT_0043d800)) {
      if (param_4 < DAT_0043d80c) {
        param_6 = param_6 - (DAT_0043d80c - param_4);
        param_4 = DAT_0043d80c;
        if (param_6 < 1) {
          return;
        }
      }
      if ((param_4 + param_6 <= DAT_0043d800) || (0 < DAT_0043d800 - param_4)) {
        if (param_3 < DAT_0043d808) {
          param_5 = param_5 - (DAT_0043d808 - param_3);
          param_3 = DAT_0043d808;
          if (param_5 < 1) {
            return;
          }
        }
        if ((param_3 + param_5 <= DAT_0043d804) || (0 < DAT_0043d804 - param_3)) {
          FUN_004150a0();
        }
      }
    }
  }
  return;
}


/*
 * FUN_004105ee at 004105ee
 * undefined __cdecl FUN_004105ee(int param_1, int param_2, int param_3, int param_4, uint param_5)
 * Address ranges: 004105ee-00410df1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004105ee(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x1008000;
  if ((param_2 < 0) || (DAT_00431b64 < param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_array_index__d_0043371c);
  }
  if (*(int *)(DAT_0043d6e8 + 0x1c + param_2 * 0x20) == 0) {
    FUN_0040187a((byte *)s__s__d____blt_with_unallocated_me_00433750);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_2 * 0x20) == 4) {
    if (param_1 == 0) {
      local_8 = FUN_0040235c(DAT_00438434);
      local_18 = DAT_004383b4;
    }
    else if (param_1 == 1) {
      local_8 = FUN_0040235c(DAT_00438438);
      local_18 = DAT_00438420;
    }
    else if (param_1 == 2) {
      local_8 = FUN_0040235c(DAT_00438418);
      local_18 = DAT_00438430;
    }
    else {
      FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433790);
    }
    local_10 = *(int *)(DAT_0043d6e8 + 8 + param_2 * 0x20);
    local_1c = *(int *)(DAT_0043d6e8 + 0xc + param_2 * 0x20);
    if ((param_5 & 2) == 0) {
      param_3 = param_3 - *(int *)(DAT_0043d6e8 + 0x10 + param_2 * 0x20);
      param_4 = param_4 - *(int *)(DAT_0043d6e8 + 0x14 + param_2 * 0x20);
    }
    local_14 = *(int *)(DAT_0043d6e8 + param_2 * 0x20);
    if ((param_5 & 1) == 0) {
      FUN_004150a0();
    }
    else {
      local_20 = 0;
      if (DAT_0043d814 == 0) {
        FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_004337cc);
      }
      if (param_3 + local_10 < DAT_0043d808) {
        return;
      }
      if (DAT_0043d804 < param_3) {
        return;
      }
      if (param_4 + local_1c < DAT_0043d80c) {
        return;
      }
      if (DAT_0043d800 < param_4) {
        return;
      }
      if (param_4 < DAT_0043d80c) {
        local_24 = local_10 * (DAT_0043d80c - param_4);
        local_14 = local_14 + local_24;
        local_1c = local_1c - (DAT_0043d80c - param_4);
        param_4 = DAT_0043d80c;
        if (local_1c < 1) {
          return;
        }
      }
      if ((DAT_0043d800 < param_4 + local_1c) && (local_1c = DAT_0043d800 - param_4, local_1c < 1))
      {
        return;
      }
      if (param_3 < DAT_0043d808) {
        local_20 = DAT_0043d808 - param_3;
        local_14 = local_14 + local_20;
        local_10 = local_10 - local_20;
        param_3 = DAT_0043d808;
        if (local_10 < 1) {
          return;
        }
      }
      if (DAT_0043d804 < param_3 + local_10) {
        local_20 = local_10 - (DAT_0043d804 - param_3);
        local_10 = DAT_0043d804 - param_3;
        if (local_10 < 1) {
          return;
        }
      }
      FUN_004150a0();
    }
    if (param_1 == 0) {
      FUN_004027f9(DAT_00438434,local_8);
    }
    else if (param_1 == 1) {
      FUN_004027f9(DAT_00438438,local_8);
    }
    else if (param_1 == 2) {
      FUN_004027f9(DAT_00438418,local_8);
    }
    else {
      FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433800);
    }
    return;
  }
  local_38 = 0;
  local_50 = 0;
  if ((param_5 & 4) != 0) {
    local_c = 0x1000000;
  }
  local_10 = *(int *)(DAT_0043d6e8 + 8 + param_2 * 0x20);
  local_1c = *(int *)(DAT_0043d6e8 + 0xc + param_2 * 0x20);
  if ((param_5 & 2) == 0) {
    param_3 = param_3 - *(int *)(DAT_0043d6e8 + 0x10 + param_2 * 0x20);
    param_4 = param_4 - *(int *)(DAT_0043d6e8 + 0x14 + param_2 * 0x20);
  }
  if (DAT_0043d814 == 0) {
    FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_0043383c);
  }
  if (param_3 + local_10 < DAT_0043d808) {
    return;
  }
  if (DAT_0043d804 < param_3) {
    return;
  }
  if (param_4 + local_1c < DAT_0043d80c) {
    return;
  }
  if (DAT_0043d800 < param_4) {
    return;
  }
  if (param_4 < DAT_0043d80c) {
    local_50 = DAT_0043d80c - param_4;
    local_1c = local_1c - local_50;
    param_4 = DAT_0043d80c;
    if (local_1c < 1) {
      return;
    }
  }
  if ((DAT_0043d800 < param_4 + local_1c) && (local_1c = DAT_0043d800 - param_4, local_1c < 1)) {
    return;
  }
  if (param_3 < DAT_0043d808) {
    local_38 = DAT_0043d808 - param_3;
    local_10 = local_10 - local_38;
    param_3 = DAT_0043d808;
    if (local_10 < 1) {
      return;
    }
  }
  if ((DAT_0043d804 < param_3 + local_10) && (local_10 = DAT_0043d804 - param_3, local_10 < 1)) {
    return;
  }
  local_34 = param_3;
  local_2c = param_3 + local_10;
  local_30 = param_4;
  local_28 = param_4 + local_1c;
  local_48 = local_38;
  local_40 = local_38 + local_10;
  local_44 = local_50;
  local_3c = local_50 + local_1c;
  iVar1 = (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_2 * 0x20) + 0x60))
                    (*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20));
  if (iVar1 != 0) {
    FUN_004015a6((byte *)s__s__d____had_to_restore__d_00433870);
    (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_2 * 0x20) + 0x6c))
              (*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20));
  }
  if (param_1 == 0) {
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_34,*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20),
                       &local_48,local_c,0);
    if (iVar1 == 0) {
      return;
    }
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_s_004338a0);
    return;
  }
  if (param_1 == 1) {
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                      (DAT_00438438,&local_34,*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20),
                       &local_48,local_c,0);
    if (iVar1 == 0) {
      return;
    }
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433910);
    return;
  }
  if (param_1 != 2) {
    return;
  }
  FUN_004028c2(DAT_00438418);
  iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                    (DAT_00438418,&local_34,*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20),
                     &local_48,local_c,0);
  if (iVar1 == 0) {
    return;
  }
  FUN_00401f61(iVar1);
  FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433988);
  return;
}


/*
 * FUN_00410df2 at 00410df2
 * undefined __cdecl FUN_00410df2(undefined4 param_1, int param_2, int param_3, int param_4, undefined4 param_5, uint param_6)
 * Address ranges: 00410df2-00411067
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_00410df2(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6)

{
  int local_10;
  int local_8;
  
  if ((param_2 < 0) || (DAT_00431b64 < param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_array_index__d_00433a00);
  }
  if (*(int *)(DAT_0043d6e8 + 0x1c + param_2 * 0x20) == 0) {
    FUN_0040187a((byte *)s__s__d____blt_with_unallocated_me_00433a34);
  }
  local_8 = *(int *)(DAT_0043d6e8 + 8 + param_2 * 0x20);
  local_10 = *(int *)(DAT_0043d6e8 + 0xc + param_2 * 0x20);
  if ((param_6 & 2) == 0) {
    param_3 = param_3 - *(int *)(DAT_0043d6e8 + 0x10 + param_2 * 0x20);
    param_4 = param_4 - *(int *)(DAT_0043d6e8 + 0x14 + param_2 * 0x20);
  }
  if ((param_6 & 1) == 0) {
    FUN_004150a0();
  }
  else {
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_00433a74);
    }
    if ((((DAT_0043d808 <= param_3 + local_8) && (param_3 <= DAT_0043d804)) &&
        (DAT_0043d80c <= param_4 + local_10)) && (param_4 <= DAT_0043d800)) {
      if (param_4 < DAT_0043d80c) {
        local_10 = local_10 - (DAT_0043d80c - param_4);
        param_4 = DAT_0043d80c;
        if (local_10 < 1) {
          return;
        }
      }
      if ((param_4 + local_10 <= DAT_0043d800) || (0 < DAT_0043d800 - param_4)) {
        if (param_3 < DAT_0043d808) {
          local_8 = local_8 - (DAT_0043d808 - param_3);
          param_3 = DAT_0043d808;
          if (local_8 < 1) {
            return;
          }
        }
        if ((param_3 + local_8 <= DAT_0043d804) || (0 < DAT_0043d804 - param_3)) {
          FUN_004150a0();
        }
      }
    }
  }
  return;
}


/*
 * FUN_00411068 at 00411068
 * undefined __cdecl FUN_00411068(int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 00411068-00411527
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411068(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_14 = 0;
  if ((param_2 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_index_00433a98);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_2 * 0xc);
  if ((iVar1 != 0) && (iVar1 == 1)) {
    local_c = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 4);
    local_10 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 8);
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_00433ae4);
    }
    if ((((DAT_0043d808 <= param_3 + local_c) && (param_3 <= DAT_0043d804)) &&
        (DAT_0043d80c <= param_4 + local_10)) && (param_4 <= DAT_0043d800)) {
      if (param_4 < DAT_0043d80c) {
        local_14 = DAT_0043d80c - param_4;
        local_10 = local_10 - local_14;
        param_4 = DAT_0043d80c;
        if (local_10 < 1) {
          return;
        }
      }
      if ((param_4 + local_10 <= DAT_0043d800) || (local_10 = DAT_0043d800 - param_4, 0 < local_10))
      {
        if (param_3 < DAT_0043d808) {
          local_8 = DAT_0043d808 - param_3;
          local_c = local_c - local_8;
          param_3 = DAT_0043d808;
          if (local_c < 1) {
            return;
          }
        }
        if ((param_3 + local_c <= DAT_0043d804) || (local_c = DAT_0043d804 - param_3, 0 < local_c))
        {
          if (DAT_004331f8 != 0) {
            param_3 = param_3 / 2 << 1;
          }
          local_24 = param_3;
          local_1c = param_3 + local_c;
          local_20 = param_4;
          local_18 = param_4 + local_10;
          local_34 = local_8;
          local_2c = local_8 + local_c;
          local_30 = local_14;
          local_28 = local_14 + local_10;
          iVar1 = (**(code **)(*(int *)**(undefined4 **)
                                         (*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 0x60))
                            (**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
          if (iVar1 != 0) {
            FUN_004015a6((byte *)s__s__d____had_to_restore__d_00433b18);
            (**(code **)(*(int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) +
                        0x6c))(**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
          }
          if (param_1 == 0) {
            FUN_004028c2(DAT_00438434);
            iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                              (DAT_00438434,&local_24,
                               **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),
                               &local_34,0x1008000,0);
            if (iVar1 != 0) {
              FUN_00401f61(iVar1);
              FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_s_00433b48);
            }
          }
          else if (param_1 == 1) {
            FUN_004028c2(DAT_00438438);
            iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                              (DAT_00438438,&local_24,
                               **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),
                               &local_34,0x1008000,0);
            if (iVar1 != 0) {
              FUN_00401f61(iVar1);
              FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433bb8);
            }
          }
          else if (param_1 == 2) {
            FUN_004028c2(DAT_00438418);
            iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                              (DAT_00438418,&local_24,
                               **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),
                               &local_34,0x1008000,0);
            if (iVar1 != 0) {
              FUN_00401f61(iVar1);
              FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433c30);
            }
          }
        }
      }
    }
  }
  return;
}


/*
 * FUN_00411528 at 00411528
 * undefined __cdecl FUN_00411528(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
 * Address ranges: 00411528-004118dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411528(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_1c = 0;
  if ((param_2 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_index_00433c98);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_2 * 0xc);
  if ((iVar1 != 0) && (iVar1 == 1)) {
    local_c = param_5;
    local_18 = param_6;
    local_14 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 4);
    local_10 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 8);
    if (DAT_004331f8 != 0) {
      param_3 = param_3 / 2 << 1;
    }
    local_2c = param_3;
    local_24 = param_3 + param_5;
    local_28 = param_4;
    local_20 = param_4 + param_6;
    local_3c = local_8;
    local_34 = local_8 + local_14;
    local_38 = local_1c;
    local_30 = local_1c + local_10;
    iVar1 = (**(code **)(*(int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) +
                        0x60))(**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
    if (iVar1 != 0) {
      FUN_004015a6((byte *)s__s__d____had_to_restore__d_00433ce4);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 0x6c))
                (**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
    }
    if (param_1 == 0) {
      FUN_004028c2(DAT_00438434);
      iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                        (DAT_00438434,&local_2c,
                         **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),&local_3c,
                         0x1000000,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_s_00433d14);
      }
    }
    else if (param_1 == 1) {
      FUN_004028c2(DAT_00438438);
      iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                        (DAT_00438438,&local_2c,
                         **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),&local_3c,
                         0x1008000,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433d84);
      }
    }
    else if (param_1 == 2) {
      FUN_004028c2(DAT_00438418);
      iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                        (DAT_00438418,&local_2c,
                         **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),&local_3c,
                         0x1008000,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433dfc);
      }
    }
  }
  return;
}


/*
 * FUN_004118dd at 004118dd
 * undefined __cdecl FUN_004118dd(int * param_1, int * param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, uint param_11)
 * Address ranges: 004118dd-00411b71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_004118dd(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,uint param_11)

{
  int iVar1;
  undefined4 local_100;
  undefined4 local_fc;
  int local_f8;
  int local_f4;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0x1000000;
  local_100 = 0x6c;
  local_fc = 6;
  local_84 = 0x6c;
  local_80 = 6;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_100);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433e74);
  }
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2,&local_84);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433ecc);
  }
  if ((param_11 & 8) != 0) {
    local_8 = local_8 | 0x8000;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (param_7 < 0) {
    param_7 = 0;
  }
  if (param_8 < 0) {
    param_8 = 0;
  }
  if (((((0 < param_5) && (0 < param_6)) && (param_3 <= local_f4)) &&
      ((param_4 <= local_f8 && (0 < param_9)))) &&
     ((0 < param_10 && ((param_7 <= local_78 && (param_8 <= local_7c)))))) {
    if (local_f4 < param_5) {
      param_5 = local_f4;
    }
    if (local_f8 < param_6) {
      param_6 = local_f8;
    }
    if (local_78 < param_9) {
      param_9 = local_78;
    }
    if (local_7c < param_10) {
      param_10 = local_7c;
    }
    if ((((param_3 != param_5) && (param_4 != param_6)) && (param_7 != param_9)) &&
       (param_8 != param_10)) {
      local_94 = param_3;
      local_8c = param_5;
      local_90 = param_4;
      local_88 = param_6;
      local_18 = param_7;
      local_10 = param_9;
      local_14 = param_8;
      local_c = param_10;
      if (((0 < param_9) && (0 < param_10)) &&
         ((0 < param_5 &&
          ((0 < param_6 &&
           (iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_18,param_1,&local_94,local_8,0),
           iVar1 != 0)))))) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____blt_surf_2_surf_blittin_00433f24);
      }
    }
  }
  return;
}


/*
 * FUN_00411b72 at 00411b72
 * bool __cdecl FUN_00411b72(int * param_1, int * param_2)
 * Address ranges: 00411b72-00411cb5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_00411b72(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x1000000;
  local_100 = 0x6c;
  local_fc = 6;
  local_84 = 0x6c;
  local_80 = 6;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_100);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433f64);
  }
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2,&local_84);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433fbc);
  }
  local_94 = 0;
  local_8c = local_f4;
  local_90 = 0;
  local_88 = local_f8;
  local_18 = 0;
  local_10 = local_78;
  local_14 = 0;
  local_c = local_7c;
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_18,param_1,&local_94,local_8,0);
  return iVar1 == 0;
}


/*
 * FUN_00411cc0 at 00411cc0
 * undefined4 __cdecl FUN_00411cc0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 00411cc0-00411d4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00411cc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00412a9d(param_1);
  iVar1 = *(int *)(DAT_0043d850 + 8 + iVar1 * 0x1c);
  if ((iVar1 == -1) || ((&DAT_0043db90)[iVar1 * 0x1c] == '\0')) {
    FUN_0040187a((byte *)s__s__d_____dispatch_form_message__0043401c);
  }
  else if (*(int *)(&DAT_0043dba8 + iVar1 * 0x1c) != 0) {
    uVar2 = (**(code **)(&DAT_0043dba8 + iVar1 * 0x1c))(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}


/*
 * FUN_00411d4c at 00411d4c
 * undefined __cdecl FUN_00411d4c(int param_1)
 * Address ranges: 00411d4c-00411d9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411d4c(int param_1)

{
  HWND pHVar1;
  undefined4 local_8;
  
  local_8 = FUN_00412a9d(param_1);
  do {
    if (local_8 == DAT_0043d84c) {
      local_8 = 0;
    }
    else {
      local_8 = local_8 + 1;
    }
    pHVar1 = SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c));
  } while (pHVar1 == (HWND)0x0);
  return;
}


/*
 * FUN_00411d9b at 00411d9b
 * undefined __cdecl FUN_00411d9b(int param_1)
 * Address ranges: 00411d9b-00411de6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411d9b(int param_1)

{
  HWND pHVar1;
  undefined4 local_8;
  
  local_8 = FUN_00412a9d(param_1);
  do {
    if (local_8 == 0) {
      local_8 = DAT_0043d84c;
    }
    else {
      local_8 = local_8 + -1;
    }
    pHVar1 = SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c));
  } while (pHVar1 == (HWND)0x0);
  return;
}


/*
 * FUN_00411de7 at 00411de7
 * undefined __cdecl FUN_00411de7(int param_1, undefined4 param_2)
 * Address ranges: 00411de7-00411f4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411de7(int param_1,undefined4 param_2)

{
  HWND pHVar1;
  
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_control_state__con_0043406c);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____set_control_state__No_a_004340c8);
  }
  *(undefined4 *)(DAT_0043d850 + 0x14 + param_1 * 0x1c) =
       *(undefined4 *)(DAT_0043d850 + 0x10 + param_1 * 0x1c);
  *(undefined4 *)(DAT_0043d850 + 0x10 + param_1 * 0x1c) = param_2;
  switch(param_2) {
  case 1:
    pHVar1 = GetFocus();
    if (pHVar1 != *(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c)) {
      if (*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) == 4) {
        FUN_0040187a((byte *)s__s__d_____set_control_state__are_00434104);
      }
      else {
        SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c));
      }
    }
    break;
  case 2:
    EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),0);
    break;
  case 3:
    EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),1);
    break;
  case 4:
    DAT_00434008 = param_1;
  }
  return;
}


/*
 * FUN_00411f5d at 00411f5d
 * undefined __cdecl FUN_00411f5d(int param_1)
 * Address ranges: 00411f5d-00411fde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411f5d(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____enable_control__contro_0043415c);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____enable_control__No_act_004341b4);
  }
  EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),1);
  return;
}


/*
 * FUN_00411fdf at 00411fdf
 * undefined __cdecl FUN_00411fdf(int param_1)
 * Address ranges: 00411fdf-00412060
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00411fdf(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____disable_control__contr_004341ec);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____disable_control__No_ac_00434248);
  }
  EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),0);
  return;
}


/*
 * FUN_00412061 at 00412061
 * undefined4 __stdcall FUN_00412061(void)
 * Address ranges: 00412061-0041206a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00412061(void)

{
  return DAT_0043d854;
}


/*
 * FUN_0041206b at 0041206b
 * undefined __cdecl FUN_0041206b(int param_1)
 * Address ranges: 0041206b-004120d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041206b(int param_1)

{
  if (DAT_0043d850 != 0) {
    FUN_0040187a((byte *)s_trying_to_change_the_focus_of_an_00434280);
  }
  if (param_1 == 0) {
    DAT_0043d854 = 0;
  }
  else if (param_1 == 1) {
    DAT_0043d854 = 1;
  }
  else {
    FUN_0040187a((byte *)s_trying_to_set_an_illegal_from_fo_004342d4);
  }
  return;
}


/*
 * FUN_004120d6 at 004120d6
 * undefined __stdcall FUN_004120d6(void)
 * Address ranges: 004120d6-004120f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004120d6(void)

{
  HWND pHVar1;
  
  pHVar1 = GetFocus();
  FUN_00412a9d((int)pHVar1);
  return;
}


/*
 * FUN_004120f3 at 004120f3
 * undefined __cdecl FUN_004120f3(int param_1)
 * Address ranges: 004120f3-00412172
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004120f3(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____focus_control__control_00434324);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____focus_control__No_acti_0043437c);
  }
  SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c));
  return;
}


/*
 * FUN_00412173 at 00412173
 * undefined __cdecl FUN_00412173(int param_1, LPCSTR param_2, int param_3, int param_4)
 * Address ranges: 00412173-004122f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00412173(int param_1,LPCSTR param_2,int param_3,int param_4)

{
  HDC hdc;
  tagRECT local_14;
  
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__con_004343b4);
  }
  GetClientRect(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),&local_14);
  hdc = GetDC(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c));
  if (*(int *)(&DAT_00435820 + param_3 * 0x10) != 0) {
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_00435820 + param_3 * 0x10));
    SetTextColor(hdc,*(COLORREF *)(&DAT_0043582c + param_3 * 0x10));
    SetBkColor(hdc,*(COLORREF *)(&DAT_00435828 + param_3 * 0x10));
    SetBkMode(hdc,*(int *)(&DAT_00435824 + param_3 * 0x10));
  }
  if (param_4 == 0) {
    DrawTextA(hdc,param_2,-1,&local_14,0x25);
  }
  else if (param_4 == 1) {
    DrawTextA(hdc,param_2,-1,&local_14,0x24);
  }
  else if (param_4 == 2) {
    DrawTextA(hdc,param_2,-1,&local_14,0x26);
  }
  else {
    DrawTextA(hdc,param_2,-1,&local_14,0x25);
  }
  ReleaseDC(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),hdc);
  return;
}


/*
 * FUN_004122f5 at 004122f5
 * undefined __cdecl FUN_004122f5(int param_1, byte * param_2, int param_3, int param_4)
 * Address ranges: 004122f5-00412589
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004122f5(int param_1,byte *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LONG LVar4;
  tagRECT local_28;
  tagRECT local_18;
  int local_8;
  
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__con_00434410);
  }
  GetClientRect(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),&local_18);
  GetWindowRect(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),&local_28);
  if (*(int *)(param_3 + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__try_0043446c);
  }
  local_8 = FUN_004152a3();
  FUN_004152ad(param_3);
  if (param_4 == 0) {
    local_28.left = local_28.left + (local_18.right + 1) / 2;
    local_28.top = local_28.top + (local_18.bottom + 1) / 2;
    iVar1 = FUN_00416f83((char *)param_2);
    local_28.left = local_28.left - iVar1 / 2;
    iVar1 = FUN_0041708c();
    iVar2 = local_28.top - iVar1 / 2;
    LVar4 = local_28.left;
    local_28.top = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,LVar4,iVar2,param_2);
  }
  else if (param_4 == 1) {
    local_28.top = local_28.top + local_18.bottom / 2;
    iVar1 = FUN_0041708c();
    iVar2 = local_28.top - iVar1 / 2;
    iVar3 = local_28.left + 8;
    local_28.left = iVar3;
    local_28.top = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,iVar3,iVar2,param_2);
  }
  else if (param_4 == 2) {
    local_28.top = local_28.top + local_18.bottom / 2;
    iVar1 = FUN_0041708c();
    local_28.top = local_28.top - iVar1 / 2;
    local_28.left = local_28.left + local_18.right;
    iVar1 = FUN_00416f83((char *)param_2);
    iVar2 = (local_28.left - iVar1 / 2) + -8;
    LVar4 = local_28.top;
    local_28.left = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,iVar2,LVar4,param_2);
  }
  else {
    local_28.left = local_28.left + local_18.right / 2;
    local_28.top = local_28.top + local_18.bottom / 2;
    iVar1 = FUN_00416f83((char *)param_2);
    local_28.left = local_28.left - iVar1 / 2;
    iVar1 = FUN_0041708c();
    iVar2 = local_28.top - iVar1 / 2;
    LVar4 = local_28.left;
    local_28.top = iVar2;
    iVar1 = FUN_00412061();
    FUN_0041635e(iVar1,LVar4,iVar2,param_2);
  }
  FUN_004152ad(local_8);
  return;
}


/*
 * FUN_0041258a at 0041258a
 * undefined __cdecl FUN_0041258a(int param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 0041258a-00412617
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041258a(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte local_38 [52];
  
  GetWindowTextA(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),(LPSTR)local_38,0x32);
  if (param_2 == 0) {
    FUN_00412173(param_1,(LPCSTR)local_38,param_3,param_5);
  }
  else if (param_2 == 1) {
    FUN_004122f5(param_1,local_38,param_4,param_5);
  }
  else {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__inv_004344dc);
  }
  return;
}


/*
 * FUN_00412618 at 00412618
 * undefined __cdecl FUN_00412618(int param_1, byte * param_2, int param_3, int param_4, int param_5, int param_6)
 * Address ranges: 00412618-00412686
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00412618(int param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6)

{
  if (param_3 == 0) {
    FUN_00412173(param_1,(LPCSTR)param_2,param_4,param_6);
  }
  else if (param_3 == 1) {
    FUN_004122f5(param_1,param_2,param_5,param_6);
  }
  else {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__inv_00434530);
  }
  return;
}


/*
 * FUN_00412687 at 00412687
 * int __cdecl FUN_00412687(int param_1, int param_2)
 * Address ranges: 00412687-004126d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00412687(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_0043d858 + 8 + param_1 * 0xc) + 4 + param_2 * 8);
  if ((iVar1 < 0) || (DAT_00431b64 < iVar1)) {
    FUN_0040187a((byte *)s__s__d____control_illegal_frame_i_00434584);
  }
  return iVar1;
}


/*
 * FUN_004126d4 at 004126d4
 * undefined __cdecl FUN_004126d4(undefined4 param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 004126d4-004127af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004126d4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  if ((((param_2 < 0) || (param_3 < 0)) || (DAT_0042c350 < param_2)) || (DAT_0042c354 < param_3)) {
    FUN_0040187a((byte *)s__s__d_____check_control_position_004345b8);
  }
  if ((param_4 < 1) || (param_5 < 1)) {
    FUN_0040187a((byte *)s__s__d_____check_control_position_00434624);
  }
  if (((DAT_0042c350 < param_4) || (DAT_0042c354 < param_5)) ||
     ((DAT_0042c350 < param_2 + param_4 || (DAT_0042c354 < param_5 + param_3)))) {
    FUN_0040187a((byte *)s__s__d_____check_control_position_00434694);
  }
  return;
}


/*
 * FUN_004127b0 at 004127b0
 * int __cdecl FUN_004127b0(int param_1, int param_2)
 * Address ranges: 004127b0-00412820
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_004127b0(int param_1,int param_2)

{
  if ((param_1 < 0) || (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_previous_control_i_00434714);
  }
  if (param_1 == 0) {
    param_1 = -1;
  }
  else {
    do {
      if (param_1 < 1) {
        return -1;
      }
      param_1 = param_1 + -1;
    } while (*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) != param_2);
  }
  return param_1;
}


/*
 * FUN_00412821 at 00412821
 * int __cdecl FUN_00412821(int param_1, int param_2)
 * Address ranges: 00412821-0041289b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00412821(int param_1,int param_2)

{
  if ((param_1 < 0) || (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_next_control_index_00434778);
  }
  if (param_1 == DAT_0043d84c) {
    param_1 = -1;
  }
  else {
    do {
      if (DAT_0043d84c <= param_1) {
        return -1;
      }
      param_1 = param_1 + 1;
    } while (*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) != param_2);
  }
  return param_1;
}


/*
 * FUN_0041289c at 0041289c
 * undefined4 __stdcall FUN_0041289c(void)
 * Address ranges: 0041289c-004128a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041289c(void)

{
  return DAT_0043d84c;
}


/*
 * FUN_004128a6 at 004128a6
 * undefined4 __cdecl FUN_004128a6(int param_1)
 * Address ranges: 004128a6-004128f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004128a6(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_old_control_state__004347d8);
  }
  return *(undefined4 *)(DAT_0043d850 + 0x14 + param_1 * 0x1c);
}


/*
 * FUN_004128fa at 004128fa
 * undefined4 __cdecl FUN_004128fa(int param_1)
 * Address ranges: 004128fa-0041294d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004128fa(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_type__cont_00434824);
  }
  return *(undefined4 *)(DAT_0043d850 + 8 + param_1 * 0x1c);
}


/*
 * FUN_0041294e at 0041294e
 * undefined4 __cdecl FUN_0041294e(int param_1)
 * Address ranges: 0041294e-004129a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041294e(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_state__con_0043486c);
  }
  return *(undefined4 *)(DAT_0043d850 + 0x10 + param_1 * 0x1c);
}


/*
 * FUN_004129a2 at 004129a2
 * undefined4 __cdecl FUN_004129a2(int param_1)
 * Address ranges: 004129a2-004129f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004129a2(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_x__control_004348b4);
  }
  return *(undefined4 *)(DAT_0043d850 + 0x18 + param_1 * 0x1c);
}


/*
 * FUN_004129f6 at 004129f6
 * undefined4 __cdecl FUN_004129f6(int param_1)
 * Address ranges: 004129f6-00412a48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004129f6(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_x__control_004348f8);
  }
  return *(undefined4 *)(DAT_0043d850 + param_1 * 0x1c);
}


/*
 * FUN_00412a49 at 00412a49
 * undefined4 __cdecl FUN_00412a49(int param_1)
 * Address ranges: 00412a49-00412a9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00412a49(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_y__control_0043493c);
  }
  return *(undefined4 *)(DAT_0043d850 + 4 + param_1 * 0x1c);
}


/*
 * FUN_00412a9d at 00412a9d
 * int __cdecl FUN_00412a9d(int param_1)
 * Address ranges: 00412a9d-00412b00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00412a9d(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) {
      FUN_0040187a((byte *)s__s__d_____get_control_index__win_00434980);
      return -1;
    }
    if (*(int *)(DAT_0043d850 + 0x18 + local_8 * 0x1c) == param_1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_00412b01 at 00412b01
 * undefined4 __cdecl FUN_00412b01(int param_1)
 * Address ranges: 00412b01-00412b6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00412b01(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) {
      FUN_0040187a((byte *)s__s__d_____get_control_pointer__w_004349c8);
      return 0;
    }
    if (*(int *)(DAT_0043d850 + 0x18 + local_8 * 0x1c) == param_1) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(DAT_0043d850 + 0xc + local_8 * 0x1c);
}


/*
 * FUN_00412b70 at 00412b70
 * undefined4 __cdecl FUN_00412b70(int param_1)
 * Address ranges: 00412b70-00412bb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00412b70(int param_1)

{
  if ((param_1 < 0) || (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_pointer__c_00434a14);
  }
  return *(undefined4 *)(DAT_0043d850 + 0xc + param_1 * 0x1c);
}


/*
 * FUN_00412bb8 at 00412bb8
 * undefined __cdecl FUN_00412bb8(int param_1)
 * Address ranges: 00412bb8-00412ca0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00412bb8(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____call_help_function__co_00434a64);
  }
  if ((*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) == -1) ||
     ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) * 0x1c] == '\0')) {
    FUN_0040187a((byte *)s__s__d_____destroy_form__Unused_c_00434ac0);
  }
  else if (*(int *)(&DAT_0043dba0 + *(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) * 0x1c) != 0) {
    (**(code **)(&DAT_0043dba0 + *(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) * 0x1c))
              (DAT_0043d850 + param_1 * 0x1c);
  }
  return;
}


/*
 * FUN_00412ca1 at 00412ca1
 * undefined __stdcall FUN_00412ca1(void)
 * Address ranges: 00412ca1-00412d95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00412ca1(void)

{
  int local_8;
  
  local_8 = 0;
  if (DAT_0043d850 != 0) {
    for (; *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) != -1; local_8 = local_8 + 1) {
      if ((*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) ||
         ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c] == '\0')) {
        FUN_0040187a((byte *)s__s__d_____destroy_form__Unused_c_00434b08);
      }
      else if (*(int *)(&DAT_0043db98 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c) != 0) {
        (**(code **)(&DAT_0043db98 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c))
                  (DAT_0043d850 + local_8 * 0x1c);
      }
    }
    DAT_0043d850 = 0;
    DAT_0043d84c = 0;
  }
  return;
}


/*
 * FUN_00412d96 at 00412d96
 * int __stdcall FUN_00412d96(void)
 * Address ranges: 00412d96-00412dac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00412d96(void)

{
  int iVar1;
  
  iVar1 = DAT_0043d850;
  if (DAT_0043d850 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}


/*
 * FUN_00412dad at 00412dad
 * undefined __cdecl FUN_00412dad(int param_1)
 * Address ranges: 00412dad-00412ecd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00412dad(int param_1)

{
  int local_8;
  
  local_8 = 0;
  if (DAT_0043d850 != 0) {
    FUN_00412ca1();
  }
  DAT_0043d850 = param_1;
  DAT_00434008 = 0xffffffff;
  DAT_0043d84c = 0;
  for (; *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) != -1; local_8 = local_8 + 1) {
    if ((*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) ||
       ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c] == '\0')) {
      FUN_0040187a((byte *)s__s__d_____destroy_form__Unused_c_00434b50);
    }
    else if (*(int *)(&DAT_0043db94 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c) != 0) {
      (**(code **)(&DAT_0043db94 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c))
                (DAT_0043d850 + local_8 * 0x1c,local_8);
    }
    DAT_0043d84c = DAT_0043d84c + 1;
  }
  DAT_0043d84c = DAT_0043d84c + -1;
  return;
}


/*
 * FUN_00412ece at 00412ece
 * undefined4 __stdcall FUN_00412ece(void)
 * Address ranges: 00412ece-00412f43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00412ece(void)

{
  HWND pHVar1;
  int iVar2;
  
  pHVar1 = GetFocus();
  if (((pHVar1 != DAT_0043842c) && (iVar2 = FUN_004120d6(), iVar2 != -1)) &&
     (*(int *)(&DAT_0043dba4 + *(int *)(DAT_0043d850 + 8 + iVar2 * 0x1c) * 0x1c) != 0)) {
    (**(code **)(&DAT_0043dba4 + *(int *)(DAT_0043d850 + 8 + iVar2 * 0x1c) * 0x1c))
              (DAT_0043d850 + iVar2 * 0x1c);
  }
  return 1;
}


/*
 * FUN_00412f44 at 00412f44
 * undefined __cdecl FUN_00412f44(undefined4 param_1)
 * Address ranges: 00412f44-00413153
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00412f44(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  iVar1 = FUN_004133f0(0x12);
  if (iVar1 == 0) {
    switch(param_1) {
    case 0xd:
      DAT_00434008 = 0x2715;
      break;
    case 0x1b:
      DAT_00434008 = 10000;
      break;
    case 0x21:
      DAT_00434008 = 0x2716;
      break;
    case 0x22:
      DAT_00434008 = 0x2717;
      break;
    case 0x23:
      DAT_00434008 = 0x2719;
      break;
    case 0x24:
      DAT_00434008 = 0x2718;
      break;
    case 0x25:
      DAT_00434008 = 0x2713;
      break;
    case 0x26:
      DAT_00434008 = 0x2711;
      break;
    case 0x27:
      DAT_00434008 = 0x2714;
      break;
    case 0x28:
      DAT_00434008 = 0x2712;
    }
  }
  else {
    for (; *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) != -1; local_8 = local_8 + 1) {
      if ((*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) ||
         ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c] == '\0')) {
        FUN_0040187a((byte *)s__s__d_____check_form_key_pressed_00434b98);
      }
      else if ((*(int *)(&DAT_0043db9c + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c) != 0)
              && (iVar1 = (**(code **)(&DAT_0043db9c +
                                      *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c))
                                    (DAT_0043d850 + local_8 * 0x1c,param_1), iVar1 != 0)) {
        DAT_0043400c = param_1;
        FUN_00411de7(local_8,4);
        SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c));
        _DAT_0043d82c = *(undefined4 *)(DAT_0043d850 + 0x18 + local_8 * 0x1c);
        _DAT_0043d828 = 0x11;
        SendMessageA(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c),0x2b,0,0x43d818);
        return;
      }
    }
  }
  return;
}


/*
 * FUN_0041319c at 0041319c
 * undefined4 __stdcall FUN_0041319c(void)
 * Address ranges: 0041319c-00413233
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041319c(void)

{
  int iVar1;
  
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____handle_form__No_active_00434be8);
  }
  DAT_00434008 = 0xffffffff;
  DAT_0043400c = 0xffffffff;
  DAT_0043d848 = DAT_0043d848 + 1;
  if (DAT_0043d848 == DAT_00434004) {
    DAT_0043d848 = 0;
    FUN_00412ece();
  }
  FUN_00405614();
  iVar1 = FUN_0040a97d();
  if (iVar1 != 0) {
    DAT_00434008 = 0xfffffffe;
  }
  iVar1 = FUN_00412061();
  if (iVar1 == 1) {
    FUN_00401cf3();
  }
  return DAT_00434008;
}


/*
 * FUN_00413234 at 00413234
 * undefined __stdcall FUN_00413234(void)
 * Address ranges: 00413234-00413262
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00413234(void)

{
  int iVar1;
  
  if (DAT_0043400c != 0xffffffff) {
    do {
      iVar1 = FUN_004133f0(DAT_0043400c);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_0040a97d();
    } while (iVar1 == 0);
  }
  return;
}


/*
 * FUN_00413270 at 00413270
 * undefined4 __cdecl FUN_00413270(int param_1)
 * Address ranges: 00413270-00413354
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00413270(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  for (local_c = 0;
      (*(int *)(param_1 + 4 + local_c * 0xc) != -1 && (*(int *)(param_1 + local_c * 0xc) != -1));
      local_c = local_c + 1) {
  }
  DAT_00434c1c = local_c;
  iVar1 = FUN_00413355(local_c);
  if (iVar1 == 0) {
    for (local_c = 0; local_c < DAT_00434c1c; local_c = local_c + 1) {
      *(undefined4 *)(DAT_0043d858 + local_c * 0xc) = *(undefined4 *)(param_1 + local_c * 0xc);
      *(undefined4 *)(DAT_0043d858 + 4 + local_c * 0xc) =
           *(undefined4 *)(param_1 + 4 + local_c * 0xc);
      *(undefined4 *)(DAT_0043d858 + 8 + local_c * 0xc) =
           *(undefined4 *)(param_1 + 8 + local_c * 0xc);
    }
    _DAT_0043d85c = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 2000;
  }
  return uVar2;
}


/*
 * FUN_00413355 at 00413355
 * undefined4 __cdecl FUN_00413355(int param_1)
 * Address ranges: 00413355-004133e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00413355(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  DAT_00434c1c = param_1;
  DAT_0043d858 = LocalAlloc(0x40,param_1 * 0xc);
  if (DAT_0043d858 == (HLOCAL)0x0) {
    uVar1 = 2000;
  }
  else {
    for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
      *(undefined4 *)((int)DAT_0043d858 + local_8 * 0xc + 8) = 0;
      *(undefined4 *)((int)DAT_0043d858 + local_8 * 0xc + 4) = 0;
      *(undefined4 *)((int)DAT_0043d858 + local_8 * 0xc) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_004133f0 at 004133f0
 * undefined4 __cdecl FUN_004133f0(uint param_1)
 * Address ranges: 004133f0-00413458
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004133f0(uint param_1)

{
  SHORT SVar1;
  undefined4 uVar2;
  
  if ((param_1 & 0x100) == 0) {
    SVar1 = GetAsyncKeyState(0x10);
    if (SVar1 < 0) {
      uVar2 = 0;
    }
    else {
      SVar1 = GetAsyncKeyState(param_1);
      if (SVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    SVar1 = GetAsyncKeyState(0x10);
    if (SVar1 < 0) {
      SVar1 = GetAsyncKeyState(param_1);
      if (SVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/*
 * FUN_00413459 at 00413459
 * undefined4 __cdecl FUN_00413459(uint param_1, uint param_2)
 * Address ranges: 00413459-004134fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00413459(uint param_1,uint param_2)

{
  SHORT SVar1;
  int iVar2;
  
  if (((int)param_2 < 0) || (3 < (int)param_2)) {
    FUN_0040187a((byte *)s__keyispressed__illegal_device_re_00434c20);
  }
  if (((param_2 & 2) != 0) && (iVar2 = FUN_004191a1(param_1), iVar2 != 0)) {
    return 0xffffffff;
  }
  if ((param_2 & 1) != 0) {
    if ((param_1 & 0x100) == 0) {
      SVar1 = GetAsyncKeyState(0x10);
      if ((-1 < SVar1) && (SVar1 = GetAsyncKeyState(param_1), SVar1 < 0)) {
        return 0xffffffff;
      }
    }
    else {
      SVar1 = GetAsyncKeyState(0x10);
      if ((SVar1 < 0) && (SVar1 = GetAsyncKeyState(param_1), SVar1 < 0)) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}


/*
 * FUN_00413500 at 00413500
 * undefined4 __cdecl FUN_00413500(LPCSTR param_1, int param_2)
 * Address ranges: 00413500-00413621
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00413500(LPCSTR param_1,int param_2)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char local_308 [768];
  int local_8;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar2 = 1000;
  }
  else {
    FUN_00409b18((int *)pFVar1,-0x300,2);
    FUN_0041f3be(local_308,0x300,1,(int *)pFVar1);
    if ((pFVar1->_flag & 0x20U) != 0) {
      FUN_0040187a((byte *)s__s__d____error_reading_00434c64);
    }
    for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
      *(char *)((int)DAT_0043d760 + local_8 * 4) = local_308[local_8 * 3];
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 1) = local_308[local_8 * 3 + 1];
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 2) = local_308[local_8 * 3 + 2];
    }
    if (param_2 != 0) {
      FUN_0040e96f(DAT_0043d760,DAT_0043d760,0,0x100);
    }
    FUN_00409f20(pFVar1);
    uVar2 = 0;
  }
  return uVar2;
}


/*
 * FUN_00413622 at 00413622
 * undefined4 __cdecl FUN_00413622(int * param_1, char * param_2)
 * Address ranges: 00413622-00413839
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00413622(int *param_1,char *param_2)

{
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  FUN_00409b18(param_1,-0x300,2);
  FUN_0041f3be(param_2,0x300,1,param_1);
  if ((param_1[3] & 0x20U) != 0) {
    FUN_0040187a((byte *)s__s__d____error_reading_00434c8c);
  }
  for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
    *(char *)(DAT_0043d760 + local_14 * 4) = param_2[local_14 * 3];
    *(char *)(DAT_0043d760 + 1 + local_14 * 4) = param_2[local_14 * 3 + 1];
    *(char *)(DAT_0043d760 + 2 + local_14 * 4) = param_2[local_14 * 3 + 2];
    if (local_14 == DAT_00434c50) {
      param_2[local_14 * 3] = (char)DAT_0043db60;
      *(char *)(DAT_0043d760 + local_14 * 4) = (char)DAT_0043db60;
      param_2[local_14 * 3 + 1] = (char)DAT_0043db64;
      *(char *)(DAT_0043d760 + 1 + local_14 * 4) = (char)DAT_0043db64;
      param_2[local_14 * 3 + 2] = (char)DAT_0043db68;
      *(char *)(DAT_0043d760 + 2 + local_14 * 4) = (char)DAT_0043db68;
      local_c = (uint)*(byte *)(DAT_0043d760 + local_14 * 4);
      local_10 = (uint)*(byte *)(DAT_0043d760 + 1 + local_14 * 4);
      local_8 = (uint)*(byte *)(DAT_0043d760 + 2 + local_14 * 4);
    }
  }
  if (DAT_00434c54 != 0) {
    for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
      if ((((local_14 != DAT_00434c50) && (local_c == *(byte *)(DAT_0043d760 + local_14 * 4))) &&
          (local_10 == *(byte *)(DAT_0043d760 + 1 + local_14 * 4))) &&
         (local_8 == *(byte *)(DAT_0043d760 + 2 + local_14 * 4))) {
        *(char *)(DAT_0043d760 + local_14 * 4) = (char)DAT_0043db60 + '\x01';
        param_2[local_14 * 3] = (char)DAT_0043db60 + '\x01';
      }
    }
  }
  return 0;
}


/*
 * FUN_0041383a at 0041383a
 * undefined4 __cdecl FUN_0041383a(LPCSTR param_1, int * param_2, int * param_3)
 * Address ranges: 0041383a-004138b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041383a(LPCSTR param_1,int *param_2,int *param_3)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char local_84 [4];
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar2 = 1000;
  }
  else {
    FUN_0041f3be(local_84,0x80,1,(int *)pFVar1);
    *param_3 = ((int)local_7a - (int)local_7e) + 1;
    *param_2 = ((int)local_7c - (int)local_80) + 1;
    FUN_00409f20(pFVar1);
    uVar2 = 0;
  }
  return uVar2;
}


/*
 * FUN_004138b8 at 004138b8
 * undefined4 __cdecl FUN_004138b8(LPCSTR param_1, uint param_2)
 * Address ranges: 004138b8-00413ad1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004138b8(LPCSTR param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *this;
  void *extraout_ECX;
  undefined4 local_3ac;
  undefined4 local_3a8;
  int local_3a4;
  int local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  int local_390;
  FILE *local_38c;
  char local_388 [768];
  int local_88;
  char local_84;
  char local_83;
  short local_7e;
  short local_7a;
  short local_42;
  
  local_38c = (FILE *)FUN_00409d69(param_1);
  if (local_38c == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    if ((param_2 & 2) != 0) {
      FUN_00413622((int *)local_38c,local_388);
    }
    FUN_00409b18((int *)local_38c,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)local_38c);
    if ((local_38c->_flag & 0x20U) == 0) {
      this = (void *)(param_2 & 1);
      if (((this != (void *)0x0) && (local_84 == '\n')) && (local_83 == '\x05')) {
        local_88 = ((int)local_7a - (int)local_7e) + 1;
        if (DAT_0042c354 < local_88) {
          local_88 = DAT_0042c354;
        }
        FUN_00414a90(2,&local_38c->_ptr,(int)local_42,local_88);
        this = extraout_ECX;
      }
      if ((param_2 & 6) == 6) {
        FUN_0040e96f(this,DAT_0043d760,0,0x100);
      }
      if ((param_2 & 8) != 0) {
        if ((param_2 & 0x10) == 0) {
          FUN_0040337e();
        }
        else {
          local_3ac = 0;
          local_3a8 = 0;
          local_3a0 = local_88;
          local_3a4 = (int)local_42;
          local_39c = 0;
          local_398 = 0;
          local_390 = DAT_0042c354;
          local_394 = DAT_0042c350;
          iVar2 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_39c,DAT_00438418,&local_3ac,0x1000000,0);
          if (iVar2 != 0) {
            FUN_00401f61(iVar2);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00434cb4);
          }
        }
      }
      FUN_00409f20(local_38c);
      uVar1 = 0;
    }
    else {
      FUN_0041f368(local_38c);
      uVar1 = 0x3e9;
    }
  }
  return uVar1;
}


/*
 * FUN_00413ad2 at 00413ad2
 * undefined4 __cdecl FUN_00413ad2(int param_1, LPCSTR param_2, uint param_3)
 * Address ranges: 00413ad2-00413c46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00413ad2(int param_1,LPCSTR param_2,uint param_3)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char local_38c [768];
  int local_8c;
  int local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  pFVar1 = (FILE *)FUN_00409d69(param_2);
  if (pFVar1 == (FILE *)0x0) {
    uVar2 = 1000;
  }
  else {
    if ((param_3 & 2) != 0) {
      FUN_00413622((int *)pFVar1,local_38c);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    if ((pFVar1->_flag & 0x20U) == 0) {
      if ((((param_3 & 1) != 0) && (local_84 == '\n')) && (local_83 == '\x05')) {
        local_8c = ((int)local_7a - (int)local_7e) + 1;
        local_88 = ((int)local_7c - (int)local_80) + 1;
        if (DAT_0042c354 < local_8c) {
          local_8c = DAT_0042c354;
        }
        FUN_004015a6((byte *)s_bpl__d__width__d_00434cd4);
        FUN_00414a90(param_1,(undefined4 *)pFVar1,(int)local_42,local_8c);
      }
      if ((param_3 & 6) == 6) {
        FUN_0040e96f((void *)0x6,DAT_0043d760,0,0x100);
      }
      FUN_00409f20(pFVar1);
      uVar2 = 0;
    }
    else {
      FUN_0041f368(pFVar1);
      uVar2 = 0x3e9;
    }
  }
  return uVar2;
}


/*
 * FUN_00413c47 at 00413c47
 * int * __cdecl FUN_00413c47(LPCSTR param_1, int * param_2, int * param_3)
 * Address ranges: 00413c47-00413dec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00413c47(LPCSTR param_1,int *param_2,int *param_3)

{
  FILE *pFVar1;
  char local_388 [768];
  int *local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    local_88 = (int *)0x0;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)pFVar1,local_388);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    FUN_004015a6((byte *)s__s__d____header_read__00434cf4);
    if ((pFVar1->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434d1c);
      if ((local_84 == '\n') && (local_83 == '\x05')) {
        *param_2 = ((int)local_7c - (int)local_80) + 1;
        *param_3 = ((int)local_7a - (int)local_7e) + 1;
        FUN_004015a6((byte *)s_creating_surface__d__d_00434d40);
        local_88 = (int *)FUN_004028e3(*param_2,*param_3);
        FUN_004015a6((byte *)s_creation_succesfull_00434d58);
        FUN_00414f40(local_88,(undefined4 *)pFVar1,(int)local_42,*param_3);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434d7c);
      FUN_00409f20(pFVar1);
    }
    else {
      FUN_00409f20(pFVar1);
      local_88 = (int *)0x0;
    }
  }
  return local_88;
}


/*
 * FUN_00413ded at 00413ded
 * int * __cdecl FUN_00413ded(LPCSTR param_1, int * param_2, int * param_3, undefined4 param_4, undefined4 * param_5)
 * Address ranges: 00413ded-00413fae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl
FUN_00413ded(LPCSTR param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 *param_5)

{
  FILE *pFVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 in_stack_fffffc4c;
  uint in_stack_fffffc50;
  undefined4 in_stack_fffffc54;
  undefined4 in_stack_fffffc58;
  uint in_stack_fffffc5c;
  uint in_stack_fffffc60;
  uint in_stack_fffffc64;
  char local_388 [768];
  int *local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  puVar3 = param_5;
  puVar4 = (undefined4 *)&stack0xfffffc4c;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_0040e544(in_stack_fffffc4c,in_stack_fffffc50,in_stack_fffffc54,in_stack_fffffc58,
               in_stack_fffffc5c,in_stack_fffffc60,in_stack_fffffc64);
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    local_88 = (int *)0x0;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)pFVar1,local_388);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    FUN_004015a6((byte *)s__s__d____header_read__00434d9c);
    if ((pFVar1->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434dc4);
      if ((local_84 == '\n') && (local_83 == '\x05')) {
        *param_2 = ((int)local_7c - (int)local_80) + 1;
        *param_3 = ((int)local_7a - (int)local_7e) + 1;
        FUN_004015a6((byte *)s_creating_surface__d__d_00434de8);
        local_88 = (int *)FUN_00402e3b(*param_2,*param_3,param_4,param_5);
        FUN_004015a6((byte *)s_creation_succesfull_00434e00);
        FUN_00414f40(local_88,(undefined4 *)pFVar1,(int)local_42,*param_3);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434e24);
      FUN_00409f20(pFVar1);
      FUN_0040e321();
    }
    else {
      FUN_00409f20(pFVar1);
      local_88 = (int *)0x0;
    }
  }
  return local_88;
}


/*
 * FUN_00413faf at 00413faf
 * int * __cdecl FUN_00413faf(LPCSTR param_1, int * param_2, int * param_3, undefined4 param_4)
 * Address ranges: 00413faf-00414158
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00413faf(LPCSTR param_1,int *param_2,int *param_3,undefined4 param_4)

{
  FILE *pFVar1;
  char local_388 [768];
  int *local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    local_88 = (int *)0x0;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)pFVar1,local_388);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    FUN_004015a6((byte *)s__s__d____header_read__00434e44);
    if ((pFVar1->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434e6c);
      if ((local_84 == '\n') && (local_83 == '\x05')) {
        *param_2 = ((int)local_7c - (int)local_80) + 1;
        *param_3 = ((int)local_7a - (int)local_7e) + 1;
        FUN_004015a6((byte *)s_creating_surface__d__d_00434e90);
        local_88 = (int *)FUN_00402a32(*param_2,*param_3,param_4);
        FUN_004015a6((byte *)s_creation_succesfull_00434ea8);
        FUN_00414f40(local_88,(undefined4 *)pFVar1,(int)local_42,*param_3);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434ecc);
      FUN_00409f20(pFVar1);
    }
    else {
      FUN_00409f20(pFVar1);
      local_88 = (int *)0x0;
    }
  }
  return local_88;
}


/*
 * FUN_00414159 at 00414159
 * undefined4 __cdecl FUN_00414159(LPCSTR param_1, int * param_2)
 * Address ranges: 00414159-004143d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00414159(LPCSTR param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 local_3c0;
  undefined4 local_3bc;
  int local_3b8;
  int local_3b4;
  undefined4 local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  FILE *local_3a0;
  char local_39c [768];
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int *local_90;
  char local_8c;
  char local_8b;
  short local_88;
  short local_86;
  short local_84;
  short local_82;
  short local_4a;
  int local_c;
  int local_8;
  
  local_3a0 = (FILE *)FUN_00409d69(param_1);
  if (local_3a0 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)local_3a0,local_39c);
    }
    FUN_00409b18((int *)local_3a0,0,0);
    FUN_0041f3be(&local_8c,0x80,1,(int *)local_3a0);
    FUN_004015a6((byte *)s__s__d____header_read__00434eec);
    if ((local_3a0->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434f14);
      FUN_0040312d(param_2,&local_94,&local_98);
      if ((local_8c == '\n') && (local_8b == '\x05')) {
        local_3b8 = ((int)local_84 - (int)local_88) + 1;
        local_3b4 = ((int)local_82 - (int)local_86) + 1;
        local_3bc = 0;
        local_3c0 = 0;
        local_3ac = 0;
        local_3a4 = local_98;
        local_3b0 = 0;
        local_3a8 = local_94;
        local_c = local_3b8;
        local_8 = local_3b4;
        local_90 = (int *)FUN_004028e3(local_3b8,local_3b4);
        FUN_004015a6((byte *)s_creation_succesfull_00434f38);
        FUN_00414f40(local_90,&local_3a0->_ptr,(int)local_4a,local_8);
        FUN_004015a6((byte *)s_blitting_to_destination_00434f50);
        local_9c = (**(code **)(*param_2 + 0x14))
                             (param_2,&local_3b0,local_90,&local_3c0,0x1000000,0);
        if (local_9c != 0) {
          FUN_00401f61(local_9c);
          FUN_0040187a((byte *)s__s__d____blitting_error___s__00434f78);
        }
        FUN_004015a6((byte *)s_Release_buffer_surface_00434f98);
        (**(code **)(*local_90 + 8))(local_90);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434fbc);
      FUN_00409f20(local_3a0);
      uVar1 = 0;
    }
    else {
      FUN_00409f20(local_3a0);
      uVar1 = 0;
    }
  }
  return uVar1;
}


/*
 * FUN_004143d4 at 004143d4
 * undefined4 __cdecl FUN_004143d4(LPCSTR param_1, int * param_2, int param_3, int param_4)
 * Address ranges: 004143d4-0041461a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004143d4(LPCSTR param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  FILE *local_a0;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int *local_90;
  char local_8c;
  char local_8b;
  short local_88;
  short local_86;
  short local_84;
  short local_82;
  short local_4a;
  int local_c;
  int local_8;
  
  local_a0 = (FILE *)FUN_00409d69(param_1);
  if (local_a0 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_0041f3be(&local_8c,0x80,1,(int *)local_a0);
    FUN_004015a6((byte *)s__s__d____header_read__00434fdc);
    if ((local_a0->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00435004);
      FUN_0040312d(param_2,&local_94,&local_98);
      if ((local_8c == '\n') && (local_8b == '\x05')) {
        local_b8 = ((int)local_84 - (int)local_88) + 1;
        local_b4 = ((int)local_82 - (int)local_86) + 1;
        local_bc = 0;
        local_c0 = 0;
        local_ac = param_4;
        local_a4 = param_4 + local_b4;
        local_b0 = param_3;
        local_a8 = param_3 + local_b8;
        local_c = local_b8;
        local_8 = local_b4;
        local_90 = (int *)FUN_004028e3(local_b8,local_b4);
        FUN_004015a6((byte *)s_creation_succesfull_00435028);
        FUN_00414f40(local_90,&local_a0->_ptr,(int)local_4a,local_8);
        FUN_004015a6((byte *)s_blitting_to_destination_00435040);
        local_9c = (**(code **)(*param_2 + 0x14))(param_2,&local_b0,local_90,&local_c0,0x1000000,0);
        if (local_9c != 0) {
          FUN_00401f61(local_9c);
          FUN_0040187a((byte *)s__s__d____blitting_error___s__00435068);
        }
        FUN_004015a6((byte *)s_Release_buffer_surface_00435088);
        (**(code **)(*local_90 + 8))(local_90);
      }
      FUN_004015a6((byte *)s__s__d____closing_004350ac);
      FUN_00409f20(local_a0);
      uVar1 = 0;
    }
    else {
      FUN_00409f20(local_a0);
      uVar1 = 0;
    }
  }
  return uVar1;
}


/*
 * FUN_0041461b at 0041461b
 * undefined1 __cdecl FUN_0041461b(int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 0041461b-00414633
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __cdecl FUN_0041461b(int param_1,int param_2,int param_3,int param_4)

{
  return *(undefined1 *)(param_1 + param_2 + param_3 * param_4);
}


/*
 * FUN_00414634 at 00414634
 * int __cdecl FUN_00414634(int param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 00414634-004146c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00414634(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_2 < param_5) {
    while( true ) {
      uVar1 = FUN_0041461b(param_1,param_2 + local_8,param_3,param_5);
      uVar2 = FUN_0041461b(param_1,param_2 + 1 + local_8,param_3,param_5);
      if (((CONCAT31(extraout_var,uVar1) != CONCAT31(extraout_var_00,uVar2)) || (param_4 <= local_8)
          ) || (0x3e < local_8)) break;
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    local_c = 1;
  }
  else {
    local_c = local_8;
  }
  return local_c;
}


/*
 * FUN_004146c3 at 004146c3
 * uint __cdecl FUN_004146c3(int * param_1, int param_2, int param_3, uint param_4, int param_5)
 * Address ranges: 004146c3-004147d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_004146c3(int *param_1,int param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  uint local_14;
  byte local_10 [4];
  byte local_c [4];
  int local_8;
  
  local_14 = 0;
  FUN_004015a6((byte *)s__s__d__004350cc);
  FUN_004015a6((byte *)s_y____d___xsize____d___pitch____d_004350d4);
  do {
    bVar1 = *(byte *)(param_2 + local_14 + param_3 * param_5);
    local_c[0] = bVar1;
    if ((bVar1 & 0xc0) == 0xc0) {
      local_8 = FUN_00414634(param_2,local_14,param_3,param_4 - local_14,param_4);
      local_10[0] = (byte)local_8 | 0xc0;
      FUN_0041fe82((char *)local_10,1,1,param_1);
      FUN_0041fe82((char *)local_c,1,1,param_1);
      local_14 = local_14 + local_8;
    }
    else {
      FUN_0041fe82((char *)local_c,1,1,param_1);
      local_14 = local_14 + 1;
    }
  } while (local_14 < param_4);
  FUN_004015a6((byte *)s__s__d__00435104);
  return local_14;
}


/*
 * FUN_004147d7 at 004147d7
 * undefined4 __cdecl FUN_004147d7(int * param_1, int param_2, uint param_3, int param_4, int param_5)
 * Address ranges: 004147d7-0041485d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004147d7(int *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int local_8;
  
  FUN_004015a6((byte *)s__s__d__00435118);
  for (local_8 = 0; local_8 < param_4; local_8 = local_8 + 1) {
    FUN_004015a6((byte *)s__s__d__0043512c);
    FUN_004146c3(param_1,param_2,local_8,param_3,param_5);
  }
  FUN_004015a6((byte *)s__s__d__00435140);
  return 0;
}


/*
 * FUN_0041485e at 0041485e
 * undefined4 __cdecl FUN_0041485e(int param_1, LPCSTR param_2)
 * Address ranges: 0041485e-00414a85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041485e(int param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  char local_398 [768];
  FILE *local_98;
  int local_94;
  int local_90;
  char local_8c [4];
  char local_88 [8];
  short local_80;
  short local_7e;
  short local_7c;
  undefined1 local_48;
  undefined1 local_47;
  short local_46;
  int local_8;
  
  local_8c[0] = '\f';
  if (DAT_0042c358 != 8) {
    FUN_0040187a((byte *)s__s__d____save_pcx_file____s___bi_00435154);
  }
  builtin_strncpy(local_88,"\n\x05\x01\b",5);
  local_7c = (short)DAT_0042c354;
  local_48 = 0;
  local_47 = 1;
  local_46 = (short)DAT_0042c350;
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_80 = (short)DAT_0042c350 + -1;
  local_7e = (short)DAT_0042c354 + -1;
  local_98 = (FILE *)FUN_0041f4c6(param_2,&DAT_004351a4);
  if (local_98 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_0041fe82(local_88,0x80,1,(int *)local_98);
    local_8 = FUN_00402531(param_1,&local_94);
    if (local_8 == 0) {
      FUN_0041f368(local_98);
      FUN_0040187a((byte *)s__s__d____Unable_to_lock_focus_fo_004351a8);
    }
    FUN_004147d7((int *)local_98,local_8,DAT_0042c350,DAT_0042c354,local_94);
    FUN_00402727(param_1,local_8);
    for (local_90 = 0; local_90 < 0x100; local_90 = local_90 + 1) {
      local_398[local_90 * 3] = *(char *)(DAT_0043d760 + local_90 * 4);
      local_398[local_90 * 3 + 1] = *(char *)(DAT_0043d760 + 1 + local_90 * 4);
      local_398[local_90 * 3 + 2] = *(char *)(DAT_0043d760 + 2 + local_90 * 4);
    }
    FUN_0041fe82(local_8c,1,1,(int *)local_98);
    FUN_0041fe82(local_398,1,0x300,(int *)local_98);
    FUN_0041f368(local_98);
    uVar1 = 0;
  }
  return uVar1;
}


/*
 * FUN_00414a90 at 00414a90
 * undefined __cdecl FUN_00414a90(int param_1, undefined4 * param_2, int param_3, int param_4)
 * Address ranges: 00414a90-00414c5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00414a90(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (DAT_0042c354 <= param_4) {
    param_4 = DAT_0042c354;
  }
  if (param_1 == 0) {
    local_10 = DAT_004383b4;
    local_14 = DAT_00438434;
  }
  else if (param_1 == 1) {
    local_10 = DAT_00438420;
    local_14 = DAT_00438438;
  }
  else if (param_1 == 2) {
    local_10 = DAT_00438430;
    local_14 = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_004351d4);
  }
  FUN_004028c2(local_14);
  if (DAT_0043d754 == 0) {
    local_8 = FUN_0040243c(param_1);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414e80(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_00402727(param_1,local_8);
  }
  else if (DAT_0043d754 == 1) {
    local_8 = FUN_0040243c(param_1);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414c60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_00402727(param_1,local_8);
  }
  else if (DAT_0043d754 == 2) {
    local_8 = FUN_0040243c(param_1);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414d60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_00402727(param_1,local_8);
  }
  return;
}


/*
 * FUN_00414c60 at 00414c60
 * int __cdecl FUN_00414c60(int param_1, undefined4 * param_2, int param_3)
 * Address ranges: 00414c60-00414d57
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00414c60(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_18;
  undefined4 local_c;
  
  local_18 = 0;
  do {
    uVar1 = FUN_0041fe68(param_2);
    if ((uVar1 & 0xc0) == 0xc0) {
      uVar2 = FUN_0041fe68(param_2);
      uVar2 = FUN_0040de93(uVar2 & 0xff,8);
      for (local_c = 0; local_c < (int)(uVar1 & 0x3f); local_c = local_c + 1) {
        *(short *)(param_1 + local_18 * 2) = (short)uVar2;
        local_18 = local_18 + 1;
      }
    }
    else {
      uVar1 = FUN_0040de93(uVar1 & 0xff,8);
      *(short *)(param_1 + local_18 * 2) = (short)uVar1;
      local_18 = local_18 + 1;
    }
  } while (local_18 < param_3);
  return local_18;
}


/*
 * FUN_00414d60 at 00414d60
 * int __cdecl FUN_00414d60(int param_1, undefined4 * param_2, int param_3)
 * Address ranges: 00414d60-00414e72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00414d60(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int local_1c;
  uint local_14;
  int local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  uint *local_8;
  
  local_1c = 0;
  local_10 = 0;
  local_8 = &local_14;
  do {
    uVar1 = FUN_0041fe68(param_2);
    _local_c = CONCAT31(uStack_b,(char)uVar1);
    if ((uVar1 & 0xc0) == 0xc0) {
      uVar2 = FUN_0041fe68(param_2);
      _local_c = CONCAT31(uStack_b,(char)uVar2);
      local_14 = FUN_0040de93(uVar2 & 0xff,8);
      for (local_10 = 0; local_10 < (int)(uVar1 & 0x3f); local_10 = local_10 + 1) {
        puVar3 = (undefined2 *)(param_1 + local_1c * 3);
        *puVar3 = (short)*local_8;
        *(undefined1 *)(puVar3 + 1) = *(undefined1 *)((int)local_8 + 2);
        local_1c = local_1c + 1;
      }
    }
    else {
      local_14 = FUN_0040de93(uVar1 & 0xff,8);
      puVar3 = (undefined2 *)(param_1 + local_1c * 3);
      *puVar3 = (short)*local_8;
      *(undefined1 *)(puVar3 + 1) = *(undefined1 *)((int)local_8 + 2);
      local_1c = local_1c + 1;
    }
  } while (local_1c < param_3);
  return local_1c;
}


/*
 * FUN_00414e80 at 00414e80
 * int __cdecl FUN_00414e80(int param_1, undefined4 * param_2, int param_3)
 * Address ranges: 00414e80-00414f30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00414e80(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_10;
  
  local_10 = 0;
  do {
    uVar1 = FUN_0041fe68(param_2);
    if ((uVar1 & 0xc0) == 0xc0) {
      uVar2 = FUN_0041fe68(param_2);
      _memset((void *)(param_1 + local_10),uVar2 & 0xff,uVar1 & 0x3f);
      local_10 = local_10 + (uVar1 & 0x3f);
    }
    else {
      *(char *)(param_1 + local_10) = (char)uVar1;
      local_10 = local_10 + 1;
    }
  } while (local_10 < param_3);
  return local_10;
}


/*
 * FUN_00414f40 at 00414f40
 * undefined __cdecl FUN_00414f40(int * param_1, undefined4 * param_2, int param_3, int param_4)
 * Address ranges: 00414f40-00415094
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00414f40(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004028c2(param_1);
  if (DAT_0043d754 == 0) {
    local_8 = FUN_00402631(param_1,&local_10);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414e80(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_004027f9(param_1,local_8);
  }
  else if (DAT_0043d754 == 1) {
    local_8 = FUN_00402631(param_1,&local_10);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414c60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_004027f9(param_1,local_8);
  }
  else if (DAT_0043d754 == 2) {
    local_8 = FUN_00402631(param_1,&local_10);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414d60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_004027f9(param_1,local_8);
  }
  return;
}


/*
 * FUN_004150a0 at 004150a0
 * undefined __stdcall FUN_004150a0(void)
 * Address ranges: 004150a0-004150a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004150a0(void)

{
  return;
}


/*
 * FUN_004150b0 at 004150b0
 * undefined __cdecl FUN_004150b0(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004150b0-004150c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004150b0(undefined4 param_1,undefined4 param_2)

{
  _DAT_0043db7c = param_1;
  _DAT_0043db80 = param_2;
  return;
}


/*
 * FUN_004150c6 at 004150c6
 * undefined __cdecl FUN_004150c6(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004150c6-004150f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004150c6(undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)(DAT_0043db88 + 0x88) = param_1;
  _DAT_0043db80 = param_1;
  *(undefined4 *)(DAT_0043db88 + 0x8c) = param_2;
  _DAT_0043db7c = param_2;
  return;
}


/*
 * FUN_004150f9 at 004150f9
 * undefined4 __stdcall FUN_004150f9(void)
 * Address ranges: 004150f9-00415122
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004150f9(void)

{
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____set_a_ascii_set_first__b_00435218);
  }
  return *(undefined4 *)(DAT_0043db88 + 0x70);
}


/*
 * FUN_00415123 at 00415123
 * undefined4 __stdcall FUN_00415123(void)
 * Address ranges: 00415123-0041514c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00415123(void)

{
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____set_a_ascii_set_first__b_00435260);
  }
  return *(undefined4 *)(DAT_0043db88 + 0x74);
}


/*
 * FUN_0041514d at 0041514d
 * undefined4 __stdcall FUN_0041514d(void)
 * Address ranges: 0041514d-00415176
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041514d(void)

{
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____set_a_ascii_set_first__b_004352a8);
  }
  return *(undefined4 *)(DAT_0043db88 + 0x7c);
}


/*
 * FUN_00415177 at 00415177
 * undefined4 __stdcall FUN_00415177(void)
 * Address ranges: 00415177-004151a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00415177(void)

{
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____set_a_ascii_set_first__b_004352f0);
  }
  return *(undefined4 *)(DAT_0043db88 + 0x78);
}


/*
 * FUN_004151a1 at 004151a1
 * undefined4 __cdecl FUN_004151a1(int param_1)
 * Address ranges: 004151a1-0041520e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004151a1(int param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_refer_00435338);
  }
  if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc) == 0) {
    FUN_0040187a((byte *)s__s__d____character_not_available_00435370);
  }
  return *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc) + 8);
}


/*
 * FUN_0041520f at 0041520f
 * undefined4 __cdecl FUN_0041520f(int param_1)
 * Address ranges: 0041520f-00415282
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041520f(int param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_refer_004353b0);
  }
  if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc) == 0) {
    FUN_0040187a((byte *)s__s__d____character_not_available_004353e8);
  }
  return *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc) + 4);
}


/*
 * FUN_00415283 at 00415283
 * undefined4 __stdcall FUN_00415283(void)
 * Address ranges: 00415283-00415292
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00415283(void)

{
  return *(undefined4 *)(DAT_0043db88 + 0x80);
}


/*
 * FUN_00415293 at 00415293
 * undefined4 __stdcall FUN_00415293(void)
 * Address ranges: 00415293-004152a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00415293(void)

{
  return *(undefined4 *)(DAT_0043db88 + 0x84);
}


/*
 * FUN_004152a3 at 004152a3
 * undefined4 __stdcall FUN_004152a3(void)
 * Address ranges: 004152a3-004152ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004152a3(void)

{
  return DAT_0043db88;
}


/*
 * FUN_004152ad at 004152ad
 * undefined __cdecl FUN_004152ad(int param_1)
 * Address ranges: 004152ad-00415319
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004152ad(int param_1)

{
  if (DAT_0043db88 != param_1) {
    DAT_0043db88 = param_1;
    if (param_1 == 0) {
      DAT_0043db84 = 0;
      _DAT_0043db7c = 0;
      _DAT_0043db80 = 0;
    }
    else {
      DAT_0043db84 = 1;
      _DAT_0043db7c = *(undefined4 *)(param_1 + 0x8c);
      _DAT_0043db80 = *(undefined4 *)(param_1 + 0x88);
    }
  }
  return;
}


/*
 * FUN_0041531a at 0041531a
 * undefined4 __cdecl FUN_0041531a(int param_1, undefined4 * param_2)
 * Address ranges: 0041531a-00415411
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041531a(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_8;
  
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____current_ascii_set_not_d_00435428);
  }
  if ((param_1 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00435460);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc);
  if (iVar1 == 0) {
    FUN_0040187a((byte *)s__s__d____locking_ascii_char_that_004354a0);
  }
  else if (iVar1 == 1) {
    local_8 = FUN_00402631((int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc),
                           param_2);
  }
  else if (iVar1 == 2) {
    local_8 = FUN_00402631(*(int **)(DAT_0043d6e8 + 4 +
                                    *(int *)(*(int *)(DAT_0043db88 + 0x68) + 4 + param_1 * 0xc) *
                                    0x20),param_2);
  }
  return local_8;
}


/*
 * FUN_00415412 at 00415412
 * undefined4 __cdecl FUN_00415412(int param_1, undefined4 param_2)
 * Address ranges: 00415412-00415500
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00415412(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____current_ascii_set_not_d_004354e4);
  }
  if ((param_1 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_0043551c);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc);
  if (iVar1 == 0) {
    FUN_0040187a((byte *)s__s__d____unlocking_ascii_char_th_0043555c);
  }
  else if (iVar1 == 1) {
    FUN_004027f9((int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc),param_2);
  }
  else if (iVar1 == 2) {
    FUN_004027f9(*(int **)(DAT_0043d6e8 + 4 +
                          *(int *)(*(int *)(DAT_0043db88 + 0x68) + 4 + param_1 * 0xc) * 0x20),
                 param_2);
  }
  return 0;
}


/*
 * FUN_00415501 at 00415501
 * undefined4 __cdecl FUN_00415501(LPCSTR param_1)
 * Address ranges: 00415501-00415dbc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00415501(LPCSTR param_1)

{
  undefined4 uVar1;
  HLOCAL pvVar2;
  uint uVar3;
  int local_174;
  uint local_170;
  short *local_16c;
  int local_168;
  int local_164;
  uint local_160;
  short *local_15c;
  int local_158;
  int local_154;
  short *local_150;
  int local_14c;
  int local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  int *local_138;
  int local_134;
  short local_130 [2];
  int local_12c;
  char *local_128;
  short local_124 [2];
  short local_120 [2];
  char local_11c [256];
  int local_1c;
  short *local_18;
  uint local_14;
  uint local_10;
  int local_c;
  short local_8 [2];
  
  local_138 = FUN_00409d69(param_1);
  if (local_138 == (int *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_004015a6((byte *)s_resetting_data_00435594);
    _memset(local_11c,0,0x100);
    FUN_004015a6((byte *)s_reading_init_data_004355a4);
    FUN_0041f3be(local_11c,1,0x100,local_138);
    FUN_0041f3be((char *)local_120,1,2,local_138);
    FUN_0041f3be((char *)local_8,1,2,local_138);
    FUN_0041f3be((char *)local_124,1,2,local_138);
    FUN_0041f3be((char *)local_130,1,2,local_138);
    FUN_004015a6((byte *)s_reading_init_data_done_004355b8);
    *(int *)(param_1 + 0x80) = (int)local_120[0];
    *(int *)(param_1 + 0x84) = (int)local_8[0];
    *(int *)(param_1 + 0x70) = (int)local_124[0];
    *(int *)(param_1 + 0x74) = (int)local_130[0];
    param_1[0x88] = '\0';
    param_1[0x89] = '\0';
    param_1[0x8a] = '\0';
    param_1[0x8b] = '\0';
    param_1[0x8c] = '\0';
    param_1[0x8d] = '\0';
    param_1[0x8e] = '\0';
    param_1[0x8f] = '\0';
    param_1[0x6c] = '\x01';
    param_1[0x6d] = '\0';
    param_1[0x6e] = '\0';
    param_1[0x6f] = '\0';
    param_1[100] = '\0';
    param_1[0x65] = '\x01';
    param_1[0x66] = '\0';
    param_1[0x67] = '\0';
    pvVar2 = LocalAlloc(0x40,0xc00);
    *(HLOCAL *)(param_1 + 0x68) = pvVar2;
    if (*(int *)(param_1 + 0x68) == 0) {
      uVar1 = 2000;
    }
    else {
      for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
        pvVar2 = LocalAlloc(0x40,0xc);
        *(HLOCAL *)(*(int *)(param_1 + 0x68) + local_1c * 0xc) = pvVar2;
        if (*(int *)(*(int *)(param_1 + 0x68) + local_1c * 0xc) == 0) {
          return 2000;
        }
      }
      local_128 = LocalAlloc(0x40,*(int *)(param_1 + 0x80) * *(int *)(param_1 + 0x84));
      if (local_128 == (char *)0x0) {
        uVar1 = 2000;
      }
      else {
        local_c = FUN_004152a3();
        FUN_004152ad((int)param_1);
        FUN_004015a6((byte *)s_resetting_types_004355d0);
        for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
          *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_1c * 0xc) = 0;
        }
        FUN_004015a6((byte *)s_reading_char_data_004355e4);
        for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
          if (local_11c[local_1c] == '\0') {
            FUN_004015a6((byte *)s___d__not_available_004355f8);
            FUN_0041f3be(local_128,*(int *)(param_1 + 0x80) * *(int *)(param_1 + 0x84),1,local_138);
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_1c * 0xc) = 0;
          }
          else {
            FUN_004015a6((byte *)s___d__WEL_available_0043560c);
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 4) =
                 *(undefined4 *)(param_1 + 0x80);
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 8) =
                 *(undefined4 *)(param_1 + 0x84);
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_1c * 0xc) = 1;
            FUN_004015a6((byte *)s_creating_surface__d___d__d__00435620);
            uVar1 = FUN_004028e3(*(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 4),
                                 *(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 8));
            **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) = uVar1;
            if (**(int **)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) == 0) {
              return 2000;
            }
            if (DAT_0043d754 == 0) {
              local_10 = DAT_0042c4d0;
            }
            else if (DAT_0043d754 == 4) {
              local_10 = FUN_0040de93(DAT_00438474,0x18);
            }
            else {
              local_10 = FUN_0040de93(DAT_0042c4d0,8);
            }
            local_14 = local_10;
            FUN_004015a6((byte *)s_color_keying_surface__d___d__d__00435640);
            local_12c = (**(code **)(*(int *)**(undefined4 **)
                                               (*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) +
                                    0x74))(**(undefined4 **)
                                             (*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc),8,
                                           &local_14);
            if (local_12c != 0) {
              FUN_00401f61(local_12c);
              FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_00435670);
            }
            FUN_004015a6((byte *)s_Reading_data_to_surface__d___d___00435698);
            local_18 = (short *)FUN_0041531a(local_1c,&local_134);
            switch(DAT_0043d754) {
            case 0:
              for (local_174 = 0; local_174 < *(int *)(param_1 + 0x84); local_174 = local_174 + 1) {
                FUN_0041f3be((char *)local_18,1,*(uint *)(param_1 + 0x80),local_138);
                local_18 = (short *)((int)local_18 + local_134);
              }
              break;
            case 1:
              for (local_158 = 0; local_158 < *(int *)(param_1 + 0x84); local_158 = local_158 + 1) {
                local_15c = local_18;
                for (local_154 = 0; local_154 < *(int *)(param_1 + 0x80); local_154 = local_154 + 1)
                {
                  FUN_0041f3be((char *)&local_160,1,1,local_138);
                  uVar3 = FUN_0040de93(local_160 & 0xff,8);
                  *local_15c = (short)uVar3;
                  local_15c = local_15c + 1;
                }
                local_18 = (short *)((int)local_18 + local_134);
              }
              break;
            case 2:
              for (local_168 = 0; local_168 < *(int *)(param_1 + 0x84); local_168 = local_168 + 1) {
                local_16c = local_18;
                for (local_164 = 0; local_164 < *(int *)(param_1 + 0x80); local_164 = local_164 + 1)
                {
                  FUN_0041f3be((char *)&local_170,1,1,local_138);
                  FUN_0040e0c3(local_170 & 0xff,8,local_16c);
                  local_16c = (short *)((int)local_16c + 3);
                }
                local_18 = (short *)((int)local_18 + local_134);
              }
              break;
            case 4:
              for (local_14c = 0; local_14c < *(int *)(param_1 + 0x84); local_14c = local_14c + 1) {
                local_150 = local_18;
                for (local_148 = 0; local_148 < *(int *)(param_1 + 0x80); local_148 = local_148 + 1)
                {
                  FUN_0041f3be((char *)&local_140,1,1,local_138);
                  FUN_0041f3be((char *)&local_144,1,1,local_138);
                  FUN_0041f3be((char *)&local_13c,1,1,local_138);
                  uVar3 = FUN_0040de93(local_140 & 0xff | (local_144 & 0xff) << 8 |
                                       (local_13c & 0xff) << 0x10,0x18);
                  *local_150 = (short)uVar3;
                  local_150 = local_150 + 1;
                }
                local_18 = (short *)((int)local_18 + local_134);
              }
            }
            FUN_00415412(local_1c,local_18);
            if ((local_138[3] & 0x20U) != 0) {
              return 0x3e9;
            }
          }
        }
        *(undefined4 *)(DAT_0043db88 + 0x90) = 0x457;
        FUN_004152ad(local_c);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_00415dd1 at 00415dd1
 * undefined __cdecl FUN_00415dd1(uint param_1)
 * Address ranges: 00415dd1-00415e00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00415dd1(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x70)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x70),param_1);
    *(uint *)(DAT_0043db88 + 0x70) = param_1;
  }
  return;
}


/*
 * FUN_00415e01 at 00415e01
 * undefined __cdecl FUN_00415e01(uint param_1)
 * Address ranges: 00415e01-00415e30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00415e01(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x74)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x74),param_1);
    *(uint *)(DAT_0043db88 + 0x74) = param_1;
  }
  return;
}


/*
 * FUN_00415e31 at 00415e31
 * undefined __cdecl FUN_00415e31(uint param_1)
 * Address ranges: 00415e31-00415e60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00415e31(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x78)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x78),param_1);
    *(uint *)(DAT_0043db88 + 0x78) = param_1;
  }
  return;
}


/*
 * FUN_00415e61 at 00415e61
 * undefined __cdecl FUN_00415e61(uint param_1)
 * Address ranges: 00415e61-00415e90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00415e61(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x7c)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x7c),param_1);
    *(uint *)(DAT_0043db88 + 0x7c) = param_1;
  }
  return;
}


/*
 * FUN_00415e91 at 00415e91
 * undefined __cdecl FUN_00415e91(int param_1, byte * param_2)
 * Address ranges: 00415e91-0041603b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00415e91(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  while (*param_2 != 0) {
    if ((int)(uint)*param_2 < *(int *)(DAT_0043db88 + 100)) {
      iVar1 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_2 * 0xc) + 8);
      iVar2 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_2 * 0xc) + 4);
      if (*param_2 == 9) {
        DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
      }
      else if (*param_2 == 10) {
        if (DAT_0043db70 + iVar1 + _DAT_0043db7c < DAT_0042c354) {
          DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
        }
        DAT_0043db6c = 0;
      }
      else {
        if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + (uint)*param_2 * 0xc) == 1) {
          FUN_00411068(param_1,(uint)*param_2,DAT_0043db6c,DAT_0043db70);
        }
        DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
      }
      param_2 = param_2 + 1;
      if (DAT_0042c350 < DAT_0043db6c) {
        if (DAT_0043db70 + iVar1 + _DAT_0043db7c < DAT_0042c354) {
          DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
        }
        DAT_0043db6c = 0;
      }
    }
    else {
      param_2 = param_2 + 1;
    }
  }
  return;
}


/*
 * FUN_0041603c at 0041603c
 * undefined __cdecl FUN_0041603c(int param_1, int param_2, int param_3, byte * param_4)
 * Address ranges: 0041603c-004161c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041603c(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  int iVar2;
  
  DAT_0043db6c = param_2;
  DAT_0043db70 = param_3;
  do {
    while( true ) {
      if (*param_4 == 0) {
        return;
      }
      if ((int)(uint)*param_4 < *(int *)(DAT_0043db88 + 100)) break;
      param_4 = param_4 + 1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_4 * 0xc) + 8);
    iVar2 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_4 * 0xc) + 4);
    if (*param_4 == 9) {
      DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
    }
    else if (*param_4 == 10) {
      if (DAT_0042c354 <= DAT_0043db70 + iVar1 + _DAT_0043db7c) {
        return;
      }
      DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
      DAT_0043db6c = 0;
    }
    else {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + (uint)*param_4 * 0xc) == 1) {
        FUN_00411068(param_1,(uint)*param_4,DAT_0043db6c,DAT_0043db70);
      }
      DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
    }
    param_4 = param_4 + 1;
  } while (DAT_0043db6c <= DAT_0042c350);
  return;
}


/*
 * FUN_004161c8 at 004161c8
 * undefined __cdecl FUN_004161c8(int param_1, int param_2, int param_3, int param_4, int param_5, byte * param_6)
 * Address ranges: 004161c8-0041635d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004161c8(int param_1,int param_2,int param_3,int param_4,int param_5,byte *param_6)

{
  int iVar1;
  int iVar2;
  
  DAT_0043db6c = param_2;
  DAT_0043db70 = param_3;
  do {
    while( true ) {
      if (*param_6 == 0) {
        return;
      }
      if ((int)(uint)*param_6 < *(int *)(DAT_0043db88 + 100)) break;
      param_6 = param_6 + 1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_6 * 0xc) + 8);
    iVar2 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_6 * 0xc) + 4);
    if (*param_6 == 9) {
      DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
    }
    else if (*param_6 == 10) {
      if (DAT_0042c354 <= DAT_0043db70 + iVar1 + _DAT_0043db7c) {
        return;
      }
      DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
      DAT_0043db6c = 0;
    }
    else {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + (uint)*param_6 * 0xc) == 1) {
        FUN_00411528(param_1,(uint)*param_6,DAT_0043db6c,DAT_0043db70,param_4,param_5);
      }
      DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
    }
    param_6 = param_6 + 1;
  } while (DAT_0043db6c <= DAT_0042c350);
  return;
}


/*
 * FUN_0041635e at 0041635e
 * int __cdecl FUN_0041635e(int param_1, int param_2, int param_3, byte * param_4)
 * Address ranges: 0041635e-004163be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0041635e(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  byte local_194 [400];
  
  iVar1 = FUN_0041f64a(local_194,param_4,(undefined4 *)&stack0x00000014);
  FUN_0041603c(param_1,param_2,param_3,local_194);
  return iVar1;
}


/*
 * FUN_004163bf at 004163bf
 * int __cdecl FUN_004163bf(int param_1, int param_2, int param_3, int param_4, int param_5, byte * param_6)
 * Address ranges: 004163bf-00416427
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_004163bf(int param_1,int param_2,int param_3,int param_4,int param_5,byte *param_6)

{
  int iVar1;
  byte local_194 [400];
  
  iVar1 = FUN_0041f64a(local_194,param_6,(undefined4 *)&stack0x0000001c);
  FUN_004161c8(param_1,param_2,param_3,param_4,param_5,local_194);
  return iVar1;
}


/*
 * FUN_00416428 at 00416428
 * undefined4 __cdecl FUN_00416428(LPCSTR param_1)
 * Address ranges: 00416428-00416d2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00416428(LPCSTR param_1)

{
  undefined4 uVar1;
  HLOCAL pvVar2;
  uint uVar3;
  int iVar4;
  int local_878;
  uint local_874;
  short *local_870;
  int local_86c;
  int local_868;
  uint local_864;
  short *local_860;
  int local_85c;
  int local_858;
  short *local_854;
  int local_850;
  int local_84c;
  uint local_848;
  uint local_844;
  uint local_840;
  int *local_83c;
  int local_838;
  int local_834;
  short local_830 [2];
  short local_82c [2];
  int aiStack_828 [511];
  short local_2c [2];
  int local_28;
  short local_24 [2];
  short *local_20;
  int local_1c;
  int local_18;
  int local_14;
  short local_10 [2];
  uint local_c;
  uint local_8;
  
  local_1c = 0xffffffff;
  local_28 = 0xffffffff;
  local_18 = FUN_004152a3();
  FUN_004015a6((byte *)s_Load_new_ascii_set__s__004356bc);
  local_83c = FUN_00409d69(param_1);
  if (local_83c == (int *)0x0) {
    uVar1 = 1000;
  }
  else {
    _memset(local_82c,0,0x800);
    FUN_0041f3be((char *)local_82c,8,0x100,local_83c);
    local_1c = -1;
    local_28 = -1;
    for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
      if (((0 < local_82c[local_14 * 4]) && (0 < *(short *)((int)aiStack_828 + local_14 * 8 + -2)))
         && (iVar4 = (int)local_82c[local_14 * 4] *
                     (int)*(short *)((int)aiStack_828 + local_14 * 8 + -2),
            iVar4 - local_1c != 0 && local_1c <= iVar4)) {
        local_1c = (int)local_82c[local_14 * 4] *
                   (int)*(short *)((int)aiStack_828 + local_14 * 8 + -2);
        local_28 = local_14;
      }
    }
    if ((local_1c < 0) || (local_28 < 0)) {
      uVar1 = 1000;
    }
    else {
      FUN_004015a6((byte *)s_Largest_buffer_size_of_character_004356d8);
      FUN_0041f3be((char *)local_2c,1,2,local_83c);
      FUN_0041f3be((char *)local_830,1,2,local_83c);
      FUN_0041f3be((char *)local_10,1,2,local_83c);
      FUN_0041f3be((char *)local_24,1,2,local_83c);
      param_1[0x6c] = '\x03';
      param_1[0x6d] = '\0';
      param_1[0x6e] = '\0';
      param_1[0x6f] = '\0';
      param_1[100] = '\0';
      param_1[0x65] = '\x01';
      param_1[0x66] = '\0';
      param_1[0x67] = '\0';
      *(int *)(param_1 + 0x70) = (int)local_2c[0];
      *(int *)(param_1 + 0x74) = (int)local_830[0];
      *(int *)(param_1 + 0x78) = (int)local_10[0];
      *(int *)(param_1 + 0x7c) = (int)local_24[0];
      *(int *)(param_1 + 0x80) = (int)local_82c[local_28 * 4];
      *(int *)(param_1 + 0x84) = (int)*(short *)((int)aiStack_828 + local_28 * 8 + -2);
      param_1[0x88] = '\0';
      param_1[0x89] = '\0';
      param_1[0x8a] = '\0';
      param_1[0x8b] = '\0';
      param_1[0x8c] = '\0';
      param_1[0x8d] = '\0';
      param_1[0x8e] = '\0';
      param_1[0x8f] = '\0';
      pvVar2 = LocalAlloc(0x40,0xc00);
      *(HLOCAL *)(param_1 + 0x68) = pvVar2;
      if (*(int *)(param_1 + 0x68) == 0) {
        uVar1 = 2000;
      }
      else {
        for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
          pvVar2 = LocalAlloc(0x40,0xc);
          *(HLOCAL *)(*(int *)(param_1 + 0x68) + local_14 * 0xc) = pvVar2;
          if (*(int *)(*(int *)(param_1 + 0x68) + local_14 * 0xc) == 0) {
            return 2000;
          }
        }
        FUN_004152ad((int)param_1);
        FUN_004015a6((byte *)s_Importing_char_data_00435718);
        for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
          if ((local_82c[local_14 * 4] < 1) ||
             (*(short *)((int)aiStack_828 + local_14 * 8 + -2) < 1)) {
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_14 * 0xc) = 0;
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4) = 0;
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8) = 0;
          }
          else {
            *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4) =
                 (int)local_82c[local_14 * 4];
            *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8) =
                 (int)*(short *)((int)aiStack_828 + local_14 * 8 + -2);
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_14 * 0xc) = 1;
            FUN_00409b18(local_83c,aiStack_828[local_14 * 2],0);
            uVar1 = FUN_004028e3(*(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4),
                                 *(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8));
            **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) = uVar1;
            if (**(int **)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) == 0) {
              return 2000;
            }
            if (DAT_0043d754 == 0) {
              local_8 = DAT_0042c4d0;
            }
            else if (DAT_0043d754 == 4) {
              local_8 = FUN_0040de93(DAT_00438474,0x18);
            }
            else {
              local_8 = FUN_0040de93(DAT_0042c4d0,8);
            }
            local_c = local_8;
            local_838 = (**(code **)(*(int *)**(undefined4 **)
                                               (*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) +
                                    0x74))(**(undefined4 **)
                                             (*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc),8,
                                           &local_c);
            if (local_838 != 0) {
              FUN_00401f61(local_838);
              FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0043573c);
            }
            local_20 = (short *)FUN_0041531a(local_14,&local_834);
            switch(DAT_0043d754) {
            case 0:
              for (local_878 = 0;
                  local_878 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_878 = local_878 + 1) {
                FUN_0041f3be((char *)local_20,1,
                             *(uint *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4)
                             ,local_83c);
                local_20 = (short *)((int)local_20 + local_834);
              }
              break;
            case 1:
              for (local_85c = 0;
                  local_85c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_85c = local_85c + 1) {
                local_860 = local_20;
                for (local_858 = 0;
                    local_858 <
                    *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4);
                    local_858 = local_858 + 1) {
                  FUN_0041f3be((char *)&local_864,1,1,local_83c);
                  uVar3 = FUN_0040de93(local_864 & 0xff,8);
                  *local_860 = (short)uVar3;
                  local_860 = local_860 + 1;
                }
                local_20 = (short *)((int)local_20 + local_834);
              }
              break;
            case 2:
              for (local_86c = 0;
                  local_86c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_86c = local_86c + 1) {
                local_870 = local_20;
                for (local_868 = 0;
                    local_868 <
                    *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4);
                    local_868 = local_868 + 1) {
                  FUN_0041f3be((char *)&local_874,1,1,local_83c);
                  FUN_0040e0c3(local_874 & 0xff,8,local_870);
                  local_870 = (short *)((int)local_870 + 3);
                }
                local_20 = (short *)((int)local_20 + local_834);
              }
              break;
            case 4:
              for (local_850 = 0;
                  local_850 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_850 = local_850 + 1) {
                local_854 = local_20;
                for (local_84c = 0;
                    local_84c <
                    *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4);
                    local_84c = local_84c + 1) {
                  FUN_0041f3be((char *)&local_844,1,1,local_83c);
                  FUN_0041f3be((char *)&local_848,1,1,local_83c);
                  FUN_0041f3be((char *)&local_840,1,1,local_83c);
                  uVar3 = FUN_0040de93(local_844 & 0xff | (local_848 & 0xff) << 8 |
                                       (local_840 & 0xff) << 0x10,0x18);
                  *local_854 = (short)uVar3;
                  local_854 = local_854 + 1;
                }
                local_20 = (short *)((int)local_20 + local_834);
              }
            }
            FUN_00415412(local_14,local_20);
            FUN_004015a6((byte *)s_Data_read_to_surface__d___d__d__00435764);
            if ((local_83c[3] & 0x20U) != 0) {
              return 0x3e9;
            }
          }
        }
        *(undefined4 *)(DAT_0043db88 + 0x90) = 0x457;
        FUN_004152ad(local_18);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_00416d40 at 00416d40
 * undefined __stdcall FUN_00416d40(uint param_1, uint param_2)
 * Address ranges: 00416d40-00416f82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00416d40(uint param_1,uint param_2)

{
  uint uVar1;
  int local_28;
  short *local_24;
  int local_20;
  int local_1c;
  short local_18;
  short local_14;
  int local_10;
  undefined4 local_c;
  short *local_8;
  
  local_c = FUN_004152a3();
  if (DAT_0042c358 == 8) {
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_10 * 0xc) != 0) {
        local_8 = (short *)FUN_0041531a(local_10,&local_28);
        for (local_20 = 0;
            local_20 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 8);
            local_20 = local_20 + 1) {
          for (local_1c = 0;
              local_1c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 4);
              local_1c = local_1c + 1) {
            if ((uint)*(byte *)((int)local_8 + local_1c) == (param_1 & 0xff)) {
              *(undefined1 *)((int)local_8 + local_1c) = (undefined1)param_2;
            }
          }
          local_8 = (short *)((int)local_8 + local_28);
        }
        FUN_00415412(local_10,local_8);
      }
    }
  }
  else if (DAT_0042c358 == 0x10) {
    uVar1 = FUN_0040de93(param_1,0x18);
    local_18 = (short)uVar1;
    uVar1 = FUN_0040de93(param_2,0x18);
    local_14 = (short)uVar1;
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_10 * 0xc) != 0) {
        local_8 = (short *)FUN_0041531a(local_10,&local_28);
        for (local_20 = 0;
            local_20 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 8);
            local_20 = local_20 + 1) {
          local_24 = local_8;
          for (local_1c = 0;
              local_1c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 4);
              local_1c = local_1c + 1) {
            if (*local_24 == local_18) {
              *local_24 = local_14;
            }
            local_24 = local_24 + 1;
          }
          local_8 = (short *)((int)local_8 + local_28);
        }
        FUN_00415412(local_10,local_8);
      }
    }
  }
  else {
    FUN_0040187a((byte *)s__s___d___Only_8_and_16_bit_ascii_00435794);
  }
  return;
}


/*
 * FUN_00416f83 at 00416f83
 * int __cdecl FUN_00416f83(char * param_1)
 * Address ranges: 00416f83-00417004
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00416f83(char *param_1)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  sVar1 = _strlen(param_1);
  local_8 = 0;
  for (local_c = 0; local_c < (int)sVar1; local_c = local_c + 1) {
    local_8 = local_8 + *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) +
                                         (uint)(byte)param_1[local_c] * 0xc) + 4);
  }
  if (0 < (int)sVar1) {
    local_8 = local_8 + (sVar1 - 1) * *(int *)(DAT_0043db88 + 0x88);
  }
  return local_8;
}


/*
 * FUN_00417005 at 00417005
 * int __cdecl FUN_00417005(char * param_1, size_t param_2)
 * Address ranges: 00417005-0041708b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00417005(char *param_1,size_t param_2)

{
  size_t local_10;
  int local_c;
  int local_8;
  
  local_10 = _strlen(param_1);
  local_8 = 0;
  if ((int)param_2 < (int)local_10) {
    local_10 = param_2;
  }
  for (local_c = 0; local_c < (int)local_10; local_c = local_c + 1) {
    local_8 = local_8 + *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) +
                                         (uint)(byte)param_1[local_c] * 0xc) + 4);
  }
  return local_8 + local_10 * *(int *)(DAT_0043db88 + 0x88);
}


/*
 * FUN_0041708c at 0041708c
 * undefined4 __stdcall FUN_0041708c(void)
 * Address ranges: 0041708c-0041709b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041708c(void)

{
  return *(undefined4 *)(DAT_0043db88 + 0x84);
}


/*
 * FUN_004170a0 at 004170a0
 * undefined __stdcall FUN_004170a0(void)
 * Address ranges: 004170a0-004171d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004170a0(void)

{
  FUN_004171d6();
  FUN_00417205(0,FUN_0041a5c1,FUN_0041a561,0,FUN_0041a4fc,0,FUN_0041a98a);
  FUN_00417205(3,FUN_0041a5c1,FUN_0041a561,0,FUN_0041a4fc,0,FUN_0041a98a);
  FUN_00417205(1,FUN_0041cc4f,FUN_0041cc20,FUN_0041cb20,FUN_0041ce28,FUN_0041cb46,FUN_0041d1f5);
  FUN_00417205(2,FUN_0041c398,FUN_0041c369,FUN_0041c220,FUN_0041c516,0,FUN_0041c922);
  FUN_00417205(4,FUN_0041be35,FUN_0041be06,FUN_0041bde0,FUN_0041c00c,0,FUN_0041c0c8);
  FUN_00417205(5,FUN_0041b3f5,FUN_0041b3c6,FUN_0041b3a0,FUN_0041b6e6,0,FUN_0041bba6);
  FUN_00417205(6,FUN_0041abd5,FUN_0041aba6,FUN_0041ab80,FUN_0041ae68,0,FUN_0041b204);
  FUN_00417205(7,FUN_00419e73,FUN_00419e35,0,FUN_00419db3,0,FUN_0041a0d0);
  FUN_0041a3b0();
  FUN_00419210();
  return;
}


/*
 * FUN_004171d6 at 004171d6
 * undefined __stdcall FUN_004171d6(void)
 * Address ranges: 004171d6-00417204
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004171d6(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    (&DAT_0043db90)[local_8 * 0x1c] = 0;
  }
  return;
}


/*
 * FUN_00417205 at 00417205
 * undefined __cdecl FUN_00417205(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7)
 * Address ranges: 00417205-0041729b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_00417205(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  if ((&DAT_0043db90)[param_1 * 0x1c] == '\0') {
    (&DAT_0043db90)[param_1 * 0x1c] = 1;
    *(undefined4 *)(&DAT_0043db94 + param_1 * 0x1c) = param_2;
    *(undefined4 *)(&DAT_0043db98 + param_1 * 0x1c) = param_3;
    *(undefined4 *)(&DAT_0043db9c + param_1 * 0x1c) = param_4;
    *(undefined4 *)(&DAT_0043dba0 + param_1 * 0x1c) = param_5;
    *(undefined4 *)(&DAT_0043dba4 + param_1 * 0x1c) = param_6;
    *(undefined4 *)(&DAT_0043dba8 + param_1 * 0x1c) = param_7;
  }
  else {
    FUN_0040187a((byte *)s__s__d_____add_control_to_list__c_004357d8);
  }
  return;
}


/*
 * FUN_004172a0 at 004172a0
 * LONG __cdecl FUN_004172a0(LPCSTR param_1, int param_2)
 * Address ranges: 004172a0-00417327
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LONG __cdecl FUN_004172a0(LPCSTR param_1,int param_2)

{
  int iVar1;
  HDC local_10;
  tagSIZE local_c;
  
  FUN_004028c2(DAT_00438434);
  iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_10);
  if (iVar1 == 0) {
    if (DAT_0043dca8 != 0) {
      SelectObject(local_10,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
    }
    GetTextExtentPoint32A(local_10,param_1,param_2,&local_c);
    (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_10);
  }
  else {
    local_c.cx = -1;
  }
  return local_c.cx;
}


/*
 * FUN_00417328 at 00417328
 * LONG __cdecl FUN_00417328(LPCSTR param_1, int param_2)
 * Address ranges: 00417328-004173af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LONG __cdecl FUN_00417328(LPCSTR param_1,int param_2)

{
  int iVar1;
  HDC local_10;
  tagSIZE local_c;
  
  FUN_004028c2(DAT_00438434);
  iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_10);
  if (iVar1 == 0) {
    if (DAT_0043dca8 != 0) {
      SelectObject(local_10,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
    }
    GetTextExtentPoint32A(local_10,param_1,param_2,&local_c);
    (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_10);
  }
  else {
    local_c.cy = -1;
  }
  return local_c.cy;
}


/*
 * FUN_004173b0 at 004173b0
 * undefined4 __cdecl FUN_004173b0(int param_1, int param_2, int param_3, byte * param_4)
 * Address ranges: 004173b0-0041796a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004173b0(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  UINT UVar2;
  tagSIZE *ptVar3;
  INT *pIVar4;
  tagRECT local_1ec;
  tagSIZE local_1dc;
  tagRECT local_1d4;
  tagSIZE local_1c4;
  tagRECT local_1bc;
  tagSIZE local_1ac;
  undefined4 *local_1a4;
  HDC local_1a0;
  HGDIOBJ local_19c;
  int local_198;
  CHAR local_194 [400];
  
  local_1a4 = (undefined4 *)&stack0x00000014;
  local_198 = FUN_0041f64a(local_194,param_4,local_1a4);
  local_1a4 = (undefined4 *)0x0;
  if (param_1 == 0) {
    if (DAT_00438458 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_1a0);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a0,0xff0000);
        SetTextColor(local_1a0,0xffff);
        iVar1 = lstrlenA(local_194);
        TextOutA(local_1a0,param_2,param_3,local_194,iVar1);
      }
      else {
        local_19c = SelectObject(local_1a0,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a0,*(COLORREF *)(&DAT_0043582c + DAT_00435818 * 0x10));
        SetBkColor(local_1a0,*(COLORREF *)(&DAT_00435828 + DAT_00435818 * 0x10));
        SetBkMode(local_1a0,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_1ac;
        iVar1 = lstrlenA(local_194);
        GetTextExtentPoint32A(local_1a0,local_194,iVar1,ptVar3);
        SetRect(&local_1bc,param_2,param_3,param_2 + local_1ac.cx,param_3 + local_1ac.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_194);
        ExtTextOutA(local_1a0,param_2,param_3,0,&local_1bc,local_194,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_1a0);
    }
  }
  else if (param_1 == 1) {
    if (DAT_0043845c == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x44))(DAT_00438438,&local_1a0);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a0,0xff0000);
        SetTextColor(local_1a0,0xffff);
        iVar1 = lstrlenA(local_194);
        TextOutA(local_1a0,param_2,param_3,local_194,iVar1);
      }
      else {
        local_19c = SelectObject(local_1a0,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a0,*(COLORREF *)(&DAT_0043582c + DAT_00435818 * 0x10));
        SetBkColor(local_1a0,*(COLORREF *)(&DAT_00435828 + DAT_00435818 * 0x10));
        SetBkMode(local_1a0,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_1c4;
        iVar1 = lstrlenA(local_194);
        GetTextExtentPoint32A(local_1a0,local_194,iVar1,ptVar3);
        SetRect(&local_1d4,param_2,param_3,param_2 + local_1c4.cx,param_3 + local_1c4.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_194);
        ExtTextOutA(local_1a0,param_2,param_3,0,&local_1d4,local_194,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438438 + 0x68))(DAT_00438438,local_1a0);
    }
  }
  else if (param_1 == 2) {
    if (DAT_00438460 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438418 + 0x44))(DAT_00438418,&local_1a0);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a0,0xff0000);
        SetTextColor(local_1a0,0xffff);
        iVar1 = lstrlenA(local_194);
        TextOutA(local_1a0,param_2,param_3,local_194,iVar1);
      }
      else {
        local_19c = SelectObject(local_1a0,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a0,*(COLORREF *)(&DAT_0043582c + DAT_00435818 * 0x10));
        SetBkColor(local_1a0,*(COLORREF *)(&DAT_00435828 + DAT_00435818 * 0x10));
        SetBkMode(local_1a0,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_1dc;
        iVar1 = lstrlenA(local_194);
        GetTextExtentPoint32A(local_1a0,local_194,iVar1,ptVar3);
        SetRect(&local_1ec,param_2,param_3,param_2 + local_1dc.cx,param_3 + local_1dc.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_194);
        ExtTextOutA(local_1a0,param_2,param_3,0,&local_1ec,local_194,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438418 + 0x68))(DAT_00438418,local_1a0);
    }
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0043594c);
  }
  return 0;
}


/*
 * FUN_0041796b at 0041796b
 * undefined4 __cdecl FUN_0041796b(int param_1, int param_2, int param_3, COLORREF param_4, COLORREF param_5, byte * param_6)
 * Address ranges: 0041796b-00417ebe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_0041796b(int param_1,int param_2,int param_3,COLORREF param_4,COLORREF param_5,byte *param_6)

{
  int iVar1;
  UINT UVar2;
  tagSIZE *ptVar3;
  INT *pIVar4;
  tagRECT local_1dc;
  tagRECT local_1cc;
  tagRECT local_1bc;
  undefined4 *local_1ac;
  HDC local_1a8;
  HGDIOBJ local_1a4;
  int local_1a0;
  CHAR local_19c [400];
  tagSIZE local_c;
  
  local_1ac = (undefined4 *)&stack0x0000001c;
  local_1a0 = FUN_0041f64a(local_19c,param_6,local_1ac);
  local_1ac = (undefined4 *)0x0;
  if (param_1 == 0) {
    if (DAT_00438458 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x44))(DAT_00438434,&local_1a8);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a8,param_4);
        SetTextColor(local_1a8,param_5);
        iVar1 = lstrlenA(local_19c);
        TextOutA(local_1a8,param_2,param_3,local_19c,iVar1);
      }
      else {
        local_1a4 = SelectObject(local_1a8,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a8,param_5);
        SetBkColor(local_1a8,param_4);
        SetBkMode(local_1a8,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_c;
        iVar1 = lstrlenA(local_19c);
        GetTextExtentPoint32A(local_1a8,local_19c,iVar1,ptVar3);
        SetRect(&local_1bc,param_2,param_3,param_2 + local_c.cx,param_3 + local_c.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_19c);
        ExtTextOutA(local_1a8,param_2,param_3,0,&local_1bc,local_19c,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438434 + 0x68))(DAT_00438434,local_1a8);
    }
  }
  else if (param_1 == 1) {
    if (DAT_0043845c == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x44))(DAT_00438438,&local_1a8);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a8,param_4);
        SetTextColor(local_1a8,param_5);
        iVar1 = lstrlenA(local_19c);
        TextOutA(local_1a8,param_2,param_3,local_19c,iVar1);
      }
      else {
        local_1a4 = SelectObject(local_1a8,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a8,param_5);
        SetBkColor(local_1a8,param_4);
        SetBkMode(local_1a8,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_c;
        iVar1 = lstrlenA(local_19c);
        GetTextExtentPoint32A(local_1a8,local_19c,iVar1,ptVar3);
        SetRect(&local_1cc,param_2,param_3,param_2 + local_c.cx,param_3 + local_c.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_19c);
        ExtTextOutA(local_1a8,param_2,param_3,0,&local_1cc,local_19c,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438438 + 0x68))(DAT_00438438,local_1a8);
    }
  }
  else if (param_1 == 2) {
    if (DAT_00438460 == 0) {
      return 0x2711;
    }
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438418 + 0x44))(DAT_00438418,&local_1a8);
    if (iVar1 == 0) {
      if (DAT_0043dca8 == 0) {
        SetBkColor(local_1a8,param_4);
        SetTextColor(local_1a8,param_5);
        iVar1 = lstrlenA(local_19c);
        TextOutA(local_1a8,param_2,param_3,local_19c,iVar1);
      }
      else {
        local_1a4 = SelectObject(local_1a8,*(HGDIOBJ *)(&DAT_00435820 + DAT_00435818 * 0x10));
        SetTextColor(local_1a8,param_5);
        SetBkColor(local_1a8,param_4);
        SetBkMode(local_1a8,*(int *)(&DAT_00435824 + DAT_00435818 * 0x10));
        ptVar3 = &local_c;
        iVar1 = lstrlenA(local_19c);
        GetTextExtentPoint32A(local_1a8,local_19c,iVar1,ptVar3);
        SetRect(&local_1dc,param_2,param_3,param_2 + local_c.cx,param_3 + local_c.cy);
        pIVar4 = (INT *)0x0;
        UVar2 = lstrlenA(local_19c);
        ExtTextOutA(local_1a8,param_2,param_3,0,&local_1dc,local_19c,UVar2,pIVar4);
      }
      (**(code **)(*DAT_00438418 + 0x68))(DAT_00438418,local_1a8);
    }
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00435980);
  }
  return 0;
}


/*
 * FUN_00417ebf at 00417ebf
 * int __cdecl FUN_00417ebf(LPCSTR param_1, int param_2, DWORD param_3, DWORD param_4)
 * Address ranges: 00417ebf-00417f16
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00417ebf(LPCSTR param_1,int param_2,DWORD param_3,DWORD param_4)

{
  int iVar1;
  
  iVar1 = FUN_00418303();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____No_Free_Font_index__004359b4);
  }
  FUN_0041802e(iVar1,param_1,param_2,param_3,param_4);
  FUN_004180d3(iVar1);
  return iVar1;
}


/*
 * FUN_00417f17 at 00417f17
 * undefined4 __cdecl FUN_00417f17(int param_1, LPCSTR param_2, int param_3, DWORD param_4, DWORD param_5, undefined4 param_6)
 * Address ranges: 00417f17-00418019
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00417f17(int param_1,LPCSTR param_2,int param_3,DWORD param_4,DWORD param_5,undefined4 param_6)

{
  HFONT pHVar1;
  undefined4 uVar2;
  int local_8;
  
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_004359e0);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) != 0) {
    FUN_0040187a((byte *)s__s__d____Font_index_already_in_u_00435a1c);
  }
  switch(param_6) {
  case 0:
    local_8 = 100;
    break;
  case 1:
    local_8 = 400;
    break;
  case 2:
    local_8 = 700;
    break;
  case 3:
    local_8 = 800;
    break;
  case 4:
    local_8 = 900;
    break;
  default:
    FUN_0040187a((byte *)s__s__d____Font_illegal_thickness__00435a54);
  }
  pHVar1 = CreateFontA(param_3,0,0,0,local_8,param_4,param_5,0,0,0,0,0,2,param_2);
  *(HFONT *)(&DAT_00435820 + param_1 * 0x10) = pHVar1;
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) == 0) {
    uVar2 = 10000;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/*
 * FUN_0041802e at 0041802e
 * undefined4 __cdecl FUN_0041802e(int param_1, LPCSTR param_2, int param_3, DWORD param_4, DWORD param_5)
 * Address ranges: 0041802e-004180d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041802e(int param_1,LPCSTR param_2,int param_3,DWORD param_4,DWORD param_5)

{
  HFONT pHVar1;
  undefined4 uVar2;
  
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435a84);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) != 0) {
    FUN_0040187a((byte *)s__s__d____Font_index_already_in_u_00435ac0);
  }
  pHVar1 = CreateFontA(param_3,0,0,0,400,param_4,param_5,0,0,0,0,0,2,param_2);
  *(HFONT *)(&DAT_00435820 + param_1 * 0x10) = pHVar1;
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) == 0) {
    uVar2 = 10000;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/*
 * FUN_004180d3 at 004180d3
 * undefined4 __cdecl FUN_004180d3(int param_1)
 * Address ranges: 004180d3-0041813b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004180d3(int param_1)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435af8);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) == 0) {
    FUN_0040187a((byte *)s__s__d____Font_is_not_loaded___d__00435b34);
  }
  DAT_00435818 = param_1;
  DAT_0043dca8 = 1;
  return 0;
}


/*
 * FUN_0041813c at 0041813c
 * undefined __cdecl FUN_0041813c(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0041813c-00418183
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041813c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435b64);
  }
  *(undefined4 *)(&DAT_00435828 + param_1 * 0x10) = param_2;
  *(undefined4 *)(&DAT_0043582c + param_1 * 0x10) = param_3;
  return;
}


/*
 * FUN_00418184 at 00418184
 * undefined __cdecl FUN_00418184(int param_1, int param_2)
 * Address ranges: 00418184-004181ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00418184(int param_1,int param_2)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435ba0);
  }
  if (param_2 == 1) {
    *(undefined4 *)(&DAT_00435824 + param_1 * 0x10) = 1;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(&DAT_00435824 + param_1 * 0x10) = 2;
  }
  else {
    FUN_0040187a((byte *)s__s__d____illegal_bkmode_for_font_00435bdc);
  }
  return;
}


/*
 * FUN_00418200 at 00418200
 * undefined __cdecl FUN_00418200(int param_1)
 * Address ranges: 00418200-0041827a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00418200(int param_1)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435c0c);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) != 0) {
    if (param_1 == DAT_00435818) {
      DAT_0043dca8 = 0;
      DAT_00435818 = -1;
    }
    DeleteObject(*(HGDIOBJ *)(&DAT_00435820 + param_1 * 0x10));
    *(undefined4 *)(&DAT_00435820 + param_1 * 0x10) = 0;
  }
  return;
}


/*
 * FUN_0041827b at 0041827b
 * undefined __stdcall FUN_0041827b(void)
 * Address ranges: 0041827b-004182e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041827b(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00435820 + local_8 * 0x10) != 0) {
      DeleteObject(*(HGDIOBJ *)(&DAT_00435820 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00435820 + local_8 * 0x10) = 0;
    }
  }
  DAT_0043dca8 = 0;
  DAT_00435818 = 0xffffffff;
  return;
}


/*
 * FUN_004182e3 at 004182e3
 * undefined4 __stdcall FUN_004182e3(void)
 * Address ranges: 004182e3-00418302
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004182e3(void)

{
  undefined4 uVar1;
  
  if (DAT_00435818 == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_00435820 + DAT_00435818 * 0x10);
  }
  return uVar1;
}


/*
 * FUN_00418303 at 00418303
 * int __stdcall FUN_00418303(void)
 * Address ranges: 00418303-00418339
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00418303(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xf < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_00435820 + local_8 * 0x10) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


/*
 * FUN_00418340 at 00418340
 * undefined __stdcall FUN_00418340(void)
 * Address ranges: 00418340-0041834a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00418340(void)

{
  joyGetNumDevs();
  return;
}


/*
 * FUN_0041834b at 0041834b
 * char __stdcall FUN_0041834b(void)
 * Address ranges: 0041834b-0041842f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_0041834b(void)

{
  MMRESULT MVar1;
  char local_8;
  
  _DAT_0043dcb0 = 0x34;
  _DAT_0043dcb4 = 0x83;
  MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    DAT_0043dd44 = 1;
    break;
  case 2:
  case 6:
  case 0xa6:
  case 0xa7:
    DAT_0043dd44 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)(s__Joystick_invalid_params_00435c47 + 1));
  }
  MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    DAT_0043dda0 = 1;
    break;
  case 2:
  case 6:
  case 0xa6:
  case 0xa7:
    DAT_0043dda0 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)s_Joystick_invalid_params_00435c64);
  }
  local_8 = DAT_0043dd44 != 0;
  if (DAT_0043dda0 != 0) {
    local_8 = local_8 + '\x02';
  }
  return local_8;
}


/*
 * FUN_004185b0 at 004185b0
 * undefined __stdcall FUN_004185b0(void)
 * Address ranges: 004185b0-004188ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004185b0(void)

{
  MMRESULT MVar1;
  tagJOYCAPSA local_198;
  
  _DAT_0043dcb0 = 0x34;
  _DAT_0043dcb4 = 0x83;
  MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    FUN_004015a6((byte *)s_Joystick_One_Found_00435c9c);
    DAT_0043dd44 = 1;
    _DAT_0043dd88 = DAT_0043dcb8;
    _DAT_0043dd8c = DAT_0043dcbc;
    FUN_004015a6((byte *)s__1_Xbase____d_00435cb0);
    FUN_004015a6((byte *)s__1_Ybase____d_00435cc0);
    break;
  case 2:
    DAT_0043dd44 = 0;
    break;
  case 6:
    DAT_0043dd44 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)s_Joystick_invalid_params_00435c80);
    break;
  case 0xa6:
    DAT_0043dd44 = 0;
    break;
  case 0xa7:
    DAT_0043dd44 = 0;
  }
  MVar1 = joyGetDevCapsA(0,&local_198,0x194);
  if (MVar1 == 0) {
    _DAT_0043dd94 = local_198.wXmin;
    _DAT_0043dd90 = local_198.wXmax;
    _DAT_0043dd9c = local_198.wYmin;
    _DAT_0043dd98 = local_198.wYmax;
    FUN_004015a6((byte *)s__1_Xmin____d_00435cd0);
    FUN_004015a6((byte *)s__1_Xmax____d_00435ce0);
    FUN_004015a6((byte *)s__1_Ymin____d_00435cf0);
    FUN_004015a6((byte *)s__1_Ymax____d_00435d00);
  }
  _DAT_0043dcb0 = 0x34;
  _DAT_0043dcb4 = 0x83;
  MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    FUN_004015a6((byte *)s_Joystick_Two_Found_00435d28);
    DAT_0043dda0 = 1;
    _DAT_0043dde4 = DAT_0043dcb8;
    _DAT_0043dde8 = DAT_0043dcbc;
    FUN_004015a6((byte *)s__2_Xbase____d_00435d3c);
    FUN_004015a6((byte *)s__2_Ybase____d_00435d4c);
    break;
  case 2:
    DAT_0043dda0 = 0;
    break;
  case 6:
    DAT_0043dda0 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)s_Joystick_invalid_param_00435d10);
    break;
  case 0xa6:
    DAT_0043dda0 = 0;
    break;
  case 0xa7:
    DAT_0043dda0 = 0;
  }
  MVar1 = joyGetDevCapsA(1,&local_198,0x194);
  if (MVar1 == 0) {
    _DAT_0043ddf0 = local_198.wXmin;
    _DAT_0043ddec = local_198.wXmax;
    _DAT_0043ddf8 = local_198.wYmin;
    _DAT_0043ddf4 = local_198.wYmax;
    FUN_004015a6((byte *)s__2_Xmin____d_00435d5c);
    FUN_004015a6((byte *)s__2_Xmax____d_00435d6c);
    FUN_004015a6((byte *)s__2_Ymin____d_00435d7c);
    FUN_004015a6((byte *)s__2_Ymax____d_00435d8c);
  }
  return;
}


/*
 * FUN_00418a53 at 00418a53
 * undefined __cdecl FUN_00418a53(int param_1)
 * Address ranges: 00418a53-00418ad7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00418a53(int param_1)

{
  *(undefined4 *)(&DAT_0043dcf8 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dcf0 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dd00 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dd08 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dd10 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dd18 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dd20 + param_1 * 0x5c) = 0;
  *(undefined4 *)(&DAT_0043dd28 + param_1 * 0x5c) = 0;
  return;
}


/*
 * FUN_00418ad8 at 00418ad8
 * undefined __cdecl FUN_00418ad8(int param_1, int param_2, int param_3, uint param_4)
 * Address ranges: 00418ad8-00418c40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418ad8(int param_1,int param_2,int param_3,uint param_4)

{
  FUN_00418a53(param_1);
  if ((double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40 +
      (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) < (double)param_2) {
    *(undefined4 *)(&DAT_0043dcf8 + param_1 * 0x5c) = 1;
  }
  if ((double)param_2 <
      (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) -
      (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40) {
    *(undefined4 *)(&DAT_0043dcf0 + param_1 * 0x5c) = 1;
  }
  if ((double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40 +
      (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) < (double)param_3) {
    *(undefined4 *)(&DAT_0043dd08 + param_1 * 0x5c) = 1;
  }
  if ((double)param_3 <
      (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) -
      (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40) {
    *(undefined4 *)(&DAT_0043dd00 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 1) != 0) {
    *(undefined4 *)(&DAT_0043dd10 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 2) != 0) {
    *(undefined4 *)(&DAT_0043dd18 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 4) != 0) {
    *(undefined4 *)(&DAT_0043dd20 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 8) != 0) {
    *(undefined4 *)(&DAT_0043dd28 + param_1 * 0x5c) = 1;
  }
  return;
}


/*
 * FUN_00418c41 at 00418c41
 * undefined __stdcall FUN_00418c41(void)
 * Address ranges: 00418c41-00418d08
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00418c41(void)

{
  MMRESULT MVar1;
  
  if (DAT_0043dd44 != 0) {
    _DAT_0043dcb0 = 0x34;
    _DAT_0043dcb4 = 0x83;
    MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_0043dcb0);
    if (MVar1 == 0) {
      FUN_00418ad8(1,DAT_0043dcb8,DAT_0043dcbc,DAT_0043dcd0);
    }
    else {
      FUN_00418a53(1);
    }
  }
  if (DAT_0043dda0 != 0) {
    _DAT_0043dcb0 = 0x34;
    _DAT_0043dcb4 = 0x83;
    MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_0043dcb0);
    if (MVar1 == 0) {
      FUN_00418ad8(2,DAT_0043dcb8,DAT_0043dcbc,DAT_0043dcd0);
    }
    else {
      FUN_00418a53(2);
    }
  }
  return;
}


/*
 * FUN_00418d09 at 00418d09
 * undefined __cdecl FUN_00418d09(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 00418d09-00418e12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00418d09(int param_1,int param_2,undefined4 param_3)

{
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_0040187a((byte *)s__set_joystick_keys__invalid_joys_00435d9c);
  }
  switch(param_2) {
  case 0:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 1:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 2:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 3:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 4:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 5:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 6:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 7:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  default:
    FUN_0040187a((byte *)s__set_joystick_keys__invalid_joys_00435dd0);
  }
  return;
}


/*
 * FUN_00418e33 at 00418e33
 * undefined __cdecl FUN_00418e33(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00418e33-00418e75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418e33(undefined4 param_1,undefined4 param_2)

{
  if ((1.0 < (double)CONCAT44(param_2,param_1)) || ((double)CONCAT44(param_2,param_1) < 0.05)) {
    FUN_0040187a((byte *)s__set_joystick_sencesibility__inv_00435e08);
  }
  _DAT_00435c40 = param_1;
  _DAT_00435c44 = param_2;
  return;
}


/*
 * FUN_00418e76 at 00418e76
 * undefined4 __cdecl FUN_00418e76(int param_1, int param_2, int param_3, uint * param_4, int * param_5, uint * param_6)
 * Address ranges: 00418e76-004191a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl
FUN_00418e76(int param_1,int param_2,int param_3,uint *param_4,int *param_5,uint *param_6)

{
  uint uVar1;
  int iVar2;
  MMRESULT MVar3;
  UINT local_c;
  
  uVar1 = param_2 / 2;
  iVar2 = param_3 / 2;
  if (param_1 == 1) {
    local_c = 0;
  }
  else if (param_1 == 2) {
    local_c = 1;
  }
  else {
    FUN_0040187a((byte *)s__get_joystick_position__invalid_j_00435e54);
  }
  if (*(int *)(&DAT_0043dce8 + param_1 * 0x5c) != 0) {
    *param_6 = 0;
    _DAT_0043dcb0 = 0x34;
    _DAT_0043dcb4 = 0x83;
    MVar3 = joyGetPosEx(local_c,(LPJOYINFOEX)&DAT_0043dcb0);
    if (MVar3 == 0) {
      if ((double)DAT_0043dcb8 <=
          (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40 +
          (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c)) {
        if ((double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) -
            (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40 <= (double)DAT_0043dcb8
           ) {
          *param_4 = uVar1;
        }
        else {
          *param_4 = DAT_0043dcb8 /
                     (uint)((*(int *)(&DAT_0043dd2c + param_1 * 0x5c) -
                            *(int *)(&DAT_0043dd38 + param_1 * 0x5c)) / (int)uVar1);
          *param_6 = *param_6 | 4;
        }
      }
      else {
        *param_4 = DAT_0043dcb8 /
                   (uint)((*(int *)(&DAT_0043dd34 + param_1 * 0x5c) -
                          *(int *)(&DAT_0043dd2c + param_1 * 0x5c)) / (int)uVar1);
        *param_6 = *param_6 | 8;
      }
      if ((double)DAT_0043dcbc <=
          (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40 +
          (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c)) {
        if ((double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) -
            (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40 <= (double)DAT_0043dcbc
           ) {
          *param_5 = iVar2;
        }
        else {
          *param_5 = iVar2 * 2 -
                     DAT_0043dcbc /
                     (uint)((*(int *)(&DAT_0043dd30 + param_1 * 0x5c) -
                            *(int *)(&DAT_0043dd40 + param_1 * 0x5c)) / iVar2);
          *param_6 = *param_6 | 1;
        }
      }
      else {
        *param_5 = iVar2 * 2 -
                   DAT_0043dcbc /
                   (uint)((*(int *)(&DAT_0043dd3c + param_1 * 0x5c) -
                          *(int *)(&DAT_0043dd30 + param_1 * 0x5c)) / iVar2);
        *param_6 = *param_6 | 2;
      }
      if ((DAT_0043dcd0 & 1) != 0) {
        *param_6 = *param_6 | 0x10;
      }
      if ((DAT_0043dcd0 & 2) != 0) {
        *param_6 = *param_6 | 0x20;
      }
      if ((DAT_0043dcd0 & 4) != 0) {
        *param_6 = *param_6 | 0x40;
      }
      if ((DAT_0043dcd0 & 8) != 0) {
        *param_6 = *param_6 | 0x80;
      }
      return 1;
    }
  }
  return 0;
}


/*
 * FUN_004191a1 at 004191a1
 * undefined4 __cdecl FUN_004191a1(int param_1)
 * Address ranges: 004191a1-0041920a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004191a1(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (7 < local_8) {
      return 0;
    }
    if ((*(int *)(&DAT_0043dd48 + local_8 * 8) == param_1) &&
       (*(int *)(&DAT_0043dd4c + local_8 * 8) != 0)) break;
    if ((*(int *)(&DAT_0043dda4 + local_8 * 8) == param_1) &&
       (*(int *)(&DAT_0043dda8 + local_8 * 8) != 0)) {
      return 1;
    }
    local_8 = local_8 + 1;
  }
  return 1;
}


/*
 * FUN_00419210 at 00419210
 * undefined __stdcall FUN_00419210(void)
 * Address ranges: 00419210-00419220
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00419210(void)

{
  FUN_00419263();
  DAT_0043df94 = 1;
  return;
}


/*
 * FUN_00419221 at 00419221
 * undefined __cdecl FUN_00419221(uint * param_1)
 * Address ranges: 00419221-00419262
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00419221(uint *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen((char *)param_1);
  if (400 < sVar1) {
    FUN_0040187a((byte *)s__s__d_____set_ownedit_keys_allow_00435e98);
  }
  FUN_0041f7a0((uint *)&DAT_0043de00,param_1);
  return;
}


/*
 * FUN_00419263 at 00419263
 * undefined __stdcall FUN_00419263(void)
 * Address ranges: 00419263-00419274
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00419263(void)

{
  FUN_00419221((uint *)s_abcdefghijklmnopqrstuvwxyzABCDEF_00435ed8);
  return;
}


/*
 * FUN_00419275 at 00419275
 * undefined4 __cdecl FUN_00419275(int param_1, int * param_2)
 * Address ranges: 00419275-004194cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00419275(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar3 = *param_2;
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____show_cursor__trying_to_00435f38);
  }
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 0;
  }
  else {
    FUN_00415dd1(*(uint *)(param_1 + 0x1c));
    FUN_00415e01(*(uint *)(param_1 + 0x18));
    if (((*(int *)(param_1 + 0x3c) != -1) && (*(int *)(param_1 + 0x40) != -1)) &&
       ((*(int *)(param_1 + 0x40) != *(int *)(param_1 + 0x30) ||
        (*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x2c))))) {
      iVar2 = FUN_00417005((char *)(param_1 + 0x50 + *(int *)(param_1 + 0x30) * 0x65),
                           *(size_t *)(param_1 + 0x3c));
      iVar3 = iVar3 + iVar2;
      if (*(char *)(param_1 + 0x50 + *(int *)(param_1 + 0x40) * 0x65 + *(int *)(param_1 + 0x3c)) ==
          '\0') {
        pbVar5 = &DAT_00435f88;
        iVar4 = param_2[1] + *(int *)(param_1 + 0x40) * *(int *)(param_1 + 0x44);
        iVar2 = FUN_00412061();
        FUN_0041635e(iVar2,iVar3,iVar4,pbVar5);
      }
      else {
        pbVar5 = &DAT_00435f8c;
        iVar2 = param_2[1] + *(int *)(param_1 + 0x40) * *(int *)(param_1 + 0x44);
        iVar4 = FUN_00412061();
        FUN_0041635e(iVar4,iVar3,iVar2,pbVar5);
      }
    }
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x2c);
    iVar3 = *param_2;
    FUN_00415dd1(*(uint *)(param_1 + 0x24));
    FUN_00415e01(*(uint *)(param_1 + 0x20));
    iVar2 = FUN_00417005((char *)(param_1 + 0x50 + *(int *)(param_1 + 0x30) * 0x65),
                         *(size_t *)(param_1 + 0x2c));
    iVar3 = iVar3 + iVar2;
    if (*(char *)(param_1 + 0x50 + *(int *)(param_1 + 0x30) * 0x65 + *(int *)(param_1 + 0x2c)) ==
        '\0') {
      pbVar5 = &DAT_00435f90;
      iVar4 = param_2[1] + *(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x44);
      iVar2 = FUN_00412061();
      FUN_0041635e(iVar2,iVar3,iVar4,pbVar5);
    }
    else {
      pbVar5 = &DAT_00435f94;
      iVar2 = param_2[1] + *(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x44);
      iVar4 = FUN_00412061();
      FUN_0041635e(iVar4,iVar3,iVar2,pbVar5);
    }
    uVar1 = 1;
  }
  return uVar1;
}


/*
 * FUN_004194cd at 004194cd
 * undefined __cdecl FUN_004194cd(int * param_1, int * param_2)
 * Address ranges: 004194cd-004195c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004194cd(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 local_70 [104];
  int local_8;
  
  FUN_0041fe16(local_70,(byte *)s___99s_00435f9c);
  if (*(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + 0x180) + 4) < 1) {
    local_8 = *param_1 + 1;
  }
  else {
    local_8 = ((*param_1 + 1) * *(int *)(DAT_0043db88 + 0x80)) /
              *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + 0x180) + 4);
  }
  if (0x65 < local_8) {
    local_8 = 100;
  }
  local_70[local_8] = 0;
  if (param_1[0x13] == 0) {
    FUN_00415dd1(param_1[5]);
    FUN_00415e01(param_1[4]);
  }
  else {
    FUN_00415dd1(param_1[7]);
    FUN_00415e01(param_1[6]);
  }
  pbVar4 = &DAT_00435fa4;
  iVar2 = param_2[1] + param_1[0xc] * param_1[0x11];
  iVar3 = *param_2;
  iVar1 = FUN_00412061();
  FUN_0041635e(iVar1,iVar3,iVar2,pbVar4);
  return;
}


/*
 * FUN_004195c9 at 004195c9
 * undefined __cdecl FUN_004195c9(int * param_1, int * param_2)
 * Address ranges: 004195c9-00419653
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004195c9(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  if (*(int *)(param_1[3] + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____show_edit_string__tryi_00435fb4);
  }
  FUN_004194cd(param_1,param_2);
  pbVar4 = &DAT_0043600c;
  iVar1 = param_2[1] + param_1[0xc] * param_1[0x11];
  iVar3 = *param_2;
  iVar2 = FUN_00412061();
  FUN_0041635e(iVar2,iVar3,iVar1,pbVar4);
  FUN_00419275((int)param_1,param_2);
  return;
}


/*
 * FUN_00419654 at 00419654
 * undefined __cdecl FUN_00419654(int * param_1, int * param_2, undefined1 param_3)
 * Address ranges: 00419654-00419757
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00419654(int *param_1,int *param_2,undefined1 param_3)

{
  size_t sVar1;
  int local_8;
  
  sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
  if ((uint)param_1[0xb] < sVar1) {
    sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
    for (local_8 = sVar1 + 1; param_1[0xb] <= local_8; local_8 = local_8 + -1) {
      *(undefined1 *)((int)param_1 + local_8 + param_1[0xc] * 0x65 + 0x51) =
           *(undefined1 *)((int)param_1 + local_8 + param_1[0xc] * 0x65 + 0x50);
    }
  }
  *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = param_3;
  param_1[0xb] = param_1[0xb] + 1;
  sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
  if (sVar1 < (uint)param_1[0xb]) {
    *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = 0;
  }
  FUN_004195c9(param_1,param_2);
  return;
}


/*
 * FUN_00419758 at 00419758
 * undefined __cdecl FUN_00419758(int * param_1, int * param_2, undefined1 param_3)
 * Address ranges: 00419758-004197d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00419758(int *param_1,int *param_2,undefined1 param_3)

{
  size_t sVar1;
  
  *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = param_3;
  param_1[0xb] = param_1[0xb] + 1;
  sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
  if (sVar1 < (uint)param_1[0xb]) {
    *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = 0;
  }
  FUN_004195c9(param_1,param_2);
  return;
}


/*
 * FUN_004197d3 at 004197d3
 * undefined __cdecl FUN_004197d3(int param_1, undefined4 param_2, char * param_3, size_t param_4)
 * Address ranges: 004197d3-00419838
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004197d3(int param_1,undefined4 param_2,char *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00412b70(param_1);
  iVar2 = FUN_004128fa(param_1);
  if (iVar2 != 7) {
    FUN_0040187a((byte *)s__s__d_____get_ownedit_box_text__c_0043601c);
  }
  _strncpy(param_3,(char *)(iVar1 + 0x50 + *(int *)(iVar1 + 0x30) * 0x65),param_4);
  return;
}


/*
 * FUN_00419839 at 00419839
 * undefined __cdecl FUN_00419839(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7)
 * Address ranges: 00419839-00419873
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_00419839(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x18) = param_5;
  *(undefined4 *)(param_1 + 0x24) = param_6;
  *(undefined4 *)(param_1 + 0x20) = param_7;
  return;
}


/*
 * FUN_00419874 at 00419874
 * undefined4 __cdecl FUN_00419874(int param_1, char param_2)
 * Address ranges: 00419874-00419d5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00419874(int param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  size_t sVar5;
  uint local_c;
  
  iVar1 = FUN_00412a9d(param_1);
  piVar2 = (int *)FUN_00412b01(param_1);
  iVar3 = FUN_00412d96();
  FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
  switch(param_2) {
  case '\b':
    if (piVar2[0xb] != 0) {
      sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
      if ((uint)piVar2[0xb] < sVar5) {
        for (local_c = piVar2[0xb];
            sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50)), local_c < sVar5 + 1;
            local_c = local_c + 1) {
          *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x4f) =
               *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x50);
        }
        piVar2[0xb] = piVar2[0xb] + -1;
        FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
      }
      else {
        piVar2[0xb] = piVar2[0xb] + -1;
        *(undefined1 *)((int)piVar2 + piVar2[0xb] + piVar2[0xc] * 0x65 + 0x50) = 0;
        FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
      }
    }
    break;
  default:
    puVar4 = FUN_0041fb70((uint *)&DAT_0043de00,&param_2);
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    if ((piVar2[0xb] < *piVar2) && ((int)sVar5 < *piVar2)) {
      if (piVar2[0xd] == 0) {
        FUN_00419758(piVar2,(int *)(iVar3 + iVar1 * 0x1c),param_2);
      }
      else {
        FUN_00419654(piVar2,(int *)(iVar3 + iVar1 * 0x1c),param_2);
      }
    }
    break;
  case '\r':
  case '(':
    if (piVar2[0xc] < piVar2[1] + -1) {
      piVar2[0xc] = piVar2[0xc] + 1;
      sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
      if (sVar5 < (uint)piVar2[0xb]) {
        sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
        piVar2[0xb] = sVar5;
      }
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '\x1b':
    piVar2[0xb] = 0;
    *(undefined1 *)((int)piVar2 + piVar2[0xb] + piVar2[0xc] * 0x65 + 0x50) = 0;
    FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    break;
  case '#':
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    piVar2[0xb] = sVar5;
    FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    break;
  case '$':
    piVar2[0xb] = 0;
    FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    break;
  case '%':
    if (0 < piVar2[0xb]) {
      piVar2[0xb] = piVar2[0xb] + -1;
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '&':
    if (0 < piVar2[0xc]) {
      piVar2[0xc] = piVar2[0xc] + -1;
      sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
      if (sVar5 < (uint)piVar2[0xb]) {
        sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
        piVar2[0xb] = sVar5;
      }
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '\'':
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    if ((uint)piVar2[0xb] < sVar5) {
      piVar2[0xb] = piVar2[0xb] + 1;
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '-':
    if (piVar2[0xd] == 0) {
      piVar2[0xd] = 1;
    }
    else {
      piVar2[0xd] = 0;
    }
    break;
  case '.':
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    if (piVar2[0xb] != sVar5) {
      for (local_c = piVar2[0xb]; sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50))
          , local_c < sVar5; local_c = local_c + 1) {
        *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x50) =
             *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x51);
      }
      FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
  }
  return 1;
}


/*
 * FUN_00419db3 at 00419db3
 * undefined __cdecl FUN_00419db3(int * param_1)
 * Address ranges: 00419db3-00419e34
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00419db3(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  FUN_00412a9d(param_1[6]);
  piVar1 = (int *)FUN_00412b01(param_1[6]);
  uVar7 = 0;
  iVar4 = param_1[1] + *(int *)(DAT_0043db88 + 0x84) * piVar1[1];
  iVar3 = *param_1 + *(int *)(DAT_0043db88 + 0x80) * *piVar1;
  iVar6 = param_1[1];
  iVar5 = *param_1;
  iVar2 = FUN_00412061();
  FUN_0040f8b1(2,iVar2,iVar5,iVar6,iVar3,iVar4,uVar7);
  return;
}


/*
 * FUN_00419e35 at 00419e35
 * undefined __cdecl FUN_00419e35(int param_1)
 * Address ranges: 00419e35-00419e72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00419e35(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_ownedit_box__n_0043606c);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


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


/*
 * FUN_0041a0d0 at 0041a0d0
 * undefined4 __stdcall FUN_0041a0d0(HWND param_1, uint param_2, HDC param_3, HWND param_4)
 * Address ranges: 0041a0d0-0041a36b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041a0d0(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  SHORT SVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  HWND pHVar7;
  
  iVar2 = FUN_00412a9d((int)param_1);
  piVar3 = (int *)FUN_00412b01((int)param_1);
  iVar4 = FUN_00412d96();
  iVar5 = FUN_004152a3();
  FUN_004152ad(piVar3[3]);
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 == 7) {
      piVar3[0x13] = 1;
      FUN_00404a0d();
      FUN_004195c9(piVar3,(int *)(iVar4 + iVar2 * 0x1c));
      FUN_00404a81();
    }
    else if (param_2 == 8) {
      piVar3[0x13] = 0;
      FUN_00404a0d();
      FUN_004195c9(piVar3,(int *)(iVar4 + iVar2 * 0x1c));
      FUN_00404a81();
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      switch(param_3) {
      case (HDC)0x9:
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar7 = GetFocus();
          FUN_00411d9b((int)pHVar7);
        }
        else {
          pHVar7 = GetFocus();
          FUN_00411d4c((int)pHVar7);
        }
        return 1;
      default:
        break;
      case (HDC)0xd:
      case (HDC)0x23:
      case (HDC)0x24:
      case (HDC)0x25:
      case (HDC)0x26:
      case (HDC)0x27:
      case (HDC)0x28:
      case (HDC)0x2d:
      case (HDC)0x2e:
        FUN_00404a0d();
        FUN_00419874((int)param_1,(char)param_3);
        FUN_00404a81();
        return 1;
      }
    }
    else if (param_2 == 0x2b) {
      FUN_00404a0d();
      FUN_004195c9(piVar3,(int *)(iVar4 + iVar2 * 0x1c));
      FUN_00404a81();
      return 1;
    }
  }
  else if (param_2 < 0x134) {
    if (param_2 == 0x133) {
      uVar6 = FUN_0041a90c(param_3,param_4);
      return uVar6;
    }
    if (param_2 == 0x102) {
      FUN_00404a0d();
      iVar2 = FUN_00419874((int)param_1,(char)param_3);
      if (iVar2 == 0) {
        return 0;
      }
      FUN_00404a81();
    }
    else if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
  }
  else if (param_2 == 0x204) {
    return 0;
  }
  FUN_004152ad(iVar5);
  CallWindowProcA(DAT_0043df90,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return 1;
}


/*
 * FUN_0041a3b0 at 0041a3b0
 * undefined __stdcall FUN_0041a3b0(void)
 * Address ranges: 0041a3b0-0041a3c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041a3b0(void)

{
  FUN_0041a403();
  DAT_0043e12c = 1;
  return;
}


/*
 * FUN_0041a3c1 at 0041a3c1
 * undefined __cdecl FUN_0041a3c1(uint * param_1)
 * Address ranges: 0041a3c1-0041a402
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041a3c1(uint *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen((char *)param_1);
  if (400 < sVar1) {
    FUN_0040187a((byte *)s__s__d_____set_edit_keys_allowed__0043628c);
  }
  FUN_0041f7a0((uint *)&DAT_0043df98,param_1);
  return;
}


/*
 * FUN_0041a403 at 0041a403
 * undefined __stdcall FUN_0041a403(void)
 * Address ranges: 0041a403-0041a414
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041a403(void)

{
  FUN_0041a3c1((uint *)s_abcdefghijklmnopqrstuvwxyzABCDEF_004362c8);
  return;
}


/*
 * FUN_0041a415 at 0041a415
 * undefined __cdecl FUN_0041a415(int param_1, undefined2 * param_2, undefined2 param_3)
 * Address ranges: 0041a415-0041a480
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041a415(int param_1,undefined2 *param_2,undefined2 param_3)

{
  int iVar1;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  
  iVar1 = FUN_004128fa(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004128fa(param_1);
    if (iVar1 != 3) {
      FUN_0040187a((byte *)s__s__d_____get_edit_box_text__con_00436328);
    }
  }
  *param_2 = param_3;
  wParam = 0;
  Msg = 0xc4;
  hWnd = (HWND)FUN_004129a2(param_1);
  SendMessageA(hWnd,Msg,wParam,(LPARAM)param_2);
  return;
}


/*
 * FUN_0041a481 at 0041a481
 * undefined __cdecl FUN_0041a481(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 0041a481-0041a4fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_0041a481(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  HBRUSH pHVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x28));
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  pHVar1 = CreateSolidBrush(*(COLORREF *)(param_1 + 0x14));
  *(HBRUSH *)(param_1 + 0x1c) = pHVar1;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  *(undefined4 *)(param_1 + 0x24) = param_5;
  pHVar1 = CreateSolidBrush(*(COLORREF *)(param_1 + 0x20));
  *(HBRUSH *)(param_1 + 0x28) = pHVar1;
  return;
}


/*
 * FUN_0041a4fc at 0041a4fc
 * undefined __cdecl FUN_0041a4fc(int * param_1)
 * Address ranges: 0041a4fc-0041a560
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041a4fc(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  FUN_00412a9d(param_1[6]);
  piVar1 = (int *)FUN_00412b01(param_1[6]);
  uVar7 = 0;
  iVar3 = param_1[1] + piVar1[1];
  iVar4 = *param_1 + *piVar1;
  iVar6 = param_1[1];
  iVar5 = *param_1;
  iVar2 = FUN_00412061();
  FUN_0040f8b1(2,iVar2,iVar5,iVar6,iVar4,iVar3,uVar7);
  return;
}


/*
 * FUN_0041a561 at 0041a561
 * undefined __cdecl FUN_0041a561(int param_1)
 * Address ranges: 0041a561-0041a5c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041a561(int param_1)

{
  if (DAT_0043e12c == '\0') {
    FUN_0040187a((byte *)s__s__d_____destroy_edit_box__edit_00436370);
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_edit_box__no_v_004363cc);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


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


/*
 * FUN_0041a90c at 0041a90c
 * undefined4 __cdecl FUN_0041a90c(HDC param_1, HWND param_2)
 * Address ranges: 0041a90c-0041a989
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041a90c(HDC param_1,HWND param_2)

{
  int iVar1;
  HWND pHVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00412b01((int)param_2);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    pHVar2 = GetFocus();
    if (param_2 == pHVar2) {
      SetTextColor(param_1,*(COLORREF *)(iVar1 + 0x24));
      SetBkColor(param_1,*(COLORREF *)(iVar1 + 0x20));
      uVar3 = *(undefined4 *)(iVar1 + 0x28);
    }
    else {
      SetTextColor(param_1,*(COLORREF *)(iVar1 + 0x18));
      SetBkColor(param_1,*(COLORREF *)(iVar1 + 0x14));
      uVar3 = *(undefined4 *)(iVar1 + 0x1c);
    }
  }
  return uVar3;
}


/*
 * FUN_0041a98a at 0041a98a
 * undefined4 __stdcall FUN_0041a98a(HWND param_1, uint param_2, HDC param_3, HWND param_4)
 * Address ranges: 0041a98a-0041ab50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041a98a(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  SHORT SVar1;
  undefined4 uVar2;
  uint *puVar3;
  HWND pHVar4;
  undefined2 local_8;
  
  local_8 = DAT_004365cc;
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      return 1;
    }
    if (param_2 == 7) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      PostMessageA(param_1,0xf,0,0);
    }
    else if (param_2 == 8) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      PostMessageA(param_1,0xf,0,0);
    }
  }
  else if (param_2 < 0x134) {
    if (param_2 == 0x133) {
      uVar2 = FUN_0041a90c(param_3,param_4);
      return uVar2;
    }
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == (HDC)0x9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar4 = GetFocus();
          FUN_00411d9b((int)pHVar4);
        }
        else {
          pHVar4 = GetFocus();
          FUN_00411d4c((int)pHVar4);
        }
        return 1;
      }
    }
    else if (param_2 == 0x102) {
      local_8 = CONCAT11((char)((ushort)DAT_004365cc >> 8),param_3._0_1_);
      switch(param_3._0_1_) {
      case 3:
      case 8:
      case 0x16:
      case 0x18:
        break;
      default:
        puVar3 = FUN_0041fb70((uint *)&DAT_0043df98,(char *)&local_8);
        if (puVar3 == (uint *)0x0) {
          return 0;
        }
      }
    }
    else if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
  }
  else if (param_2 == 0x204) {
    return 0;
  }
  CallWindowProcA(DAT_0043e128,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return 1;
}


/*
 * FUN_0041ab80 at 0041ab80
 * bool __cdecl FUN_0041ab80(int param_1, int param_2)
 * Address ranges: 0041ab80-0041aba5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_0041ab80(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0xc) == param_2;
}


/*
 * FUN_0041aba6 at 0041aba6
 * undefined __cdecl FUN_0041aba6(int param_1)
 * Address ranges: 0041aba6-0041abd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041aba6(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_radiobutton__n_004365e0);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


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


/*
 * FUN_0041ad41 at 0041ad41
 * undefined __cdecl FUN_0041ad41(int param_1)
 * Address ranges: 0041ad41-0041ae67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041ad41(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = param_1;
  do {
    local_8 = FUN_004127b0(local_8,6);
    if (local_8 == -1) {
      local_8 = param_1;
      do {
        local_8 = FUN_00412821(local_8,6);
        if (local_8 == -1) {
          return;
        }
        iVar1 = FUN_00412b70(local_8);
      } while (*(int *)(iVar1 + 0x20) != 4);
      *(undefined4 *)(iVar1 + 0x20) = 0;
      DAT_0043e144 = (HWND)FUN_004129a2(local_8);
      _DAT_0043e140 = 0;
      SendMessageA(DAT_0043e144,0x2b,0,0x43e130);
      return;
    }
    iVar1 = FUN_00412b70(local_8);
  } while (*(int *)(iVar1 + 0x20) != 4);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  DAT_0043e144 = (HWND)FUN_004129a2(local_8);
  _DAT_0043e140 = 0;
  SendMessageA(DAT_0043e144,0x2b,0,0x43e130);
  return;
}


/*
 * FUN_0041ae68 at 0041ae68
 * undefined __cdecl FUN_0041ae68(int param_1)
 * Address ranges: 0041ae68-0041af20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041ae68(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar2 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  iVar6 = piVar1[1];
  iVar5 = piVar1[2];
  iVar3 = FUN_00412687(*piVar1,0);
  uVar7 = 1;
  iVar4 = FUN_00412a49(iVar2);
  iVar4 = iVar4 + iVar5 / 2;
  iVar5 = FUN_004129f6(iVar2);
  iVar5 = iVar5 + iVar6 / 2;
  iVar6 = FUN_00412061();
  FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar7);
  if (piVar1[4] != 0) {
    FUN_0041258a(iVar2,piVar1[5],piVar1[6],piVar1[6],piVar1[7]);
  }
  return;
}


/*
 * FUN_0041af21 at 0041af21
 * undefined __cdecl FUN_0041af21(int param_1)
 * Address ranges: 0041af21-0041b203
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041af21(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  iVar3 = piVar2[1] / 2;
  iVar4 = piVar2[2] / 2;
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_radiobutton__no_v_004366c4);
  }
  FUN_00404a0d();
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 4) {
    FUN_00411de7(iVar1,2);
    iVar5 = FUN_00412687(*piVar2,4);
    uVar7 = 1;
    iVar6 = FUN_00412a49(iVar1);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar1);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
  }
  else if (iVar5 == 0x10) {
    FUN_00411de7(iVar1,1);
    if (piVar2[8] == 4) {
      iVar5 = FUN_00412687(*piVar2,3);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
    else {
      iVar5 = FUN_00412687(*piVar2,1);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
  }
  else if (iVar5 == 0x11) {
    FUN_00411de7(iVar1,4);
    piVar2[8] = 4;
    iVar5 = FUN_00412687(*piVar2,3);
    uVar7 = 1;
    iVar6 = FUN_00412a49(iVar1);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar1);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    FUN_0041ad41(iVar1);
  }
  else {
    FUN_00411de7(iVar1,0);
    if (piVar2[8] == 4) {
      iVar5 = FUN_00412687(*piVar2,2);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
    else {
      iVar5 = FUN_00412687(*piVar2,0);
      uVar7 = 1;
      iVar6 = FUN_00412a49(iVar1);
      iVar6 = iVar6 + iVar4;
      iVar4 = FUN_004129f6(iVar1);
      iVar4 = iVar4 + iVar3;
      iVar3 = FUN_00412061();
      FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar7);
    }
  }
  if (piVar2[4] != 0) {
    FUN_0041258a(iVar1,piVar2[5],piVar2[6],piVar2[6],piVar2[7]);
  }
  FUN_00404a81();
  return;
}


/*
 * FUN_0041b204 at 0041b204
 * undefined4 __stdcall FUN_0041b204(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041b204-0041b395
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041b204(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == 9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar2 = GetFocus();
          FUN_00411d9b((int)pHVar2);
        }
        else {
          pHVar2 = GetFocus();
          FUN_00411d4c((int)pHVar2);
        }
      }
      else if (param_3 == 0xd) {
        DAT_0043e144 = param_1;
        _DAT_0043e140 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e130);
      }
    }
    else if (param_2 == 0x2b) {
      FUN_0041af21(param_4);
      return 1;
    }
  }
  else if (param_2 == 0x101) {
    if (param_3 == 0xd) {
      DAT_0043e144 = param_1;
      pHVar2 = GetFocus();
      if (pHVar2 == param_1) {
        _DAT_0043e140 = 0x10;
      }
      else {
        _DAT_0043e140 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e130);
    }
  }
  else if (param_2 == 0x104) {
    FUN_00412f44(param_3);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e160,param_1,param_2,param_3,param_4);
  return 1;
}


/*
 * FUN_0041b3a0 at 0041b3a0
 * bool __cdecl FUN_0041b3a0(int param_1, int param_2)
 * Address ranges: 0041b3a0-0041b3c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_0041b3a0(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0x1c) == param_2;
}


/*
 * FUN_0041b3c6 at 0041b3c6
 * undefined __cdecl FUN_0041b3c6(int param_1)
 * Address ranges: 0041b3c6-0041b3f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041b3c6(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_animbutton__no_00436718);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


/*
 * FUN_0041b3f5 at 0041b3f5
 * undefined __cdecl FUN_0041b3f5(int * param_1, HMENU param_2)
 * Address ranges: 0041b3f5-0041b538
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041b3f5(int *param_1,HMENU param_2)

{
  int *piVar1;
  int iVar2;
  HINSTANCE hInstance;
  HWND pHVar3;
  LPVOID lpParam;
  
  piVar1 = (int *)param_1[3];
  iVar2 = FUN_00412687(*piVar1,0);
  if (piVar1[4] == -1) {
    piVar1[4] = *(int *)(DAT_0043d6e8 + 8 + iVar2 * 0x20);
  }
  if (piVar1[5] == -1) {
    piVar1[5] = *(int *)(DAT_0043d6e8 + 0xc + iVar2 * 0x20);
  }
  FUN_004126d4(param_2,*param_1,param_1[1],piVar1[4],piVar1[5]);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
  pHVar3 = CreateWindowExA(0,s_BUTTON_00436750,(LPCSTR)piVar1[8],0x5001000b,*param_1,param_1[1],
                           piVar1[4],piVar1[5],DAT_0043842c,param_2,hInstance,lpParam);
  param_1[6] = (int)pHVar3;
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_an_00436758);
  }
  DAT_0043e198 = SetWindowLongA((HWND)param_1[6],-4,0x41bba6);
  if (param_1[4] == 4) {
    param_1[4] = 1;
  }
  FUN_00411de7((int)param_2,param_1[4]);
  param_1[5] = 0;
  return;
}


/*
 * FUN_0041b539 at 0041b539
 * undefined __cdecl FUN_0041b539(int param_1, int param_2, DWORD param_3, int param_4)
 * Address ranges: 0041b539-0041b6e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041b539(int param_1,int param_2,DWORD param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_c;
  
  iVar1 = FUN_00412b70(param_2);
  iVar8 = *(int *)(DAT_0043d858 + param_1 * 0xc);
  iVar2 = *(int *)(iVar1 + 0x10) / 2;
  iVar3 = *(int *)(iVar1 + 0x14) / 2;
  if (param_4 == 2) {
    while (local_c = iVar8 + -1, -1 < local_c) {
      iVar8 = FUN_00412687(param_1,local_c);
      uVar9 = 1;
      iVar4 = FUN_00412a49(param_2);
      iVar4 = iVar4 + iVar3;
      iVar5 = FUN_004129f6(param_2);
      iVar5 = iVar5 + iVar2;
      iVar6 = FUN_00412061();
      FUN_004105ee(iVar6,iVar8,iVar5,iVar4,uVar9);
      if (*(int *)(iVar1 + 0x20) != 0) {
        FUN_0041258a(param_2,*(int *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28),*(int *)(iVar1 + 0x28),
                     *(int *)(iVar1 + 0x2c));
      }
      Sleep(param_3);
      iVar8 = local_c;
    }
  }
  else {
    for (local_c = 0; local_c < iVar8; local_c = local_c + 1) {
      iVar4 = FUN_00412687(param_1,local_c);
      uVar9 = 1;
      iVar5 = FUN_00412a49(param_2);
      iVar5 = iVar5 + iVar3;
      iVar6 = FUN_004129f6(param_2);
      iVar6 = iVar6 + iVar2;
      iVar7 = FUN_00412061();
      FUN_004105ee(iVar7,iVar4,iVar6,iVar5,uVar9);
      if (*(int *)(iVar1 + 0x20) != 0) {
        FUN_0041258a(param_2,*(int *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28),*(int *)(iVar1 + 0x28),
                     *(int *)(iVar1 + 0x2c));
      }
      Sleep(param_3);
    }
  }
  return;
}


/*
 * FUN_0041b6e6 at 0041b6e6
 * undefined __cdecl FUN_0041b6e6(int param_1)
 * Address ranges: 0041b6e6-0041b884
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041b6e6(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar2 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  iVar3 = piVar1[4] / 2;
  iVar4 = piVar1[5] / 2;
  iVar5 = FUN_00412687(*piVar1,*(int *)(DAT_0043d858 + *piVar1 * 0xc) + -1);
  uVar9 = 1;
  iVar6 = FUN_00412a49(iVar2);
  iVar6 = iVar6 + iVar4;
  iVar7 = FUN_004129f6(iVar2);
  iVar7 = iVar7 + iVar3;
  iVar8 = FUN_00412061();
  FUN_004105ee(iVar8,iVar5,iVar7,iVar6,uVar9);
  iVar5 = FUN_0041294e(iVar2);
  if ((iVar5 == 1) || (iVar5 == 4)) {
    iVar5 = FUN_00412687(piVar1[3],*(int *)(DAT_0043d858 + piVar1[3] * 0xc) + -1);
    uVar9 = 1;
    iVar6 = FUN_00412a49(iVar2);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar2);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar9);
  }
  else {
    iVar5 = FUN_00412687(*piVar1,*(int *)(DAT_0043d858 + *piVar1 * 0xc) + -1);
    uVar9 = 1;
    iVar6 = FUN_00412a49(iVar2);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar2);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar9);
  }
  if (piVar1[8] != 0) {
    FUN_0041258a(iVar2,piVar1[9],piVar1[10],piVar1[10],piVar1[0xb]);
  }
  return;
}


/*
 * FUN_0041b885 at 0041b885
 * undefined __cdecl FUN_0041b885(int param_1)
 * Address ranges: 0041b885-0041bb91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041b885(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  iVar6 = piVar2[4];
  iVar5 = piVar2[5];
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_animbutton__no_va_00436798);
  }
  FUN_00404a0d();
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 4) {
    iVar6 = FUN_004128a6(iVar1);
    if (iVar6 != 2) {
      FUN_00411de7(iVar1,2);
      FUN_0041b539(piVar2[2],iVar1,piVar2[6],1);
    }
  }
  else if (iVar3 == 0x10) {
    iVar3 = FUN_0041294e(iVar1);
    if (iVar3 == 4) {
      FUN_00411de7(iVar1,1);
      iVar3 = FUN_00412687(piVar2[3],*(int *)(DAT_0043d858 + piVar2[3] * 0xc) + -1);
      uVar8 = 1;
      iVar4 = FUN_00412a49(iVar1);
      iVar4 = iVar4 + iVar5 / 2;
      iVar5 = FUN_004129f6(iVar1);
      iVar5 = iVar5 + iVar6 / 2;
      iVar6 = FUN_00412061();
      FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar8);
    }
    else {
      FUN_00411de7(iVar1,1);
      FUN_0041b539(piVar2[3],iVar1,piVar2[6],1);
    }
  }
  else if (iVar3 == 0x11) {
    FUN_00411de7(iVar1,4);
    FUN_0041b539(piVar2[1],iVar1,piVar2[6],1);
  }
  else {
    uVar7 = FUN_0041294e(iVar1);
    switch(uVar7) {
    case 0:
      iVar6 = FUN_004128a6(iVar1);
      if (iVar6 == 0) {
        FUN_00411de7(iVar1,0);
        FUN_0041b539(*piVar2,iVar1,piVar2[6],1);
      }
      break;
    case 1:
    case 4:
      FUN_00411de7(iVar1,0);
      iVar3 = FUN_00412687(*piVar2,*(int *)(DAT_0043d858 + *piVar2 * 0xc) + -1);
      uVar8 = 1;
      iVar4 = FUN_00412a49(iVar1);
      iVar4 = iVar4 + iVar5 / 2;
      iVar5 = FUN_004129f6(iVar1);
      iVar5 = iVar5 + iVar6 / 2;
      iVar6 = FUN_00412061();
      FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar8);
      break;
    case 2:
      FUN_00411de7(iVar1,0);
      FUN_0041b539(piVar2[2],iVar1,piVar2[6],2);
      break;
    default:
      FUN_00411de7(iVar1,0);
      FUN_0041b539(*piVar2,iVar1,piVar2[6],1);
    }
  }
  if (piVar2[8] != 0) {
    FUN_0041258a(iVar1,piVar2[9],piVar2[10],piVar2[10],piVar2[0xb]);
  }
  FUN_00404a81();
  return;
}


/*
 * FUN_0041bba6 at 0041bba6
 * undefined4 __stdcall FUN_0041bba6(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041bba6-0041bddf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041bba6(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  int iVar2;
  HWND pHVar3;
  undefined4 uVar4;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 == 7) {
      if (DAT_0043d568 != (code *)0x0) {
        (*DAT_0043d568)(param_1,7,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 8) && (DAT_0043d564 != (code *)0x0)) {
      (*DAT_0043d564)(param_1,8,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == 9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar3 = GetFocus();
          FUN_00411d9b((int)pHVar3);
        }
        else {
          pHVar3 = GetFocus();
          FUN_00411d4c((int)pHVar3);
        }
      }
      else if (param_3 == 0xd) {
        _DAT_0043e17c = param_1;
        _DAT_0043e178 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e168);
      }
    }
    else if (param_2 == 0x2b) {
      FUN_0041b885(param_4);
      return 1;
    }
  }
  else if (param_2 < 0x105) {
    if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
    else if ((param_2 == 0x101) && (param_3 == 0xd)) {
      _DAT_0043e17c = param_1;
      pHVar3 = GetFocus();
      if (pHVar3 == param_1) {
        _DAT_0043e178 = 0x10;
      }
      else {
        _DAT_0043e178 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e168);
    }
  }
  else if (param_2 == 0x201) {
    uVar4 = 4;
    iVar2 = FUN_00412a9d((int)param_1);
    FUN_00411de7(iVar2,uVar4);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e198,param_1,param_2,param_3,param_4);
  return 1;
}


/*
 * FUN_0041bde0 at 0041bde0
 * bool __cdecl FUN_0041bde0(int param_1, int param_2)
 * Address ranges: 0041bde0-0041be05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_0041bde0(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0x10) == param_2;
}


/*
 * FUN_0041be06 at 0041be06
 * undefined __cdecl FUN_0041be06(int param_1)
 * Address ranges: 0041be06-0041be34
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041be06(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_areabutton__no_004367ec);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


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


/*
 * FUN_0041c00c at 0041c00c
 * undefined __cdecl FUN_0041c00c(int * param_1)
 * Address ranges: 0041c00c-0041c070
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041c00c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  FUN_00412a9d(param_1[6]);
  piVar1 = (int *)FUN_00412b01(param_1[6]);
  uVar7 = 0;
  iVar3 = param_1[1] + piVar1[1];
  iVar4 = *param_1 + *piVar1;
  iVar6 = param_1[1];
  iVar5 = *param_1;
  iVar2 = FUN_00412061();
  FUN_0040f8b1(2,iVar2,iVar5,iVar6,iVar4,iVar3,uVar7);
  return;
}


/*
 * FUN_0041c071 at 0041c071
 * undefined __cdecl FUN_0041c071(int param_1)
 * Address ranges: 0041c071-0041c0c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041c071(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  FUN_00412b01(*(int *)(param_1 + 0x14));
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_areabutton__no_va_004368cc);
  }
  FUN_00404a0d();
  FUN_00404b2d();
  FUN_00404a81();
  return;
}


/*
 * FUN_0041c0c8 at 0041c0c8
 * undefined4 __stdcall FUN_0041c0c8(HWND param_1, uint param_2, WPARAM param_3, LPARAM param_4)
 * Address ranges: 0041c0c8-0041c216
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041c0c8(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  int iVar3;
  undefined4 uVar4;
  tagPAINTSTRUCT local_44;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      BeginPaint(param_1,&local_44);
      EndPaint(param_1,&local_44);
      return 1;
    }
    if (param_2 == 7) {
      SVar1 = GetKeyState(0x10);
      if (SVar1 < 0) {
        pHVar2 = GetFocus();
        FUN_00411d9b((int)pHVar2);
      }
      else {
        pHVar2 = GetFocus();
        FUN_00411d4c((int)pHVar2);
      }
    }
  }
  else if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      return 1;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x105) {
    if (param_2 == 0x104) {
      FUN_00412f44(param_3);
    }
    else if (param_2 == 0x100) {
      FUN_00412f44(param_3);
    }
  }
  else if (param_2 == 0x201) {
    uVar4 = 4;
    iVar3 = FUN_00412a9d((int)param_1);
    FUN_00411de7(iVar3,uVar4);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e19c,param_1,param_2,param_3,param_4);
  return 1;
}


/*
 * FUN_0041c220 at 0041c220
 * bool __cdecl FUN_0041c220(int param_1, int param_2)
 * Address ranges: 0041c220-0041c245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_0041c220(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0xc) == param_2;
}


/*
 * FUN_0041c246 at 0041c246
 * undefined4 __cdecl FUN_0041c246(int param_1)
 * Address ranges: 0041c246-0041c2b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041c246(int param_1)

{
  int iVar1;
  
  if (-1 < param_1) {
    iVar1 = FUN_0041289c();
    if (param_1 <= iVar1) goto LAB_0041c272;
  }
  FUN_0040187a((byte *)s__s__d_____get_togglebutton_toggl_00436920);
LAB_0041c272:
  iVar1 = FUN_004128fa(param_1);
  if (iVar1 != 2) {
    FUN_0040187a((byte *)s__s__d_____get_togglebutton_toggl_00436978);
  }
  iVar1 = FUN_00412b70(param_1);
  return *(undefined4 *)(iVar1 + 0x10);
}


/*
 * FUN_0041c2b4 at 0041c2b4
 * undefined __cdecl FUN_0041c2b4(int param_1, int param_2)
 * Address ranges: 0041c2b4-0041c368
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041c2b4(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (-1 < param_1) {
    iVar1 = FUN_0041289c();
    if (param_1 <= iVar1) goto LAB_0041c2e0;
  }
  FUN_0040187a((byte *)s__s__d_____set_togglebutton_toggl_004369d4);
LAB_0041c2e0:
  iVar1 = FUN_004128fa(param_1);
  if (iVar1 != 2) {
    FUN_0040187a((byte *)s__s__d_____get_togglebutton_toggl_00436a2c);
  }
  piVar2 = (int *)FUN_00412b70(param_1);
  if (*(int *)(DAT_0043d858 + *piVar2 * 0xc) / 2 < param_2) {
    FUN_0040187a((byte *)s__s__d_____set_togglebutton_toggl_00436a88);
  }
  piVar2[4] = param_2;
  return;
}


/*
 * FUN_0041c369 at 0041c369
 * undefined __cdecl FUN_0041c369(int param_1)
 * Address ranges: 0041c369-0041c397
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041c369(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_togglebutton__n_00436ae4);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


/*
 * FUN_0041c398 at 0041c398
 * undefined __cdecl FUN_0041c398(int * param_1, HMENU param_2)
 * Address ranges: 0041c398-0041c515
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Removing unreachable block (ram,0x0041c418) */

void __cdecl FUN_0041c398(int *param_1,HMENU param_2)

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
  FUN_004126d4(param_2,*param_1,param_1[1],piVar1[1],piVar1[2]);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
  pHVar3 = CreateWindowExA(0,s_BUTTON_00436b9c,(LPCSTR)0x0,0x5001000b,*param_1,param_1[1],piVar1[1],
                           piVar1[2],DAT_0043842c,param_2,hInstance,lpParam);
  param_1[6] = (int)pHVar3;
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_to_00436ba4);
  }
  FUN_0041c2b4((int)param_2,piVar1[4]);
  DAT_0043e1a0 = SetWindowLongA((HWND)param_1[6],-4,0x41c922);
  FUN_00411de7((int)param_2,param_1[4]);
  return;
}


/*
 * FUN_0041c516 at 0041c516
 * undefined __cdecl FUN_0041c516(int param_1)
 * Address ranges: 0041c516-0041c5f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041c516(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar3 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  iVar2 = piVar1[4];
  iVar7 = piVar1[1];
  iVar6 = piVar1[2];
  iVar4 = FUN_00412687(*piVar1,iVar2 << 1);
  uVar8 = 1;
  iVar5 = FUN_00412a49(iVar3);
  iVar5 = iVar5 + iVar6 / 2;
  iVar6 = FUN_004129f6(iVar3);
  iVar6 = iVar6 + iVar7 / 2;
  iVar7 = FUN_00412061();
  FUN_004105ee(iVar7,iVar4,iVar6,iVar5,uVar8);
  if ((piVar1[5] != 0) && (*(int *)(piVar1[5] + iVar2 * 4) != 0)) {
    FUN_00412618(iVar3,*(byte **)(piVar1[5] + iVar2 * 4),piVar1[6],piVar1[7],piVar1[7],piVar1[8]);
  }
  return;
}


/*
 * FUN_0041c5f8 at 0041c5f8
 * undefined __cdecl FUN_0041c5f8(int param_1)
 * Address ranges: 0041c5f8-0041c921
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041c5f8(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_18;
  int local_10;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  local_18 = piVar2[4];
  iVar3 = piVar2[1] / 2;
  iVar4 = piVar2[2] / 2;
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_togglebutton__no_v_00436be4);
  }
  FUN_00404a0d();
  iVar8 = *(int *)(param_1 + 0x10);
  if (iVar8 == 4) {
    FUN_00411de7(iVar1,2);
    if (piVar2[5] == 0) {
      local_10 = FUN_00412687(*piVar2,local_18 << 1);
    }
    else {
      local_10 = FUN_00412687(*piVar2,local_18 << 1);
    }
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_10;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else if (iVar8 == 0x10) {
    FUN_00411de7(iVar1,1);
    local_10 = FUN_00412687(*piVar2,local_18 * 2 + 1);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_10;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else if (iVar8 == 0x11) {
    FUN_00411de7(iVar1,4);
    if (local_18 == *(int *)(DAT_0043d858 + *piVar2 * 0xc) / 2 + -1) {
      local_18 = 0;
    }
    else {
      local_18 = local_18 + 1;
    }
    FUN_0041c2b4(iVar1,local_18);
    local_10 = FUN_00412687(*piVar2,local_18 * 2 + 1);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_10;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else {
    FUN_00411de7(iVar1,0);
    local_10 = FUN_00412687(*piVar2,local_18 << 1);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_10;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  if ((piVar2[5] != 0) && (*(int *)(piVar2[5] + local_18 * 4) != 0)) {
    FUN_00412618(iVar1,*(byte **)(piVar2[5] + local_18 * 4),piVar2[6],piVar2[7],piVar2[7],piVar2[8])
    ;
  }
  if (*(int *)(param_1 + 0x10) == 4) {
    if (piVar2[5] != 0) {
      local_10 = FUN_00412687(*piVar2,local_18 << 1);
    }
    uVar9 = 1;
    iVar8 = FUN_00412a49(iVar1);
    iVar8 = iVar8 + iVar4;
    iVar1 = FUN_004129f6(iVar1);
    iVar1 = iVar1 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,local_10,iVar1,iVar8,uVar9);
  }
  FUN_00404a81();
  return;
}


/*
 * FUN_0041c922 at 0041c922
 * undefined4 __stdcall FUN_0041c922(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041c922-0041cb18
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041c922(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 0;
    }
    if (param_2 == 7) {
      if (DAT_0043d568 != (code *)0x0) {
        (*DAT_0043d568)(param_1,7,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 8) && (DAT_0043d564 != (code *)0x0)) {
      (*DAT_0043d564)(param_1,8,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == 9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar2 = GetFocus();
          FUN_00411d9b((int)pHVar2);
        }
        else {
          pHVar2 = GetFocus();
          FUN_00411d4c((int)pHVar2);
        }
      }
      else if (param_3 == 0xd) {
        _DAT_0043e1bc = param_1;
        _DAT_0043e1b8 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e1a8);
      }
    }
    else if (param_2 == 0x2b) {
      FUN_0041c5f8(param_4);
      return 0;
    }
  }
  else if (param_2 == 0x101) {
    if (param_3 == 0xd) {
      _DAT_0043e1bc = param_1;
      pHVar2 = GetFocus();
      if (pHVar2 == param_1) {
        _DAT_0043e1b8 = 0x10;
      }
      else {
        _DAT_0043e1b8 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e1a8);
    }
  }
  else if (param_2 == 0x104) {
    FUN_00412f44(param_3);
  }
  else if (param_2 == 0x204) {
    return 0;
  }
  CallWindowProcA(DAT_0043e1a0,param_1,param_2,param_3,param_4);
  return 1;
}


/*
 * FUN_0041cb20 at 0041cb20
 * bool __cdecl FUN_0041cb20(int param_1, int param_2)
 * Address ranges: 0041cb20-0041cb45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_0041cb20(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0xc) == param_2;
}


/*
 * FUN_0041cb46 at 0041cb46
 * undefined __cdecl FUN_0041cb46(int param_1)
 * Address ranges: 0041cb46-0041cc1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041cb46(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0x20) != -1) {
    iVar3 = FUN_00412a9d(*(int *)(param_1 + 0x18));
    iVar2 = *(int *)(DAT_0043d858 + *(int *)(iVar1 + 0x20) * 0xc);
    iVar7 = *(int *)(iVar1 + 4);
    iVar6 = *(int *)(iVar1 + 8);
    iVar4 = FUN_00412687(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24));
    uVar8 = 1;
    iVar5 = FUN_00412a49(iVar3);
    iVar5 = iVar5 + iVar6 / 2;
    iVar6 = FUN_004129f6(iVar3);
    iVar6 = iVar6 + iVar7 / 2;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar4,iVar6,iVar5,uVar8);
    if (*(int *)(iVar1 + 0x24) < iVar2 + -1) {
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
    }
    else {
      *(undefined4 *)(iVar1 + 0x24) = 0;
    }
  }
  return;
}


/*
 * FUN_0041cc20 at 0041cc20
 * undefined __cdecl FUN_0041cc20(int param_1)
 * Address ranges: 0041cc20-0041cc4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041cc20(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_button__no_val_00436c34);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}


/*
 * FUN_0041cc4f at 0041cc4f
 * undefined __cdecl FUN_0041cc4f(int * param_1, HMENU param_2)
 * Address ranges: 0041cc4f-0041ce27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041cc4f(int *param_1,HMENU param_2)

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
  if (*(int *)(DAT_0043d858 + *piVar1 * 0xc) < 4) {
    FUN_0040187a((byte *)s__s__d_____create_button__not_eno_00436c74);
  }
  FUN_004126d4(param_2,*param_1,param_1[1],piVar1[1],piVar1[2]);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)GetWindowLongA(DAT_0043842c,-6);
  pHVar3 = CreateWindowExA(0,s_BUTTON_00436cc0,(LPCSTR)piVar1[4],0x5001000b,*param_1,param_1[1],
                           piVar1[1],piVar1[2],DAT_0043842c,param_2,hInstance,lpParam);
  param_1[6] = (int)pHVar3;
  if (param_1[6] == 0) {
    FUN_0040187a((byte *)s_Unable_to_create_a_window_for_co_00436cc8);
  }
  DAT_0043e1d8 = SetWindowLongA((HWND)param_1[6],-4,0x41d1f5);
  piVar1[9] = 0;
  if (piVar1[8] == -1) {
    piVar1[8] = -1;
  }
  else {
    FUN_00412687(piVar1[8],0);
    if (*(int *)(DAT_0043d858 + piVar1[8] * 0xc) == 1) {
      FUN_0040187a((byte *)s__s__d_____create_button__Anim_fo_00436d08);
    }
  }
  if (param_1[4] == 4) {
    param_1[4] = 1;
  }
  FUN_00411de7((int)param_2,param_1[4]);
  return;
}


/*
 * FUN_0041ce28 at 0041ce28
 * undefined __cdecl FUN_0041ce28(int param_1)
 * Address ranges: 0041ce28-0041cf4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041ce28(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x18));
  iVar6 = piVar2[1];
  iVar5 = piVar2[2];
  iVar3 = FUN_0041294e(iVar1);
  if ((iVar3 == 1) || (iVar3 == 4)) {
    iVar3 = FUN_00412687(*piVar2,1);
    uVar7 = 1;
    iVar4 = FUN_00412a49(iVar1);
    iVar4 = iVar4 + iVar5 / 2;
    iVar5 = FUN_004129f6(iVar1);
    iVar5 = iVar5 + iVar6 / 2;
    iVar6 = FUN_00412061();
    FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar7);
  }
  else {
    iVar3 = FUN_00412687(*piVar2,0);
    uVar7 = 1;
    iVar4 = FUN_00412a49(iVar1);
    iVar4 = iVar4 + iVar5 / 2;
    iVar5 = FUN_004129f6(iVar1);
    iVar5 = iVar5 + iVar6 / 2;
    iVar6 = FUN_00412061();
    FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar7);
  }
  if (piVar2[4] != 0) {
    FUN_0041258a(iVar1,piVar2[5],piVar2[6],piVar2[6],piVar2[7]);
  }
  return;
}


/*
 * FUN_0041cf50 at 0041cf50
 * undefined __cdecl FUN_0041cf50(int param_1)
 * Address ranges: 0041cf50-0041d1f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041cf50(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_8;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  iVar3 = piVar2[1] / 2;
  iVar4 = piVar2[2] / 2;
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_button__no_valid_w_00436d58);
  }
  FUN_00404a0d();
  iVar8 = *(int *)(param_1 + 0x10);
  if (iVar8 == 4) {
    FUN_00411de7(iVar1,2);
    if (piVar2[4] == 0) {
      local_8 = FUN_00412687(*piVar2,2);
    }
    else {
      local_8 = FUN_00412687(*piVar2,0);
    }
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else if (iVar8 == 0x10) {
    FUN_00411de7(iVar1,1);
    local_8 = FUN_00412687(*piVar2,3);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else if (iVar8 == 0x11) {
    FUN_00411de7(iVar1,4);
    local_8 = FUN_00412687(*piVar2,1);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else {
    FUN_00411de7(iVar1,0);
    local_8 = FUN_00412687(*piVar2,0);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  if (piVar2[4] != 0) {
    FUN_0041258a(iVar1,piVar2[5],piVar2[6],piVar2[6],piVar2[7]);
  }
  if (*(int *)(param_1 + 0x10) == 4) {
    if (piVar2[4] != 0) {
      local_8 = FUN_00412687(*piVar2,2);
    }
    uVar9 = 1;
    iVar8 = FUN_00412a49(iVar1);
    iVar8 = iVar8 + iVar4;
    iVar1 = FUN_004129f6(iVar1);
    iVar1 = iVar1 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,local_8,iVar1,iVar8,uVar9);
  }
  FUN_00404a81();
  return;
}


/*
 * FUN_0041d1f5 at 0041d1f5
 * undefined4 __stdcall FUN_0041d1f5(HWND param_1, uint param_2, WPARAM param_3, int param_4)
 * Address ranges: 0041d1f5-0041d3fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041d1f5(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  SHORT SVar1;
  HWND pHVar2;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 == 7) {
      if (DAT_0043d568 != (code *)0x0) {
        (*DAT_0043d568)(param_1,7,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 8) && (DAT_0043d564 != (code *)0x0)) {
      (*DAT_0043d564)(param_1,8,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      FUN_00412f44(param_3);
      if (param_3 == 9) {
        SVar1 = GetKeyState(0x10);
        if (SVar1 < 0) {
          pHVar2 = GetFocus();
          FUN_00411d9b((int)pHVar2);
        }
        else {
          pHVar2 = GetFocus();
          FUN_00411d4c((int)pHVar2);
        }
      }
      else if (param_3 == 0xd) {
        _DAT_0043e1f4 = param_1;
        _DAT_0043e1f0 = 0x11;
        SendMessageA(param_1,0x2b,0,0x43e1e0);
      }
      return 1;
    }
    if (param_2 == 0x2b) {
      FUN_0041cf50(param_4);
      return 1;
    }
  }
  else if (param_2 == 0x101) {
    if (param_3 == 0xd) {
      _DAT_0043e1f4 = param_1;
      pHVar2 = GetFocus();
      if (pHVar2 == param_1) {
        _DAT_0043e1f0 = 0x10;
      }
      else {
        _DAT_0043e1f0 = 0;
      }
      SendMessageA(param_1,0x2b,0,0x43e1e0);
    }
  }
  else if (param_2 == 0x104) {
    FUN_00412f44(param_3);
  }
  else if (param_2 == 0x204) {
    return 1;
  }
  CallWindowProcA(DAT_0043e1d8,param_1,param_2,param_3,param_4);
  return 1;
}


/*
 * DDRAW.DLL::DirectDrawCreate at 0041d3fe
 * undefined DirectDrawCreate(void)
 * Address ranges: 0041d3fe-0041d403
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to DDRAW.DLL::DirectDrawCreate
 */


void DirectDrawCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041d3fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}


/*
 * DDRAW.DLL::DirectDrawEnumerateA at 0041d404
 * undefined DirectDrawEnumerateA(void)
 * Address ranges: 0041d404-0041d409
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to DDRAW.DLL::DirectDrawEnumerateA
 */


void DirectDrawEnumerateA(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041d404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawEnumerateA();
  return;
}


/*
 * DINPUT.DLL::DirectInputCreateA at 0041e428
 * undefined DirectInputCreateA(void)
 * Address ranges: 0041e428-0041e42d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to DINPUT.DLL::DirectInputCreateA
 */


void DirectInputCreateA(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041e428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectInputCreateA();
  return;
}


/*
 * DSOUND.DLL::Ordinal_2 at 0041e42e
 * undefined Ordinal_2(void)
 * Address ranges: 0041e42e-0041e433
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to DSOUND.DLL::Ordinal_2
 */


void Ordinal_2(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041e42e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_2();
  return;
}


/*
 * DSOUND.DLL::Ordinal_1 at 0041e434
 * undefined Ordinal_1(void)
 * Address ranges: 0041e434-0041e439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to DSOUND.DLL::Ordinal_1
 */


void Ordinal_1(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041e434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_1();
  return;
}


/*
 * FUN_0041e440 at 0041e440
 * undefined4 __cdecl FUN_0041e440(undefined4 param_1)
 * Address ranges: 0041e440-0041e4d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0041e440(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 local_90 [20];
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int *piStack_1c;
  int *piStack_18;
  
  puVar4 = local_90;
  uStack_94 = 0;
  uStack_98 = 0;
  uStack_9c = 0;
  uStack_a0 = 0x73646976;
  uStack_a4 = param_1;
  uVar1 = AVIStreamOpenFromFileA(local_90);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  iVar2 = AVIStreamInfoA(puVar4,&uStack_a4,0x8c);
  if (iVar2 < 0) {
    uVar1 = AVIStreamRelease(puVar4);
    return uVar1 & 0xffffff00;
  }
  *piStack_1c = iStack_74 - iStack_7c;
  *piStack_18 = iStack_70 - iStack_78;
  uVar3 = AVIStreamRelease(puVar4);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


/*
 * FUN_0041e4e0 at 0041e4e0
 * undefined4 __cdecl FUN_0041e4e0(int param_1, undefined4 param_2)
 * Address ranges: 0041e4e0-0041e67a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041e4e0(int param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char in_stack_0000001c;
  undefined4 uStack_a4;
  undefined1 *local_80 [2];
  int local_78 [27];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00427ef8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0041efe0(local_78);
  uVar6 = 0;
  local_4 = 0;
  FUN_0041f090((int)local_78);
  uStack_a4 = 0x41e52d;
  FUN_0041e440(param_2);
  FUN_0041ee10(local_78,param_2);
  FUN_0041f060(local_78,param_1);
  uVar3 = FUN_0041e900((int *)&stack0x0000000c);
  if ((char)uVar3 != '\0') {
    iVar4 = FUN_0041efb0((int)local_78);
    puVar5 = (undefined4 *)FUN_0041e8d0(iVar4);
    FUN_0041e8b0(&stack0x0000000c,puVar5);
  }
  local_80[0] = (undefined1 *)&uStack_a4;
  FUN_0041e870(&uStack_a4,(undefined4 *)&stack0x0000000c);
  FUN_0041f070((int)local_78);
  FUN_0041f050(local_78);
  FUN_0041eec0((int)local_78);
  bVar1 = false;
LAB_0041e5b2:
  while( true ) {
    if (DAT_0043d534 == 0) {
      FUN_0041ef10((int)local_78);
      while (DAT_0043d534 == 0) {
        FUN_0040a97d();
      }
      FUN_0041eec0((int)local_78);
    }
    iVar4 = FUN_0041e680();
    if (iVar4 == 1) break;
    if (iVar4 == 2) {
      if (bVar1) {
        bVar1 = false;
        FUN_0041eec0((int)local_78);
      }
      goto LAB_0041e61a;
    }
    if ((iVar4 != 3) || (bVar1)) goto LAB_0041e615;
    bVar1 = true;
    FUN_0041ef10((int)local_78);
  }
  uVar6 = 0xfffffffe;
LAB_0041e64d:
  local_4 = 0xffffffff;
  FUN_0041e980(local_78);
  ExceptionList = pvStack_c;
  return uVar6;
LAB_0041e615:
  if (!bVar1) {
LAB_0041e61a:
    cVar2 = FUN_0041ee30(local_78);
    if (cVar2 == '\0') {
      if (in_stack_0000001c == '\0') goto LAB_0041e64d;
      FUN_0041efc0(local_80,0);
      FUN_0041ef60(local_78,(undefined8 *)local_80);
    }
  }
  goto LAB_0041e5b2;
}


/*
 * FUN_0041e680 at 0041e680
 * undefined4 __stdcall FUN_0041e680(void)
 * Address ranges: 0041e680-0041e6ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0041e680(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  
  iVar6 = 0;
  if (DAT_0043e210 != 0) {
    puVar5 = (uint *)&DAT_0043e210;
    do {
      iVar3 = FUN_004133f0(*puVar5);
      if (iVar3 != 0) {
        uVar2 = (&DAT_0043e210)[iVar6 * 2];
        if (uVar2 == 0) {
          return 0;
        }
        iVar6 = FUN_004133f0(uVar2);
        while (iVar6 != 0) {
          FUN_0040a97d();
          iVar6 = FUN_004133f0(uVar2);
        }
        uVar4 = FUN_0041e6f0(uVar2);
        return uVar4;
      }
      puVar1 = puVar5 + 2;
      puVar5 = puVar5 + 2;
      iVar6 = iVar6 + 1;
    } while (*puVar1 != 0);
  }
  return 0;
}


/*
 * FUN_0041e6f0 at 0041e6f0
 * undefined4 __cdecl FUN_0041e6f0(int param_1)
 * Address ranges: 0041e6f0-0041e714
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041e6f0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_0043e210;
  do {
    if (*piVar1 == param_1) {
      return (&DAT_0043e214)[iVar2 * 2];
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x43e2b0);
  return 0;
}


/*
 * thunk_FUN_0041e980 at 0041e720
 * undefined __fastcall thunk_FUN_0041e980(int * param_1)
 * Address ranges: 0041e720-0041e724
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_0041e980
 */


void __fastcall thunk_FUN_0041e980(int *param_1)

{
  *param_1 = (int)&PTR_FUN_00429f10;
  FUN_0041ee80(param_1);
  return;
}


/*
 * FUN_0041e730 at 0041e730
 * undefined __stdcall FUN_0041e730(void)
 * Address ranges: 0041e730-0041e758
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041e730(void)

{
  FUN_004015a6((byte *)s_init_video_library__version__s_00436d98);
  CoInitialize((LPVOID)0x0);
  AVIFileInit();
  FUN_0041e770();
  FUN_0041e800();
  return;
}


/*
 * FUN_0041e760 at 0041e760
 * undefined __stdcall FUN_0041e760(void)
 * Address ranges: 0041e760-0041e76f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041e760(void)

{
  FUN_0041e770();
  AVIFileExit();
                    /* WARNING: Could not recover jumptable at 0x0041e76a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoUninitialize();
  return;
}


/*
 * FUN_0041e770 at 0041e770
 * undefined __stdcall FUN_0041e770(void)
 * Address ranges: 0041e770-0041e786
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041e770(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0043e214;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x43e2b4);
  return;
}


/*
 * FUN_0041e790 at 0041e790
 * undefined __cdecl FUN_0041e790(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0041e790-0041e7cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041e790(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0041e7d0();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____Invalid_action_key_00436dc4);
  }
  (&DAT_0043e210)[iVar1 * 2] = param_1;
  (&DAT_0043e214)[iVar1 * 2] = param_2;
  return;
}


/*
 * FUN_0041e7d0 at 0041e7d0
 * int __stdcall FUN_0041e7d0(void)
 * Address ranges: 0041e7d0-0041e7f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0041e7d0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_0043e214;
  while ((piVar2[-1] != 0 || (*piVar2 != 0))) {
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
    if (0x43e2b3 < (int)piVar2) {
      return -1;
    }
  }
  return iVar1;
}


/*
 * FUN_0041e800 at 0041e800
 * undefined __stdcall FUN_0041e800(void)
 * Address ranges: 0041e800-0041e827
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041e800(void)

{
  FUN_0041e790(0x20,1);
  FUN_0041e790(0x1b,1);
  FUN_0041e790(0xd,1);
  FUN_0041e790(1,1);
  return;
}


/*
 * CRect::CRect at 0041e830
 * undefined __thiscall CRect(CRect * this, int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 0041e830-0041e84f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  public: __thiscall CRect::CRect(int,int,int,int)  Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release
 */


/* Library Function - Single Match
    public: __thiscall CRect::CRect(int,int,int,int)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __thiscall CRect::CRect(CRect *this,int param_1,int param_2,int param_3,int param_4)

{
  *(int *)this = param_1;
  *(int *)(this + 4) = param_2;
  *(int *)(this + 8) = param_3;
  *(int *)(this + 0xc) = param_4;
  return;
}


/*
 * FUN_0041e850 at 0041e850
 * void * __thiscall FUN_0041e850(void * this, undefined4 * param_1)
 * Address ranges: 0041e850-0041e862
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void * __thiscall FUN_0041e850(void *this,undefined4 *param_1)

{
  FUN_0041e890(this,param_1);
  return this;
}


/*
 * FUN_0041e870 at 0041e870
 * void * __thiscall FUN_0041e870(void * this, undefined4 * param_1)
 * Address ranges: 0041e870-0041e882
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void * __thiscall FUN_0041e870(void *this,undefined4 *param_1)

{
  FUN_0041e8b0(this,param_1);
  return this;
}


/*
 * FUN_0041e890 at 0041e890
 * undefined __thiscall FUN_0041e890(void * this, undefined4 * param_1)
 * Address ranges: 0041e890-0041e8ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041e890(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 8) = param_1[2];
  *(undefined4 *)((int)this + 4) = param_1[1];
  *(undefined4 *)((int)this + 0xc) = param_1[3];
  return;
}


/*
 * FUN_0041e8b0 at 0041e8b0
 * undefined __thiscall FUN_0041e8b0(void * this, undefined4 * param_1)
 * Address ranges: 0041e8b0-0041e8ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041e8b0(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  *(undefined4 *)((int)this + 8) = param_1[2];
  *(undefined4 *)((int)this + 0xc) = param_1[3];
  return;
}


/*
 * FUN_0041e8d0 at 0041e8d0
 * undefined4 __fastcall FUN_0041e8d0(undefined4 param_1)
 * Address ranges: 0041e8d0-0041e8d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0041e8d0(undefined4 param_1)

{
  return param_1;
}


/*
 * FUN_0041e8e0 at 0041e8e0
 * int __fastcall FUN_0041e8e0(int param_1)
 * Address ranges: 0041e8e0-0041e8e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __fastcall FUN_0041e8e0(int param_1)

{
  return *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4);
}


/*
 * FUN_0041e8f0 at 0041e8f0
 * int __fastcall FUN_0041e8f0(int * param_1)
 * Address ranges: 0041e8f0-0041e8f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __fastcall FUN_0041e8f0(int *param_1)

{
  return param_1[2] - *param_1;
}


/*
 * FUN_0041e900 at 0041e900
 * undefined4 __fastcall FUN_0041e900(int * param_1)
 * Address ranges: 0041e900-0041e921
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0041e900(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0041e8f0(param_1);
  if (0 < iVar1) {
    iVar1 = FUN_0041e8e0((int)param_1);
    if (0 < iVar1) {
      return 0;
    }
  }
  return 1;
}


/*
 * FUN_0041e930 at 0041e930
 * undefined4 * __fastcall FUN_0041e930(undefined4 * param_1)
 * Address ranges: 0041e930-0041e95d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __fastcall FUN_0041e930(undefined4 *param_1)

{
  *(undefined4 *)((int)param_1 + 5) = 0;
  *(undefined4 *)((int)param_1 + 9) = 0;
  *(undefined4 *)((int)param_1 + 0xd) = 0;
  *(undefined4 *)((int)param_1 + 0x15) = 0;
  *(undefined4 *)((int)param_1 + 0x19) = 0;
  *(undefined4 *)((int)param_1 + 0x1d) = 0;
  FUN_0041f0a0((CRect *)((int)param_1 + 0x21));
  *param_1 = &PTR_FUN_00429f10;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}


/*
 * FUN_0041e960 at 0041e960
 * int * __thiscall FUN_0041e960(void * this, byte param_1)
 * Address ranges: 0041e960-0041e97d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __thiscall FUN_0041e960(void *this,byte param_1)

{
  FUN_0041e980(this);
  if ((param_1 & 1) != 0) {
    FUN_0042035e(this);
  }
  return this;
}


/*
 * FUN_0041e980 at 0041e980
 * undefined __fastcall FUN_0041e980(int * param_1)
 * Address ranges: 0041e980-0041e98a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041e980(int *param_1)

{
  *param_1 = (int)&PTR_FUN_00429f10;
  FUN_0041ee80(param_1);
  return;
}


/*
 * FUN_0041e990 at 0041e990
 * undefined FUN_0041e990(void)
 * Address ranges: 0041e990-0041e9a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __fastcall FUN_0041e990(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x19) + 0x18))(*(int **)(param_1 + 0x19),0,0,0,0);
  return iVar1 == 0;
}


/*
 * FUN_0041e9b0 at 0041e9b0
 * undefined __fastcall FUN_0041e9b0(int param_1)
 * Address ranges: 0041e9b0-0041ea29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041e9b0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x1d);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x7c))(piVar1,0);
  }
  piVar1 = *(int **)(param_1 + 0x1d);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x1d) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x19);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x19) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x15);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x15) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x11);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x11) = 0;
  }
  piVar1 = *(int **)(param_1 + 0xd);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0xd) = 0;
  }
  piVar1 = *(int **)(param_1 + 9);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 9) = 0;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


/*
 * FUN_0041ea30 at 0041ea30
 * undefined FUN_0041ea30(void)
 * Address ranges: 0041ea30-0041eb02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __fastcall FUN_0041ea30(int param_1)

{
  LPVOID *ppv;
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  ppv = (LPVOID *)(param_1 + 9);
  CoCreateInstance((IID *)&DAT_00429fb8,(LPUNKNOWN)0x0,1,(IID *)&DAT_00429fc8,ppv);
  pvVar1 = *ppv;
  if (pvVar1 == (LPVOID)0x0) {
    FUN_004015a6((byte *)s__s__d____Error_creating_stream_o_00436e84);
  }
  iVar2 = (**(code **)(*(int *)*ppv + 0x30))(*ppv,0,1,0);
  if (-1 >= iVar2) {
    FUN_004015a6((byte *)s__s__d____Failed_to_call_Initiali_00436e5c);
  }
  iVar3 = (**(code **)(*(int *)*ppv + 0x3c))(*ppv,DAT_00438414,&DAT_00429fa8,0,0);
  if (-1 >= iVar3) {
    FUN_004015a6((byte *)s__s__d____Failed_adding_primary_v_00436e34);
  }
  iVar4 = (**(code **)(*(int *)*ppv + 0x3c))(*ppv,0,&DAT_00429f98,1,0);
  if (iVar4 < 0) {
    FUN_004015a6((byte *)s__s__d____Failed_adding_primary_s_00436e0c);
    return true;
  }
  return -1 < iVar3 && (-1 < iVar2 && pvVar1 != (LPVOID)0x0);
}


/*
 * FUN_0041eb10 at 0041eb10
 * undefined FUN_0041eb10(void)
 * Address ranges: 0041eb10-0041eb30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __thiscall FUN_0041eb10(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_004028e3(param_2,param_3);
  *(int *)(param_1 + 0x1d) = iVar1;
  return iVar1 != 0;
}


/*
 * FUN_0041eb40 at 0041eb40
 * undefined FUN_0041eb40(void)
 * Address ranges: 0041eb40-0041ec90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0041eb40(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piStack_54;
  undefined *puStack_40;
  undefined4 *puStack_3c;
  int *piStack_38;
  
  piStack_38 = *(int **)(param_1 + 9);
  *(int **)(param_1 + 0xd) = piStack_38;
  puStack_3c = (undefined4 *)0x41eb55;
  (**(code **)(*piStack_38 + 4))();
  puStack_40 = &DAT_00429fa8;
  puStack_3c = (undefined4 *)(param_1 + 0x11);
  iVar2 = (**(code **)(**(int **)(param_1 + 0xd) + 0x10))();
  if (iVar2 < 0) {
    piStack_54 = (int *)0x41eb7f;
    FUN_004015a6((byte *)s__s__d__Failed_getting_media_stre_00436f14);
    return 0;
  }
  piStack_54 = (int *)0x41eb9c;
  iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x11))();
  if (iVar2 < 0) {
    piStack_54 = (int *)0x13d;
    FUN_004015a6((byte *)s__s__d__Failed_getting_media_stre_00436f14);
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x1d);
  if (piVar1 != (int *)0x0) {
    piStack_54 = DAT_0043d75c;
    (**(code **)(*piVar1 + 0x7c))(piVar1);
  }
  piStack_54 = (int *)(param_1 + 0x19);
  iVar2 = (**(code **)(**(int **)(param_1 + 0x15) + 0x34))
                    (*(int **)(param_1 + 0x15),*(undefined4 *)(param_1 + 0x1d),0,1);
  if (iVar2 < 0) {
    FUN_004015a6((byte *)s__s__d__Failed_creating_sample_00436ef4);
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x19);
  piStack_54 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,&piStack_54,&stack0xffffffb0);
    if (iVar2 < 0) {
      FUN_004015a6((byte *)s__s__d__Failed_getting_surface_00436ed4);
      return 0;
    }
  }
  FUN_0041e850(&puStack_40,(undefined4 *)&stack0xffffffb0);
  FUN_0041f0c0((void *)(param_1 + 0x21),&puStack_40);
  FUN_0041f0e0((void *)(param_1 + 0x21),piStack_54);
  return 1;
}


/*
 * FUN_0041eca0 at 0041eca0
 * undefined __thiscall FUN_0041eca0(void * this, int * param_1)
 * Address ranges: 0041eca0-0041ecb4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041eca0(void *this,int *param_1)

{
  *(int **)((int)this + 5) = param_1;
  (**(code **)(*param_1 + 0xc))((int)this + 0x21);
  return;
}


/*
 * FUN_0041ecc0 at 0041ecc0
 * undefined FUN_0041ecc0(void)
 * Address ranges: 0041ecc0-0041ee0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall FUN_0041ecc0(int *param_1,LPCSTR param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  
  cVar1 = (**(code **)(*param_1 + 4))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x10))();
    return 0;
  }
  uVar2 = FUN_0041e440(param_2);
  if ((char)uVar2 == '\0') {
    FUN_004015a6((byte *)s__s__d____Error_getting_dims_of___00436fa8);
    (**(code **)(*param_1 + 0x10))();
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 8))(uStack_210,uStack_20c);
  if (cVar1 == '\0') {
    FUN_004015a6((byte *)s__s__d____Error_creating_surface_f_00436f80);
    (**(code **)(*param_1 + 0x10))();
    return 0;
  }
  MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)&uStack_210,0x104);
  iVar3 = (**(code **)(**(int **)((int)param_1 + 9) + 0x40))
                    (*(int **)((int)param_1 + 9),&uStack_210,0);
  if (iVar3 < 0) {
    (**(code **)(*param_1 + 0x10))();
    FUN_0040187a((byte *)s__s__d__Failed_to_open_movie__s_00436f60);
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0xc))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x10))();
    FUN_0040187a((byte *)s__s__d__Error_finalizing_video_fo_00436f38);
    return 0;
  }
  *(undefined1 *)(param_1 + 1) = 1;
  return 1;
}


/*
 * FUN_0041ee10 at 0041ee10
 * undefined __thiscall FUN_0041ee10(void * this, undefined4 param_1)
 * Address ranges: 0041ee10-0041ee2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041ee10(void *this,undefined4 param_1)

{
  if (*(char *)((int)this + 4) != '\0') {
    (**(code **)(*(int *)this + 0x20))();
  }
  (*(code *)**(undefined4 **)this)(param_1);
  return;
}


/*
 * FUN_0041ee30 at 0041ee30
 * char __fastcall FUN_0041ee30(int * param_1)
 * Address ranges: 0041ee30-0041ee7c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char __fastcall FUN_0041ee30(int *param_1)

{
  char cVar1;
  
  if (DAT_0043d534 == 0) {
    return '\x01';
  }
  cVar1 = (**(code **)(*param_1 + 0x14))();
  if (cVar1 == '\x01') {
    if (*(int **)((int)param_1 + 5) == (int *)0x0) {
      FUN_004015a6((byte *)s__s__d____Video_stream_has_no_ass_00436fcc);
      return '\0';
    }
    FUN_0041f210(*(int **)((int)param_1 + 5));
  }
  return cVar1;
}


/*
 * FUN_0041ee80 at 0041ee80
 * undefined __fastcall FUN_0041ee80(int * param_1)
 * Address ranges: 0041ee80-0041ee84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041ee80(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0041ee82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


/*
 * FUN_0041ee90 at 0041ee90
 * undefined FUN_0041ee90(void)
 * Address ranges: 0041ee90-0041eebc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0041ee90(int param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(param_1 + 0xd);
  uStack_4 = 0;
  uVar1 = (**(code **)(*piVar2 + 0x18))(piVar2,&uStack_4);
  if (-1 < (int)uVar1) {
    return (uint)(piVar2 == (int *)0x1);
  }
  return uVar1 & 0xffffff00;
}


/*
 * FUN_0041eec0 at 0041eec0
 * undefined4 __fastcall FUN_0041eec0(int param_1)
 * Address ranges: 0041eec0-0041ef0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0041eec0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar2 = FUN_004015a6((byte *)s__s__d____Not_initialized_for_pla_00437000);
    return uVar2 & 0xffffff00;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd) + 0x1c))(*(int **)(param_1 + 0xd),1);
  if (-1 < iVar1) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  uVar2 = FUN_004015a6((byte *)s__s__d____Couldn_t_play_file_00437028);
  return uVar2 & 0xffffff00;
}


/*
 * FUN_0041ef10 at 0041ef10
 * undefined4 __fastcall FUN_0041ef10(int param_1)
 * Address ranges: 0041ef10-0041ef5c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0041ef10(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar2 = FUN_004015a6((byte *)s__s__d____Not_initialized_00437048);
    return uVar2 & 0xffffff00;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd) + 0x1c))(*(int **)(param_1 + 0xd),0);
  if (-1 < iVar1) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  uVar2 = FUN_004015a6((byte *)s__s__d____Couldn_t_stop_file_00437064);
  return uVar2 & 0xffffff00;
}


/*
 * FUN_0041ef60 at 0041ef60
 * undefined __thiscall FUN_0041ef60(void * this, undefined8 * param_1)
 * Address ranges: 0041ef60-0041efa2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041ef60(void *this,undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(char *)((int)this + 4) != '\0') &&
     (piVar1 = *(int **)((int)this + 0xd), piVar1 != (int *)0x0)) {
    iVar2 = *piVar1;
    uVar3 = FUN_0041efd0(param_1);
    iVar2 = (**(code **)(iVar2 + 0x28))(piVar1,uVar3);
    if (iVar2 < 0) {
      FUN_004015a6((byte *)s__s__d____Failed_seeking__00437084);
    }
  }
  return;
}


/*
 * FUN_0041efb0 at 0041efb0
 * int __fastcall FUN_0041efb0(int param_1)
 * Address ranges: 0041efb0-0041efb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __fastcall FUN_0041efb0(int param_1)

{
  return param_1 + 0x21;
}


/*
 * FUN_0041efc0 at 0041efc0
 * int * __thiscall FUN_0041efc0(void * this, int param_1)
 * Address ranges: 0041efc0-0041efce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __thiscall FUN_0041efc0(void *this,int param_1)

{
  *(int *)this = param_1;
  *(int *)((int)this + 4) = param_1 >> 0x1f;
  return this;
}


/*
 * FUN_0041efd0 at 0041efd0
 * undefined8 __fastcall FUN_0041efd0(undefined8 * param_1)
 * Address ranges: 0041efd0-0041efd5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_0041efd0(undefined8 *param_1)

{
  return *param_1;
}


/*
 * FUN_0041efe0 at 0041efe0
 * undefined4 * __fastcall FUN_0041efe0(undefined4 * param_1)
 * Address ranges: 0041efe0-0041f02a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __fastcall FUN_0041efe0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00427f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041e930(param_1);
  local_4 = 0;
  *(undefined1 *)((int)param_1 + 0x35) = 0;
  FUN_0041f250((undefined4 *)((int)param_1 + 0x36));
  *param_1 = &PTR_FUN_00429f48;
  ExceptionList = local_c;
  return param_1;
}


/*
 * FUN_0041f030 at 0041f030
 * int * __thiscall FUN_0041f030(void * this, byte param_1)
 * Address ranges: 0041f030-0041f04d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __thiscall FUN_0041f030(void *this,byte param_1)

{
  thunk_FUN_0041e980(this);
  if ((param_1 & 1) != 0) {
    FUN_0042035e(this);
  }
  return this;
}


/*
 * FUN_0041f050 at 0041f050
 * undefined __fastcall FUN_0041f050(void * param_1)
 * Address ranges: 0041f050-0041f059
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041f050(void *param_1)

{
  FUN_0041eca0(param_1,(int *)((int)param_1 + 0x36));
  return;
}


/*
 * FUN_0041f060 at 0041f060
 * undefined __thiscall FUN_0041f060(void * this, int param_1)
 * Address ranges: 0041f060-0041f06f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041f060(void *this,int param_1)

{
  FUN_0041f2e0((void *)((int)this + 0x36),param_1);
  return;
}


/*
 * FUN_0041f070 at 0041f070
 * undefined __fastcall FUN_0041f070(int param_1)
 * Address ranges: 0041f070-0041f08d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041f070(int param_1)

{
  int iVar1;
  void *this;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&stack0x00000004;
  iVar1 = FUN_0041f140(param_1 + 0x36);
  this = (void *)FUN_0041e8d0(iVar1);
  FUN_0041e8b0(this,puVar2);
  return;
}


/*
 * FUN_0041f090 at 0041f090
 * undefined __fastcall FUN_0041f090(int param_1)
 * Address ranges: 0041f090-0041f094
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041f090(int param_1)

{
  *(undefined1 *)(param_1 + 0x35) = 1;
  return;
}


/*
 * FUN_0041f0a0 at 0041f0a0
 * CRect * __fastcall FUN_0041f0a0(CRect * param_1)
 * Address ranges: 0041f0a0-0041f0ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


CRect * __fastcall FUN_0041f0a0(CRect *param_1)

{
  CRect::CRect(param_1,0,0,0,0);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return param_1;
}


/*
 * FUN_0041f0c0 at 0041f0c0
 * undefined __thiscall FUN_0041f0c0(void * this, undefined4 * param_1)
 * Address ranges: 0041f0c0-0041f0cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041f0c0(void *this,undefined4 *param_1)

{
  FUN_0041e8b0(this,param_1);
  return;
}


/*
 * FUN_0041f0d0 at 0041f0d0
 * int __fastcall FUN_0041f0d0(int param_1)
 * Address ranges: 0041f0d0-0041f0d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __fastcall FUN_0041f0d0(int param_1)

{
  return param_1 + 0x10;
}


/*
 * FUN_0041f0e0 at 0041f0e0
 * undefined __thiscall FUN_0041f0e0(void * this, undefined4 param_1)
 * Address ranges: 0041f0e0-0041f0e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041f0e0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x10) = param_1;
  return;
}


/*
 * FUN_0041f0f0 at 0041f0f0
 * undefined4 __fastcall FUN_0041f0f0(int param_1)
 * Address ranges: 0041f0f0-0041f0f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0041f0f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


/*
 * FUN_0041f100 at 0041f100
 * undefined FUN_0041f100(void)
 * Address ranges: 0041f100-0041f11b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041f100(int param_1,undefined4 *param_2)

{
  FUN_0041e8b0((void *)(param_1 + 4),param_2);
  *(undefined4 *)(param_1 + 0x14) = param_2[4];
  return;
}


/*
 * FUN_0041f120 at 0041f120
 * undefined FUN_0041f120(void)
 * Address ranges: 0041f120-0041f13b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041f120(int param_1,undefined4 *param_2)

{
  FUN_0041e8b0((void *)(param_1 + 0x18),param_2);
  *(undefined4 *)(param_1 + 0x28) = param_2[4];
  return;
}


/*
 * FUN_0041f140 at 0041f140
 * int __fastcall FUN_0041f140(int param_1)
 * Address ranges: 0041f140-0041f143
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __fastcall FUN_0041f140(int param_1)

{
  return param_1 + 0x18;
}


/*
 * FUN_0041f150 at 0041f150
 * undefined __fastcall FUN_0041f150(int param_1)
 * Address ranges: 0041f150-0041f205
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041f150(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = param_1 + 0x18;
  puVar3 = (undefined4 *)FUN_0041f0d0(iVar1);
  piVar2 = (int *)*puVar3;
  iVar8 = param_1 + 4;
  iVar7 = *piVar2;
  uVar4 = FUN_0041e8d0(iVar8);
  uVar5 = FUN_0041e8d0(uVar4);
  puVar3 = (undefined4 *)FUN_0041f0d0(iVar8);
  uVar4 = *puVar3;
  uVar6 = FUN_0041e8d0(iVar1);
  uVar6 = FUN_0041e8d0(uVar6);
  iVar7 = (**(code **)(iVar7 + 0x14))(piVar2,uVar6,uVar4,uVar5);
  if (iVar7 < 0) {
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar8);
    FUN_0041e8d0(iVar8);
    FUN_0041e8d0(iVar8);
    FUN_0041e8d0(iVar8);
    FUN_004015a6((byte *)s_FAILED_rendering_from___d___d____004370a0);
  }
  return;
}


/*
 * FUN_0041f210 at 0041f210
 * undefined __fastcall FUN_0041f210(int * param_1)
 * Address ranges: 0041f210-0041f240
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041f210(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0041f0f0((int)(param_1 + 1));
  if (iVar1 != 0) {
    iVar1 = FUN_0041f0f0((int)(param_1 + 6));
    if (iVar1 != 0) {
      (**(code **)*param_1)();
      (**(code **)(*param_1 + 4))();
      (**(code **)(*param_1 + 8))();
    }
  }
  return;
}


/*
 * FUN_0041f250 at 0041f250
 * undefined4 * __fastcall FUN_0041f250(undefined4 * param_1)
 * Address ranges: 0041f250-0041f274
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __fastcall FUN_0041f250(undefined4 *param_1)

{
  FUN_0041f0a0((CRect *)(param_1 + 1));
  FUN_0041f0a0((CRect *)(param_1 + 6));
  *param_1 = &PTR_FUN_00429f80;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return param_1;
}


/*
 * FUN_0041f280 at 0041f280
 * undefined __fastcall FUN_0041f280(int param_1)
 * Address ranges: 0041f280-0041f2df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0041f280(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))();
  }
  if (*(int *)(param_1 + 0x2c) == 1) {
    FUN_00401cf3();
  }
  else if (*(int *)(param_1 + 0x2c) == 2) {
    uVar6 = 0;
    iVar1 = *DAT_00438434;
    uVar5 = 0x1000000;
    uVar2 = FUN_0041e8d0(param_1 + 0x18);
    uVar3 = FUN_0041e8d0(uVar2);
    uVar2 = DAT_00438418;
    uVar4 = FUN_0041e8d0(param_1 + 0x18);
    uVar4 = FUN_0041e8d0(uVar4);
    (**(code **)(iVar1 + 0x14))(DAT_00438434,uVar4,uVar2,uVar3,uVar5,uVar6);
    return;
  }
  return;
}


/*
 * FUN_0041f2e0 at 0041f2e0
 * undefined __thiscall FUN_0041f2e0(void * this, int param_1)
 * Address ranges: 0041f2e0-0041f31f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041f2e0(void *this,int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *(int *)((int)this + 0x2c) = param_1;
  if (param_1 == 1) {
    uVar2 = DAT_00438438;
    pvVar1 = (void *)FUN_0041f140((int)this);
    FUN_0041f0e0(pvVar1,uVar2);
    return;
  }
  uVar2 = DAT_00438418;
  if (param_1 != 2) {
    uVar2 = DAT_00438434;
  }
  pvVar1 = (void *)FUN_0041f140((int)this);
  FUN_0041f0e0(pvVar1,uVar2);
  return;
}


/*
 * FUN_0041f320 at 0041f320
 * undefined FUN_0041f320(void)
 * Address ranges: 0041f320-0041f320
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041f320(void)

{
  return;
}


/*
 * _strncmp at 0041f330
 * int __cdecl _strncmp(char * _Str1, char * _Str2, size_t _MaxCount)
 * Address ranges: 0041f330-0041f367
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _strncmp  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}


/*
 * FUN_0041f368 at 0041f368
 * undefined4 __cdecl FUN_0041f368(FILE * param_1)
 * Address ranges: 0041f368-0041f3bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0041f368(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x40U) == 0) {
    if ((param_1->_flag & 0x83U) != 0) {
      uVar2 = FUN_0042056d((int *)param_1);
      __freebuf(param_1);
      iVar1 = FUN_00420454(param_1->_file);
      if (iVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else if (param_1->_tmpfname != (char *)0x0) {
        FUN_0041fd93(param_1->_tmpfname);
        param_1->_tmpfname = (char *)0x0;
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  param_1->_flag = 0;
  return uVar2;
}


/*
 * FUN_0041f3be at 0041f3be
 * uint __cdecl FUN_0041f3be(char * param_1, uint param_2, uint param_3, int * param_4)
 * Address ranges: 0041f3be-0041f4a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0041f3be(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  piVar1 = param_4;
  pcVar6 = (char *)(param_2 * param_3);
  if (pcVar6 == (char *)0x0) {
    param_3 = 0;
  }
  else {
    pcVar5 = param_1;
    param_1 = pcVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) ||
         (pcVar2 = (char *)piVar1[1], pcVar2 == (char *)0x0)) {
        if (param_1 < param_4) {
          uVar4 = FUN_0042063f(piVar1);
          if (uVar4 == 0xffffffff) goto LAB_0041f49a;
          *pcVar5 = (char)uVar4;
          param_4 = (int *)piVar1[6];
          pcVar5 = pcVar5 + 1;
          param_1 = param_1 + -1;
        }
        else {
          pcVar2 = param_1;
          if (param_4 != (int *)0x0) {
            pcVar2 = param_1 + -((uint)param_1 % (uint)param_4);
          }
          iVar3 = FUN_00420718(piVar1[4],pcVar5,pcVar2);
          if (iVar3 == 0) {
            piVar1[3] = piVar1[3] | 0x10;
LAB_0041f49a:
            return (uint)((int)pcVar6 - (int)param_1) / param_2;
          }
          if (iVar3 == -1) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_0041f49a;
          }
          param_1 = param_1 + -iVar3;
          pcVar5 = pcVar5 + iVar3;
        }
      }
      else {
        pcVar7 = param_1;
        if (pcVar2 <= param_1) {
          pcVar7 = pcVar2;
        }
        FUN_00420910((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
        param_1 = param_1 + -(int)pcVar7;
        piVar1[1] = piVar1[1] - (int)pcVar7;
        *piVar1 = (int)(pcVar7 + *piVar1);
        pcVar5 = pcVar5 + (int)pcVar7;
      }
    } while (param_1 != (char *)0x0);
  }
  return param_3;
}


/*
 * FUN_0041f4a6 at 0041f4a6
 * undefined __cdecl FUN_0041f4a6(LPCSTR param_1, char * param_2, uint param_3)
 * Address ranges: 0041f4a6-0041f4c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f4a6(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00420db5();
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00420c45(param_1,param_2,param_3,puVar1);
  return;
}


/*
 * FUN_0041f4c6 at 0041f4c6
 * undefined __cdecl FUN_0041f4c6(LPCSTR param_1, char * param_2)
 * Address ranges: 0041f4c6-0041f4d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f4c6(LPCSTR param_1,char *param_2)

{
  FUN_0041f4a6(param_1,param_2,0x40);
  return;
}


/*
 * entry at 0041f4d9
 * undefined __stdcall entry(void)
 * Address ranges: 0041f4d9-0041f5c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  HMODULE pHVar5;
  UINT UVar6;
  undefined4 uVar7;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00429fe8;
  pcStack_10 = FUN_00421630;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_0043e2d8 = DVar1 >> 8 & 0xff;
  _DAT_0043e2d4 = DVar1 & 0xff;
  _DAT_0043e2d0 = _DAT_0043e2d4 * 0x100 + _DAT_0043e2d8;
  _DAT_0043e2cc = DVar1 >> 0x10;
  iVar2 = FUN_004215ec(0);
  if (iVar2 == 0) {
    FUN_0041f5f4(0x1c);
  }
  local_8 = 0;
  FUN_00421441();
  DAT_0043f934 = GetCommandLineA();
  DAT_0043e2b4 = FUN_0042130f();
  FUN_004210c2();
  FUN_00421009();
  FUN_0041f69b();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  pbVar3 = FUN_00420fb1();
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_60.wShowWindow;
  }
  uVar7 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  UVar6 = FUN_00401400(pHVar5,uVar7,(LPCSTR)pbVar3,uVar4);
  FUN_0041f6c8(UVar6);
  FUN_00420e2d(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}


/*
 * __amsg_exit at 0041f5cf
 * void __cdecl __amsg_exit(int param_1)
 * Address ranges: 0041f5cf-0041f5f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __amsg_exit  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0043e2bc == 1) {
    FUN_00421708();
  }
  FUN_00421741(param_1);
  (*(code *)PTR___exit_004370e0)(0xff);
  return;
}


/*
 * FUN_0041f5f4 at 0041f5f4
 * undefined __cdecl FUN_0041f5f4(DWORD param_1)
 * Address ranges: 0041f5f4-0041f616
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f5f4(DWORD param_1)

{
  if (DAT_0043e2bc == 1) {
    FUN_00421708();
  }
  FUN_00421741(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xff);
}


/*
 * FUN_0041f618 at 0041f618
 * int __cdecl FUN_0041f618(int * param_1, byte * param_2)
 * Address ranges: 0041f618-0041f649
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0041f618(int *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00421894(param_1);
  iVar2 = FUN_0042195e(param_1,param_2,(undefined4 *)&stack0x0000000c);
  FUN_00421921(iVar1,param_1);
  return iVar2;
}


/*
 * FUN_0041f64a at 0041f64a
 * int __cdecl FUN_0041f64a(undefined1 * param_1, byte * param_2, undefined4 * param_3)
 * Address ranges: 0041f64a-0041f69a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0041f64a(undefined1 *param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_0042195e((int *)&local_24,param_2,param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_00422168(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}


/*
 * FUN_0041f69b at 0041f69b
 * undefined __stdcall FUN_0041f69b(void)
 * Address ranges: 0041f69b-0041f6c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041f69b(void)

{
  if (PTR_FUN_00437108 != (undefined *)0x0) {
    (*(code *)PTR_FUN_00437108)();
  }
  FUN_0041f783((undefined4 *)&DAT_0042c008,(undefined4 *)&DAT_0042c018);
  FUN_0041f783((undefined4 *)&DAT_0042c000,(undefined4 *)&DAT_0042c004);
  return;
}


/*
 * FUN_0041f6c8 at 0041f6c8
 * undefined __cdecl FUN_0041f6c8(UINT param_1)
 * Address ranges: 0041f6c8-0041f6d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f6c8(UINT param_1)

{
  FUN_0041f6ea(param_1,0,0);
  return;
}


/*
 * __exit at 0041f6d9
 * noreturn void __cdecl __exit(int _Code)
 * Address ranges: 0041f6d9-0041f6e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 * Analysis note: Library Function - Single Match  __exit  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_0041f6ea(_Code,1,0);
  return;
}


/*
 * FUN_0041f6ea at 0041f6ea
 * undefined __cdecl FUN_0041f6ea(UINT param_1, int param_2, int param_3)
 * Address ranges: 0041f6ea-0041f782
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041f6ea(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0043e308 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0043e304 = 1;
  DAT_0043e300 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0043f930 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0043f92c - 4), DAT_0043f930 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0043f930 <= puVar1);
    }
    FUN_0041f783((undefined4 *)&DAT_0042c01c,(undefined4 *)&DAT_0042c024);
  }
  FUN_0041f783((undefined4 *)&DAT_0042c028,(undefined4 *)&DAT_0042c030);
  if (param_3 != 0) {
    return;
  }
  DAT_0043e308 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


/*
 * FUN_0041f783 at 0041f783
 * undefined __cdecl FUN_0041f783(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 0041f783-0041f79c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f783(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


/*
 * FUN_0041f7a0 at 0041f7a0
 * uint * __cdecl FUN_0041f7a0(uint * param_1, uint * param_2)
 * Address ranges: 0041f7a0-0041f7a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_0041f7a0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0041f888;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0041f888:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}


/*
 * FUN_0041f7b0 at 0041f7b0
 * uint * __cdecl FUN_0041f7b0(uint * param_1, uint * param_2)
 * Address ranges: 0041f7b0-0041f88f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_0041f7b0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0041f7cc;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0041f7ff;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0041f81b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0041f7cc:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0041f81b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0041f81b;
    }
  }
LAB_0041f7ff:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0041f81b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0041f888:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0041f888;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


/*
 * _memset at 0041f890
 * void * __cdecl _memset(void * _Dst, int _Val, size_t _Size)
 * Address ranges: 0041f890-0041f8e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _memset  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}


/*
 * FUN_0041f8e8 at 0041f8e8
 * undefined __cdecl FUN_0041f8e8(undefined4 param_1)
 * Address ranges: 0041f8e8-0041f8f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f8e8(undefined4 param_1)

{
  DAT_004370f0 = param_1;
  return;
}


/*
 * FUN_0041f8f2 at 0041f8f2
 * uint __stdcall FUN_0041f8f2(void)
 * Address ranges: 0041f8f2-0041f90f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint FUN_0041f8f2(void)

{
  DAT_004370f0 = DAT_004370f0 * 0x343fd + 0x269ec3;
  return DAT_004370f0 >> 0x10 & 0x7fff;
}


/*
 * FUN_0041f910 at 0041f910
 * undefined __cdecl FUN_0041f910(int * param_1)
 * Address ranges: 0041f910-0041f9eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041f910(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_0043e320._2_2_) {
    if (local_24.wHour == (WORD)DAT_0043e320) {
      if (local_24.wDay == DAT_0043e31c._2_2_) {
        if (local_24.wMonth == DAT_0043e318._2_2_) {
          if (local_24.wYear == (WORD)DAT_0043e318) goto LAB_0041f9ba;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_0043e310 = -1;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_0043e310 = 1;
  }
  else {
    DAT_0043e310 = 0;
  }
  DAT_0043e318._0_2_ = local_24.wYear;
  DAT_0043e318._2_2_ = local_24.wMonth;
  DAT_0043e31c._0_2_ = local_24.wDayOfWeek;
  DAT_0043e31c._2_2_ = local_24.wDay;
  DAT_0043e320._0_2_ = local_24.wHour;
  DAT_0043e320._2_2_ = local_24.wMinute;
  DAT_0043e324._0_2_ = local_24.wSecond;
  DAT_0043e324._2_2_ = local_24.wMilliseconds;
LAB_0041f9ba:
  iVar2 = FUN_0042227d((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                       (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,
                       DAT_0043e310);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}


/*
 * _strlen at 0041f9f0
 * size_t __cdecl _strlen(char * _Str)
 * Address ranges: 0041f9f0-0041fa6a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _strlen  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_0041fa10;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0041fa43:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0041fa10:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_0041fa43;
}


/*
 * _strncpy at 0041fa70
 * char * __cdecl _strncpy(char * _Dest, char * _Source, size_t _Count)
 * Address ranges: 0041fa70-0041fb6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _strncpy  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x0041faae;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0041faeb;
        goto LAB_0041fb59;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x0041fb55:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_0041fb59:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0041faeb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x0041fb55;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x0041fb55;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x0041fb55;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0041faae:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_0041faeb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


/*
 * FUN_0041fb70 at 0041fb70
 * uint * __cdecl FUN_0041fb70(uint * param_1, char * param_2)
 * Address ranges: 0041fb70-0041fbef;00422340-00422344
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_0041fb70(uint *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;
  
  cVar3 = *param_2;
  if (cVar3 == '\0') {
    return param_1;
  }
  if (param_2[1] == '\0') {
    while (((uint)param_1 & 3) != 0) {
      uVar5 = *param_1;
      if ((char)uVar5 == cVar3) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if ((char)uVar5 == '\0') {
        return (uint *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar5 = *param_1;
        uVar9 = uVar5 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar7 = uVar5 ^ 0xffffffff ^ uVar5 + 0x7efefeff;
        puVar10 = param_1 + 1;
        if (((uVar9 ^ 0xffffffff ^ uVar9 + 0x7efefeff) & 0x81010100) != 0) break;
        param_1 = puVar10;
        if ((uVar7 & 0x81010100) != 0) {
          if ((uVar7 & 0x1010100) != 0) {
            return (uint *)0x0;
          }
          if ((uVar5 + 0x7efefeff & 0x80000000) == 0) {
            return (uint *)0x0;
          }
        }
      }
      uVar5 = *param_1;
      if ((char)uVar5 == cVar3) {
        return param_1;
      }
      if ((char)uVar5 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar5 >> 8);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 1);
      }
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar5 >> 0x10);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 2);
      }
      if (cVar6 == '\0') break;
      cVar6 = (char)(uVar5 >> 0x18);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 3);
      }
      param_1 = puVar10;
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  do {
    cVar6 = (char)*param_1;
    do {
      while (puVar10 = param_1, param_1 = (uint *)((int)puVar10 + 1), cVar6 != cVar3) {
        if (cVar6 == '\0') {
          return (uint *)0x0;
        }
        cVar6 = *(char *)param_1;
      }
      cVar6 = *(char *)param_1;
      pcVar8 = param_2;
      puVar4 = puVar10;
    } while (cVar6 != param_2[1]);
    do {
      if (pcVar8[2] == '\0') {
        return puVar10;
      }
      if (*(char *)((int)puVar4 + 2) != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') {
        return puVar10;
      }
      pcVar2 = (char *)((int)puVar4 + 3);
      pcVar8 = pcVar8 + 2;
      puVar4 = (uint *)((int)puVar4 + 2);
    } while (*pcVar1 == *pcVar2);
  } while( true );
}


/*
 * FUN_0041fbf0 at 0041fbf0
 * int __thiscall FUN_0041fbf0(void * this, byte * param_1)
 * Address ranges: 0041fbf0-0041fc7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __thiscall FUN_0041fbf0(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  
  while( true ) {
    if (DAT_0043746c < 2) {
      uVar1 = (byte)PTR_DAT_00437260[(uint)*param_1 * 2] & 8;
      this = PTR_DAT_00437260;
    }
    else {
      puVar6 = (undefined *)0x8;
      uVar1 = FUN_0042240c(this,(uint)*param_1,8);
      this = puVar6;
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar5 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar4 = uVar1, uVar1 == 0x2b)) {
    uVar4 = (uint)*pbVar5;
    pbVar5 = param_1 + 2;
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_0043746c < 2) {
      uVar2 = (byte)PTR_DAT_00437260[uVar4 * 2] & 4;
    }
    else {
      puVar6 = (undefined *)0x4;
      uVar2 = FUN_0042240c(this,uVar4,4);
      this = puVar6;
    }
    if (uVar2 == 0) break;
    iVar3 = (uVar4 - 0x30) + iVar3 * 10;
    uVar4 = (uint)*pbVar5;
    pbVar5 = pbVar5 + 1;
  }
  if (uVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return iVar3;
}


/*
 * FUN_0041fc7b at 0041fc7b
 * undefined __thiscall FUN_0041fc7b(void * this, byte * param_1)
 * Address ranges: 0041fc7b-0041fc85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0041fc7b(void *this,byte *param_1)

{
  FUN_0041fbf0(this,param_1);
  return;
}


/*
 * _strrchr at 0041fc90
 * char * __cdecl _strrchr(char * _Str, int _Ch)
 * Address ranges: 0041fc90-0041fcb6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _strrchr  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _strrchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}


/*
 * FUN_0041fcb7 at 0041fcb7
 * undefined __stdcall FUN_0041fcb7(void)
 * Address ranges: 0041fcb7-0041fccd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fcb7(void)

{
  void *extraout_ECX;
  
  FUN_0041fccf();
  _DAT_0043e32c = FUN_004224d1();
  FUN_00422481(extraout_ECX);
  return;
}


/*
 * FUN_0041fcce at 0041fcce
 * undefined FUN_0041fcce(void)
 * Address ranges: 0041fcce-0041fcce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041fcce(void)

{
  return;
}


/*
 * FUN_0041fccf at 0041fccf
 * undefined __stdcall FUN_0041fccf(void)
 * Address ranges: 0041fccf-0041fd06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041fccf(void)

{
  PTR_FUN_0043747c = &LAB_00422554;
  PTR_FUN_00437478 = __cfltcvt;
  PTR_FUN_00437480 = __fassign;
  PTR_FUN_00437484 = FUN_004224fa;
  PTR_FUN_00437488 = &LAB_004225a2;
  PTR_FUN_0043748c = __cfltcvt;
  return;
}


/*
 * FUN_0041fd07 at 0041fd07
 * int __cdecl FUN_0041fd07(int * param_1, int param_2, DWORD param_3)
 * Address ranges: 0041fd07-0041fd92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0041fd07(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  
  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    _DAT_0043e2c0 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_004229cf((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_0042056d(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    DVar3 = FUN_00422935(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}


/*
 * FUN_0041fd93 at 0041fd93
 * undefined __cdecl FUN_0041fd93(LPVOID param_1)
 * Address ranges: 0041fd93-0041fdc1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041fd93(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    puVar1 = (uint *)FUN_00422b65((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_00422b90(puVar1,(uint)param_1);
      return;
    }
    HeapFree(DAT_0043f81c,0,param_1);
  }
  return;
}


/*
 * FUN_0041fdc2 at 0041fdc2
 * undefined __cdecl FUN_0041fdc2(int * param_1)
 * Address ranges: 0041fdc2-0041fe15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0041fdc2(int *param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = param_1[4];
  FUN_0042056d(param_1);
  param_1[3] = param_1[3] & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &DAT_004371b8;
  }
  else {
    puVar2 = (undefined *)((&DAT_0043f820)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  if ((param_1[3] & 0x80U) != 0) {
    param_1[3] = param_1[3] & 0xfffffffc;
  }
  FUN_00422935(uVar1,0,0);
  return;
}


/*
 * FUN_0041fe16 at 0041fe16
 * int __cdecl FUN_0041fe16(undefined1 * param_1, byte * param_2)
 * Address ranges: 0041fe16-0041fe67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0041fe16(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_0042195e((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_00422168(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}


/*
 * FUN_0041fe68 at 0041fe68
 * uint __cdecl FUN_0041fe68(undefined4 * param_1)
 * Address ranges: 0041fe68-0041fe81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0041fe68(undefined4 *param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    bVar2 = *(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
    return (uint)bVar2;
  }
  uVar3 = FUN_0042063f(param_1);
  return uVar3;
}


/*
 * FUN_0041fe82 at 0041fe82
 * uint __cdecl FUN_0041fe82(char * param_1, uint param_2, uint param_3, int * param_4)
 * Address ranges: 0041fe82-0041ff8b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0041fe82(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar1 = param_4;
  piVar6 = (int *)(param_2 * param_3);
  if (piVar6 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar5 = piVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar7 = (int *)piVar1[1], piVar7 == (int *)0x0)) {
        if (param_4 <= piVar5) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_0042056d(piVar1), iVar2 != 0)) {
LAB_0041ff83:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          piVar7 = piVar5;
          if (param_4 != (int *)0x0) {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_00423666(piVar1[4],param_1,(uint)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_0041ff83;
          }
          goto LAB_0041ff3a;
        }
        uVar4 = FUN_00422168((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_0041ff83;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar5 = (int *)((int)piVar5 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        piVar3 = piVar5;
        if (piVar7 <= piVar5) {
          piVar3 = piVar7;
        }
        FUN_00420910((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_0041ff3a:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}


/*
 * FUN_0041ff8c at 0041ff8c
 * undefined __stdcall FUN_0041ff8c(undefined * UNRECOVERED_JUMPTABLE)
 * Address ranges: 0041ff8c-0041ffb8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041ff8c(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x0041ffb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


/*
 * FUN_0041ffc0 at 0041ffc0
 * undefined __stdcall FUN_0041ffc0(undefined4 param_1, undefined * UNRECOVERED_JUMPTABLE)
 * Address ranges: 0041ffc0-0041ffc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041ffc0(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ffc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


/*
 * FUN_0041ffc7 at 0041ffc7
 * undefined __stdcall FUN_0041ffc7(undefined4 param_1, undefined * UNRECOVERED_JUMPTABLE)
 * Address ranges: 0041ffc7-0041ffcd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041ffc7(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ffcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


/*
 * FUN_0041ffce at 0041ffce
 * undefined __stdcall FUN_0041ffce(PVOID param_1, PEXCEPTION_RECORD param_2)
 * Address ranges: 0041ffce-0042001c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0041ffce(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x41fff6,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


/*
 * FUN_0042001d at 0042001d
 * undefined4 __cdecl FUN_0042001d(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 0042001d-00420052
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_0042001d(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_00423813(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}


/*
 * FUN_00420053 at 00420053
 * undefined4 __cdecl FUN_00420053(undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5)
 * Address ranges: 00420053-004200a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00420053(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_004200a7;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}


/*
 * FUN_004200a7 at 004200a7
 * undefined __cdecl FUN_004200a7(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3)
 * Address ranges: 004200a7-004200cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004200a7(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3)

{
  FUN_00423813(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}


/*
 * FUN_004200cc at 004200cc
 * undefined4 __cdecl FUN_004200cc(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7)
 * Address ranges: 004200cc-0042017f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_004200cc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_00420180;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x420152;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*DAT_0043e460)(*param_1,&local_34);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}


/*
 * FUN_00420180 at 00420180
 * undefined4 __cdecl FUN_00420180(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3)
 * Address ranges: 00420180-004201ec;004201f0-004201f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00420180(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_00423813(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_0041ffce(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x004201ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}


/*
 * FUN_004201f5 at 004201f5
 * int __cdecl FUN_004201f5(int param_1, int param_2, int param_3, uint * param_4, uint * param_5)
 * Address ranges: 004201f5-0042026f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_004201f5(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar4 = uVar5;
  uVar3 = uVar5;
  while (uVar2 = uVar4, -1 < param_2) {
    if (uVar5 == 0xffffffff) {
      FUN_004240b2();
    }
    uVar5 = uVar5 - 1;
    if (((*(int *)(iVar1 + 4 + uVar5 * 0x14) < param_3) &&
        (param_3 <= *(int *)(iVar1 + uVar5 * 0x14 + 8))) || (uVar4 = uVar2, uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar4 = uVar5;
      uVar3 = uVar2;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar5)) {
    FUN_004240b2();
  }
  return iVar1 + uVar5 * 0x14;
}


/*
 * __global_unwind2 at 00420270
 * undefined __cdecl __global_unwind2(PVOID param_1)
 * Address ranges: 00420270-0042028f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __global_unwind2  Library: Visual Studio
 */


/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x420288,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


/*
 * FUN_00420290 at 00420290
 * undefined FUN_00420290(void)
 * Address ranges: 00420290-004202b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00420290(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


/*
 * __local_unwind2 at 004202b2
 * undefined __cdecl __local_unwind2(int param_1, int param_2)
 * Address ranges: 004202b2-00420319
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __local_unwind2  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  pcStack_18 = FUN_00420290;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00420346();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


/*
 * __abnormal_termination at 0042031a
 * int __cdecl __abnormal_termination(void)
 * Address ranges: 0042031a-0042033c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __abnormal_termination  Library: Visual Studio
 */


/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(code **)((int)ExceptionList + 4) == FUN_00420290) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


/*
 * __NLG_Notify1 at 0042033d
 * undefined __fastcall __NLG_Notify1(undefined4 param_1)
 * Address ranges: 0042033d-00420345
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __NLG_Notify1  Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual Studio 2019 Release
 */


/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_0043711c = param_1;
  DAT_00437118 = in_EAX;
  DAT_00437120 = unaff_EBP;
  return;
}


/*
 * FUN_00420346 at 00420346
 * undefined __stdcall FUN_00420346(void)
 * Address ranges: 00420346-0042035d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00420346(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0043711c = *(undefined4 *)(unaff_EBP + 8);
  DAT_00437118 = in_EAX;
  DAT_00437120 = unaff_EBP;
  return;
}


/*
 * FUN_0042035e at 0042035e
 * undefined __cdecl FUN_0042035e(LPVOID param_1)
 * Address ranges: 0042035e-00420368
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042035e(LPVOID param_1)

{
  FUN_0041fd93(param_1);
  return;
}


/*
 * FUN_00420454 at 00420454
 * undefined4 __cdecl FUN_00420454(uint param_1)
 * Address ranges: 00420454-00420506
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00420454(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_0043f920 <= param_1) {
    DAT_0043e2c4 = 0;
    _DAT_0043e2c0 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) {
    _DAT_0043e2c0 = 9;
    DAT_0043e2c4 = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_004242f5(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_004242f5(2);
      iVar2 = FUN_004242f5(1);
      if (iVar2 == iVar1) goto LAB_004204cd;
    }
    hObject = (HANDLE)FUN_004242f5(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_004204cf;
    }
  }
LAB_004204cd:
  DVar4 = 0;
LAB_004204cf:
  FUN_0042427b(param_1);
  *(undefined1 *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + iVar5) = 0;
  if (DVar4 == 0) {
    return 0;
  }
  FUN_00424108(DVar4);
  return 0xffffffff;
}


/*
 * __freebuf at 00420507
 * void __cdecl __freebuf(FILE * _File)
 * Address ranges: 00420507-00420531
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __freebuf  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_0041fd93(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


/*
 * FUN_00420532 at 00420532
 * int __cdecl FUN_00420532(int * param_1)
 * Address ranges: 00420532-0042056c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00420532(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = flsall(0);
    return iVar1;
  }
  iVar1 = FUN_0042056d(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_00424332(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}


/*
 * FUN_0042056d at 0042056d
 * undefined4 __cdecl FUN_0042056d(int * param_1)
 * Address ranges: 0042056d-004205c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0042056d(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_00423666(param_1[4],(char *)param_1[2],uVar3);
      if (uVar1 == uVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}


/*
 * flsall at 004205d2
 * int __cdecl flsall(int param_1)
 * Address ranges: 004205d2-0042063e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _flsall  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 2003 Release */

int __cdecl flsall(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  iVar5 = 0;
  if (0 < DAT_0043f800) {
    do {
      piVar1 = *(int **)(DAT_0043e7e8 + iVar4 * 4);
      if ((piVar1 != (int *)0x0) && ((piVar1[3] & 0x83U) != 0)) {
        if (param_1 == 1) {
          iVar2 = FUN_00420532(piVar1);
          if (iVar2 != -1) {
            iVar3 = iVar3 + 1;
          }
        }
        else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
          iVar2 = FUN_00420532(piVar1);
          if (iVar2 == -1) {
            iVar5 = -1;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_0043f800);
  }
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}


/*
 * FUN_0042063f at 0042063f
 * uint __cdecl FUN_0042063f(undefined4 * param_1)
 * Address ranges: 0042063f-00420717
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0042063f(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      param_1[3] = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        FUN_00424442(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_00420718(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_004371b8;
          }
          else {
            puVar4 = (undefined *)((&DAT_0043f820)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            param_1[3] = param_1[3] | 0x2000;
          }
        }
        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
          param_1[6] = 0x1000;
        }
        param_1[1] = iVar3 + -1;
        bVar1 = *(byte *)*param_1;
        *param_1 = (byte *)*param_1 + 1;
        return (uint)bVar1;
      }
      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      param_1[1] = 0;
    }
    else {
      param_1[3] = uVar2 | 0x20;
    }
  }
  return 0xffffffff;
}


/*
 * FUN_00420718 at 00420718
 * int __cdecl FUN_00420718(uint param_1, char * param_2, char * param_3)
 * Address ranges: 00420718-0042090d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00420718(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  int iVar7;
  char *pcVar8;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  if (param_1 < DAT_0043f920) {
    iVar7 = (param_1 & 0x1f) * 8;
    piVar1 = &DAT_0043f820 + ((int)param_1 >> 5);
    bVar4 = *(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar7 + 4);
    if ((bVar4 & 1) != 0) {
      local_c = (char *)0x0;
      if ((param_3 == (char *)0x0) || ((bVar4 & 2) != 0)) {
        return 0;
      }
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar7 + 5), cVar3 != '\n')) {
        param_3 = param_3 + -1;
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar7) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar7),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          _DAT_0043e2c0 = 9;
          DAT_0043e2c4 = 5;
          return -1;
        }
        if (DVar6 != 0x6d) {
          FUN_00424108(DVar6);
          return -1;
        }
        return 0;
      }
      bVar4 = *(byte *)(*piVar1 + 4 + iVar7);
      if ((bVar4 & 0x80) == 0) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*param_2 != '\n')) {
        bVar4 = bVar4 & 0xfb;
      }
      else {
        bVar4 = bVar4 | 4;
      }
      *(byte *)(*piVar1 + 4 + iVar7) = bVar4;
      param_3 = param_2;
      local_c = param_2 + (int)local_c + local_10;
      pcVar8 = param_2;
      if (param_2 < local_c) {
        do {
          cVar3 = *param_3;
          if (cVar3 == '\x1a') {
            pbVar2 = (byte *)(*piVar1 + 4 + iVar7);
            bVar4 = *pbVar2;
            if ((bVar4 & 0x40) == 0) {
              *pbVar2 = bVar4 | 2;
            }
            break;
          }
          if (cVar3 == '\r') {
            if (param_3 < local_c + -1) {
              if (param_3[1] == '\n') {
                param_3 = param_3 + 2;
                goto LAB_004208ae;
              }
              *pcVar8 = '\r';
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              param_3 = param_3 + 1;
              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar7),&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_004208c8:
                *pcVar8 = '\r';
LAB_004208cb:
                pcVar8 = pcVar8 + 1;
              }
              else if ((*(byte *)(*piVar1 + 4 + iVar7) & 0x48) == 0) {
                if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_004208ae:
                  *pcVar8 = '\n';
                  goto LAB_004208cb;
                }
                FUN_00422935(param_1,-1,1);
                if (local_5 != '\n') goto LAB_004208c8;
              }
              else {
                if (local_5 == '\n') goto LAB_004208ae;
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                *(char *)(*piVar1 + 5 + iVar7) = local_5;
              }
            }
          }
          else {
            *pcVar8 = cVar3;
            pcVar8 = pcVar8 + 1;
            param_3 = param_3 + 1;
          }
        } while (param_3 < local_c);
      }
      return (int)pcVar8 - (int)param_2;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return -1;
}


/*
 * FUN_00420910 at 00420910
 * undefined4 * __cdecl FUN_00420910(undefined4 * param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 00420910-0042096a;0042096c-00420972;00420980-004209a8;004209ac-004209ce;004209d0-004209e8;00420a0c-00420a55;00420a68-00420a6e;00420a70-00420a7a;00420a7c-00420a8c;00420a90-00420aa6;00420aa8-00420acd;00420ad0-00420ad8;00420adc-00420afa;00420b08-00420b24;00420b28-00420b4e;00420b50-00420b80;00420ba4-00420bed;00420c00-00420c06;00420c08-00420c14;00420c18-00420c2a;00420c2c-00420c44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __cdecl FUN_00420910(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_00420ac7_caseD_2;
        case 3:
          goto switchD_00420ac7_caseD_3;
        }
        goto switchD_00420ac7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00420ac7_caseD_0;
      case 1:
        goto switchD_00420ac7_caseD_1;
      case 2:
        goto switchD_00420ac7_caseD_2;
      case 3:
        goto switchD_00420ac7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00420ac7_caseD_2;
            case 3:
              goto switchD_00420ac7_caseD_3;
            }
            goto switchD_00420ac7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00420ac7_caseD_2;
            case 3:
              goto switchD_00420ac7_caseD_3;
            }
            goto switchD_00420ac7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00420ac7_caseD_2;
            case 3:
              goto switchD_00420ac7_caseD_3;
            }
            goto switchD_00420ac7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_00420ac7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_00420ac7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_00420ac7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_00420ac7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00420945_caseD_2;
      case 3:
        goto switchD_00420945_caseD_3;
      }
      goto switchD_00420945_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00420945_caseD_0;
    case 1:
      goto switchD_00420945_caseD_1;
    case 2:
      goto switchD_00420945_caseD_2;
    case 3:
      goto switchD_00420945_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00420945_caseD_2;
          case 3:
            goto switchD_00420945_caseD_3;
          }
          goto switchD_00420945_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00420945_caseD_2;
          case 3:
            goto switchD_00420945_caseD_3;
          }
          goto switchD_00420945_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00420945_caseD_2;
          case 3:
            goto switchD_00420945_caseD_3;
          }
          goto switchD_00420945_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00420945_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00420945_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00420945_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00420945_caseD_0:
  return param_1;
}


/*
 * FUN_00420c45 at 00420c45
 * undefined4 * __cdecl FUN_00420c45(LPCSTR param_1, char * param_2, uint param_3, undefined4 * param_4)
 * Address ranges: 00420c45-00420db4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_00420c45(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  
  bVar4 = false;
  bVar3 = false;
  cVar1 = *param_2;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar6 = DAT_0043e46c | 1;
      goto LAB_00420c86;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_0043e46c | 2;
LAB_00420c86:
  bVar2 = true;
LAB_00420c89:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_00424486(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_0043e468 = _DAT_0043e468 + 1;
    param_4[3] = uVar6;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = uVar5;
    return param_4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_00420c89;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_00420c89;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_00420c89;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_00420c89;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_00420c89;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_00420d69;
      uVar5 = uVar5 | 0x8000;
      goto LAB_00420c89;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_00420c89;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_00420d69;
        uVar5 = uVar5 | 0x4000;
        goto LAB_00420c89;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_00420c89;
      }
    }
  }
LAB_00420d69:
  bVar2 = false;
  goto LAB_00420c89;
}


/*
 * FUN_00420db5 at 00420db5
 * undefined4 * __stdcall FUN_00420db5(void)
 * Address ranges: 00420db5-00420e2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * FUN_00420db5(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = 0;
  piVar4 = DAT_0043e7e8;
  if (0 < DAT_0043f800) {
    do {
      if (*piVar4 == 0) {
        pvVar2 = _malloc(0x20);
        DAT_0043e7e8[iVar1] = (int)pvVar2;
        puVar3 = (undefined4 *)DAT_0043e7e8[iVar1];
        if (puVar3 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
LAB_00420e10:
        if (puVar3 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
        puVar3[4] = 0xffffffff;
        puVar3[1] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        *puVar3 = 0;
        puVar3[7] = 0;
        return puVar3;
      }
      if ((*(byte *)(*piVar4 + 0xc) & 0x83) == 0) {
        puVar3 = (undefined4 *)DAT_0043e7e8[iVar1];
        goto LAB_00420e10;
      }
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar1 < DAT_0043f800);
  }
  return (undefined4 *)0x0;
}


/*
 * FUN_00420e2d at 00420e2d
 * LONG __cdecl FUN_00420e2d(int param_1, _EXCEPTION_POINTERS * param_2)
 * Address ranges: 00420e2d-00420f6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LONG __cdecl FUN_00420e2d(int param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = FUN_00420f6e(param_1);
  uVar3 = DAT_0043e330;
  if ((piVar4 == (int *)0x0) || (pcVar1 = (code *)piVar4[2], pcVar1 == (code *)0x0)) {
    LVar5 = UnhandledExceptionFilter(param_2);
  }
  else if (pcVar1 == (code *)0x5) {
    piVar4[2] = 0;
    LVar5 = 1;
  }
  else {
    if (pcVar1 != (code *)0x1) {
      DAT_0043e330 = param_2;
      if (piVar4[1] == 8) {
        if (DAT_004371a8 < DAT_004371ac + DAT_004371a8) {
          iVar6 = (DAT_004371ac + DAT_004371a8) - DAT_004371a8;
          puVar7 = (undefined4 *)(DAT_004371a8 * 0xc + 0x437138);
          do {
            *puVar7 = 0;
            puVar7 = puVar7 + 3;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        uVar2 = DAT_004371b4;
        iVar6 = *piVar4;
        if (iVar6 == -0x3fffff72) {
          DAT_004371b4 = 0x83;
        }
        else if (iVar6 == -0x3fffff70) {
          DAT_004371b4 = 0x81;
        }
        else if (iVar6 == -0x3fffff6f) {
          DAT_004371b4 = 0x84;
        }
        else if (iVar6 == -0x3fffff6d) {
          DAT_004371b4 = 0x85;
        }
        else if (iVar6 == -0x3fffff73) {
          DAT_004371b4 = 0x82;
        }
        else if (iVar6 == -0x3fffff71) {
          DAT_004371b4 = 0x86;
        }
        else if (iVar6 == -0x3fffff6e) {
          DAT_004371b4 = 0x8a;
        }
        (*pcVar1)(8,DAT_004371b4);
        DAT_004371b4 = uVar2;
      }
      else {
        piVar4[2] = 0;
        (*pcVar1)(piVar4[1]);
      }
    }
    LVar5 = -1;
    DAT_0043e330 = (_EXCEPTION_POINTERS *)uVar3;
  }
  return LVar5;
}


/*
 * FUN_00420f6e at 00420f6e
 * int * __cdecl FUN_00420f6e(int param_1)
 * Address ranges: 00420f6e-00420fb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00420f6e(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00437130;
  if (DAT_00437130 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&DAT_00437130 + DAT_004371b0 * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_00437130 + DAT_004371b0 * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


/*
 * FUN_00420fb1 at 00420fb1
 * byte * __stdcall FUN_00420fb1(void)
 * Address ranges: 00420fb1-00421008
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


byte * FUN_00420fb1(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_0043f928 == 0) {
    FUN_00424bb9();
  }
  bVar1 = *DAT_0043f934;
  pbVar4 = DAT_0043f934;
  if (bVar1 == 0x22) {
    while( true ) {
      pbVar3 = pbVar4;
      bVar1 = pbVar3[1];
      pbVar4 = pbVar3 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar2 = FUN_004247b3(bVar1);
      if (iVar2 != 0) {
        pbVar4 = pbVar3 + 2;
      }
    }
    if (*pbVar4 == 0x22) goto LAB_00420fee;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
    }
  }
  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
LAB_00420fee:
  }
  return pbVar4;
}


/*
 * FUN_00421009 at 00421009
 * undefined __stdcall FUN_00421009(void)
 * Address ranges: 00421009-004210c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00421009(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_0043f928 == 0) {
    FUN_00424bb9();
  }
  iVar5 = 0;
  for (puVar6 = DAT_0043e2b4; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_0043e2e8 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_0043e2b4;
  puVar6 = DAT_0043e2b4;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_0041f7a0((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_0041fd93(DAT_0043e2b4);
  DAT_0043e2b4 = (uint *)0x0;
  *puVar3 = 0;
  DAT_0043f924 = 1;
  return;
}


/*
 * FUN_004210c2 at 004210c2
 * undefined __stdcall FUN_004210c2(void)
 * Address ranges: 004210c2-0042115a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004210c2(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_0043f928 == 0) {
    FUN_00424bb9();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_0043e334,0x104);
  _DAT_0043e2f8 = &DAT_0043e334;
  pbVar2 = &DAT_0043e334;
  if (*DAT_0043f934 != 0) {
    pbVar2 = DAT_0043f934;
  }
  FUN_0042115b(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_0042115b(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_0043e2e0 = puVar1;
  _DAT_0043e2dc = local_8 + -1;
  return;
}


/*
 * FUN_0042115b at 0042115b
 * undefined __cdecl FUN_0042115b(byte * param_1, undefined4 * param_2, byte * param_3, int * param_4, int * param_5)
 * Address ranges: 0042115b-0042130e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042115b(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if (((*(byte *)((int)&DAT_0043e6e0 + bVar1 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if ((*(byte *)((int)&DAT_0043e6e0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00421206;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00421206:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar7 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = param_3;
      puVar7 = puVar7 + 1;
      param_2 = puVar7;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar6 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar4 == 0x22) {
        pbVar5 = pbVar4;
        if ((uVar6 & 1) == 0) {
          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {
            bVar3 = false;
            pbVar5 = pbVar4;
          }
          bVar2 = !bVar2;
          puVar7 = param_2;
        }
        uVar6 = uVar6 >> 1;
        pbVar4 = pbVar5;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_0043e6e0 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_0043e6e0 + bVar1 + 1) & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}


/*
 * FUN_0042130f at 0042130f
 * LPSTR __stdcall FUN_0042130f(void)
 * Address ranges: 0042130f-00421440
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LPSTR FUN_0042130f(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR pCVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_0043e438 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_0043e438 = 1;
LAB_00421366:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      local_8 = (LPSTR)0x0;
      if (((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0),
         local_8 = pCVar6, iVar5 == 0)) {
        FUN_0041fd93(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_0043e438 = 2;
  }
  else {
    if (DAT_0043e438 == 1) goto LAB_00421366;
    if (DAT_0043e438 != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    FUN_00420910((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}


/*
 * FUN_00421441 at 00421441
 * undefined __stdcall FUN_00421441(void)
 * Address ranges: 00421441-004215eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00421441(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  byte *pbVar5;
  int iVar6;
  UINT *pUVar7;
  UINT UVar8;
  UINT UVar9;
  uint uVar10;
  _STARTUPINFOA local_44;
  
  puVar2 = _malloc(0x100);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_0043f920 = 0x20;
  DAT_0043f820 = puVar2;
  for (; puVar2 < DAT_0043f820 + 0x40; puVar2 = puVar2 + 2) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_44.lpReserved2;
    pUVar7 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar5 = (byte *)(UVar8 + (int)pUVar7);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    UVar9 = UVar8;
    if ((int)DAT_0043f920 < (int)UVar8) {
      puVar2 = &DAT_0043f824;
      do {
        puVar3 = _malloc(0x100);
        UVar9 = DAT_0043f920;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_0043f920 = DAT_0043f920 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x40; puVar3 = puVar3 + 2) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
        UVar9 = UVar8;
      } while ((int)DAT_0043f920 < (int)UVar8);
    }
    uVar10 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)pbVar5 != (HANDLE)0xffffffff) && ((*pUVar7 & 1) != 0)) &&
           (((*pUVar7 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)pbVar5), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_0043f820)[(int)uVar10 >> 5] + (uVar10 & 0x1f) * 8);
          *puVar2 = *(undefined4 *)pbVar5;
          *(byte *)(puVar2 + 1) = (byte)*pUVar7;
        }
        uVar10 = uVar10 + 1;
        pUVar7 = (UINT *)((int)pUVar7 + 1);
        pbVar5 = pbVar5 + 4;
      } while ((int)uVar10 < (int)UVar9);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_0043f820 + iVar6 * 2;
    if (DAT_0043f820[iVar6 * 2] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_004215d2;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_004215d2:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_0043f920);
      return;
    }
  } while( true );
}


/*
 * FUN_004215ec at 004215ec
 * undefined4 __cdecl FUN_004215ec(int param_1)
 * Address ranges: 004215ec-00421627
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004215ec(int param_1)

{
  int iVar1;
  
  DAT_0043f81c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_0043f81c != (HANDLE)0x0) {
    iVar1 = FUN_00422b27();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_0043f81c);
  }
  return 0;
}


/*
 * FUN_00421630 at 00421630
 * undefined FUN_00421630(void)
 * Address ranges: 00421630-004216ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00421630(int param_1,PVOID param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar4 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if ((*(uint *)(param_1 + 4) & 6) == 0) {
    iStack_c = param_1;
    uStack_8 = param_3;
    *(int **)((int)param_2 + -4) = &iStack_c;
    iVar1 = *(int *)((int)param_2 + 8);
    for (iVar3 = *(int *)((int)param_2 + 0xc); iVar3 != -1; iVar3 = *(int *)(iVar1 + iVar3 * 0xc)) {
      if (*(int *)(iVar1 + 4 + iVar3 * 0xc) != 0) {
        iVar1 = (**(code **)(iVar1 + 4 + iVar3 * 0xc))(puVar2,iVar3,puVar4);
        param_2 = *(PVOID *)(puVar2 + 0xc);
        if (iVar1 != 0) {
          if (iVar1 < 0) {
            return 0;
          }
          iVar1 = *(int *)((int)param_2 + 8);
          __global_unwind2(param_2);
          puVar2 = (undefined1 *)((int)param_2 + 0x10);
          __local_unwind2((int)param_2,iVar3);
          FUN_00420346();
          *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(iVar1 + extraout_ECX * 4);
          (**(code **)(iVar1 + 8 + extraout_ECX * 4))();
        }
      }
      iVar1 = *(int *)((int)param_2 + 8);
    }
  }
  else {
    __local_unwind2((int)param_2,-1);
  }
  return 1;
}


/*
 * FUN_004216ed at 004216ed
 * undefined __stdcall FUN_004216ed(int param_1)
 * Address ranges: 004216ed-00421707
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004216ed(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


/*
 * FUN_00421708 at 00421708
 * undefined __stdcall FUN_00421708(void)
 * Address ranges: 00421708-00421740
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00421708(void)

{
  if ((DAT_0043e2bc == 1) || ((DAT_0043e2bc == 0 && (DAT_004370e4 == 1)))) {
    FUN_00421741(0xfc);
    if (DAT_0043e43c != (code *)0x0) {
      (*DAT_0043e43c)();
    }
    FUN_00421741(0xff);
  }
  return;
}


/*
 * FUN_00421741 at 00421741
 * undefined __cdecl FUN_00421741(DWORD param_1)
 * Address ranges: 00421741-00421893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00421741(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
  iVar5 = 0;
  pDVar2 = &DAT_004371c8;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x437258);
  if (param_1 == (&DAT_004371c8)[iVar5 * 2]) {
    if ((DAT_0043e2bc == 1) || ((DAT_0043e2bc == 0 && (DAT_004370e4 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x4371cc);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_0041f7a0(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_0041f7a0(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_0041f7b0(local_a4,_Dest);
      FUN_0041f7b0(local_a4,(uint *)&DAT_0042a2a8);
      FUN_0041f7b0(local_a4,*(uint **)(iVar5 * 8 + 0x4371cc));
      auStackY_1e3._3_4_ = 0x421865;
      FUN_00424bd5(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


/*
 * FUN_00421894 at 00421894
 * undefined4 __cdecl FUN_00421894(undefined4 * param_1)
 * Address ranges: 00421894-00421920
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00421894(undefined4 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  void *pvVar4;
  
  bVar2 = FUN_00424c5e(param_1[4]);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  if (param_1 == (undefined4 *)&DAT_00437630) {
    iVar3 = 0;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_00437650) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_0043e468 = _DAT_0043e468 + 1;
  if ((*(ushort *)(param_1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_0043e440)[iVar3] == 0) {
    pvVar4 = _malloc(0x1000);
    (&DAT_0043e440)[iVar3] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      param_1[2] = param_1 + 5;
      *param_1 = param_1 + 5;
      param_1[6] = 2;
      param_1[1] = 2;
      goto LAB_00421910;
    }
  }
  uVar1 = (&DAT_0043e440)[iVar3];
  param_1[6] = 0x1000;
  param_1[2] = uVar1;
  *param_1 = uVar1;
  param_1[1] = 0x1000;
LAB_00421910:
  *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x1102;
  return 1;
}


/*
 * FUN_00421921 at 00421921
 * undefined __cdecl FUN_00421921(int param_1, int * param_2)
 * Address ranges: 00421921-0042195d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00421921(int param_1,int *param_2)

{
  if (param_1 == 0) {
    if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
      FUN_0042056d(param_2);
    }
  }
  else if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
    FUN_0042056d(param_2);
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
    return;
  }
  return;
}


/*
 * FUN_0042195e at 0042195e
 * int __cdecl FUN_0042195e(int * param_1, byte * param_2, undefined4 * param_3)
 * Address ranges: 0042195e-0042207e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0042195e(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  uint uVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined1 local_24c [511];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  undefined1 *local_10;
  WCHAR *local_c;
  uint local_8;
  
  local_34 = 0;
  bVar9 = *param_2;
  local_10 = (undefined1 *)0x0;
  local_18 = 0;
  pbVar1 = param_2;
  do {
    if ((bVar9 == 0) || (param_2 = pbVar1 + 1, local_18 < 0)) {
      return local_18;
    }
    if (((char)bVar9 < ' ') || ('x' < (char)bVar9)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"Runtime Error!\n\nProgram: "[(char)bVar9 + 0x18] & 0xf;
    }
    local_34 = (int)(char)(&DAT_0042a2e4)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_004219cc_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_00437260[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_0042209f((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = pbVar1 + 2;
      }
      FUN_0042209f((int)(char)bVar9,param_1,&local_18);
      break;
    case 1:
      local_14 = -1;
      local_38 = 0;
      local_2c = 0;
      local_24 = 0;
      local_20 = 0;
      local_8 = 0;
      local_28 = 0;
      break;
    case 2:
      if (bVar9 == 0x20) {
        local_8 = local_8 | 2;
      }
      else if (bVar9 == 0x23) {
        local_8 = local_8 | 0x80;
      }
      else if (bVar9 == 0x2b) {
        local_8 = local_8 | 1;
      }
      else if (bVar9 == 0x2d) {
        local_8 = local_8 | 4;
      }
      else if (bVar9 == 0x30) {
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar9 == 0x2a) {
        local_24 = FUN_0042213d((int *)&param_3);
        if (local_24 < 0) {
          local_8 = local_8 | 4;
          local_24 = -local_24;
        }
      }
      else {
        local_24 = (char)bVar9 + -0x30 + local_24 * 10;
      }
      break;
    case 4:
      local_14 = 0;
      break;
    case 5:
      if (bVar9 == 0x2a) {
        local_14 = FUN_0042213d((int *)&param_3);
        if (local_14 < 0) {
          local_14 = -1;
        }
      }
      else {
        local_14 = (char)bVar9 + -0x30 + local_14 * 10;
      }
      break;
    case 6:
      if (bVar9 == 0x49) {
        if ((*param_2 != 0x36) || (pbVar1[2] != 0x34)) {
          local_34 = 0;
          goto switchD_004219cc_caseD_0;
        }
        param_2 = pbVar1 + 3;
        local_8 = local_8 | 0x8000;
      }
      else if (bVar9 == 0x68) {
        local_8 = local_8 | 0x20;
      }
      else if (bVar9 == 0x6c) {
        local_8 = local_8 | 0x10;
      }
      else if (bVar9 == 0x77) {
        local_8 = local_8 | 0x800;
      }
      break;
    case 7:
      pWVar4 = local_c;
      if ((char)bVar9 < 'h') {
        if ((char)bVar9 < 'e') {
          if ((char)bVar9 < 'Y') {
            if (bVar9 == 0x58) {
LAB_00421ddd:
              local_30 = 7;
LAB_00421de4:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_00421e4e;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_00421b8b;
                }
                goto LAB_00421f68;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_00421bec;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_00421c19:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_0042213d((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar5 = FUN_0042215a((int *)&param_3);
              local_10 = (undefined1 *)FUN_00424c84(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_0042213d((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_DAT_00437258;
              pWVar4 = (WCHAR *)PTR_DAT_00437258;
              goto LAB_00421d5e;
            }
            if ((local_8 & 0x800) == 0) {
              local_28 = 0;
              local_10 = (undefined1 *)(int)*psVar6;
            }
            else {
              local_28 = 1;
              local_10 = (undefined1 *)((uint)(int)*psVar6 >> 1);
            }
          }
          else {
            if (bVar9 == 99) goto LAB_00421c19;
            if (bVar9 == 100) goto LAB_00421e43;
          }
        }
        else {
LAB_00421bec:
          local_8 = local_8 | 0x40;
          pWVar4 = (WCHAR *)local_24c;
          if (local_14 < 0) {
            local_14 = 6;
          }
          else if ((local_14 == 0) && (bVar9 == 0x67)) {
            local_14 = 1;
          }
          local_4c = *param_3;
          local_48 = param_3[1];
          param_3 = param_3 + 2;
          local_c = pWVar4;
          (*(code *)PTR_FUN_00437478)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR_FUN_00437484)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR_FUN_0043747c)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_00421d5e:
          local_10 = (undefined1 *)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_00421e43:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_0042213d((int *)&param_3);
            if ((local_8 & 0x20) == 0) {
              *piVar7 = local_18;
            }
            else {
              *(undefined2 *)piVar7 = (undefined2)local_18;
            }
            local_2c = 1;
            break;
          }
          if (bVar9 == 0x6f) {
            local_10 = (undefined1 *)0x8;
            if ((local_8 & 0x80) != 0) {
              local_8 = local_8 | 0x200;
            }
            goto LAB_00421e4e;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_00421ddd;
          }
          if (bVar9 == 0x73) {
LAB_00421b8b:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_0042213d((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_00437258;
                pWVar4 = (WCHAR *)PTR_DAT_00437258;
              }
              for (; (iVar10 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1))
              {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_0043725c;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_00421f68;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_00421f68;
            local_30 = 0x27;
            goto LAB_00421de4;
          }
        }
        local_10 = (undefined1 *)0xa;
LAB_00421e4e:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_0042213d((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_00421ea1;
            }
            uVar2 = FUN_0042213d((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_0042213d((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_0042213d((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_0042214a((int *)&param_3);
        }
LAB_00421ea1:
        iVar10 = (int)(uVar13 >> 0x20);
        if ((((local_8 & 0x40) != 0) && (iVar10 == 0 || (longlong)uVar13 < 0)) &&
           ((longlong)uVar13 < 0)) {
          local_8 = local_8 | 0x100;
          uVar13 = CONCAT44(-(iVar10 + (uint)((int)uVar13 != 0)),-(int)uVar13);
        }
        uVar2 = (uint)(uVar13 >> 0x20);
        uVar15 = uVar13 & 0xffffffff;
        if ((local_8 & 0x8000) == 0) {
          uVar2 = 0;
        }
        if (local_14 < 0) {
          local_14 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((int)uVar13 == 0 && uVar2 == 0) {
          local_20 = 0;
        }
        local_c = (WCHAR *)&local_4d;
        while( true ) {
          uVar11 = (uint)uVar15;
          iVar10 = local_14 + -1;
          if ((local_14 < 1) && (uVar11 == 0 && uVar2 == 0)) break;
          local_40 = (int)local_10 >> 0x1f;
          local_44 = (uint)local_10;
          local_14 = iVar10;
          uVar14 = __aullrem(uVar11,uVar2,(uint)local_10,local_40);
          iVar10 = (int)uVar14 + 0x30;
          uVar15 = __aulldiv(uVar11,uVar2,local_44,local_40);
          uVar2 = (uint)(uVar15 >> 0x20);
          if (0x39 < iVar10) {
            iVar10 = iVar10 + local_30;
          }
          pWVar4 = (WCHAR *)((int)local_c + -1);
          *(char *)local_c = (char)iVar10;
          local_c = pWVar4;
        }
        iVar8 = -(int)local_c;
        local_10 = &local_4d + iVar8;
        pWVar4 = (WCHAR *)((int)local_c + 1);
        local_14 = iVar10;
        if (((local_8 & 0x200) != 0) &&
           ((*(char *)pWVar4 != '0' || (local_10 == (undefined1 *)0x0)))) {
          *(char *)local_c = '0';
          local_10 = (undefined1 *)((int)&local_4c + iVar8);
          pWVar4 = local_c;
        }
      }
LAB_00421f68:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_00421fa0;
              local_1a = ' ';
            }
            else {
              local_1a = '+';
            }
          }
          else {
            local_1a = '-';
          }
          local_20 = 1;
        }
LAB_00421fa0:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_004220d4(0x20,iVar10,param_1,&local_18);
        }
        FUN_00422105(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_004220d4(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (puVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_00422105((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            puVar12 = puVar12 + -1;
            iVar8 = FUN_00424c84(local_3c,*pWVar4);
            if (iVar8 < 1) break;
            FUN_00422105(local_3c,iVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (puVar12 != (undefined1 *)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_004220d4(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    pbVar1 = param_2;
  } while( true );
}


/*
 * FUN_0042209f at 0042209f
 * undefined __cdecl FUN_0042209f(uint param_1, int * param_2, int * param_3)
 * Address ranges: 0042209f-004220d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042209f(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_00422168(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    uVar2 = param_1 & 0xff;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}


/*
 * FUN_004220d4 at 004220d4
 * undefined __cdecl FUN_004220d4(uint param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 004220d4-00422104
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004220d4(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_0042209f(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


/*
 * FUN_00422105 at 00422105
 * undefined __cdecl FUN_00422105(char * param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 00422105-0042213c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00422105(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_0042209f((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


/*
 * FUN_0042213d at 0042213d
 * undefined4 __cdecl FUN_0042213d(int * param_1)
 * Address ranges: 0042213d-00422149
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0042213d(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}


/*
 * FUN_0042214a at 0042214a
 * undefined8 __cdecl FUN_0042214a(int * param_1)
 * Address ranges: 0042214a-00422159
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __cdecl FUN_0042214a(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}


/*
 * FUN_0042215a at 0042215a
 * undefined4 __cdecl FUN_0042215a(int * param_1)
 * Address ranges: 0042215a-00422167
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0042215a(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}


/*
 * FUN_00422168 at 00422168
 * uint __cdecl FUN_00422168(uint param_1, int * param_2)
 * Address ranges: 00422168-0042227c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_00422168(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  undefined3 extraout_var;
  undefined *puVar6;
  int *piVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_00422271:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_00422271;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_00437630 && (piVar4 != (int *)&DAT_00437650)) ||
        (bVar5 = FUN_00424c5e(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_00424442(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_00423666(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_004371b8;
        }
        else {
          puVar6 = (undefined *)((&DAT_0043f820)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_00422935(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_00423666(uVar2,pcVar3,(uint)piVar7);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    if (param_2 == piVar7) {
      return param_1 & 0xff;
    }
    piVar4[3] = piVar4[3] | 0x20;
  }
  return 0xffffffff;
}


/*
 * FUN_0042227d at 0042227d
 * int __cdecl FUN_0042227d(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
 * Address ranges: 0042227d-0042233e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
FUN_0042227d(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    iVar2 = -1;
  }
  else {
    iVar4 = *(int *)(&DAT_00437a74 + param_2 * 4) + param_3;
    if (((uVar3 & 3) == 0) && (2 < param_2)) {
      iVar4 = iVar4 + 1;
    }
    FUN_00424dd5();
    local_20 = param_4;
    local_18 = param_2 + -1;
    iVar2 = ((param_4 + (uVar3 * 0x16d + iVar4 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c + param_5)
            * 0x3c + DAT_00437990 + 0x7c558180 + param_6;
    if ((param_7 == 1) ||
       (((param_7 == -1 && (DAT_00437994 != 0)) &&
        (local_14 = uVar3, local_c = iVar4, bVar1 = FUN_00425048(local_28),
        CONCAT31(extraout_var,bVar1) != 0)))) {
      iVar2 = iVar2 + _DAT_00437998;
    }
  }
  return iVar2;
}


/*
 * FUN_00422350 at 00422350
 * uint * __cdecl FUN_00422350(uint * param_1, char param_2)
 * Address ranges: 00422350-0042240b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_00422350(uint *param_1,char param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)param_1 & 3) != 0) {
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    param_1 = (uint *)((int)param_1 + 1);
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}


/*
 * FUN_0042240c at 0042240c
 * uint __thiscall FUN_0042240c(void * this, int param_1, uint param_2)
 * Address ranges: 0042240c-00422480
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __thiscall FUN_0042240c(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_00437260 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_00437260[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_00425334(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}


/*
 * FUN_00422481 at 00422481
 * undefined __fastcall FUN_00422481(void * param_1)
 * Address ranges: 00422481-00422492
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00422481(void *param_1)

{
  FUN_004254b2(param_1,0x10000,0x30000);
  return;
}


/*
 * FUN_00422493 at 00422493
 * undefined4 __stdcall FUN_00422493(void)
 * Address ranges: 00422493-004224d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Removing unreachable block (ram,0x004224c8) */

undefined4 FUN_00422493(void)

{
  return 0;
}


/*
 * FUN_004224d1 at 004224d1
 * undefined __stdcall FUN_004224d1(void)
 * Address ranges: 004224d1-004224f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004224d1(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  FUN_00422493();
  return;
}


/*
 * FUN_004224fa at 004224fa
 * undefined __thiscall FUN_004224fa(void * this, char * param_1)
 * Address ranges: 004224fa-00422553
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_004224fa(void *this,char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this_00;
  uint uVar3;
  undefined *puVar4;
  
  this_00 = (undefined *)(int)*param_1;
  uVar3 = FUN_004255e3(this,(uint)this_00);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_0043746c < 2) {
        uVar3 = (byte)PTR_DAT_00437260[*param_1 * 2] & 4;
        this_00 = PTR_DAT_00437260;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_0042240c(this_00,(int)*param_1,4);
        this_00 = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_00437470;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}


/*
 * __fassign at 004225ba
 * void __cdecl __fassign(int flag, char * argument, char * number)
 * Address ranges: 004225ba-004225f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __fassign  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;
  
  if (flag != 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    FUN_00425a40(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_00425a6d(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}


/*
 * FUN_004225f8 at 004225f8
 * undefined1 * __cdecl FUN_004225f8(undefined4 param_1, undefined1 * param_2, int param_3, int param_4)
 * Address ranges: 004225f8-004226fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 * __cdecl FUN_004225f8(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint *puVar4;
  int iVar5;
  
  piVar1 = DAT_0043e448;
  if (DAT_0043e44c == '\0') {
    piVar1 = (int *)FUN_00425b11();
    FUN_00425a9a(param_2 + (uint)(0 < param_3) + (uint)(*piVar1 == 0x2d),param_3 + 1,(int)piVar1);
  }
  else {
    FUN_00422910(param_2 + (*DAT_0043e448 == 0x2d),(uint)(0 < param_3));
  }
  puVar2 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = 0x2d;
    puVar2 = param_2 + 1;
  }
  puVar3 = puVar2;
  if (0 < param_3) {
    puVar3 = puVar2 + 1;
    *puVar2 = puVar2[1];
    *puVar3 = DAT_00437470;
  }
  puVar4 = FUN_0041f7a0((uint *)(puVar3 + param_3 + (uint)(DAT_0043e44c == '\0')),(uint *)"e+000");
  if (param_4 != 0) {
    *(undefined1 *)puVar4 = 0x45;
  }
  if (*(char *)piVar1[3] != '0') {
    iVar5 = piVar1[1] + -1;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
      *(undefined1 *)((int)puVar4 + 1) = 0x2d;
    }
    if (99 < iVar5) {
      *(char *)((int)puVar4 + 2) = *(char *)((int)puVar4 + 2) + (char)(iVar5 / 100);
      iVar5 = iVar5 % 100;
    }
    if (9 < iVar5) {
      *(char *)((int)puVar4 + 3) = *(char *)((int)puVar4 + 3) + (char)(iVar5 / 10);
      iVar5 = iVar5 % 10;
    }
    *(char *)(puVar4 + 1) = (char)puVar4[1] + (char)iVar5;
  }
  return param_2;
}


/*
 * FUN_004226fc at 004226fc
 * char * __cdecl FUN_004226fc(undefined4 param_1, char * param_2, size_t param_3)
 * Address ranges: 004226fc-004227d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_004226fc(undefined4 param_1,char *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  piVar1 = DAT_0043e448;
  if (DAT_0043e44c == '\0') {
    piVar1 = (int *)FUN_00425b11();
    FUN_00425a9a(param_2 + (*piVar1 == 0x2d),piVar1[1] + param_3,(int)piVar1);
  }
  else if (DAT_0043e450 == param_3) {
    iVar2 = (*DAT_0043e448 == 0x2d) + DAT_0043e450;
    param_2[iVar2] = '0';
    (param_2 + iVar2)[1] = '\0';
  }
  pcVar3 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = '-';
    pcVar3 = param_2 + 1;
  }
  if (piVar1[1] < 1) {
    FUN_00422910(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + piVar1[1];
  }
  if (0 < (int)param_3) {
    FUN_00422910(pcVar3,1);
    *pcVar3 = DAT_00437470;
    iVar2 = piVar1[1];
    if (iVar2 < 0) {
      if ((DAT_0043e44c != '\0') || (-iVar2 <= (int)param_3)) {
        param_3 = -iVar2;
      }
      FUN_00422910(pcVar3 + 1,param_3);
      _memset(pcVar3 + 1,0x30,param_3);
    }
  }
  return param_2;
}


/*
 * FUN_004227da at 004227da
 * undefined __cdecl FUN_004227da(undefined4 param_1, char * param_2, size_t param_3, int param_4)
 * Address ranges: 004227da-00422874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004227da(undefined4 param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  DAT_0043e448 = (int *)FUN_00425b11();
  DAT_0043e450 = DAT_0043e448[1] + -1;
  iVar1 = *DAT_0043e448;
  FUN_00425a9a(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_0043e448);
  DAT_0043e454 = DAT_0043e450 < DAT_0043e448[1] + -1;
  DAT_0043e450 = DAT_0043e448[1] + -1;
  if ((DAT_0043e450 < -4) || ((int)param_3 <= DAT_0043e450)) {
    FUN_00422875(param_1,param_2,param_3,param_4);
  }
  else {
    pcVar2 = param_2 + (iVar1 == 0x2d);
    if ((bool)DAT_0043e454) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_0042289c(param_1,param_2,param_3);
  }
  return;
}


/*
 * FUN_00422875 at 00422875
 * undefined __cdecl FUN_00422875(undefined4 param_1, undefined1 * param_2, int param_3, int param_4)
 * Address ranges: 00422875-0042289b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00422875(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)

{
  DAT_0043e44c = 1;
  FUN_004225f8(param_1,param_2,param_3,param_4);
  DAT_0043e44c = 0;
  return;
}


/*
 * FUN_0042289c at 0042289c
 * undefined __cdecl FUN_0042289c(undefined4 param_1, char * param_2, size_t param_3)
 * Address ranges: 0042289c-004228be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042289c(undefined4 param_1,char *param_2,size_t param_3)

{
  DAT_0043e44c = 1;
  FUN_004226fc(param_1,param_2,param_3);
  DAT_0043e44c = 0;
  return;
}


/*
 * __cfltcvt at 004228bf
 * errno_t __cdecl __cfltcvt(double * arg, char * buffer, size_t sizeInBytes, int format, int precision, int caps)
 * Address ranges: 004228bf-0042290f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __cfltcvt  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_004225f8(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_004226fc(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_004227da(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}


/*
 * FUN_00422910 at 00422910
 * undefined __cdecl FUN_00422910(char * param_1, int param_2)
 * Address ranges: 00422910-00422934
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00422910(char *param_1,int param_2)

{
  size_t sVar1;
  
  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_00425c30((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}


/*
 * FUN_00422935 at 00422935
 * DWORD __cdecl FUN_00422935(uint param_1, LONG param_2, DWORD param_3)
 * Address ranges: 00422935-004229ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_00422935(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 < DAT_0043f920) {
    iVar4 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      hFile = (HANDLE)FUN_004242f5(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_0043e2c0 = 9;
        return 0xffffffff;
      }
      DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
      if (DVar2 == 0xffffffff) {
        uVar3 = GetLastError();
      }
      else {
        uVar3 = 0;
      }
      if (uVar3 != 0) {
        FUN_00424108(uVar3);
        return 0xffffffff;
      }
      pbVar1 = (byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + iVar4);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar2;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}


/*
 * FUN_004229cf at 004229cf
 * int __cdecl FUN_004229cf(char * param_1)
 * Address ranges: 004229cf-00422b26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_004229cf(char *param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char *pcVar4;
  DWORD DVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int local_c;
  DWORD local_8;
  
  pcVar7 = param_1;
  uVar1 = *(uint *)(param_1 + 0x10);
  if (*(int *)(param_1 + 4) < 0) {
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  local_8 = FUN_00422935(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_00422a59:
    local_c = -1;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xc);
    if ((uVar2 & 0x108) == 0) {
      return local_8 - *(int *)(param_1 + 4);
    }
    pcVar4 = *(char **)param_1;
    pcVar6 = *(char **)(param_1 + 8);
    local_c = (int)pcVar4 - (int)pcVar6;
    if ((uVar2 & 3) == 0) {
      if ((uVar2 & 0x80) == 0) {
        _DAT_0043e2c0 = 0x16;
        goto LAB_00422a59;
      }
    }
    else {
      pcVar8 = pcVar6;
      if ((*(byte *)((&DAT_0043f820)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 8) & 0x80) != 0) {
        for (; pcVar8 < pcVar4; pcVar8 = pcVar8 + 1) {
          if (*pcVar8 == '\n') {
            local_c = local_c + 1;
          }
        }
      }
    }
    if (local_8 != 0) {
      if ((param_1[0xc] & 1U) != 0) {
        if (*(int *)(param_1 + 4) == 0) {
          local_c = 0;
        }
        else {
          pcVar4 = pcVar4 + (*(int *)(param_1 + 4) - (int)pcVar6);
          iVar9 = (uVar1 & 0x1f) * 8;
          if ((*(byte *)(iVar9 + 4 + (&DAT_0043f820)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar5 = FUN_00422935(uVar1,0,2);
            if (DVar5 == local_8) {
              pcVar6 = *(char **)(param_1 + 8);
              pcVar8 = pcVar4 + (int)pcVar6;
              param_1 = pcVar4;
              for (; pcVar6 < pcVar8; pcVar6 = pcVar6 + 1) {
                if (*pcVar6 == '\n') {
                  param_1 = param_1 + 1;
                }
              }
              bVar3 = pcVar7[0xd] & 0x20;
            }
            else {
              FUN_00422935(uVar1,local_8,0);
              pcVar7 = (char *)0x200;
              if ((((char *)0x200 < pcVar4) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar7 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar9 + 4 + (&DAT_0043f820)[(int)uVar1 >> 5]) & 4;
              param_1 = pcVar7;
            }
            pcVar4 = param_1;
            if (bVar3 != 0) {
              pcVar4 = param_1 + 1;
            }
          }
          param_1 = pcVar4;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}


/*
 * FUN_00422b27 at 00422b27
 * undefined4 __stdcall FUN_00422b27(void)
 * Address ranges: 00422b27-00422b64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00422b27(void)

{
  DAT_0043f818 = HeapAlloc(DAT_0043f81c,0,0x140);
  if (DAT_0043f818 == (LPVOID)0x0) {
    return 0;
  }
  DAT_0043f810 = 0;
  DAT_0043f814 = 0;
  DAT_0043f80c = DAT_0043f818;
  DAT_0043f804 = 0x10;
  return 1;
}


/*
 * FUN_00422b65 at 00422b65
 * uint __cdecl FUN_00422b65(int param_1)
 * Address ranges: 00422b65-00422b8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_00422b65(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_0043f818;
  while( true ) {
    if (DAT_0043f818 + DAT_0043f814 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


/*
 * FUN_00422b90 at 00422b90
 * undefined __cdecl FUN_00422b90(uint * param_1, uint param_2)
 * Address ranges: 00422b90-00422eba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00422b90(uint *param_1,uint param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_10;
  
  uVar5 = param_1[4];
  iVar6 = *(int *)(param_2 - 4);
  piVar9 = (int *)(param_2 - 4);
  uVar10 = param_2 - param_1[3] >> 0xf;
  uVar7 = *(uint *)(param_2 - 8);
  local_10 = iVar6 + -1;
  piVar3 = (int *)(uVar10 * 0x204 + 0x144 + uVar5);
  uVar12 = *(uint *)(local_10 + (int)piVar9);
  if ((uVar12 & 1) == 0) {
    param_2 = ((int)uVar12 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    if (*(int *)(iVar6 + 3 + (int)piVar9) == *(int *)(iVar6 + 7 + (int)piVar9)) {
      if (param_2 < 0x20) {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 7 + (int)piVar9) + 4) =
         *(undefined4 *)(iVar6 + 3 + (int)piVar9);
    local_10 = local_10 + uVar12;
    *(undefined4 *)(*(int *)(iVar6 + 3 + (int)piVar9) + 8) =
         *(undefined4 *)(iVar6 + 7 + (int)piVar9);
  }
  uVar12 = (local_10 >> 4) - 1;
  if (0x3f < uVar12) {
    uVar12 = 0x3f;
  }
  if ((uVar7 & 1) == 0) {
    piVar9 = (int *)((int)piVar9 - uVar7);
    param_2 = ((int)uVar7 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    local_10 = local_10 + uVar7;
    uVar12 = (local_10 >> 4) - 1;
    if (0x3f < uVar12) {
      uVar12 = 0x3f;
    }
    if (param_2 != uVar12) {
      if (piVar9[1] == piVar9[2]) {
        if (param_2 < 0x20) {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(int *)(piVar9[2] + 4) = piVar9[1];
      *(int *)(piVar9[1] + 8) = piVar9[2];
    }
  }
  if (((uVar7 & 1) != 0) || (param_2 != uVar12)) {
    piVar9[1] = piVar3[uVar12 * 2 + 1];
    piVar9[2] = (int)(piVar3 + uVar12 * 2);
    (piVar3 + uVar12 * 2)[1] = (int)piVar9;
    *(int **)(piVar9[1] + 8) = piVar9;
    if (piVar9[1] == piVar9[2]) {
      cVar4 = *(char *)(uVar12 + 4 + uVar5);
      *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar12;
      if (uVar12 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  *piVar9 = local_10;
  *(int *)(local_10 + -4 + (int)piVar9) = local_10;
  *piVar3 = *piVar3 + -1;
  uVar5 = DAT_0043f808;
  puVar2 = DAT_0043f810;
  if ((*piVar3 == 0) && (uVar5 = uVar10, puVar2 = param_1, DAT_0043f810 != (uint *)0x0)) {
    VirtualFree((LPVOID)(DAT_0043f808 * 0x8000 + DAT_0043f810[3]),0x8000,0x4000);
    DAT_0043f810[2] = DAT_0043f810[2] | 0x80000000U >> ((byte)DAT_0043f808 & 0x1f);
    *(undefined4 *)(DAT_0043f810[4] + 0xc4 + DAT_0043f808 * 4) = 0;
    *(char *)(DAT_0043f810[4] + 0x43) = *(char *)(DAT_0043f810[4] + 0x43) + -1;
    if (*(char *)(DAT_0043f810[4] + 0x43) == '\0') {
      DAT_0043f810[1] = DAT_0043f810[1] & 0xfffffffe;
    }
    puVar2 = param_1;
    if (DAT_0043f810[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_0043f810[3],0,0x8000);
      HeapFree(DAT_0043f81c,0,(LPVOID)DAT_0043f810[4]);
      FUN_00425c30(DAT_0043f810,DAT_0043f810 + 5,
                   (DAT_0043f814 * 0x14 - (int)DAT_0043f810) + -0x14 + DAT_0043f818);
      DAT_0043f814 = DAT_0043f814 + -1;
      if (DAT_0043f810 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_0043f80c = DAT_0043f818;
      puVar2 = param_1;
    }
  }
  DAT_0043f810 = puVar2;
  DAT_0043f808 = uVar5;
  return;
}


/*
 * FUN_00422ebb at 00422ebb
 * int * __cdecl FUN_00422ebb(uint * param_1)
 * Address ranges: 00422ebb-004231c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00422ebb(uint *param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar8 = DAT_0043f818 + DAT_0043f814 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_0043f80c;
  if (iVar7 < 0x20) {
    local_10 = 0xffffffff >> (bVar5 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> (bVar5 - 0x20 & 0x1f);
    local_10 = 0;
  }
  for (; (param_1 < puVar8 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  puVar11 = DAT_0043f818;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_0043f80c && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_0043f80c) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_0043f818;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_0043f80c && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_0043f80c) && (param_1 = FUN_004231c4(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_00423275((int)param_1);
      *(int *)param_1[4] = iVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar4 = (int *)param_1[4];
  local_8 = *piVar4;
  if ((local_8 == -1) ||
     ((piVar4[local_8 + 0x31] & local_c) == 0 && (piVar4[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    puVar8 = (uint *)(piVar4 + 0x11);
    if ((piVar4[0x31] & local_c) == 0 && (piVar4[0x11] & local_10) == 0) {
      do {
        puVar11 = puVar8 + 0x21;
        local_8 = local_8 + 1;
        puVar8 = puVar8 + 1;
      } while ((*puVar11 & local_c) == 0 && (local_10 & *puVar8) == 0);
    }
  }
  iVar7 = 0;
  piVar2 = piVar4 + local_8 * 0x81 + 0x51;
  local_10 = piVar4[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = piVar4[local_8 + 0x31] & local_c;
    iVar7 = 0x20;
  }
  for (; -1 < (int)local_10; local_10 = local_10 << 1) {
    iVar7 = iVar7 + 1;
  }
  piVar10 = (int *)piVar2[iVar7 * 2 + 1];
  iVar9 = *piVar10 - uVar6;
  iVar14 = (iVar9 >> 4) + -1;
  if (0x3f < iVar14) {
    iVar14 = 0x3f;
  }
  DAT_0043f80c = param_1;
  if (iVar14 != iVar7) {
    if (piVar10[1] == piVar10[2]) {
      if (iVar7 < 0x20) {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 & 0x1f));
        piVar4[local_8 + 0x11] = uVar13 & piVar4[local_8 + 0x11];
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar13;
        }
      }
      else {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 - 0x20 & 0x1f));
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar13;
        }
      }
    }
    *(int *)(piVar10[2] + 4) = piVar10[1];
    *(int *)(piVar10[1] + 8) = piVar10[2];
    if (iVar9 == 0) goto LAB_00423181;
    piVar10[1] = piVar2[iVar14 * 2 + 1];
    piVar10[2] = (int)(piVar2 + iVar14 * 2);
    (piVar2 + iVar14 * 2)[1] = (int)piVar10;
    *(int **)(piVar10[1] + 8) = piVar10;
    if (piVar10[1] == piVar10[2]) {
      cVar3 = *(char *)(iVar14 + 4 + (int)piVar4);
      bVar5 = (byte)iVar14;
      if (iVar14 < 0x20) {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar5 & 0x1f);
        }
        piVar4[local_8 + 0x11] = piVar4[local_8 + 0x11] | 0x80000000U >> (bVar5 & 0x1f);
      }
      else {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
        }
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar9 != 0) {
    *piVar10 = iVar9;
    *(int *)(iVar9 + -4 + (int)piVar10) = iVar9;
  }
LAB_00423181:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_0043f810)) && (local_8 == DAT_0043f808)) {
    DAT_0043f810 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}


/*
 * FUN_004231c4 at 004231c4
 * undefined4 * __stdcall FUN_004231c4(void)
 * Address ranges: 004231c4-00423274
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * FUN_004231c4(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_0043f814 == DAT_0043f804) {
    pvVar2 = HeapReAlloc(DAT_0043f81c,0,DAT_0043f818,(DAT_0043f804 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_0043f804 = DAT_0043f804 + 0x10;
    DAT_0043f818 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_0043f818 + DAT_0043f814 * 0x14);
  pvVar2 = HeapAlloc(DAT_0043f81c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_0043f814 = DAT_0043f814 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_0043f81c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


/*
 * FUN_00423275 at 00423275
 * int __cdecl FUN_00423275(int param_1)
 * Address ranges: 00423275-0042336f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00423275(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *lpAddress;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar9 = 0;
  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {
    iVar9 = iVar9 + 1;
  }
  iVar8 = 0x3f;
  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;
  iVar5 = iVar4;
  do {
    *(int *)(iVar5 + 8) = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    iVar5 = iVar5 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    iVar9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      piVar7 = lpAddress + 4;
      do {
        piVar7[-2] = -1;
        piVar7[0x3fb] = -1;
        piVar7[-1] = 0xff0;
        *piVar7 = (int)(piVar7 + 0x3ff);
        piVar7[1] = (int)(piVar7 + -0x401);
        piVar7[0x3fa] = 0xff0;
        piVar1 = piVar7 + 0x3fc;
        piVar7 = piVar7 + 0x400;
      } while (piVar1 <= lpAddress + 0x1c00);
    }
    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = iVar4 + 0x1f8;
    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = iVar4 + 0x1f8;
    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;
    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;
    cVar2 = *(char *)(iVar3 + 0x43);
    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));
  }
  return iVar9;
}


/*
 * FUN_00423370 at 00423370
 * undefined4 __cdecl FUN_00423370(uint * param_1, int param_2, int param_3)
 * Address ranges: 00423370-00423665
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00423370(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;
  
  uVar5 = param_1[4];
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar3 = uVar10 * 0x204 + 0x144 + uVar5;
  iVar6 = *(int *)(param_2 + -4);
  iVar9 = iVar6 + -1;
  uVar13 = *(uint *)(iVar6 + -5 + param_2);
  iVar6 = iVar6 + -5 + param_2;
  if (iVar9 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + iVar9) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
    iVar6 = uVar13 + (iVar9 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar9 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar3 = iVar3 + uVar13 * 8;
      *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar3 + 4);
      *(int *)(iVar9 + 8) = iVar3;
      *(int *)(iVar3 + 4) = iVar9;
      *(int *)(*(int *)(iVar9 + 4) + 8) = iVar9;
      if (*(int *)(iVar9 + 4) == *(int *)(iVar9 + 8)) {
        cVar4 = *(char *)(uVar13 + 4 + uVar5);
        *(char *)(uVar13 + 4 + uVar5) = cVar4 + '\x01';
        bVar8 = (byte)uVar13;
        if (uVar13 < 0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          bVar8 = bVar8 - 0x20;
        }
        *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
      }
      piVar2 = (int *)(param_2 + -4 + uVar12);
      *piVar2 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar2) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < iVar9) {
    param_3 = iVar9 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar2 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar2[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar6 = iVar3 + uVar11 * 8;
    piVar2[1] = *(int *)(iVar3 + 4 + uVar11 * 8);
    piVar2[2] = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *(int **)(piVar2[1] + 8) = piVar2;
    if (piVar2[1] == piVar2[2]) {
      cVar4 = *(char *)(uVar11 + 4 + uVar5);
      *(char *)(uVar11 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar11;
      if (uVar11 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        bVar8 = bVar8 - 0x20;
      }
      *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
    }
    *piVar2 = param_3;
    *(int *)(param_3 + -4 + (int)piVar2) = param_3;
  }
  return 1;
}


/*
 * FUN_00423666 at 00423666
 * int __cdecl FUN_00423666(DWORD param_1, char * param_2, uint param_3)
 * Address ranges: 00423666-00423812
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00423666(DWORD param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  char *pcVar5;
  BOOL BVar6;
  int iVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  if (param_1 < DAT_0043f920) {
    piVar1 = &DAT_0043f820 + ((int)param_1 >> 5);
    iVar7 = (param_1 & 0x1f) * 8;
    bVar3 = *(byte *)(*piVar1 + 4 + iVar7);
    if ((bVar3 & 1) != 0) {
      local_c = 0;
      local_14 = 0;
      if (param_3 == 0) {
        return 0;
      }
      if ((bVar3 & 0x20) != 0) {
        FUN_00422935(param_1,0,2);
      }
      if ((*(byte *)((undefined4 *)(*piVar1 + iVar7) + 1) & 0x80) == 0) {
        BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar7),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
        if (BVar6 == 0) {
          param_1 = GetLastError();
        }
        else {
          local_c = local_10;
          param_1 = 0;
        }
LAB_0042375f:
        if (local_c != 0) {
          return local_c - local_14;
        }
        if (param_1 != 0) {
          if (param_1 == 5) {
            _DAT_0043e2c0 = 9;
            DAT_0043e2c4 = 5;
            return -1;
          }
          FUN_00424108(param_1);
          return -1;
        }
      }
      else {
        local_8 = param_2;
        param_1 = 0;
        if (param_3 != 0) {
          do {
            pcVar5 = local_418;
            do {
              if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
              pcVar2 = local_8 + 1;
              cVar4 = *local_8;
              local_8 = pcVar2;
              if (cVar4 == '\n') {
                local_14 = local_14 + 1;
                *pcVar5 = '\r';
                pcVar5 = pcVar5 + 1;
              }
              *pcVar5 = cVar4;
              pcVar5 = pcVar5 + 1;
            } while ((int)pcVar5 - (int)local_418 < 0x400);
            BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar7),local_418,(int)pcVar5 - (int)local_418,
                              &local_10,(LPOVERLAPPED)0x0);
            if (BVar6 == 0) {
              param_1 = GetLastError();
              goto LAB_0042375f;
            }
            local_c = local_c + local_10;
            if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
               (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_0042375f;
          } while( true );
        }
      }
      if (((*(byte *)(*piVar1 + 4 + iVar7) & 0x40) != 0) && (*param_2 == '\x1a')) {
        return 0;
      }
      _DAT_0043e2c0 = 0x1c;
      DAT_0043e2c4 = 0;
      return -1;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return -1;
}


/*
 * FUN_00423813 at 00423813
 * undefined4 __cdecl FUN_00423813(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4, int * param_5, int param_6, PVOID param_7, char param_8)
 * Address ranges: 00423813-004238ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00423813(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4,
            int *param_5,int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_004240b2();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_004238ae(param_1,param_2,param_3,param_4,(int)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_00423b5a((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}


/*
 * FUN_004238ae at 004238ae
 * undefined __cdecl FUN_004238ae(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4, int param_5, char param_6, int param_7, PVOID param_8)
 * Address ranges: 004238ae-00423a54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_004238ae(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4,
            int param_5,char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  PEXCEPTION_RECORD pEVar2;
  bool bVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_004240b2();
  }
  pEVar2 = DAT_0043e458;
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      if (DAT_0043e458 == (PEXCEPTION_RECORD)0x0) {
        return;
      }
      param_3 = DAT_0043e45c;
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar3 = FUN_00425fd2(DAT_0043e458,1);
      if (CONCAT31(extraout_var,bVar3) == 0) {
        FUN_004240b2();
      }
      param_1 = pEVar2;
      if (pEVar2->ExceptionCode != 0xe06d7363) goto LAB_00423a2a;
      if (((pEVar2->NumberParameters == 3) && (pEVar2->ExceptionInformation[0] == 0x19930520)) &&
         (pEVar2->ExceptionInformation[2] == 0)) {
        FUN_004240b2();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_004201f5(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_00423f83((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; iVar5 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_00423afd(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_00423c0e(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                iVar5 = local_14;
                goto LAB_00423a0a;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
        }
LAB_00423a0a:
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_00423a2a:
  if (param_6 == '\0') {
    FUN_00423a55(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_0042405c();
  return;
}


/*
 * FUN_00423a55 at 00423a55
 * undefined __cdecl FUN_00423a55(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6, int param_7, PVOID param_8)
 * Address ranges: 00423a55-00423afc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_00423a55(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4,
            int param_5,int param_6,int param_7,PVOID param_8)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint local_c;
  uint local_8;
  
  if ((DAT_0043e460 != 0) &&
     (iVar1 = FUN_004200cc(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar1 != 0)) {
    return;
  }
  piVar2 = (int *)FUN_004201f5(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar2 <= param_6) && (param_6 <= piVar2[1])) {
      iVar3 = piVar2[3] * 0x10 + piVar2[4];
      iVar1 = *(int *)(iVar3 + -0xc);
      if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
        FUN_00423c0e(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar3 + -0x10),(byte *)0x0,
                     piVar2,param_7,param_8);
      }
    }
    piVar2 = piVar2 + 5;
  }
  return;
}


/*
 * FUN_00423afd at 00423afd
 * undefined4 __cdecl FUN_00423afd(byte * param_1, byte * param_2, uint * param_3)
 * Address ranges: 00423afd-00423b59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00423afd(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_00423b54:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_00423b2e:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_00423b54;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_00423b2e;
    }
    uVar2 = 0;
  }
  return uVar2;
}


/*
 * FUN_00423b5a at 00423b5a
 * undefined __cdecl FUN_00423b5a(int param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00423b5a-00423bc0;00423bdb-00423bf7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00423b5a(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3a8;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_004240b2();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_14;
  return;
}


/*
 * FUN_00423c0e at 00423c0e
 * undefined __cdecl FUN_00423c0e(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4, int param_5, byte * param_6, byte * param_7, int * param_8, int param_9, PVOID param_10)
 * Address ranges: 00423c0e-00423c88
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_00423c0e(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4,
            int param_5,byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_00423dbf((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  FUN_0041ffce(param_10,param_1);
  FUN_00423b5a((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_00423c89(param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_0041ff8c(UNRECOVERED_JUMPTABLE);
  }
  return;
}


/*
 * FUN_00423c89 at 00423c89
 * undefined4 __cdecl FUN_00423c89(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, int param_6, int param_7)
 * Address ranges: 00423c89-00423d24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00423c89(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7)

{
  undefined4 uVar1;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3b8;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  DAT_0043e458 = param_1;
  DAT_0043e45c = param_3;
  local_8 = 1;
  ExceptionList = &local_14;
  uVar1 = FUN_00420053(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00423d4f();
  ExceptionList = local_14;
  return uVar1;
}


/*
 * FUN_00423d4f at 00423d4f
 * undefined __stdcall FUN_00423d4f(void)
 * Address ranges: 00423d4f-00423d94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00423d4f(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_0043e458 = *(undefined4 *)(unaff_EBP + -0x1c);
  DAT_0043e45c = *(undefined4 *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == unaff_EBX && (*(int *)(unaff_EBP + -0x2c) != unaff_EBX)))) {
    __abnormal_termination();
    FUN_00423f83((int)unaff_EDI);
  }
  return;
}


/*
 * FUN_00423dbf at 00423dbf
 * undefined __cdecl FUN_00423dbf(int param_1, int param_2, byte * param_3, byte * param_4)
 * Address ranges: 00423dbf-00423f76
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00423dbf(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar5;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3d0;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar2 = FUN_00425fd2(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_00425fee(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_00423fea(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_00425c30(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_00425fd2(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_00425fee(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_0042600a(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) != 0) {
            FUN_00423fea(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_0041ffc7(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_00423fea(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_0041ffc0(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_00425fd2(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_00425fee(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_00425c30(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_00423e4d;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_00425fd2(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_00425fee(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_00423e4d:
      iVar3 = FUN_00423fea(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_004240b2();
  ExceptionList = local_14;
  return;
}


/*
 * FUN_00423f83 at 00423f83
 * undefined __cdecl FUN_00423f83(int param_1)
 * Address ranges: 00423f83-00423fd8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00423f83(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3e0;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_0041ffc0(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}


/*
 * FUN_00423fea at 00423fea
 * int __cdecl FUN_00423fea(int param_1, int * param_2)
 * Address ranges: 00423fea-0042400c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00423fea(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}


/*
 * __CallSettingFrame@12 at 00424010
 * undefined __stdcall __CallSettingFrame@12(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 00424010-0042405b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __CallSettingFrame@12  Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual Studio 2019 Release
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}


/*
 * FUN_0042405c at 0042405c
 * undefined __stdcall FUN_0042405c(void)
 * Address ranges: 0042405c-00424098;004240a0-004240b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0042405c(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3f0;
  pcStack_10 = FUN_00421630;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (DAT_0043e464 != (code *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*DAT_0043e464)();
  }
  local_8 = 0xffffffff;
  FUN_004260b4();
  return;
}


/*
 * FUN_004240b2 at 004240b2
 * undefined __stdcall FUN_004240b2(void)
 * Address ranges: 004240b2-004240ee;004240f6-00424107
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004240b2(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a408;
  pcStack_10 = FUN_00421630;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_004374a4 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_004374a4)();
  }
  local_8 = 0xffffffff;
  FUN_0042405c();
  return;
}


/*
 * FUN_00424108 at 00424108
 * undefined __cdecl FUN_00424108(uint param_1)
 * Address ranges: 00424108-0042416e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00424108(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_0043e2c4 = param_1;
  puVar1 = &DAT_004374a8;
  do {
    if (param_1 == *puVar1) {
      _DAT_0043e2c0 = *(undefined4 *)(iVar2 * 8 + 0x4374ac);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x437610);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_0043e2c0 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (_DAT_0043e2c0 = 8, 0xca < param_1)) {
    _DAT_0043e2c0 = 0x16;
  }
  return;
}


/*
 * FUN_0042416f at 0042416f
 * int __stdcall FUN_0042416f(void)
 * Address ranges: 0042416f-00424203
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_0042416f(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = -1;
  iVar6 = 0;
  iVar5 = 0;
  piVar3 = &DAT_0043f820;
  do {
    puVar2 = (undefined4 *)*piVar3;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = _malloc(0x100);
      if (puVar2 != (undefined4 *)0x0) {
        DAT_0043f920 = DAT_0043f920 + 0x20;
        (&DAT_0043f820)[iVar6] = puVar2;
        puVar1 = puVar2;
        for (; puVar2 < puVar1 + 0x40; puVar2 = puVar2 + 2) {
          *(undefined1 *)(puVar2 + 1) = 0;
          *puVar2 = 0xffffffff;
          *(undefined1 *)((int)puVar2 + 5) = 10;
          puVar1 = (undefined4 *)(&DAT_0043f820)[iVar6];
        }
        iVar4 = iVar6 << 5;
      }
      return iVar4;
    }
    puVar1 = puVar2 + 0x40;
    for (; puVar2 < puVar1; puVar2 = puVar2 + 2) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        *puVar2 = 0xffffffff;
        iVar4 = ((int)puVar2 - *piVar3 >> 3) + iVar5;
        if (iVar4 != -1) {
          return iVar4;
        }
        break;
      }
    }
    piVar3 = piVar3 + 1;
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0x20;
    if (0x43f91f < (int)piVar3) {
      return iVar4;
    }
  } while( true );
}


/*
 * FUN_00424204 at 00424204
 * undefined4 __cdecl FUN_00424204(uint param_1, HANDLE param_2)
 * Address ranges: 00424204-0042427a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00424204(uint param_1,HANDLE param_2)

{
  int iVar1;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0043f920) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (*(int *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar1) == -1) {
      if (DAT_004370e4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0042425a;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_0042425a:
      *(HANDLE *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar1) = param_2;
      return 0;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}


/*
 * FUN_0042427b at 0042427b
 * undefined4 __cdecl FUN_0042427b(uint param_1)
 * Address ranges: 0042427b-004242f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042427b(uint param_1)

{
  int *piVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0043f920) {
    iVar2 = (param_1 & 0x1f) * 8;
    piVar1 = (int *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar2);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_004370e4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004242d4;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_004242d4:
      *(undefined4 *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar2) = 0xffffffff;
      return 0;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}


/*
 * FUN_004242f5 at 004242f5
 * undefined4 __cdecl FUN_004242f5(uint param_1)
 * Address ranges: 004242f5-00424331
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004242f5(uint param_1)

{
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0043f820)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}


/*
 * FUN_00424332 at 00424332
 * undefined4 __cdecl FUN_00424332(uint param_1)
 * Address ranges: 00424332-00424388
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00424332(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = DAT_0043e2c4;
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_004242f5(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    if (DVar2 == 0) {
      return 0;
    }
  }
  DAT_0043e2c4 = DVar2;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}


/*
 * FUN_00424389 at 00424389
 * undefined FUN_00424389(void)
 * Address ranges: 00424389-0042442d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00424389(void)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = 0x14;
  if (DAT_0043f800 == 0) {
    iVar1 = 0x200;
  }
  else if (0x13 < DAT_0043f800) goto LAB_004243a8;
  DAT_0043f800 = iVar1;
LAB_004243a8:
  DAT_0043e7e8 = FUN_004260cb(DAT_0043f800,4);
  if (DAT_0043e7e8 == (int *)0x0) {
    DAT_0043f800 = 0x14;
    DAT_0043e7e8 = FUN_004260cb(0x14,4);
    if (DAT_0043e7e8 == (int *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  iVar1 = 0;
  ppuVar2 = &PTR_DAT_00437610;
  do {
    *(undefined ***)(iVar1 + (int)DAT_0043e7e8) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar1 = iVar1 + 4;
  } while ((int)ppuVar2 < 0x437890);
  uVar4 = 0;
  puVar3 = &DAT_00437620;
  do {
    iVar1 = *(int *)((&DAT_0043f820)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 8);
    if ((iVar1 == -1) || (iVar1 == 0)) {
      *puVar3 = 0xffffffff;
    }
    puVar3 = puVar3 + 8;
    uVar4 = uVar4 + 1;
  } while ((int)puVar3 < 0x437680);
  return;
}


/*
 * FUN_00424442 at 00424442
 * undefined __cdecl FUN_00424442(undefined4 * param_1)
 * Address ranges: 00424442-00424485
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00424442(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_0043e468 = _DAT_0043e468 + 1;
  pvVar1 = _malloc(0x1000);
  param_1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}


/*
 * FUN_00424486 at 00424486
 * uint __cdecl FUN_00424486(LPCSTR param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00424486-0042473e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_00424486(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  HANDLE hFile;
  DWORD DVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;
  
  bVar7 = (param_2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar7) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar7;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_0043e574 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) {
      _DAT_0043e2c0 = 0x16;
      DAT_0043e2c4 = 0;
      return 0xffffffff;
    }
    local_10 = 0xc0000000;
  }
  if (param_3 == 0x10) {
    local_14 = 0;
  }
  else if (param_3 == 0x20) {
    local_14 = 1;
  }
  else if (param_3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (param_3 != 0x40) {
      _DAT_0043e2c0 = 0x16;
      DAT_0043e2c4 = 0;
      return 0xffffffff;
    }
    local_14 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_004245a4;
      if (uVar2 != 0x300) {
        _DAT_0043e2c0 = 0x16;
        DAT_0043e2c4 = 0;
        return 0xffffffff;
      }
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_004245a4:
        local_c = 5;
        goto LAB_004245b4;
      }
      if (uVar2 != 0x700) {
        _DAT_0043e2c0 = 0x16;
        DAT_0043e2c4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_004245b4:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_0043e2c8 & param_4 & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = FUN_0042416f();
  if (uVar3 == 0xffffffff) {
    DAT_0043e2c4 = 0;
    _DAT_0043e2c0 = 0x18;
  }
  else {
    hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      DVar4 = GetFileType(hFile);
      if (DVar4 != 0) {
        if (DVar4 == 2) {
          local_5 = local_5 | 0x40;
        }
        else if (DVar4 == 3) {
          local_5 = local_5 | 8;
        }
        FUN_00424204(uVar3,hFile);
        iVar6 = (uVar3 & 0x1f) * 8;
        param_1._3_1_ = local_5 & 0x48;
        *(byte *)((&DAT_0043f820)[(int)uVar3 >> 5] + 4 + iVar6) = local_5 | 1;
        if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
          local_14 = FUN_00422935(uVar3,-1,2);
          if (local_14 == 0xffffffff) {
            if (DAT_0043e2c4 != 0x83) {
LAB_00424715:
              FUN_00420454(uVar3);
              return 0xffffffff;
            }
          }
          else {
            param_3 = param_3 & 0xffffff;
            iVar5 = FUN_00420718(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
            if ((((iVar5 == 0) && (param_3._3_1_ == '\x1a')) &&
                (iVar5 = FUN_004261a0(uVar3,local_14), iVar5 == -1)) ||
               (DVar4 = FUN_00422935(uVar3,0,0), DVar4 == 0xffffffff)) goto LAB_00424715;
          }
        }
        if (param_1._3_1_ != 0) {
          return uVar3;
        }
        if ((param_2 & 8) != 0) {
          pbVar1 = (byte *)((&DAT_0043f820)[(int)uVar3 >> 5] + 4 + iVar6);
          *pbVar1 = *pbVar1 | 0x20;
          return uVar3;
        }
        return uVar3;
      }
      CloseHandle(hFile);
    }
    DVar4 = GetLastError();
    FUN_00424108(DVar4);
  }
  return 0xffffffff;
}


/*
 * _malloc at 0042473f
 * void * __cdecl _malloc(size_t _Size)
 * Address ranges: 0042473f-00424750
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _malloc  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_0043e578);
  return pvVar1;
}


/*
 * __nh_malloc at 00424751
 * void * __cdecl __nh_malloc(size_t _Size, int _NhFlag)
 * Address ranges: 00424751-0042477c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __nh_malloc  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = (void *)FUN_0042477d((uint *)_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_004262e6(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


/*
 * FUN_0042477d at 0042477d
 * undefined __cdecl FUN_0042477d(uint * param_1)
 * Address ranges: 0042477d-004247b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042477d(uint *param_1)

{
  int *piVar1;
  
  if ((param_1 <= DAT_00437490) && (piVar1 = FUN_00422ebb(param_1), piVar1 != (int *)0x0)) {
    return;
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  HeapAlloc(DAT_0043f81c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return;
}


/*
 * FUN_004247b3 at 004247b3
 * undefined __cdecl FUN_004247b3(byte param_1)
 * Address ranges: 004247b3-004247c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004247b3(byte param_1)

{
  FUN_004247c4(param_1,0,4);
  return;
}


/*
 * FUN_004247c4 at 004247c4
 * undefined4 __cdecl FUN_004247c4(byte param_1, uint param_2, byte param_3)
 * Address ranges: 004247c4-004247f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004247c4(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((*(byte *)((int)&DAT_0043e6e0 + param_1 + 1) & param_3) == 0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(&DAT_0043726a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


/*
 * FUN_004247f5 at 004247f5
 * undefined4 __cdecl FUN_004247f5(int param_1)
 * Address ranges: 004247f5-0042498d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004247f5(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  BYTE *pBVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  _cpinfo local_1c;
  uint local_8;
  
  CodePage = FUN_0042498e(param_1);
  if (CodePage == DAT_0043e5bc) {
    return 0;
  }
  if (CodePage != 0) {
    iVar11 = 0;
    pUVar5 = &DAT_00437898;
    do {
      if (*pUVar5 == CodePage) {
        puVar13 = &DAT_0043e6e0;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
        local_8 = 0;
        iVar11 = iVar11 * 0x30;
        *(undefined1 *)puVar13 = 0;
        pbVar12 = (byte *)(iVar11 + 0x4378a8);
        do {
          bVar3 = *pbVar12;
          pbVar10 = pbVar12;
          while ((bVar3 != 0 && (bVar3 = pbVar10[1], bVar3 != 0))) {
            uVar7 = (uint)*pbVar10;
            if (uVar7 <= bVar3) {
              bVar4 = (&DAT_00437890)[local_8];
              do {
                pbVar2 = (byte *)((int)&DAT_0043e6e0 + uVar7 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar7 = uVar7 + 1;
              } while (uVar7 <= bVar3);
            }
            pbVar10 = pbVar10 + 2;
            bVar3 = *pbVar10;
          }
          local_8 = local_8 + 1;
          pbVar12 = pbVar12 + 8;
        } while (local_8 < 4);
        DAT_0043e5cc = 1;
        DAT_0043e5bc = CodePage;
        DAT_0043e7e4 = FUN_004249d8(CodePage);
        DAT_0043e5c0 = *(undefined4 *)(iVar11 + 0x43789c);
        DAT_0043e5c4 = *(undefined4 *)(iVar11 + 0x4378a0);
        DAT_0043e5c8 = *(undefined4 *)(iVar11 + 0x4378a4);
        goto LAB_0042497d;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar11 = iVar11 + 1;
    } while ((int)pUVar5 < 0x437988);
    BVar6 = GetCPInfo(CodePage,&local_1c);
    if (BVar6 == 1) {
      puVar13 = &DAT_0043e6e0;
      DAT_0043e5bc = CodePage;
      for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      *(undefined1 *)puVar13 = 0;
      DAT_0043e7e4 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_0043e5cc = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar8 = local_1c.LeadByte + 1;
          do {
            bVar3 = *pBVar8;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar8[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              pbVar12 = (byte *)((int)&DAT_0043e6e0 + uVar7 + 1);
              *pbVar12 = *pbVar12 | 4;
            }
            pBVar1 = pBVar8 + 1;
            pBVar8 = pBVar8 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          pbVar12 = (byte *)((int)&DAT_0043e6e0 + uVar7 + 1);
          *pbVar12 = *pbVar12 | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_0043e7e4 = FUN_004249d8(CodePage);
        DAT_0043e5cc = 1;
      }
      DAT_0043e5c0 = 0;
      DAT_0043e5c4 = 0;
      DAT_0043e5c8 = 0;
      goto LAB_0042497d;
    }
    if (DAT_0043e470 == 0) {
      return 0xffffffff;
    }
  }
  FUN_00424a0b();
LAB_0042497d:
  FUN_00424a34();
  return 0;
}


/*
 * FUN_0042498e at 0042498e
 * int __cdecl FUN_0042498e(int param_1)
 * Address ranges: 0042498e-004249d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0042498e(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0043e470 = 1;
                    /* WARNING: Could not recover jumptable at 0x004249a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0043e470 = 1;
                    /* WARNING: Could not recover jumptable at 0x004249bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0043e598;
  }
  DAT_0043e470 = (uint)bVar2;
  return param_1;
}


/*
 * FUN_004249d8 at 004249d8
 * undefined4 __cdecl FUN_004249d8(int param_1)
 * Address ranges: 004249d8-00424a0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004249d8(int param_1)

{
  if (param_1 == 0x3a4) {
    return 0x411;
  }
  if (param_1 == 0x3a8) {
    return 0x804;
  }
  if (param_1 == 0x3b5) {
    return 0x412;
  }
  if (param_1 != 0x3b6) {
    return 0;
  }
  return 0x404;
}


/*
 * FUN_00424a0b at 00424a0b
 * undefined __stdcall FUN_00424a0b(void)
 * Address ranges: 00424a0b-00424a33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00424a0b(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0043e6e0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0043e5bc = 0;
  DAT_0043e5cc = 0;
  DAT_0043e7e4 = 0;
  DAT_0043e5c0 = 0;
  DAT_0043e5c4 = 0;
  DAT_0043e5c8 = 0;
  return;
}


/*
 * FUN_00424a34 at 00424a34
 * undefined __stdcall FUN_00424a34(void)
 * Address ranges: 00424a34-00424bb8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00424a34(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  BVar2 = GetCPInfo(DAT_0043e5bc,&local_18);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      local_118[uVar3] = (CHAR)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar3 = (uint)local_18.LeadByte[0];
        if (uVar3 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar3) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar3;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_00425334(1,local_118,0x100,local_518,DAT_0043e5bc,DAT_0043e7e4,0);
    FUN_00426301(DAT_0043e7e4,0x100,local_118,0x100,local_218,0x100,DAT_0043e5bc,0);
    FUN_00426301(DAT_0043e7e4,0x200,local_118,0x100,local_318,0x100,DAT_0043e5bc,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_0043e6e0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_00424b40;
        }
        (&DAT_0043e5e0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_0043e6e0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_00424b40:
        (&DAT_0043e5e0)[uVar3] = uVar8;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_0043e6e0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_00424b8a;
        }
        (&DAT_0043e5e0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_0043e6e0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_00424b8a:
        (&DAT_0043e5e0)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


/*
 * FUN_00424bb9 at 00424bb9
 * undefined __stdcall FUN_00424bb9(void)
 * Address ranges: 00424bb9-00424bd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00424bb9(void)

{
  if (DAT_0043f928 == 0) {
    FUN_004247f5(-3);
    DAT_0043f928 = 1;
  }
  return;
}


/*
 * FUN_00424bd5 at 00424bd5
 * int __cdecl FUN_00424bd5(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00424bd5-00424c5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00424bd5(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0043e474 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_0043e474 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_0043e474 != (FARPROC)0x0) {
        DAT_0043e478 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_0043e47c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_00424c24;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_00424c24:
    if (DAT_0043e478 != (FARPROC)0x0) {
      iVar1 = (*DAT_0043e478)();
      if ((iVar1 != 0) && (DAT_0043e47c != (FARPROC)0x0)) {
        iVar1 = (*DAT_0043e47c)(iVar1);
      }
    }
    iVar1 = (*DAT_0043e474)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


/*
 * FUN_00424c5e at 00424c5e
 * byte __cdecl FUN_00424c5e(uint param_1)
 * Address ranges: 00424c5e-00424c83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


byte __cdecl FUN_00424c5e(uint param_1)

{
  if (DAT_0043f920 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}


/*
 * FUN_00424c84 at 00424c84
 * int __cdecl FUN_00424c84(LPSTR param_1, WCHAR param_2)
 * Address ranges: 00424c84-00424ceb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00424c84(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_0043e588 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_0043e598,0x220,&param_2,1,lpMultiByteStr,DAT_0043746c,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  _DAT_0043e2c0 = 0x2a;
  return -1;
}


/*
 * __aulldiv at 00424cf0
 * undefined8 __stdcall __aulldiv(uint param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00424cf0-00424d57
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __aulldiv  Library: Visual Studio
 */


/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;
  
  uVar9 = param_1;
  uVar6 = param_4;
  uVar7 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar9)) ||
       ((param_2 <= uVar9 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}


/*
 * __aullrem at 00424d60
 * undefined8 __stdcall __aullrem(uint param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00424d60-00424dd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __aullrem  Library: Visual Studio
 */


/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = param_1;
  uVar9 = param_4;
  uVar10 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar5;
      uVar10 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}


/*
 * FUN_00424dd5 at 00424dd5
 * undefined __stdcall FUN_00424dd5(void)
 * Address ranges: 00424dd5-00424de9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00424dd5(void)

{
  if (DAT_0043e538 == 0) {
    FUN_00424dea();
    DAT_0043e538 = DAT_0043e538 + 1;
  }
  return;
}


/*
 * FUN_00424dea at 00424dea
 * undefined __stdcall FUN_00424dea(void)
 * Address ranges: 00424dea-00425047
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424dea(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_4;
  
  DAT_0043e480 = 0;
  DAT_00437a38 = 0xffffffff;
  DAT_00437a28 = 0xffffffff;
  _Str1 = (uint *)FUN_00426550("TZ");
  if (_Str1 == (uint *)0x0) {
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_0043e488);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_00437990 = (void *)(DAT_0043e488 * 0x3c);
    DAT_0043e480 = 1;
    if (DAT_0043e4ce != 0) {
      DAT_00437990 = (void *)((int)DAT_00437990 + DAT_0043e4dc * 0x3c);
    }
    if ((DAT_0043e522 == 0) || (DAT_0043e530 == 0)) {
      DAT_00437994 = 0;
      _DAT_00437998 = 0;
    }
    else {
      DAT_00437994 = 1;
      _DAT_00437998 = (DAT_0043e530 - DAT_0043e4dc) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_0043e598,0x220,(LPCWSTR)&DAT_0043e48c,-1,PTR_DAT_00437a1c,0x3f,
                                (LPCSTR)0x0,&local_4);
    if ((iVar4 == 0) || (local_4 != 0)) {
      *PTR_DAT_00437a1c = 0;
    }
    else {
      PTR_DAT_00437a1c[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_0043e598,0x220,(LPCWSTR)&DAT_0043e4e0,-1,PTR_DAT_00437a20,0x3f,
                                (LPCSTR)0x0,&local_4);
    if ((iVar4 != 0) && (local_4 == 0)) {
      PTR_DAT_00437a20[0x3f] = 0;
      return;
    }
  }
  else {
    if ((char)*_Str1 == '\0') {
      return;
    }
    if ((DAT_0043e534 != (uint *)0x0) &&
       (iVar4 = _strcmp((char *)_Str1,(char *)DAT_0043e534), iVar4 == 0)) {
      return;
    }
    FUN_0041fd93(DAT_0043e534);
    sVar5 = _strlen((char *)_Str1);
    DAT_0043e534 = _malloc(sVar5 + 1);
    if (DAT_0043e534 == (uint *)0x0) {
      return;
    }
    FUN_0041f7a0(DAT_0043e534,_Str1);
    _strncpy(PTR_DAT_00437a1c,(char *)_Str1,3);
    _Source = (uint *)((int)_Str1 + 3);
    PTR_DAT_00437a1c[3] = 0;
    cVar1 = *(char *)_Source;
    if (cVar1 == '-') {
      _Source = _Str1 + 1;
    }
    iVar4 = FUN_0041fbf0(this,(byte *)_Source);
    DAT_00437990 = (void *)(iVar4 * 0xe10);
    for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
        _Source = (uint *)((int)_Source + 1)) {
    }
    if ((char)*_Source == ':') {
      _Source = (uint *)((int)_Source + 1);
      iVar4 = FUN_0041fbf0(DAT_00437990,(byte *)_Source);
      DAT_00437990 = (void *)((int)DAT_00437990 + iVar4 * 0x3c);
      for (; ('/' < (char)*_Source && ((char)*_Source < ':')); _Source = (uint *)((int)_Source + 1))
      {
      }
      if ((char)*_Source == ':') {
        _Source = (uint *)((int)_Source + 1);
        iVar4 = FUN_0041fbf0(DAT_00437990,(byte *)_Source);
        DAT_00437990 = (void *)((int)DAT_00437990 + iVar4);
        for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
            _Source = (uint *)((int)_Source + 1)) {
        }
      }
    }
    if (cVar1 == '-') {
      DAT_00437990 = (void *)-(int)DAT_00437990;
    }
    DAT_00437994 = (int)(char)*_Source;
    if (DAT_00437994 != 0) {
      _strncpy(PTR_DAT_00437a20,(char *)_Source,3);
      PTR_DAT_00437a20[3] = 0;
      return;
    }
  }
  *PTR_DAT_00437a20 = 0;
  return;
}


/*
 * FUN_00425048 at 00425048
 * bool __cdecl FUN_00425048(int * param_1)
 * Address ranges: 00425048-004251f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_00425048(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (DAT_00437994 != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_00437a28) || (uVar5 != DAT_00437a38)) {
      if (DAT_0043e480 == 0) {
        FUN_004251f4(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_004251f4(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_0043e520 != 0) {
          uVar6 = (uint)DAT_0043e526;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_0043e524;
          uVar6 = 0;
          uVar4 = (uint)DAT_0043e526;
        }
        FUN_004251f4(1,(uint)(DAT_0043e520 == 0),uVar5,(uint)DAT_0043e522,uVar4,uVar3,uVar6,
                     (uint)DAT_0043e528,(uint)DAT_0043e52a,(uint)DAT_0043e52c,(uint)DAT_0043e52e);
        if (DAT_0043e4cc != 0) {
          uVar6 = (uint)DAT_0043e4d2;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_0043e4d0;
          uVar6 = 0;
          uVar4 = (uint)DAT_0043e4d2;
          uVar5 = param_1[5];
        }
        FUN_004251f4(0,(uint)(DAT_0043e4cc == 0),uVar5,(uint)DAT_0043e4ce,uVar4,uVar3,uVar6,
                     (uint)DAT_0043e4d4,(uint)DAT_0043e4d6,(uint)DAT_0043e4d8,(uint)DAT_0043e4da);
      }
    }
    iVar1 = param_1[7];
    if (DAT_00437a2c < DAT_00437a3c) {
      if ((DAT_00437a2c <= iVar1) && (iVar1 <= DAT_00437a3c)) {
        if ((DAT_00437a2c < iVar1) && (iVar1 < DAT_00437a3c)) {
          return true;
        }
LAB_004251c0:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_00437a2c) {
          return DAT_00437a30 <= iVar2;
        }
        return iVar2 < DAT_00437a40;
      }
    }
    else {
      if (iVar1 < DAT_00437a3c) {
        return true;
      }
      if (DAT_00437a2c < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_00437a3c) || (DAT_00437a2c <= iVar1)) goto LAB_004251c0;
    }
  }
  return false;
}


/*
 * FUN_004251f4 at 004251f4
 * undefined __cdecl FUN_004251f4(int param_1, int param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11)
 * Address ranges: 004251f4-00425333
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_004251f4(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = (&DAT_00437a40)[param_4];
    }
    else {
      iVar1 = *(int *)(&DAT_00437a74 + param_4 * 4);
    }
    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;
    if (iVar2 < param_6) {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_00437a44 + param_4 * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_00437a78 + param_4 * 4);
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = (&DAT_00437a40)[param_4];
    }
    else {
      iVar1 = *(int *)(&DAT_00437a74 + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_00437a28 = param_3;
    DAT_00437a30 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;
    DAT_00437a2c = iVar1;
  }
  else {
    DAT_00437a40 = ((param_8 * 0x3c + param_9) * 0x3c + _DAT_00437998 + param_10) * 1000 + param_11;
    if (DAT_00437a40 < 0) {
      DAT_00437a40 = DAT_00437a40 + 86400000;
      DAT_00437a3c = iVar1 + -1;
    }
    else {
      DAT_00437a3c = iVar1;
      if (86399999 < DAT_00437a40) {
        DAT_00437a40 = DAT_00437a40 + -86400000;
        DAT_00437a3c = iVar1 + 1;
      }
    }
    DAT_00437a38 = param_3;
  }
  return;
}


/*
 * FUN_00425334 at 00425334
 * BOOL __cdecl FUN_00425334(DWORD param_1, LPCSTR param_2, int param_3, LPWORD param_4, UINT param_5, LCID param_6, int param_7)
 * Address ranges: 00425334-0042542c;00425438-0042547c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


BOOL __cdecl
FUN_00425334(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined1 *puVar1;
  BOOL BVar2;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042a4a8;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_0043e53c;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_0043e53c == 0) {
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_0043e53c = iVar3;
  if (DAT_0043e53c != 2) {
    if (DAT_0043e53c == 1) {
      if (param_5 == 0) {
        param_5 = DAT_0043e598;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_004265d0();
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return BVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_0043e588;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}


/*
 * FUN_0042547d at 0042547d
 * uint __thiscall FUN_0042547d(void * this, uint param_1, uint param_2)
 * Address ranges: 0042547d-004254b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __thiscall FUN_0042547d(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_004254c8(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_0042555a(uVar1);
  return uVar1;
}


/*
 * FUN_004254b2 at 004254b2
 * undefined __thiscall FUN_004254b2(void * this, uint param_1, uint param_2)
 * Address ranges: 004254b2-004254c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_004254b2(void *this,uint param_1,uint param_2)

{
  FUN_0042547d(this,param_1,param_2 & 0xfff7ffff);
  return;
}


/*
 * FUN_004254c8 at 004254c8
 * uint __cdecl FUN_004254c8(uint param_1)
 * Address ranges: 004254c8-00425559
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_004254c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}


/*
 * FUN_0042555a at 0042555a
 * uint __cdecl FUN_0042555a(uint param_1)
 * Address ranges: 0042555a-004255e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_0042555a(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)((param_1 & 0x10) != 0);
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = param_1 & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}


/*
 * FUN_004255e3 at 004255e3
 * uint __thiscall FUN_004255e3(void * this, uint param_1)
 * Address ranges: 004255e3-004256ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __thiscall FUN_004255e3(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_0043e588 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_0043746c < 2) {
        uVar2 = (byte)PTR_DAT_00437260[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_0042240c(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_00437260[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_00426301(DAT_0043e588,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}


/*
 * FUN_004256ae at 004256ae
 * undefined4 __cdecl FUN_004256ae(int param_1, int param_2)
 * Address ranges: 004256ae-004256f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004256ae(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}


/*
 * FUN_004256f7 at 004256f7
 * undefined __cdecl FUN_004256f7(int param_1, int param_2)
 * Address ranges: 004256f7-0042574c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004256f7(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_004265ff(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_004265ff(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}


/*
 * FUN_0042574d at 0042574d
 * undefined4 __cdecl FUN_0042574d(int param_1, int param_2)
 * Address ranges: 0042574d-004257d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0042574d(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  bVar3 = 0x1f - (char)(param_2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_004256ae(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_004256f7(param_1,param_2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}


/*
 * FUN_004257d9 at 004257d9
 * undefined __cdecl FUN_004257d9(int param_1, undefined4 * param_2)
 * Address ranges: 004257d9-004257f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004257d9(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 - (int)param_2;
  iVar2 = 3;
  do {
    *(undefined4 *)(iVar1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/*
 * FUN_004257f4 at 004257f4
 * undefined __cdecl FUN_004257f4(undefined4 * param_1)
 * Address ranges: 004257f4-004257ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004257f4(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


/*
 * FUN_00425800 at 00425800
 * undefined4 __cdecl FUN_00425800(int * param_1)
 * Address ranges: 00425800-0042581a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00425800(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}


/*
 * FUN_0042581b at 0042581b
 * undefined __cdecl FUN_0042581b(uint * param_1, uint param_2)
 * Address ranges: 0042581b-004258a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042581b(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;
  
  local_8 = 3;
  iVar2 = (int)param_2 / 0x20;
  iVar5 = (int)param_2 % 0x20;
  param_2 = 0;
  bVar3 = (byte)iVar5;
  puVar6 = param_1;
  do {
    uVar1 = *puVar6;
    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;
    puVar6 = puVar6 + 1;
    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar5 = 2;
  iVar4 = 8;
  do {
    if (iVar5 < iVar2) {
      *(undefined4 *)(iVar4 + (int)param_1) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar4);
  return;
}


/*
 * FUN_004258a8 at 004258a8
 * undefined4 __cdecl FUN_004258a8(ushort * param_1, uint * param_2, int * param_3)
 * Address ranges: 004258a8-00425a13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004258a8(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)*param_1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_00425800((int *)&local_10);
    if (iVar2 != 0) {
LAB_004259d4:
      uVar5 = 0;
      goto LAB_004259d6;
    }
    FUN_004257f4(&local_10);
  }
  else {
    FUN_004257d9((int)local_1c,&local_10);
    iVar2 = FUN_0042574d((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_004257f4(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_004257f4(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_0042581b(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_004259d6;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_0042581b(&local_10,param_3[3]);
        goto LAB_004259d4;
      }
      FUN_004257d9((int)&local_10,local_1c);
      FUN_0042581b(&local_10,iVar2 - iVar4);
      FUN_0042574d((int)&local_10,param_3[2]);
      FUN_0042581b(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_004259d6:
  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar5;
}


/*
 * FUN_00425a14 at 00425a14
 * undefined __cdecl FUN_00425a14(ushort * param_1, uint * param_2)
 * Address ranges: 00425a14-00425a29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00425a14(ushort *param_1,uint *param_2)

{
  FUN_004258a8(param_1,param_2,(int *)&DAT_00437ab0);
  return;
}


/*
 * FUN_00425a2a at 00425a2a
 * undefined __cdecl FUN_00425a2a(ushort * param_1, uint * param_2)
 * Address ranges: 00425a2a-00425a3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00425a2a(ushort *param_1,uint *param_2)

{
  FUN_004258a8(param_1,param_2,(int *)&DAT_00437ac8);
  return;
}


/*
 * FUN_00425a40 at 00425a40
 * undefined __thiscall FUN_00425a40(void * this, uint * param_1, byte * param_2)
 * Address ranges: 00425a40-00425a6c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_00425a40(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_004267a0(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_00425a14(local_10,param_1);
  return;
}


/*
 * FUN_00425a6d at 00425a6d
 * undefined __thiscall FUN_00425a6d(void * this, uint * param_1, byte * param_2)
 * Address ranges: 00425a6d-00425a99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_00425a6d(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_004267a0(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_00425a2a(local_10,param_1);
  return;
}


/*
 * FUN_00425a9a at 00425a9a
 * undefined __cdecl FUN_00425a9a(char * param_1, int param_2, int param_3)
 * Address ranges: 00425a9a-00425b10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00425a9a(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;
  
  pcVar1 = param_1;
  pcVar4 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar2 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar5 = *pcVar4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        pcVar4 = pcVar4 + 1;
      }
      *pcVar2 = cVar5;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  *pcVar2 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar4)) {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
      *pcVar2 = '0';
    }
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*pcVar1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar3 = _strlen(_Str);
    FUN_00425c30((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}


/*
 * FUN_00425b11 at 00425b11
 * undefined * __stdcall FUN_00425b11(void)
 * Address ranges: 00425b11-00425b74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00425b11(void)

{
  undefined4 in_stack_ffffffd8;
  undefined2 uVar1;
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar1 = (undefined2)((uint)in_stack_ffffffd8 >> 0x10);
  FUN_00425b75(&local_10,(uint *)&stack0x00000004);
  _DAT_0043e568 = FUN_00426c71(local_10,uStack_c,CONCAT22(uVar1,uStack_8),0x11,0,&DAT_0043e540);
  _DAT_0043e560 = (int)DAT_0043e542;
  _DAT_0043e564 = (int)DAT_0043e540;
  _DAT_0043e56c = &DAT_0043e544;
  return &DAT_0043e560;
}


/*
 * FUN_00425b75 at 00425b75
 * undefined __cdecl FUN_00425b75(uint * param_1, uint * param_2)
 * Address ranges: 00425b75-00425c2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00425b75(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *param_2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  param_1[1] = local_8;
  *param_1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *param_1 >> 0x1f | local_8 * 2;
    *param_1 = *param_1 * 2;
    param_1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return;
}


/*
 * FUN_00425c30 at 00425c30
 * undefined4 * __cdecl FUN_00425c30(undefined4 * param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 00425c30-00425c8a;00425c8c-00425c92;00425ca0-00425cc8;00425ccc-00425cee;00425cf0-00425d08;00425d2c-00425d75;00425d88-00425d8e;00425d90-00425d9a;00425d9c-00425dac;00425db0-00425dc6;00425dc8-00425ded;00425df0-00425df8;00425dfc-00425e1a;00425e28-00425e44;00425e48-00425e6e;00425e70-00425ea0;00425ec4-00425f0d;00425f20-00425f26;00425f28-00425f34;00425f38-00425f4a;00425f4c-00425f64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __cdecl FUN_00425c30(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_00425de7_caseD_2;
        case 3:
          goto switchD_00425de7_caseD_3;
        }
        goto switchD_00425de7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00425de7_caseD_0;
      case 1:
        goto switchD_00425de7_caseD_1;
      case 2:
        goto switchD_00425de7_caseD_2;
      case 3:
        goto switchD_00425de7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00425de7_caseD_2;
            case 3:
              goto switchD_00425de7_caseD_3;
            }
            goto switchD_00425de7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00425de7_caseD_2;
            case 3:
              goto switchD_00425de7_caseD_3;
            }
            goto switchD_00425de7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00425de7_caseD_2;
            case 3:
              goto switchD_00425de7_caseD_3;
            }
            goto switchD_00425de7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_00425de7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_00425de7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_00425de7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_00425de7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00425c65_caseD_2;
      case 3:
        goto switchD_00425c65_caseD_3;
      }
      goto switchD_00425c65_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00425c65_caseD_0;
    case 1:
      goto switchD_00425c65_caseD_1;
    case 2:
      goto switchD_00425c65_caseD_2;
    case 3:
      goto switchD_00425c65_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00425c65_caseD_2;
          case 3:
            goto switchD_00425c65_caseD_3;
          }
          goto switchD_00425c65_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00425c65_caseD_2;
          case 3:
            goto switchD_00425c65_caseD_3;
          }
          goto switchD_00425c65_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00425c65_caseD_2;
          case 3:
            goto switchD_00425c65_caseD_3;
          }
          goto switchD_00425c65_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00425c65_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00425c65_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00425c65_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00425c65_caseD_0:
  return param_1;
}


/*
 * FUN_00425f65 at 00425f65
 * undefined __stdcall FUN_00425f65(void)
 * Address ranges: 00425f65-00425f6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00425f65(void)

{
  __amsg_exit(2);
  return;
}


/*
 * FUN_00425f6e at 00425f6e
 * int __stdcall FUN_00425f6e(int * param_1)
 * Address ranges: 00425f6e-00425fb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00425f6e(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_0042405c();
    return iVar3;
  }
  if ((DAT_0043e570 != (FARPROC)0x0) &&
     (bVar2 = FUN_0042600a(DAT_0043e570), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_0043e570)(param_1);
    return iVar3;
  }
  return 0;
}


/*
 * FUN_00425fb4 at 00425fb4
 * undefined FUN_00425fb4(void)
 * Address ranges: 00425fb4-00425fc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00425fb4(void)

{
  DAT_0043e570 = SetUnhandledExceptionFilter(FUN_00425f6e);
  return;
}


/*
 * FUN_00425fd2 at 00425fd2
 * bool __cdecl FUN_00425fd2(void * param_1, UINT_PTR param_2)
 * Address ranges: 00425fd2-00425fed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_00425fd2(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


/*
 * FUN_00425fee at 00425fee
 * bool __cdecl FUN_00425fee(LPVOID param_1, UINT_PTR param_2)
 * Address ranges: 00425fee-00426009
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_00425fee(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}


/*
 * FUN_0042600a at 0042600a
 * bool __cdecl FUN_0042600a(FARPROC param_1)
 * Address ranges: 0042600a-00426021
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool __cdecl FUN_0042600a(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}


/*
 * _strcmp at 00426030
 * int __cdecl _strcmp(char * _Str1, char * _Str2)
 * Address ranges: 00426030-00426072;00426074-00426079;0042607c-004260b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _strcmp  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_00426074;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00426040;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_00426074;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_00426074;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_00426040:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_00426074:
  return (uint)bVar5 * -2 + 1;
}


/*
 * FUN_004260b4 at 004260b4
 * undefined __stdcall FUN_004260b4(void)
 * Address ranges: 004260b4-004260ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004260b4(void)

{
  FUN_00421741(10);
  FUN_00426f04(0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


/*
 * FUN_004260cb at 004260cb
 * int * __cdecl FUN_004260cb(int param_1, int param_2)
 * Address ranges: 004260cb-00426147
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_004260cb(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *_Size;
  uint *puVar3;
  
  _Size = (uint *)(param_1 * param_2);
  puVar3 = _Size;
  if (_Size < (uint *)0xffffffe1) {
    if (_Size == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar3 < (uint *)0xffffffe1) {
      if ((_Size < DAT_00437490 || (int)_Size - (int)DAT_00437490 == 0) &&
         (piVar1 = FUN_00422ebb(_Size), piVar1 != (int *)0x0)) {
        _memset(piVar1,0,(size_t)_Size);
        return piVar1;
      }
      piVar1 = HeapAlloc(DAT_0043f81c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_0043e578 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_004262e6(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}


/*
 * FUN_004261a0 at 004261a0
 * int __cdecl FUN_004261a0(uint param_1, int param_2)
 * Address ranges: 004261a0-004262e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_004261a0(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  HANDLE hFile;
  BOOL BVar6;
  int iVar7;
  uint uVar8;
  char local_1004 [4060];
  undefined4 uStackY_28;
  
  FUN_004265d0();
  iVar7 = 0;
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    DVar1 = FUN_00422935(param_1,0,1);
    if ((DVar1 != 0xffffffff) && (DVar2 = FUN_00422935(param_1,0,2), DVar2 != 0xffffffff)) {
      uVar8 = param_2 - DVar2;
      if ((int)uVar8 < 1) {
        if ((int)uVar8 < 0) {
          FUN_00422935(param_1,param_2,0);
          hFile = (HANDLE)FUN_004242f5(param_1);
          BVar6 = SetEndOfFile(hFile);
          iVar7 = (BVar6 != 0) - 1;
          if (iVar7 == -1) {
            _DAT_0043e2c0 = 0xd;
            DAT_0043e2c4 = GetLastError();
          }
        }
      }
      else {
        _memset(local_1004,0,0x1000);
        uStackY_28 = 0x426230;
        iVar3 = FUN_00427076(param_1,0x8000);
        do {
          uVar4 = 0x1000;
          if ((int)uVar8 < 0x1000) {
            uVar4 = uVar8;
          }
          iVar5 = FUN_00423666(param_1,local_1004,uVar4);
          if (iVar5 == -1) {
            if (DAT_0043e2c4 == 5) {
              _DAT_0043e2c0 = 0xd;
            }
            iVar7 = -1;
            break;
          }
          uVar8 = uVar8 - iVar5;
        } while (0 < (int)uVar8);
        FUN_00427076(param_1,iVar3);
      }
      FUN_00422935(param_1,DVar1,0);
      return iVar7;
    }
  }
  else {
    _DAT_0043e2c0 = 9;
  }
  return -1;
}


/*
 * FUN_004262e6 at 004262e6
 * undefined4 __cdecl FUN_004262e6(undefined4 param_1)
 * Address ranges: 004262e6-00426300
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004262e6(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_0043e57c != (code *)0x0) {
    iVar1 = (*DAT_0043e57c)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


/*
 * FUN_00426301 at 00426301
 * int __cdecl FUN_00426301(LCID param_1, uint param_2, char * param_3, int param_4, LPWSTR param_5, int param_6, UINT param_7, int param_8)
 * Address ranges: 00426301-00426410;00426424-004264c4;004264d7-00426524
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl
FUN_00426301(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042a4b8;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_0043e5a0 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_0043e5a0 = 2;
    }
    else {
      DAT_0043e5a0 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_00426525(param_3,param_4);
  }
  if (DAT_0043e5a0 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_0043e5a0 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_0043e598;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_004265d0();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_004265d0();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5
                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (param_6 == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (param_6 < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}


/*
 * FUN_00426525 at 00426525
 * int __cdecl FUN_00426525(char * param_1, int param_2)
 * Address ranges: 00426525-0042654f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00426525(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 != '\0') {
    return param_2;
  }
  return (int)pcVar1 - (int)param_1;
}


/*
 * FUN_00426550 at 00426550
 * int __cdecl FUN_00426550(uchar * param_1)
 * Address ranges: 00426550-004265cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00426550(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_0043f924 != 0) &&
      ((DAT_0043e2e8 != (int *)0x0 ||
       (((DAT_0043e2f0 != 0 && (iVar1 = FUN_0042712b(), iVar1 == 0)) && (DAT_0043e2e8 != (int *)0x0)
        ))))) && (piVar3 = DAT_0043e2e8, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}


/*
 * FUN_004265d0 at 004265d0
 * undefined __stdcall FUN_004265d0(void)
 * Address ranges: 004265d0-004265fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Unable to track spacebase fully for stack */

void FUN_004265d0(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}


/*
 * FUN_004265ff at 004265ff
 * undefined4 __cdecl FUN_004265ff(uint param_1, uint param_2, uint * param_3)
 * Address ranges: 004265ff-0042661f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004265ff(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}


/*
 * ___add_12 at 00426620
 * undefined __cdecl ___add_12(uint * param_1, uint * param_2)
 * Address ranges: 00426620-0042667d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  ___add_12  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_004265ff(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004265ff(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_004265ff(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_004265ff(param_1[2],param_2[2],param_1 + 2);
  return;
}


/*
 * FUN_0042667e at 0042667e
 * undefined __cdecl FUN_0042667e(uint * param_1)
 * Address ranges: 0042667e-004266ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0042667e(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}


/*
 * FUN_004266ac at 004266ac
 * undefined __cdecl FUN_004266ac(uint * param_1)
 * Address ranges: 004266ac-004266d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004266ac(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}


/*
 * FUN_004266d9 at 004266d9
 * undefined __cdecl FUN_004266d9(char * param_1, int param_2, uint * param_3)
 * Address ranges: 004266d9-0042679f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004266d9(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar1 = param_3;
  local_8 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      FUN_0042667e(puVar1);
      FUN_0042667e(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_0042667e(puVar1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*param_1;
      ___add_12(puVar1,&local_14);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  while (puVar1[2] == 0) {
    puVar1[2] = puVar1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
    *puVar1 = *puVar1 << 0x10;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    FUN_0042667e(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}


/*
 * FUN_004267a0 at 004267a0
 * undefined4 __thiscall FUN_004267a0(void * this, ushort * param_1, int * param_2, byte * param_3, int param_4, int param_5, int param_6, int param_7)
 * Address ranges: 004267a0-00426c40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __thiscall
FUN_004267a0(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = param_3;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_004267f7:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_00426814:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_00426a39;
    }
    if (bVar6 == DAT_00437470) goto LAB_00426823;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_00426b13;
    }
    goto LAB_004267f7;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_00426814;
    iVar9 = iVar1;
    if (bVar6 != DAT_00437470) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_004268a8;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_00426881;
    }
    goto LAB_004267f7;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_00426814;
    if (bVar6 == DAT_00437470) {
LAB_00426823:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_00426b18;
    }
    goto LAB_004267f7;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_0043746c < 2) {
        uVar3 = (byte)PTR_DAT_00437260[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_00437260;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_0042240c(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_00437470) goto LAB_00426995;
    goto LAB_004267f7;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_0043746c < 2) {
        uVar3 = (byte)PTR_DAT_00437260[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_00437260;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_0042240c(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_00426995:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_004268a8:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_00426881:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_00426b13;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_004267f7;
  case 5:
    local_28 = iVar5;
    if (DAT_0043746c < 2) {
      uVar3 = (byte)PTR_DAT_00437260[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_00437260;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_0042240c(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_00426a39;
    goto LAB_00426b18;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_00426a6e;
      if (bVar6 == 0x2d) goto LAB_00426a62;
      if (bVar6 != 0x30) goto LAB_00426b18;
LAB_00426a07:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_004267f7;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_00426a07;
      goto LAB_00426b18;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_00426b13;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_00426a99;
  default:
    goto switchD_00426803_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_00426a6e:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_00426b18;
LAB_00426a62:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_004267f7;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_00426803_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_004267f7;
    goto LAB_00426b18;
  }
  iVar9 = 9;
LAB_00426a39:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_004267f7;
LAB_00426a99:
  if (DAT_0043746c < 2) {
    uVar3 = (byte)PTR_DAT_00437260[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_00437260;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_0042240c(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_00426ae3;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_00426adb;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_00426a99;
LAB_00426adb:
  pbVar7 = (byte *)0x1451;
LAB_00426ae3:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_0043746c < 2) {
      uVar3 = (byte)PTR_DAT_00437260[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_00437260;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_0042240c(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_00426b13:
  pbVar7 = pbVar8 + -1;
LAB_00426b18:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_00426c26;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_004266d9(local_60,local_8,(uint *)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + param_5;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -param_6;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_004273b9((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_00426bab;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44 = local_3a;
  }
LAB_00426bab:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_00426c26:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}


/*
 * FUN_00426c71 at 00426c71
 * undefined4 __cdecl FUN_00426c71(uint param_1, uint param_2, uint param_3, int param_4, byte param_5, short * param_6)
 * Address ranges: 00426c71-00426f03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_00426c71(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;
  
  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 != 0) || (param_2 != 0)) || (param_1 != 0)) {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_00426d66;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_00426d66:
            pcVar11 = "1#QNAN";
            goto LAB_00426d6b;
          }
          pcVar11 = "1#IND";
        }
        FUN_0041f7a0((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_00426d6b:
        FUN_0041f7a0((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 6;
      }
      return 0;
    }
    local_14 = 0;
    local_a = (undefined1)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_004273b9((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_00427199((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    iVar10 = param_4;
    if (((param_5 & 1) == 0) || (iVar10 = param_4 + sVar8, 0 < param_4 + sVar8)) {
      if (0x15 < iVar10) {
        iVar10 = 0x15;
      }
      iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
      local_a = 0;
      cStack_9 = '\0';
      param_6 = (short *)0x8;
      do {
        FUN_0042667e((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_004266ac((uint *)&local_14);
        }
      }
      param_4 = iVar10 + 1;
      psVar6 = psVar3 + 2;
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      if (0 < param_4) {
        do {
          local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
          local_e._0_2_ = (undefined2)uVar2;
          local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
          local_12._0_2_ = (undefined2)uVar5;
          param_1 = CONCAT22((undefined2)local_12,local_14);
          param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
          local_12 = uVar5;
          local_e = uVar2;
          FUN_0042667e((uint *)&local_14);
          FUN_0042667e((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_0042667e((uint *)&local_14);
          cVar4 = cStack_9;
          cStack_9 = '\0';
          psVar6 = (short *)((int)param_6 + 1);
          param_4 = param_4 + -1;
          *(char *)param_6 = cVar4 + '0';
          param_6 = psVar6;
          uVar5 = local_12;
          uVar2 = local_e;
        } while (param_4 != 0);
      }
      psVar7 = psVar6 + -1;
      psVar1 = psVar3 + 2;
      if ('4' < *(char *)((int)psVar6 + -1)) {
        for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
          if ((char)*psVar7 != '9') {
            if (psVar1 <= psVar7) goto LAB_00426ec3;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_00426ec3:
        *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_00426ec5:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_00426ec5;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined1 *)(psVar3 + 1) = 0x20;
      *(undefined1 *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_00426efb;
    }
  }
  *psVar3 = 0;
  *(undefined1 *)(psVar3 + 1) = 0x20;
  *(undefined1 *)((int)psVar3 + 3) = 1;
  *(undefined1 *)(psVar3 + 2) = 0x30;
LAB_00426efb:
  *(undefined1 *)((int)psVar3 + 5) = 0;
  return 1;
}


/*
 * FUN_00426f04 at 00426f04
 * undefined4 __cdecl FUN_00426f04(int param_1)
 * Address ranges: 00426f04-00427030
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00426f04(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  
  iVar2 = param_1;
  if (param_1 == 2) {
    puVar3 = &DAT_0043e5a4;
    pcVar6 = DAT_0043e5a4;
  }
  else if (((param_1 == 4) || (param_1 == 8)) || (param_1 == 0xb)) {
    puVar3 = FUN_00427031(param_1);
    pcVar6 = (code *)puVar3[2];
    puVar3 = puVar3 + 2;
  }
  else if (param_1 == 0xf) {
    puVar3 = &DAT_0043e5b0;
    pcVar6 = DAT_0043e5b0;
  }
  else if (param_1 == 0x15) {
    puVar3 = &DAT_0043e5a8;
    pcVar6 = DAT_0043e5a8;
  }
  else {
    if (param_1 != 0x16) {
      return 0xffffffff;
    }
    puVar3 = &DAT_0043e5ac;
    pcVar6 = DAT_0043e5ac;
  }
  iVar1 = DAT_0043e330;
  iVar4 = DAT_004371b4;
  if (pcVar6 == (code *)0x1) {
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (iVar5 = param_1, param_1 == 4)) {
    DAT_0043e330 = 0;
    iVar5 = iVar1;
    if (param_1 == 8) {
      DAT_004371b4 = 0x8c;
      param_1 = iVar4;
      goto LAB_00426fc8;
    }
LAB_00426ff4:
    *puVar3 = 0;
    if (iVar2 != 8) {
      (*pcVar6)(iVar2);
      if ((iVar2 != 0xb) && (iVar2 != 4)) {
        return 0;
      }
      goto LAB_00427017;
    }
  }
  else {
LAB_00426fc8:
    if (iVar2 != 8) goto LAB_00426ff4;
    if (DAT_004371a8 < DAT_004371ac + DAT_004371a8) {
      iVar4 = (DAT_004371ac + DAT_004371a8) - DAT_004371a8;
      puVar3 = (undefined4 *)(DAT_004371a8 * 0xc + 0x437138);
      do {
        *puVar3 = 0;
        puVar3 = puVar3 + 3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  (*pcVar6)(8,DAT_004371b4);
LAB_00427017:
  if (iVar2 == 8) {
    DAT_004371b4 = param_1;
  }
  DAT_0043e330 = iVar5;
  return 0;
}


/*
 * FUN_00427031 at 00427031
 * undefined4 * __cdecl FUN_00427031(int param_1)
 * Address ranges: 00427031-00427075
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __cdecl FUN_00427031(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00437130;
  if (DAT_00437134 != param_1) {
    puVar3 = puVar2;
    do {
      puVar2 = puVar3 + 3;
      if (&DAT_00437130 + DAT_004371b0 * 3 <= puVar2) break;
      piVar1 = puVar3 + 4;
      puVar3 = puVar2;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_00437130 + DAT_004371b0 * 3 <= puVar2) || (puVar2[1] != param_1)) {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}


/*
 * FUN_00427076 at 00427076
 * int __cdecl FUN_00427076(uint param_1, int param_2)
 * Address ranges: 00427076-004270eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00427076(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 < DAT_0043f920) {
    bVar1 = *(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8);
    if ((bVar1 & 1) != 0) {
      if (param_2 == 0x8000) {
        bVar2 = bVar1 & 0x7f;
      }
      else {
        if (param_2 != 0x4000) {
          _DAT_0043e2c0 = 0x16;
          return -1;
        }
        bVar2 = bVar1 | 0x80;
      }
      *(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) = bVar2;
      return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  _DAT_0043e2c0 = 9;
  return -1;
}


/*
 * __mbsnbicoll at 004270ec
 * int __cdecl __mbsnbicoll(uchar * _Str1, uchar * _Str2, size_t _MaxCount)
 * Address ranges: 004270ec-0042712a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __mbsnbicoll  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_00427435(DAT_0043e7e4,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_0043e5bc);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}


/*
 * FUN_0042712b at 0042712b
 * undefined4 __stdcall FUN_0042712b(void)
 * Address ranges: 0042712b-00427198
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_0042712b(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWSTR)*DAT_0043e2f0;
  puVar2 = DAT_0043e2f0;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_004276b2(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}


/*
 * FUN_00427199 at 00427199
 * undefined __cdecl FUN_00427199(int * param_1, int * param_2)
 * Address ranges: 00427199-004273b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00427199(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_0042723c:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_0042723c;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_004265ff(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_004272f0:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_004266ac((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_0042667e((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_004272f0;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_00427399;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_00427399:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}


/*
 * FUN_004273b9 at 004273b9
 * undefined __cdecl FUN_004273b9(int * param_1, uint param_2, int param_3)
 * Address ranges: 004273b9-00427434
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004273b9(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  int iStack_8;
  
  iVar3 = 0x437a80;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0x437be0;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      iVar3 = iVar3 + 0x54;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        piVar4 = (int *)(iVar3 + uVar2 * 0xc);
        if (0x7fff < *(ushort *)(iVar3 + uVar2 * 0xc)) {
          local_10 = (undefined2)*piVar4;
          local_e._0_2_ = (undefined2)((uint)*piVar4 >> 0x10);
          local_e._2_2_ = (undefined2)piVar4[1];
          uStack_a = (undefined2)((uint)piVar4[1] >> 0x10);
          iStack_8 = piVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          piVar4 = (int *)&local_10;
        }
        FUN_00427199(param_1,piVar4);
      }
    }
  }
  return;
}


/*
 * FUN_00427435 at 00427435
 * int __cdecl FUN_00427435(LCID param_1, DWORD param_2, byte * param_3, int param_4, byte * param_5, int param_6, UINT param_7)
 * Address ranges: 00427435-004275eb;00427602-0042765a;0042766d-004276b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl
FUN_00427435(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  undefined1 *puVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  int iVar5;
  _cpinfo local_40;
  undefined1 *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0042a4f0;
  pcStack_10 = FUN_00421630;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_0043e5b8 == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,"",1,"",1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_0043e5b8 = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_0043e5b8 = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_00426525((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_00426525((char *)param_5,param_6);
  }
  if (DAT_0043e5b8 == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_0043e5b8 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_0043e598;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        ExceptionList = local_14;
        return 2;
      }
      if (1 < param_6) {
        ExceptionList = local_14;
        return 1;
      }
      if (1 < param_4) {
        ExceptionList = local_14;
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (0 < param_4) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 3;
      }
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 1;
      }
    }
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_004265d0();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_004265d0();
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined1 *)0x50) &&
             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,
             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,
                                         iVar2), iVar5 != 0)) {
            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2
                                  );
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}


/*
 * FUN_004276b2 at 004276b2
 * undefined4 __cdecl FUN_004276b2(uint * param_1, int param_2)
 * Address ranges: 004276b2-00427838
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004276b2(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  undefined1 *puVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = FUN_00427a18(param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(char *)((int)puVar1 + 1) == '\0';
  if (DAT_0043e2e8 == DAT_0043e2ec) {
    DAT_0043e2e8 = FUN_00427891(DAT_0043e2e8);
  }
  if (DAT_0043e2e8 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0043e2f0 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_0043e2e8 = _malloc(4);
      if (DAT_0043e2e8 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0043e2e8 = 0;
      if (DAT_0043e2f0 == (undefined4 *)0x0) {
        DAT_0043e2f0 = _malloc(4);
        if (DAT_0043e2f0 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_0043e2f0 = 0;
      }
    }
    else {
      iVar2 = FUN_0042712b();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_0043e2e8;
  iVar2 = FUN_00427839((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_004278f8(piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_004277e6;
    }
    piVar6 = piVar3 + iVar2;
    FUN_0041fd93((LPVOID)piVar3[iVar2]);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_004278f8(piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_004277e6;
  }
  DAT_0043e2e8 = piVar3;
LAB_004277e6:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      FUN_0041f7a0(lpName,param_1);
      puVar5 = (undefined1 *)(((int)lpName - (int)param_1) + (int)puVar1);
      *puVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(puVar5 + 1)));
      FUN_0041fd93(lpName);
    }
  }
  return 0;
}


/*
 * FUN_00427839 at 00427839
 * int __cdecl FUN_00427839(uchar * param_1, size_t param_2)
 * Address ranges: 00427839-00427890
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00427839(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_0043e2e8;
  piVar2 = DAT_0043e2e8;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_0043e2e8 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_0043e2e8 >> 2;
}


/*
 * FUN_00427891 at 00427891
 * undefined4 * __cdecl FUN_00427891(int * param_1)
 * Address ranges: 00427891-004278f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __cdecl FUN_00427891(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    puVar4 = (uint *)*param_1;
    puVar6 = puVar3;
    while (puVar4 != (uint *)0x0) {
      param_1 = param_1 + 1;
      puVar4 = FUN_00427a8b(puVar4);
      *puVar6 = puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}


/*
 * FUN_004278f8 at 004278f8
 * int * __cdecl FUN_004278f8(int * param_1, uint * param_2)
 * Address ranges: 004278f8-00427a17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_004278f8(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_0041fd93(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          puVar2 = (uint *)FUN_00422b65((int)param_1);
          if (puVar2 == (uint *)0x0) {
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_0043f81c,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (param_2 <= DAT_00437490) {
              iVar3 = FUN_00423370(puVar2,(int)param_1,(int)param_2);
              piVar1 = param_1;
              if (iVar3 == 0) {
                piVar1 = FUN_00422ebb(param_2);
                if (piVar1 == (int *)0x0) goto LAB_00427991;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_00420910(piVar1,param_1,(uint)puVar4);
                FUN_00422b90(puVar2,(uint)param_1);
              }
              if (piVar1 != (int *)0x0) {
                return piVar1;
              }
            }
LAB_00427991:
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapAlloc(DAT_0043f81c,0,(SIZE_T)param_2);
            if (piVar1 == (int *)0x0) goto LAB_004279f4;
            puVar4 = (uint *)(param_1[-1] - 1U);
            if (param_2 <= (uint *)(param_1[-1] - 1U)) {
              puVar4 = param_2;
            }
            FUN_00420910(piVar1,param_1,(uint)puVar4);
            FUN_00422b90(puVar2,(uint)param_1);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
LAB_004279f4:
        if (DAT_0043e578 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_004262e6(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


/*
 * FUN_00427a18 at 00427a18
 * uint * __cdecl FUN_00427a18(uint * param_1, uint param_2)
 * Address ranges: 00427a18-00427a8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_00427a18(uint *param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  
  if (DAT_0043e5cc == 0) {
    puVar2 = FUN_00422350(param_1,(char)param_2);
    return puVar2;
  }
  while( true ) {
    uVar1 = (ushort)(byte)*param_1;
    if (uVar1 == 0) break;
    if ((*(byte *)((int)&DAT_0043e6e0 + uVar1 + 1) & 4) == 0) {
      puVar2 = param_1;
      if (param_2 == uVar1) break;
    }
    else {
      puVar2 = (uint *)((int)param_1 + 1);
      if (*(byte *)((int)param_1 + 1) == 0) {
        return (uint *)0x0;
      }
      if (param_2 == CONCAT11((byte)*param_1,*(byte *)((int)param_1 + 1))) {
        return param_1;
      }
    }
    param_1 = (uint *)((int)puVar2 + 1);
  }
  return (uint *)(~-(uint)(param_2 != uVar1) & (uint)param_1);
}


/*
 * FUN_00427a8b at 00427a8b
 * uint * __cdecl FUN_00427a8b(uint * param_1)
 * Address ranges: 00427a8b-00427ab5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_00427a8b(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  
  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_0041f7a0(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}


/*
 * AVIFIL32.DLL::AVIStreamRelease at 00427ac0
 * undefined AVIStreamRelease(void)
 * Address ranges: 00427ac0-00427ac5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to AVIFIL32.DLL::AVIStreamRelease
 */


void AVIStreamRelease(void)

{
                    /* WARNING: Could not recover jumptable at 0x00427ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamRelease();
  return;
}


/*
 * AVIFIL32.DLL::AVIStreamInfoA at 00427ac6
 * undefined AVIStreamInfoA(void)
 * Address ranges: 00427ac6-00427acb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to AVIFIL32.DLL::AVIStreamInfoA
 */


void AVIStreamInfoA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00427ac6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamInfoA();
  return;
}


/*
 * AVIFIL32.DLL::AVIStreamOpenFromFileA at 00427acc
 * undefined AVIStreamOpenFromFileA(void)
 * Address ranges: 00427acc-00427ad1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to AVIFIL32.DLL::AVIStreamOpenFromFileA
 */


void AVIStreamOpenFromFileA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00427acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamOpenFromFileA();
  return;
}


/*
 * AVIFIL32.DLL::AVIFileInit at 00427ad2
 * undefined AVIFileInit(void)
 * Address ranges: 00427ad2-00427ad7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to AVIFIL32.DLL::AVIFileInit
 */


void AVIFileInit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00427ad2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileInit();
  return;
}


/*
 * AVIFIL32.DLL::AVIFileExit at 00427ad8
 * undefined AVIFileExit(void)
 * Address ranges: 00427ad8-00427add
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to AVIFIL32.DLL::AVIFileExit
 */


void AVIFileExit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00427ad8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileExit();
  return;
}


/*
 * KERNEL32.DLL::RtlUnwind at 00427ade
 * void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
 * Address ranges: 00427ade-00427ae3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::RtlUnwind
 */


void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x00427ade. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}


/*
 * FUN_00427ae4 at 00427ae4
 * undefined __cdecl FUN_00427ae4(uint * param_1, size_t param_2)
 * Address ranges: 00427ae4-00427af6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00427ae4(uint *param_1,size_t param_2)

{
  FUN_00427af7(0,param_1,param_2);
  return;
}


/*
 * FUN_00427af7 at 00427af7
 * uint * __cdecl FUN_00427af7(uint param_1, uint * param_2, size_t param_3)
 * Address ranges: 00427af7-00427bc7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl FUN_00427af7(uint param_1,uint *param_2,size_t param_3)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  uint *puVar4;
  uint local_10c [65];
  LPSTR local_8;
  
  uVar3 = param_1;
  if (param_1 == 0) {
    DVar2 = GetCurrentDirectoryA(0x104,(LPSTR)local_10c);
  }
  else {
    iVar1 = FUN_00427bc8(param_1);
    if (iVar1 == 0) {
      _DAT_0043e2c0 = 0xd;
      DAT_0043e2c4 = 0xf;
      return (uint *)0x0;
    }
    param_1 = (uint)CONCAT12(0x2e,CONCAT11(0x3a,(char)uVar3 + '@'));
    DVar2 = GetFullPathNameA((LPCSTR)&param_1,0x104,(LPSTR)local_10c,&local_8);
  }
  if ((DVar2 != 0) && (uVar3 = DVar2 + 1, uVar3 < 0x105)) {
    if (param_2 == (uint *)0x0) {
      if ((int)uVar3 <= (int)param_3) {
        uVar3 = param_3;
      }
      puVar4 = _malloc(uVar3);
      if (puVar4 != (uint *)0x0) {
LAB_00427bb4:
        puVar4 = FUN_0041f7a0(puVar4,local_10c);
        return puVar4;
      }
      _DAT_0043e2c0 = 0xc;
    }
    else {
      puVar4 = param_2;
      if ((int)uVar3 <= (int)param_3) goto LAB_00427bb4;
      _DAT_0043e2c0 = 0x22;
    }
  }
  return (uint *)0x0;
}


/*
 * FUN_00427bc8 at 00427bc8
 * undefined4 __cdecl FUN_00427bc8(uint param_1)
 * Address ranges: 00427bc8-00427bfe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00427bc8(uint param_1)

{
  char cVar1;
  UINT UVar2;
  
  if (param_1 != 0) {
    cVar1 = (char)param_1;
    param_1 = (uint)CONCAT12(0x5c,CONCAT11(0x3a,cVar1 + '@'));
    UVar2 = GetDriveTypeA((LPCSTR)&param_1);
    if ((UVar2 == 0) || (UVar2 == 1)) {
      return 0;
    }
  }
  return 1;
}


/*
 * FUN_00427bff at 00427bff
 * char * __cdecl FUN_00427bff(uint param_1, char * param_2, uint param_3)
 * Address ranges: 00427bff-00427c2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_00427bff(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 == 10) && ((int)param_1 < 0)) {
    iVar1 = 1;
    param_3 = 10;
  }
  else {
    iVar1 = 0;
  }
  FUN_00427c2c(param_1,param_2,param_3,iVar1);
  return param_2;
}


/*
 * FUN_00427c2c at 00427c2c
 * undefined __cdecl FUN_00427c2c(uint param_1, char * param_2, uint param_3, int param_4)
 * Address ranges: 00427c2c-00427c87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00427c2c(uint param_1,char *param_2,uint param_3,int param_4)

{
  ulonglong uVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  
  pcVar2 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    param_2 = param_2 + 1;
    param_1 = -param_1;
    pcVar2 = param_2;
  }
  do {
    pcVar3 = pcVar2;
    uVar1 = (ulonglong)param_1;
    param_1 = param_1 / param_3;
    cVar4 = (char)(uVar1 % (ulonglong)param_3);
    if ((uint)(uVar1 % (ulonglong)param_3) < 10) {
      cVar4 = cVar4 + '0';
    }
    else {
      cVar4 = cVar4 + 'W';
    }
    *pcVar3 = cVar4;
    pcVar2 = pcVar3 + 1;
  } while (param_1 != 0);
  pcVar3[1] = '\0';
  do {
    cVar4 = *pcVar3;
    *pcVar3 = *param_2;
    *param_2 = cVar4;
    pcVar3 = pcVar3 + -1;
    param_2 = param_2 + 1;
  } while (param_2 < pcVar3);
  return;
}


/*
 * __strcmpi at 00427c90
 * int __cdecl __strcmpi(char * _Str1, char * _Str2)
 * Address ranges: 00427c90-00427d1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __strcmpi  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    __strcmpi
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl __strcmpi(char *_Str1,char *_Str2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint uVar7;
  void *in_ECX;
  void *this;
  void *extraout_ECX;
  uint uVar8;
  int iVar6;
  
  if (DAT_0043e588 == 0) {
    bVar4 = 0xff;
    do {
      do {
        cVar5 = '\0';
        if (bVar4 == 0) goto LAB_00427cde;
        bVar4 = *_Str2;
        _Str2 = _Str2 + 1;
        bVar3 = *_Str1;
        _Str1 = _Str1 + 1;
      } while (bVar3 == bVar4);
      bVar2 = bVar4 + 0xbf + (-((byte)(bVar4 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar3 = bVar3 + 0xbf;
      bVar4 = bVar3 + (-(bVar3 < 0x1a) & 0x20U) + 0x41;
    } while (bVar4 == bVar2);
    cVar5 = (bVar4 < bVar2) * -2 + '\x01';
LAB_00427cde:
    iVar6 = (int)cVar5;
  }
  else {
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') {
          return uVar7;
        }
        cVar5 = *_Str2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),cVar5);
        _Str2 = _Str2 + 1;
        cVar1 = *_Str1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),cVar1);
        _Str1 = _Str1 + 1;
      } while (cVar5 == cVar1);
      uVar8 = FUN_004255e3(in_ECX,uVar8);
      uVar7 = FUN_004255e3(this,uVar7);
      in_ECX = extraout_ECX;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar7 = (uint)((byte)uVar8 < (byte)uVar7);
    iVar6 = (1 - uVar7) - (uint)(uVar7 != 0);
  }
  return iVar6;
}


/*
 * FUN_00427d1c at 00427d1c
 * DWORD __cdecl FUN_00427d1c(uint param_1)
 * Address ranges: 00427d1c-00427d93
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_00427d1c(uint param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    DVar1 = FUN_00422935(param_1,0,1);
    DVar2 = 0xffffffff;
    if (DVar1 != 0xffffffff) {
      DVar2 = FUN_00422935(param_1,0,2);
      if (DVar1 != DVar2) {
        FUN_00422935(param_1,DVar1,0);
      }
    }
    return DVar2;
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}


/*
 * FUN_00427d94 at 00427d94
 * undefined4 __cdecl FUN_00427d94(int param_1)
 * Address ranges: 00427d94-00427d9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00427d94(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


/*
 * FUN_00427da0 at 00427da0
 * undefined4 __cdecl FUN_00427da0(byte * param_1, char * param_2, void * param_3)
 * Address ranges: 00427da0-00427e4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00427da0(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  void *this;
  uint uVar6;
  bool bVar7;
  
  uVar5 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_0043e588 == 0) {
      do {
        bVar2 = *param_1;
        cVar1 = *param_2;
        uVar3 = CONCAT11(bVar2,cVar1);
        if (bVar2 == 0) break;
        uVar3 = CONCAT11(bVar2,cVar1);
        uVar6 = (uint)uVar3;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar6 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
        }
        uVar3 = (ushort)uVar6;
        bVar2 = (byte)uVar6;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar3 = (ushort)CONCAT31((int3)(uVar6 >> 8),bVar2 + 0x20);
        }
        bVar2 = (byte)(uVar3 >> 8);
        bVar7 = bVar2 < (byte)uVar3;
        if (bVar2 != (byte)uVar3) goto LAB_00427dfb;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar5 = 0;
      bVar2 = (byte)(uVar3 >> 8);
      bVar7 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) {
LAB_00427dfb:
        uVar5 = 0xffffffff;
        if (!bVar7) {
          uVar5 = 1;
        }
      }
    }
    else {
      uVar4 = 0;
      uVar6 = 0;
      do {
        uVar4 = CONCAT31((int3)(uVar4 >> 8),*param_1);
        uVar6 = CONCAT31((int3)(uVar6 >> 8),*param_2);
        if ((uVar4 == 0) || (uVar6 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar6 = FUN_004255e3(param_3,uVar6);
        uVar4 = FUN_004255e3(this,uVar4);
        bVar7 = uVar4 < uVar6;
        if (uVar4 != uVar6) goto LAB_00427e3d;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar5 = 0;
      bVar7 = uVar4 < uVar6;
      if (uVar4 != uVar6) {
LAB_00427e3d:
        uVar5 = 0xffffffff;
        if (!bVar7) {
          uVar5 = 1;
        }
      }
    }
  }
  return uVar5;
}


/*
 * FUN_00427e4d at 00427e4d
 * uint * __cdecl FUN_00427e4d(uint * param_1)
 * Address ranges: 00427e4d-00427eea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_00427e4d(uint *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  uint *puVar3;
  LPWSTR local_8;
  
  local_8 = (LPWSTR)0x0;
  if (DAT_0043e588 == 0) {
    cVar1 = (char)*param_1;
    puVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = (char)*puVar3;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *(char *)puVar3 = cVar1 + -0x20;
      }
      puVar3 = (uint *)((int)puVar3 + 1);
      cVar1 = *(char *)puVar3;
    }
  }
  else {
    _Size = FUN_00426301(DAT_0043e588,0x200,(char *)param_1,-1,(LPWSTR)0x0,0,0,1);
    if (((_Size != 0) && (local_8 = _malloc(_Size), local_8 != (LPWSTR)0x0)) &&
       (iVar2 = FUN_00426301(DAT_0043e588,0x200,(char *)param_1,-1,local_8,_Size,0,1), iVar2 != 0))
    {
      FUN_0041f7a0(param_1,(uint *)local_8);
    }
    FUN_0041fd93(local_8);
  }
  return param_1;
}


/*
 * Unwind@00427ef0 at 00427ef0
 * undefined __stdcall Unwind@00427ef0(void)
 * Address ranges: 00427ef0-00427ef7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void Unwind_00427ef0(void)

{
  int unaff_EBP;
  
  thunk_FUN_0041e980((int *)(unaff_EBP + -0x78));
  return;
}


/*
 * Unwind@00427f10 at 00427f10
 * undefined __stdcall Unwind@00427f10(void)
 * Address ranges: 00427f10-00427f17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void Unwind_00427f10(void)

{
  int unaff_EBP;
  
  FUN_0041e980(*(int **)(unaff_EBP + -0x10));
  return;
}


