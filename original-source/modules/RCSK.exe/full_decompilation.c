/* Ghidra-generated C-like pseudocode for inspection. Not original source and not a buildable reconstruction. */
/*
 * FUN_00401000 at 00401000
 * int __cdecl FUN_00401000(UINT param_1, undefined * param_2, undefined4 param_3)
 * Address ranges: 00401000-00401083
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00401000(UINT param_1,undefined *param_2,undefined4 param_3)

{
  DWORD DVar1;
  UINT UVar2;
  int iVar3;
  char *lpRootPathName;
  int local_70;
  char local_6c [108];
  
  lpRootPathName = local_6c;
  local_70 = 0;
  DVar1 = GetLogicalDriveStringsA(0x68,local_6c);
  if ((DVar1 != 0) && (local_6c[0] != '\0')) {
    do {
      UVar2 = GetDriveTypeA(lpRootPathName);
      if (UVar2 == param_1) {
        iVar3 = (*(code *)param_2)(lpRootPathName,param_3);
        if (iVar3 == 0) {
          return local_70;
        }
        local_70 = local_70 + 1;
      }
      iVar3 = lstrlenA(lpRootPathName);
      lpRootPathName = lpRootPathName + iVar3 + 1;
    } while (*lpRootPathName != '\0');
    return local_70;
  }
  return 0;
}


/*
 * FUN_00401090 at 00401090
 * undefined FUN_00401090(void)
 * Address ranges: 00401090-00401113
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00401090(byte *param_1,undefined1 *param_2)

{
  HANDLE hObject;
  byte abStack_104 [260];
  
  FUN_0040191e(abStack_104,param_1,&DAT_00408c00,(byte *)s_SHELLTRO_00408054,&DAT_00408060);
  hObject = CreateFileA((LPCSTR)abStack_104,0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  CloseHandle(hObject);
  if (hObject == (HANDLE)0xffffffff) {
    return 1;
  }
  _strncpy(&DAT_00408034,(char *)param_1,0x20);
  *param_2 = 1;
  return 0;
}


/*
 * FUN_00401120 at 00401120
 * undefined1 __fastcall FUN_00401120(uint3 param_1)
 * Address ranges: 00401120-0040113e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __fastcall FUN_00401120(uint3 param_1)

{
  undefined4 uStack_4;
  
  uStack_4 = (uint)param_1;
  FUN_00401000(5,FUN_00401090,(int)&uStack_4 + 3);
  return uStack_4._3_1_;
}


/*
 * FUN_00401140 at 00401140
 * int __cdecl FUN_00401140(uint * param_1, undefined4 param_2)
 * Address ranges: 00401140-00401266
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00401140(uint *param_1,undefined4 param_2)

{
  int iVar1;
  uint **ppuVar2;
  uint *local_600 [128];
  CHAR local_400 [1024];
  
  ppuVar2 = local_600;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (uint *)0x0;
    ppuVar2 = ppuVar2 + 1;
  }
  local_600[0] = param_1;
  local_600[1] = (uint *)param_2;
  iVar1 = FUN_00405c96(0,param_1,local_600);
  if (iVar1 == -1) {
    switch(DAT_00408c04) {
    case 2:
      FUN_004019af(local_400,0x400,(byte *)s_Could_not_find_file__s___s_004080e4);
      MessageBoxA((HWND)0x0,local_400,s_REDCAT_MOTOR_00408140,0);
      return -1;
    case 7:
      MessageBoxA((HWND)0x0,s_Argument_list_exceeds_1024_bytes_0040811c,s_REDCAT_MOTOR_00408140,0);
      return -1;
    case 8:
      MessageBoxA((HWND)0x0,s_Specified_file_is_not_executable_0040809c,s_REDCAT_MOTOR_00408140,0);
      return -1;
    case 0xc:
      MessageBoxA((HWND)0x0,s_Not_enough_memory_is_available_t_00408064,s_REDCAT_MOTOR_00408140,0);
      break;
    case 0x16:
      MessageBoxA((HWND)0x0,s_Mode_argument_is_invalid_00408100,s_REDCAT_MOTOR_00408140,0);
      return -1;
    }
  }
  return iVar1;
}


/*
 * FUN_004012a0 at 004012a0
 * undefined __stdcall FUN_004012a0(void)
 * Address ranges: 004012a0-004012b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004012a0(void)

{
  ShellExecuteA((HWND)0x0,&DAT_00408150,s_http___www_davilex_nl_cgi_davile_00408158,(LPCSTR)0x0,
                (LPCSTR)0x0,1);
  return;
}


/*
 * FUN_004012c0 at 004012c0
 * undefined4 __cdecl FUN_004012c0(int param_1)
 * Address ranges: 004012c0-004013ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004012c0(int param_1)

{
  FILE *pFVar1;
  int iVar2;
  char *pcVar3;
  char local_184 [128];
  CHAR local_104 [260];
  
  if (param_1 == 0) {
    pcVar3 = local_184;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
  }
  else {
    _strncpy(local_184,s__FIRST_004081f4,0x80);
    FUN_004019af(local_104,0x104,(byte *)s__sRTTMENU_SHELLTRO_AVI_004081dc);
    pFVar1 = (FILE *)FUN_00401766(local_104,&DAT_00408030);
    if (pFVar1 == (FILE *)0x0) {
      FUN_004019af(local_104,0x104,(byte *)s__sRTTMENU_SHELLTRO_MOV_004081c4);
    }
    else {
      FUN_004019af(local_104,0x104,(byte *)s__sRTTMENU_SHELLTRO_AVI_004081dc);
      FUN_004016f0(pFVar1);
    }
  }
LAB_00401371:
  iVar2 = FUN_00401140((uint *)s_rcskmenu_dat_004081b4,local_184);
  switch(iVar2) {
  case 0x28:
  case 0x29:
    break;
  default:
    return 0;
  case 0x2d:
    FUN_004012a0();
    return 0;
  case 0xff:
    FUN_00401140((uint *)s_RCMovie_dat_00408198,local_104);
    return 0;
  }
  iVar2 = FUN_00401140((uint *)s_rcskspel_dat_004081a4,&DAT_00408c00);
  if (iVar2 == 0xff) {
    return 1;
  }
  goto LAB_00401371;
}


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


/*
 * FUN_00401650 at 00401650
 * undefined FUN_00401650(void)
 * Address ranges: 00401650-004016e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LRESULT FUN_00401650(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  tagPAINTSTRUCT tStack_40;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      BeginPaint(param_1,&tStack_40);
      EndPaint(param_1,&tStack_40);
      return 0;
    }
    if (param_2 == 1) {
      return 0;
    }
    if (param_2 == 2) {
      PostQuitMessage(0);
      return 0;
    }
  }
  else {
    if (param_2 == 0x10) {
      DestroyWindow(param_1);
      return 0;
    }
    if (param_2 == 0x200) {
      SetCursor((HCURSOR)0x0);
      return 0;
    }
  }
  LVar1 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar1;
}


/*
 * FUN_004016f0 at 004016f0
 * undefined4 __cdecl FUN_004016f0(FILE * param_1)
 * Address ranges: 004016f0-00401745
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004016f0(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x40U) == 0) {
    if ((param_1->_flag & 0x83U) != 0) {
      uVar2 = FUN_00401d5a((int *)param_1);
      __freebuf(param_1);
      iVar1 = FUN_00401c41(param_1->_file);
      if (iVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else if (param_1->_tmpfname != (char *)0x0) {
        FUN_00401779(param_1->_tmpfname);
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
 * FUN_00401746 at 00401746
 * undefined __cdecl FUN_00401746(LPCSTR param_1, char * param_2, uint param_3)
 * Address ranges: 00401746-00401765
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401746(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00401f9c();
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00401e2c(param_1,param_2,param_3,puVar1);
  return;
}


/*
 * FUN_00401766 at 00401766
 * undefined __cdecl FUN_00401766(LPCSTR param_1, char * param_2)
 * Address ranges: 00401766-00401778
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401766(LPCSTR param_1,char *param_2)

{
  FUN_00401746(param_1,param_2,0x40);
  return;
}


/*
 * FUN_00401779 at 00401779
 * undefined __cdecl FUN_00401779(LPVOID param_1)
 * Address ranges: 00401779-004017a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401779(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    puVar1 = (uint *)FUN_00402b28((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_00402b53(puVar1,(uint)param_1);
      return;
    }
    HeapFree(DAT_0040a01c,0,param_1);
  }
  return;
}


/*
 * _malloc at 004017a8
 * void * __cdecl _malloc(size_t _Size)
 * Address ranges: 004017a8-004017b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _malloc  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00408c5c);
  return pvVar1;
}


/*
 * __nh_malloc at 004017ba
 * void * __cdecl __nh_malloc(size_t _Size, int _NhFlag)
 * Address ranges: 004017ba-004017e5
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
      pvVar1 = (void *)FUN_004017e6((uint *)_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_00403333(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


/*
 * FUN_004017e6 at 004017e6
 * undefined __cdecl FUN_004017e6(uint * param_1)
 * Address ranges: 004017e6-0040181b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004017e6(uint *param_1)

{
  int *piVar1;
  
  if ((param_1 <= DAT_004083bc) && (piVar1 = FUN_00402e7e(param_1), piVar1 != (int *)0x0)) {
    return;
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  HeapAlloc(DAT_0040a01c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return;
}


/*
 * _strncpy at 00401820
 * char * __cdecl _strncpy(char * _Dest, char * _Source, size_t _Count)
 * Address ranges: 00401820-0040191d
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
        goto joined_r0x0040185e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0040189b;
        goto LAB_00401909;
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
joined_r0x00401905:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00401909:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0040189b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00401905;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00401905;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00401905;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0040185e:
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
LAB_0040189b:
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
 * FUN_0040191e at 0040191e
 * undefined __cdecl FUN_0040191e(byte * param_1, byte * param_2, byte * param_3, byte * param_4, byte * param_5)
 * Address ranges: 0040191e-004019ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040191e(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {
    *param_1 = *param_2;
    param_1[1] = 0x3a;
    param_1 = param_1 + 2;
  }
  if ((param_3 != (byte *)0x0) && (bVar1 = *param_3, pbVar2 = param_3, bVar1 != 0)) {
    do {
      pbVar3 = param_1;
      *pbVar3 = bVar1;
      bVar1 = pbVar2[1];
      param_1 = pbVar3 + 1;
      pbVar2 = pbVar2 + 1;
    } while (bVar1 != 0);
    pbVar2 = FUN_0040334e(param_3,pbVar2);
    if ((*pbVar2 != 0x2f) && (*pbVar2 != 0x5c)) {
      *param_1 = 0x5c;
      param_1 = pbVar3 + 2;
    }
  }
  if (param_4 != (byte *)0x0) {
    bVar1 = *param_4;
    while (bVar1 != 0) {
      *param_1 = bVar1;
      pbVar2 = param_4 + 1;
      param_1 = param_1 + 1;
      param_4 = param_4 + 1;
      bVar1 = *pbVar2;
    }
  }
  if (param_5 == (byte *)0x0) {
    *param_1 = 0;
  }
  else {
    if ((*param_5 != 0) && (*param_5 != 0x2e)) {
      *param_1 = 0x2e;
      param_1 = param_1 + 1;
    }
    do {
      bVar1 = *param_5;
      *param_1 = bVar1;
      param_1 = param_1 + 1;
      param_5 = param_5 + 1;
    } while (bVar1 != 0);
  }
  return;
}


/*
 * FUN_004019af at 004019af
 * int __cdecl FUN_004019af(undefined1 * param_1, int param_2, byte * param_3)
 * Address ranges: 004019af-004019ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_004019af(undefined1 *param_1,int param_2,byte *param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = param_2;
  iVar1 = FUN_00403396((int *)&local_24,param_3,(undefined4 *)&stack0x00000010);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_00402785(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}


/*
 * FUN_00401a00 at 00401a00
 * undefined __stdcall FUN_00401a00(void)
 * Address ranges: 00401a00-00401a2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00401a00(void)

{
  if (DAT_0040a138 != (code *)0x0) {
    (*DAT_0040a138)();
  }
  FUN_00401ae8((undefined4 *)&DAT_00408008,(undefined4 *)&DAT_00408014);
  FUN_00401ae8((undefined4 *)&DAT_00408000,(undefined4 *)&DAT_00408004);
  return;
}


/*
 * FUN_00401a2d at 00401a2d
 * undefined __cdecl FUN_00401a2d(UINT param_1)
 * Address ranges: 00401a2d-00401a3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401a2d(UINT param_1)

{
  FUN_00401a4f(param_1,0,0);
  return;
}


/*
 * __exit at 00401a3e
 * noreturn void __cdecl __exit(int _Code)
 * Address ranges: 00401a3e-00401a4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 * Analysis note: Library Function - Single Match  __exit  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_00401a4f(_Code,1,0);
  return;
}


/*
 * FUN_00401a4f at 00401a4f
 * undefined __cdecl FUN_00401a4f(UINT param_1, int param_2, int param_3)
 * Address ranges: 00401a4f-00401ae7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00401a4f(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_00408c4c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00408c48 = 1;
  DAT_00408c44 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0040a134 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0040a130 - 4), DAT_0040a134 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0040a134 <= puVar1);
    }
    FUN_00401ae8((undefined4 *)&DAT_00408018,(undefined4 *)&DAT_00408020);
  }
  FUN_00401ae8((undefined4 *)&DAT_00408024,(undefined4 *)&DAT_00408028);
  if (param_3 != 0) {
    return;
  }
  DAT_00408c4c = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


/*
 * FUN_00401ae8 at 00401ae8
 * undefined __cdecl FUN_00401ae8(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 00401ae8-00401b01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401ae8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


/*
 * entry at 00401b02
 * undefined __stdcall entry(void)
 * Address ranges: 00401b02-00401bec
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
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00407130;
  pcStack_10 = FUN_004042ac;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_00408c1c = DVar1 >> 8 & 0xff;
  _DAT_00408c18 = DVar1 & 0xff;
  _DAT_00408c14 = _DAT_00408c18 * 0x100 + _DAT_00408c1c;
  _DAT_00408c10 = DVar1 >> 0x10;
  iVar2 = FUN_00402aae(0);
  if (iVar2 == 0) {
    FUN_00401c1d(0x1c);
  }
  local_8 = 0;
  FUN_00402014();
  DAT_0040a124 = GetCommandLineA();
  DAT_00408c50 = FUN_00404082();
  FUN_00403e35();
  FUN_00403d7c();
  FUN_00401a00();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  pbVar3 = FUN_00403d24();
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_60.wShowWindow;
  }
  iVar2 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  UVar6 = FUN_004014e0(pHVar5,iVar2,pbVar3,uVar4);
  FUN_00401a2d(UVar6);
  FUN_00403ba0(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}


/*
 * __amsg_exit at 00401bf8
 * void __cdecl __amsg_exit(int param_1)
 * Address ranges: 00401bf8-00401c19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __amsg_exit  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00408c58 == 1) {
    FUN_00404384();
  }
  FUN_004043bd(param_1);
  (*(code *)PTR___exit_00408240)(0xff);
  return;
}


/*
 * FUN_00401c1d at 00401c1d
 * undefined __cdecl FUN_00401c1d(DWORD param_1)
 * Address ranges: 00401c1d-00401c3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00401c1d(DWORD param_1)

{
  if (DAT_00408c58 == 1) {
    FUN_00404384();
  }
  FUN_004043bd(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xff);
}


/*
 * FUN_00401c41 at 00401c41
 * undefined4 __cdecl FUN_00401c41(uint param_1)
 * Address ranges: 00401c41-00401cf3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401c41(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_0040a120 <= param_1) {
    DAT_00408c08 = 0;
    DAT_00408c04 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) {
    DAT_00408c04 = 9;
    DAT_00408c08 = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_00404696(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_00404696(2);
      iVar2 = FUN_00404696(1);
      if (iVar2 == iVar1) goto LAB_00401cba;
    }
    hObject = (HANDLE)FUN_00404696(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_00401cbc;
    }
  }
LAB_00401cba:
  DVar4 = 0;
LAB_00401cbc:
  FUN_0040461c(param_1);
  *(undefined1 *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar5) = 0;
  if (DVar4 == 0) {
    return 0;
  }
  FUN_00402a47(DVar4);
  return 0xffffffff;
}


/*
 * __freebuf at 00401cf4
 * void __cdecl __freebuf(FILE * _File)
 * Address ranges: 00401cf4-00401d1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __freebuf  Library: Visual Studio 2003 Release
 */


/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_00401779(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


/*
 * FUN_00401d1f at 00401d1f
 * int __cdecl FUN_00401d1f(int * param_1)
 * Address ranges: 00401d1f-00401d59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00401d1f(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = flsall(0);
    return iVar1;
  }
  iVar1 = FUN_00401d5a(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_004046d3(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}


/*
 * FUN_00401d5a at 00401d5a
 * undefined4 __cdecl FUN_00401d5a(int * param_1)
 * Address ranges: 00401d5a-00401db5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00401d5a(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_0040289a(param_1[4],(char *)param_1[2],uVar3);
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
 * flsall at 00401dbf
 * int __cdecl flsall(int param_1)
 * Address ranges: 00401dbf-00401e2b
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
  if (0 < DAT_0040a000) {
    do {
      piVar1 = *(int **)(DAT_00408fe8 + iVar4 * 4);
      if ((piVar1 != (int *)0x0) && ((piVar1[3] & 0x83U) != 0)) {
        if (param_1 == 1) {
          iVar2 = FUN_00401d1f(piVar1);
          if (iVar2 != -1) {
            iVar3 = iVar3 + 1;
          }
        }
        else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
          iVar2 = FUN_00401d1f(piVar1);
          if (iVar2 == -1) {
            iVar5 = -1;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_0040a000);
  }
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}


/*
 * FUN_00401e2c at 00401e2c
 * undefined4 * __cdecl FUN_00401e2c(LPCSTR param_1, char * param_2, uint param_3, undefined4 * param_4)
 * Address ranges: 00401e2c-00401f9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_00401e2c(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

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
      uVar6 = DAT_00408d78 | 1;
      goto LAB_00401e6d;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_00408d78 | 2;
LAB_00401e6d:
  bVar2 = true;
LAB_00401e70:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_004047e3(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_00408d74 = _DAT_00408d74 + 1;
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
        goto LAB_00401e70;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_00401e70;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_00401e70;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_00401e70;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_00401e70;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_00401f50;
      uVar5 = uVar5 | 0x8000;
      goto LAB_00401e70;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_00401e70;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_00401f50;
        uVar5 = uVar5 | 0x4000;
        goto LAB_00401e70;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_00401e70;
      }
    }
  }
LAB_00401f50:
  bVar2 = false;
  goto LAB_00401e70;
}


/*
 * FUN_00401f9c at 00401f9c
 * undefined4 * __stdcall FUN_00401f9c(void)
 * Address ranges: 00401f9c-00402013
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * FUN_00401f9c(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = 0;
  piVar4 = DAT_00408fe8;
  if (0 < DAT_0040a000) {
    do {
      if (*piVar4 == 0) {
        pvVar2 = _malloc(0x20);
        DAT_00408fe8[iVar1] = (int)pvVar2;
        puVar3 = (undefined4 *)DAT_00408fe8[iVar1];
        if (puVar3 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
LAB_00401ff7:
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
        puVar3 = (undefined4 *)DAT_00408fe8[iVar1];
        goto LAB_00401ff7;
      }
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar1 < DAT_0040a000);
  }
  return (undefined4 *)0x0;
}


/*
 * FUN_00402014 at 00402014
 * undefined __stdcall FUN_00402014(void)
 * Address ranges: 00402014-004021be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00402014(void)

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
  DAT_0040a120 = 0x20;
  DAT_0040a020 = puVar2;
  for (; puVar2 < DAT_0040a020 + 0x40; puVar2 = puVar2 + 2) {
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
    if ((int)DAT_0040a120 < (int)UVar8) {
      puVar2 = &DAT_0040a024;
      do {
        puVar3 = _malloc(0x100);
        UVar9 = DAT_0040a120;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_0040a120 = DAT_0040a120 + 0x20;
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
      } while ((int)DAT_0040a120 < (int)UVar8);
    }
    uVar10 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)pbVar5 != (HANDLE)0xffffffff) && ((*pUVar7 & 1) != 0)) &&
           (((*pUVar7 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)pbVar5), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_0040a020)[(int)uVar10 >> 5] + (uVar10 & 0x1f) * 8);
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
    puVar2 = DAT_0040a020 + iVar6 * 2;
    if (DAT_0040a020[iVar6 * 2] == -1) {
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
          goto LAB_004021a5;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_004021a5:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_0040a120);
      return;
    }
  } while( true );
}


/*
 * FUN_004021bf at 004021bf
 * DWORD __cdecl FUN_004021bf(uint param_1, LONG param_2, DWORD param_3)
 * Address ranges: 004021bf-00402258
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


DWORD __cdecl FUN_004021bf(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 < DAT_0040a120) {
    iVar4 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      hFile = (HANDLE)FUN_00404696(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        DAT_00408c04 = 9;
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
        FUN_00402a47(uVar3);
        return 0xffffffff;
      }
      pbVar1 = (byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar4);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar2;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}


/*
 * FUN_00402259 at 00402259
 * int __cdecl FUN_00402259(uint param_1, char * param_2, char * param_3)
 * Address ranges: 00402259-0040244e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00402259(uint param_1,char *param_2,char *param_3)

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
  
  if (param_1 < DAT_0040a120) {
    iVar7 = (param_1 & 0x1f) * 8;
    piVar1 = &DAT_0040a020 + ((int)param_1 >> 5);
    bVar4 = *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar7 + 4);
    if ((bVar4 & 1) != 0) {
      local_c = (char *)0x0;
      if ((param_3 == (char *)0x0) || ((bVar4 & 2) != 0)) {
        return 0;
      }
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar7 + 5), cVar3 != '\n')) {
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
          DAT_00408c04 = 9;
          DAT_00408c08 = 5;
          return -1;
        }
        if (DVar6 != 0x6d) {
          FUN_00402a47(DVar6);
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
                goto LAB_004023ef;
              }
              *pcVar8 = '\r';
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              param_3 = param_3 + 1;
              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar7),&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_00402409:
                *pcVar8 = '\r';
LAB_0040240c:
                pcVar8 = pcVar8 + 1;
              }
              else if ((*(byte *)(*piVar1 + 4 + iVar7) & 0x48) == 0) {
                if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_004023ef:
                  *pcVar8 = '\n';
                  goto LAB_0040240c;
                }
                FUN_004021bf(param_1,-1,1);
                if (local_5 != '\n') goto LAB_00402409;
              }
              else {
                if (local_5 == '\n') goto LAB_004023ef;
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
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return -1;
}


/*
 * FUN_00402450 at 00402450
 * undefined4 * __cdecl FUN_00402450(undefined4 * param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 00402450-004024aa;004024ac-004024b2;004024c0-004024e8;004024ec-0040250e;00402510-00402528;0040254c-00402595;004025a8-004025ae;004025b0-004025ba;004025bc-004025cc;004025d0-004025e6;004025e8-0040260d;00402610-00402618;0040261c-0040263a;00402648-00402664;00402668-0040268e;00402690-004026c0;004026e4-0040272d;00402740-00402746;00402748-00402754;00402758-0040276a;0040276c-00402784
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __cdecl FUN_00402450(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_00402607_caseD_2;
        case 3:
          goto switchD_00402607_caseD_3;
        }
        goto switchD_00402607_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00402607_caseD_0;
      case 1:
        goto switchD_00402607_caseD_1;
      case 2:
        goto switchD_00402607_caseD_2;
      case 3:
        goto switchD_00402607_caseD_3;
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
              goto switchD_00402607_caseD_2;
            case 3:
              goto switchD_00402607_caseD_3;
            }
            goto switchD_00402607_caseD_1;
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
              goto switchD_00402607_caseD_2;
            case 3:
              goto switchD_00402607_caseD_3;
            }
            goto switchD_00402607_caseD_1;
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
              goto switchD_00402607_caseD_2;
            case 3:
              goto switchD_00402607_caseD_3;
            }
            goto switchD_00402607_caseD_1;
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
switchD_00402607_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_00402607_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_00402607_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_00402607_caseD_0:
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
        goto switchD_00402485_caseD_2;
      case 3:
        goto switchD_00402485_caseD_3;
      }
      goto switchD_00402485_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00402485_caseD_0;
    case 1:
      goto switchD_00402485_caseD_1;
    case 2:
      goto switchD_00402485_caseD_2;
    case 3:
      goto switchD_00402485_caseD_3;
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
            goto switchD_00402485_caseD_2;
          case 3:
            goto switchD_00402485_caseD_3;
          }
          goto switchD_00402485_caseD_1;
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
            goto switchD_00402485_caseD_2;
          case 3:
            goto switchD_00402485_caseD_3;
          }
          goto switchD_00402485_caseD_1;
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
            goto switchD_00402485_caseD_2;
          case 3:
            goto switchD_00402485_caseD_3;
          }
          goto switchD_00402485_caseD_1;
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
switchD_00402485_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00402485_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00402485_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00402485_caseD_0:
  return param_1;
}


/*
 * FUN_00402785 at 00402785
 * uint __cdecl FUN_00402785(uint param_1, int * param_2)
 * Address ranges: 00402785-00402899
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_00402785(uint param_1,int *param_2)

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
LAB_0040288e:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_0040288e;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_00408510 && (piVar4 != (int *)&DAT_00408530)) ||
        (bVar5 = FUN_00404ae0(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_00404a9c(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_0040289a(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_00408248;
        }
        else {
          puVar6 = (undefined *)((&DAT_0040a020)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 8);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_004021bf(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_0040289a(uVar2,pcVar3,(uint)piVar7);
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
 * FUN_0040289a at 0040289a
 * int __cdecl FUN_0040289a(DWORD param_1, char * param_2, uint param_3)
 * Address ranges: 0040289a-00402a46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040289a(DWORD param_1,char *param_2,uint param_3)

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
  
  if (param_1 < DAT_0040a120) {
    piVar1 = &DAT_0040a020 + ((int)param_1 >> 5);
    iVar7 = (param_1 & 0x1f) * 8;
    bVar3 = *(byte *)(*piVar1 + 4 + iVar7);
    if ((bVar3 & 1) != 0) {
      local_c = 0;
      local_14 = 0;
      if (param_3 == 0) {
        return 0;
      }
      if ((bVar3 & 0x20) != 0) {
        FUN_004021bf(param_1,0,2);
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
LAB_00402993:
        if (local_c != 0) {
          return local_c - local_14;
        }
        if (param_1 != 0) {
          if (param_1 == 5) {
            DAT_00408c04 = 9;
            DAT_00408c08 = 5;
            return -1;
          }
          FUN_00402a47(param_1);
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
              goto LAB_00402993;
            }
            local_c = local_c + local_10;
            if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
               (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_00402993;
          } while( true );
        }
      }
      if (((*(byte *)(*piVar1 + 4 + iVar7) & 0x40) != 0) && (*param_2 == '\x1a')) {
        return 0;
      }
      DAT_00408c04 = 0x1c;
      DAT_00408c08 = 0;
      return -1;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return -1;
}


/*
 * FUN_00402a47 at 00402a47
 * undefined __cdecl FUN_00402a47(uint param_1)
 * Address ranges: 00402a47-00402aad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00402a47(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_00408c08 = param_1;
  puVar1 = &DAT_00408250;
  do {
    if (param_1 == *puVar1) {
      DAT_00408c04 = *(undefined4 *)(iVar2 * 8 + 0x408254);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x4083b8);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    DAT_00408c04 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (DAT_00408c04 = 8, 0xca < param_1)) {
    DAT_00408c04 = 0x16;
  }
  return;
}


/*
 * FUN_00402aae at 00402aae
 * undefined4 __cdecl FUN_00402aae(int param_1)
 * Address ranges: 00402aae-00402ae9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00402aae(int param_1)

{
  int iVar1;
  
  DAT_0040a01c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_0040a01c != (HANDLE)0x0) {
    iVar1 = FUN_00402aea();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_0040a01c);
  }
  return 0;
}


/*
 * FUN_00402aea at 00402aea
 * undefined4 __stdcall FUN_00402aea(void)
 * Address ranges: 00402aea-00402b27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00402aea(void)

{
  DAT_0040a018 = HeapAlloc(DAT_0040a01c,0,0x140);
  if (DAT_0040a018 == (LPVOID)0x0) {
    return 0;
  }
  DAT_0040a010 = 0;
  DAT_0040a014 = 0;
  DAT_0040a00c = DAT_0040a018;
  DAT_0040a004 = 0x10;
  return 1;
}


/*
 * FUN_00402b28 at 00402b28
 * uint __cdecl FUN_00402b28(int param_1)
 * Address ranges: 00402b28-00402b52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_00402b28(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_0040a018;
  while( true ) {
    if (DAT_0040a018 + DAT_0040a014 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


/*
 * FUN_00402b53 at 00402b53
 * undefined __cdecl FUN_00402b53(uint * param_1, uint param_2)
 * Address ranges: 00402b53-00402e7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00402b53(uint *param_1,uint param_2)

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
  uVar5 = DAT_0040a008;
  puVar2 = DAT_0040a010;
  if ((*piVar3 == 0) && (uVar5 = uVar10, puVar2 = param_1, DAT_0040a010 != (uint *)0x0)) {
    VirtualFree((LPVOID)(DAT_0040a008 * 0x8000 + DAT_0040a010[3]),0x8000,0x4000);
    DAT_0040a010[2] = DAT_0040a010[2] | 0x80000000U >> ((byte)DAT_0040a008 & 0x1f);
    *(undefined4 *)(DAT_0040a010[4] + 0xc4 + DAT_0040a008 * 4) = 0;
    *(char *)(DAT_0040a010[4] + 0x43) = *(char *)(DAT_0040a010[4] + 0x43) + -1;
    if (*(char *)(DAT_0040a010[4] + 0x43) == '\0') {
      DAT_0040a010[1] = DAT_0040a010[1] & 0xfffffffe;
    }
    puVar2 = param_1;
    if (DAT_0040a010[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_0040a010[3],0,0x8000);
      HeapFree(DAT_0040a01c,0,(LPVOID)DAT_0040a010[4]);
      FUN_00404b10(DAT_0040a010,DAT_0040a010 + 5,
                   (DAT_0040a014 * 0x14 - (int)DAT_0040a010) + -0x14 + DAT_0040a018);
      DAT_0040a014 = DAT_0040a014 + -1;
      if (DAT_0040a010 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_0040a00c = DAT_0040a018;
      puVar2 = param_1;
    }
  }
  DAT_0040a010 = puVar2;
  DAT_0040a008 = uVar5;
  return;
}


/*
 * FUN_00402e7e at 00402e7e
 * int * __cdecl FUN_00402e7e(uint * param_1)
 * Address ranges: 00402e7e-00403186
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00402e7e(uint *param_1)

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
  
  puVar8 = DAT_0040a018 + DAT_0040a014 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_0040a00c;
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
  puVar11 = DAT_0040a018;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_0040a00c && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_0040a00c) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_0040a018;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_0040a00c && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_0040a00c) && (param_1 = FUN_00403187(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_00403238((int)param_1);
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
  DAT_0040a00c = param_1;
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
    if (iVar9 == 0) goto LAB_00403144;
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
LAB_00403144:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_0040a010)) && (local_8 == DAT_0040a008)) {
    DAT_0040a010 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}


/*
 * FUN_00403187 at 00403187
 * undefined4 * __stdcall FUN_00403187(void)
 * Address ranges: 00403187-00403237
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * FUN_00403187(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_0040a014 == DAT_0040a004) {
    pvVar2 = HeapReAlloc(DAT_0040a01c,0,DAT_0040a018,(DAT_0040a004 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_0040a004 = DAT_0040a004 + 0x10;
    DAT_0040a018 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_0040a018 + DAT_0040a014 * 0x14);
  pvVar2 = HeapAlloc(DAT_0040a01c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_0040a014 = DAT_0040a014 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_0040a01c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


/*
 * FUN_00403238 at 00403238
 * int __cdecl FUN_00403238(int param_1)
 * Address ranges: 00403238-00403332
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00403238(int param_1)

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
 * FUN_00403333 at 00403333
 * undefined4 __cdecl FUN_00403333(undefined4 param_1)
 * Address ranges: 00403333-0040334d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00403333(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00408c60 != (code *)0x0) {
    iVar1 = (*DAT_00408c60)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


/*
 * FUN_0040334e at 0040334e
 * byte * __cdecl FUN_0040334e(byte * param_1, byte * param_2)
 * Address ranges: 0040334e-00403395
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


byte * __cdecl FUN_0040334e(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_2 <= param_1) {
    return (byte *)0x0;
  }
  if (DAT_00408dcc != 0) {
    pbVar1 = param_2 + -1;
    if ((*(byte *)((int)&DAT_00408ee0 + param_2[-1] + 1) & 4) != 0) {
      return param_2 + -2;
    }
    do {
      pbVar1 = pbVar1 + -1;
      if (pbVar1 < param_1) break;
    } while ((*(byte *)((int)&DAT_00408ee0 + *pbVar1 + 1) & 4) != 0);
    param_2 = param_2 + -((int)param_2 - (int)pbVar1 & 1U);
  }
  return param_2 + -1;
}


/*
 * FUN_00403396 at 00403396
 * int __cdecl FUN_00403396(int * param_1, byte * param_2, undefined4 * param_3)
 * Address ranges: 00403396-00403ab6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00403396(int *param_1,byte *param_2,undefined4 *param_3)

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
      uVar2 = *(byte *)((int)&PeekMessageA_exref + (int)(char)bVar9) & 0xf;
    }
    local_34 = (int)(char)(&DAT_0040713c)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_00403404_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_00408888[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_00403ad7((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = pbVar1 + 2;
      }
      FUN_00403ad7((int)(char)bVar9,param_1,&local_18);
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
        local_24 = FUN_00403b75((int *)&param_3);
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
        local_14 = FUN_00403b75((int *)&param_3);
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
          goto switchD_00403404_caseD_0;
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
LAB_00403815:
              local_30 = 7;
LAB_0040381c:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_00403886;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_004035c3;
                }
                goto LAB_004039a0;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_00403624;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_00403651:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_00403b75((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar5 = FUN_00403b92((int *)&param_3);
              local_10 = (undefined1 *)FUN_004052ab(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_00403b75((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_DAT_004083c0;
              pWVar4 = (WCHAR *)PTR_DAT_004083c0;
              goto LAB_00403796;
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
            if (bVar9 == 99) goto LAB_00403651;
            if (bVar9 == 100) goto LAB_0040387b;
          }
        }
        else {
LAB_00403624:
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
          (*(code *)PTR_FUN_00408870)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR_FUN_0040887c)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR_FUN_00408874)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_00403796:
          local_10 = (undefined1 *)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_0040387b:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_00403b75((int *)&param_3);
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
            goto LAB_00403886;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_00403815;
          }
          if (bVar9 == 0x73) {
LAB_004035c3:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_00403b75((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_004083c0;
                pWVar4 = (WCHAR *)PTR_DAT_004083c0;
              }
              for (; (iVar10 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1))
              {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_004083c4;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_004039a0;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_004039a0;
            local_30 = 0x27;
            goto LAB_0040381c;
          }
        }
        local_10 = (undefined1 *)0xa;
LAB_00403886:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_00403b75((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_004038d9;
            }
            uVar2 = FUN_00403b75((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_00403b75((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_00403b75((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_00403b82((int *)&param_3);
        }
LAB_004038d9:
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
LAB_004039a0:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_004039d8;
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
LAB_004039d8:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_00403b0c(0x20,iVar10,param_1,&local_18);
        }
        FUN_00403b3d(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_00403b0c(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (puVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_00403b3d((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            puVar12 = puVar12 + -1;
            iVar8 = FUN_004052ab(local_3c,*pWVar4);
            if (iVar8 < 1) break;
            FUN_00403b3d(local_3c,iVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (puVar12 != (undefined1 *)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_00403b0c(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    pbVar1 = param_2;
  } while( true );
}


/*
 * FUN_00403ad7 at 00403ad7
 * undefined __cdecl FUN_00403ad7(uint param_1, int * param_2, int * param_3)
 * Address ranges: 00403ad7-00403b0b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00403ad7(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_00402785(param_1,param_2);
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
 * FUN_00403b0c at 00403b0c
 * undefined __cdecl FUN_00403b0c(uint param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 00403b0c-00403b3c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00403b0c(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_00403ad7(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


/*
 * FUN_00403b3d at 00403b3d
 * undefined __cdecl FUN_00403b3d(char * param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 00403b3d-00403b74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00403b3d(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_00403ad7((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


/*
 * FUN_00403b75 at 00403b75
 * undefined4 __cdecl FUN_00403b75(int * param_1)
 * Address ranges: 00403b75-00403b81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00403b75(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}


/*
 * FUN_00403b82 at 00403b82
 * undefined8 __cdecl FUN_00403b82(int * param_1)
 * Address ranges: 00403b82-00403b91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __cdecl FUN_00403b82(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}


/*
 * FUN_00403b92 at 00403b92
 * undefined4 __cdecl FUN_00403b92(int * param_1)
 * Address ranges: 00403b92-00403b9f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00403b92(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}


/*
 * FUN_00403ba0 at 00403ba0
 * LONG __cdecl FUN_00403ba0(int param_1, _EXCEPTION_POINTERS * param_2)
 * Address ranges: 00403ba0-00403ce0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LONG __cdecl FUN_00403ba0(int param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = FUN_00403ce1(param_1);
  uVar3 = DAT_00408c64;
  if ((piVar4 == (int *)0x0) || (pcVar1 = (code *)piVar4[2], pcVar1 == (code *)0x0)) {
    LVar5 = UnhandledExceptionFilter(param_2);
  }
  else if (pcVar1 == (code *)0x5) {
    piVar4[2] = 0;
    LVar5 = 1;
  }
  else {
    if (pcVar1 != (code *)0x1) {
      DAT_00408c64 = param_2;
      if (piVar4[1] == 8) {
        if (DAT_00408440 < DAT_00408444 + DAT_00408440) {
          iVar6 = (DAT_00408444 + DAT_00408440) - DAT_00408440;
          puVar7 = (undefined4 *)(DAT_00408440 * 0xc + 0x4083d0);
          do {
            *puVar7 = 0;
            puVar7 = puVar7 + 3;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        uVar2 = DAT_0040844c;
        iVar6 = *piVar4;
        if (iVar6 == -0x3fffff72) {
          DAT_0040844c = 0x83;
        }
        else if (iVar6 == -0x3fffff70) {
          DAT_0040844c = 0x81;
        }
        else if (iVar6 == -0x3fffff6f) {
          DAT_0040844c = 0x84;
        }
        else if (iVar6 == -0x3fffff6d) {
          DAT_0040844c = 0x85;
        }
        else if (iVar6 == -0x3fffff73) {
          DAT_0040844c = 0x82;
        }
        else if (iVar6 == -0x3fffff71) {
          DAT_0040844c = 0x86;
        }
        else if (iVar6 == -0x3fffff6e) {
          DAT_0040844c = 0x8a;
        }
        (*pcVar1)(8,DAT_0040844c);
        DAT_0040844c = uVar2;
      }
      else {
        piVar4[2] = 0;
        (*pcVar1)(piVar4[1]);
      }
    }
    LVar5 = -1;
    DAT_00408c64 = (_EXCEPTION_POINTERS *)uVar3;
  }
  return LVar5;
}


/*
 * FUN_00403ce1 at 00403ce1
 * int * __cdecl FUN_00403ce1(int param_1)
 * Address ranges: 00403ce1-00403d23
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_00403ce1(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_004083c8;
  if (DAT_004083c8 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&DAT_004083c8 + DAT_00408448 * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_004083c8 + DAT_00408448 * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


/*
 * FUN_00403d24 at 00403d24
 * byte * __stdcall FUN_00403d24(void)
 * Address ranges: 00403d24-00403d7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


byte * FUN_00403d24(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_0040a12c == 0) {
    FUN_00405209();
  }
  bVar1 = *DAT_0040a124;
  pbVar4 = DAT_0040a124;
  if (bVar1 == 0x22) {
    while( true ) {
      pbVar3 = pbVar4;
      bVar1 = pbVar3[1];
      pbVar4 = pbVar3 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar2 = FUN_00405405(bVar1);
      if (iVar2 != 0) {
        pbVar4 = pbVar3 + 2;
      }
    }
    if (*pbVar4 == 0x22) goto LAB_00403d61;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
    }
  }
  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
LAB_00403d61:
  }
  return pbVar4;
}


/*
 * FUN_00403d7c at 00403d7c
 * undefined __stdcall FUN_00403d7c(void)
 * Address ranges: 00403d7c-00403e34
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403d7c(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_0040a12c == 0) {
    FUN_00405209();
  }
  iVar5 = 0;
  for (puVar6 = DAT_00408c50; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  _DAT_00408c2c = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_00408c50;
  puVar6 = DAT_00408c50;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_00405450((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_00401779(DAT_00408c50);
  DAT_00408c50 = (uint *)0x0;
  *puVar3 = 0;
  _DAT_0040a128 = 1;
  return;
}


/*
 * FUN_00403e35 at 00403e35
 * undefined __stdcall FUN_00403e35(void)
 * Address ranges: 00403e35-00403ecd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403e35(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_0040a12c == 0) {
    FUN_00405209();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_00408c68,0x104);
  _DAT_00408c3c = &DAT_00408c68;
  pbVar2 = &DAT_00408c68;
  if (*DAT_0040a124 != 0) {
    pbVar2 = DAT_0040a124;
  }
  FUN_00403ece(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_00403ece(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_00408c24 = puVar1;
  _DAT_00408c20 = local_8 + -1;
  return;
}


/*
 * FUN_00403ece at 00403ece
 * undefined __cdecl FUN_00403ece(byte * param_1, undefined4 * param_2, byte * param_3, int * param_4, int * param_5)
 * Address ranges: 00403ece-00404081
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00403ece(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_00408ee0 + bVar1 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00408ee0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00403f79;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00403f79:
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
          if ((*(byte *)((int)&DAT_00408ee0 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_00408ee0 + bVar1 + 1) & 4) != 0) {
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
 * FUN_00404082 at 00404082
 * LPSTR __stdcall FUN_00404082(void)
 * Address ranges: 00404082-004041b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LPSTR FUN_00404082(void)

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
  if (DAT_00408d6c == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_00408d6c = 1;
LAB_004040d9:
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
        FUN_00401779(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_00408d6c = 2;
  }
  else {
    if (DAT_00408d6c == 1) goto LAB_004040d9;
    if (DAT_00408d6c != 2) {
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
    FUN_00402450((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}


/*
 * __global_unwind2 at 004041b4
 * undefined __cdecl __global_unwind2(PVOID param_1)
 * Address ranges: 004041b4-004041d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __global_unwind2  Library: Visual Studio
 */


/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x4041cc,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


/*
 * __local_unwind2 at 004041f6
 * undefined __cdecl __local_unwind2(int param_1, int param_2)
 * Address ranges: 004041f6-0040425d
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
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_004041d4;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0040428a();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


/*
 * FUN_0040428a at 0040428a
 * undefined __stdcall FUN_0040428a(void)
 * Address ranges: 0040428a-004042a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040428a(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_00408458 = *(undefined4 *)(unaff_EBP + 8);
  DAT_00408454 = in_EAX;
  DAT_0040845c = unaff_EBP;
  return;
}


/*
 * FUN_004042ac at 004042ac
 * undefined FUN_004042ac(void)
 * Address ranges: 004042ac-00404368
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004042ac(int param_1,PVOID param_2,undefined4 param_3)

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
          FUN_0040428a();
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
 * FUN_00404369 at 00404369
 * undefined __stdcall FUN_00404369(int param_1)
 * Address ranges: 00404369-00404383
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404369(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


/*
 * FUN_00404384 at 00404384
 * undefined __stdcall FUN_00404384(void)
 * Address ranges: 00404384-004043bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404384(void)

{
  if ((DAT_00408c58 == 1) || ((DAT_00408c58 == 0 && (DAT_00408244 == 1)))) {
    FUN_004043bd(0xfc);
    if (DAT_00408d70 != (code *)0x0) {
      (*DAT_00408d70)();
    }
    FUN_004043bd(0xff);
  }
  return;
}


/*
 * FUN_004043bd at 004043bd
 * undefined __cdecl FUN_004043bd(DWORD param_1)
 * Address ranges: 004043bd-0040450f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_004043bd(DWORD param_1)

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
  pDVar2 = &DAT_00408460;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x4084f0);
  if (param_1 == (&DAT_00408460)[iVar5 * 2]) {
    if ((DAT_00408c58 == 1) || ((DAT_00408c58 == 0 && (DAT_00408244 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x408464);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_00405450(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_00405450(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_00405460(local_a4,_Dest);
      FUN_00405460(local_a4,(uint *)&DAT_00407464);
      FUN_00405460(local_a4,*(uint **)(iVar5 * 8 + 0x408464));
      auStackY_1e3._3_4_ = 0x4044e1;
      FUN_00405540(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


/*
 * FUN_00404510 at 00404510
 * int __stdcall FUN_00404510(void)
 * Address ranges: 00404510-004045a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00404510(void)

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
  piVar3 = &DAT_0040a020;
  do {
    puVar2 = (undefined4 *)*piVar3;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = _malloc(0x100);
      if (puVar2 != (undefined4 *)0x0) {
        DAT_0040a120 = DAT_0040a120 + 0x20;
        (&DAT_0040a020)[iVar6] = puVar2;
        puVar1 = puVar2;
        for (; puVar2 < puVar1 + 0x40; puVar2 = puVar2 + 2) {
          *(undefined1 *)(puVar2 + 1) = 0;
          *puVar2 = 0xffffffff;
          *(undefined1 *)((int)puVar2 + 5) = 10;
          puVar1 = (undefined4 *)(&DAT_0040a020)[iVar6];
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
    if (0x40a11f < (int)piVar3) {
      return iVar4;
    }
  } while( true );
}


/*
 * FUN_004045a5 at 004045a5
 * undefined4 __cdecl FUN_004045a5(uint param_1, HANDLE param_2)
 * Address ranges: 004045a5-0040461b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004045a5(uint param_1,HANDLE param_2)

{
  int iVar1;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0040a120) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (*(int *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar1) == -1) {
      if (DAT_00408244 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004045fb;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_004045fb:
      *(HANDLE *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar1) = param_2;
      return 0;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}


/*
 * FUN_0040461c at 0040461c
 * undefined4 __cdecl FUN_0040461c(uint param_1)
 * Address ranges: 0040461c-00404695
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_0040461c(uint param_1)

{
  int *piVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0040a120) {
    iVar2 = (param_1 & 0x1f) * 8;
    piVar1 = (int *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar2);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00408244 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00404675;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00404675:
      *(undefined4 *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar2) = 0xffffffff;
      return 0;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}


/*
 * FUN_00404696 at 00404696
 * undefined4 __cdecl FUN_00404696(uint param_1)
 * Address ranges: 00404696-004046d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00404696(uint param_1)

{
  if ((param_1 < DAT_0040a120) &&
     ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0040a020)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}


/*
 * FUN_004046d3 at 004046d3
 * undefined4 __cdecl FUN_004046d3(uint param_1)
 * Address ranges: 004046d3-00404729
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_004046d3(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = DAT_00408c08;
  if ((param_1 < DAT_0040a120) &&
     ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_00404696(param_1);
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
  DAT_00408c08 = DVar2;
  DAT_00408c04 = 9;
  return 0xffffffff;
}


/*
 * FUN_0040472a at 0040472a
 * undefined FUN_0040472a(void)
 * Address ranges: 0040472a-004047ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040472a(void)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = 0x14;
  if (DAT_0040a000 == 0) {
    iVar1 = 0x200;
  }
  else if (0x13 < DAT_0040a000) goto LAB_00404749;
  DAT_0040a000 = iVar1;
LAB_00404749:
  DAT_00408fe8 = FUN_004055c9(DAT_0040a000,4);
  if (DAT_00408fe8 == (int *)0x0) {
    DAT_0040a000 = 0x14;
    DAT_00408fe8 = FUN_004055c9(0x14,4);
    if (DAT_00408fe8 == (int *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  iVar1 = 0;
  ppuVar2 = &PTR_DAT_004084f0;
  do {
    *(undefined ***)(iVar1 + (int)DAT_00408fe8) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar1 = iVar1 + 4;
  } while ((int)ppuVar2 < 0x408770);
  uVar4 = 0;
  puVar3 = &DAT_00408500;
  do {
    iVar1 = *(int *)((&DAT_0040a020)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 8);
    if ((iVar1 == -1) || (iVar1 == 0)) {
      *puVar3 = 0xffffffff;
    }
    puVar3 = puVar3 + 8;
    uVar4 = uVar4 + 1;
  } while ((int)puVar3 < 0x408560);
  return;
}


/*
 * FUN_004047e3 at 004047e3
 * uint __cdecl FUN_004047e3(LPCSTR param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 004047e3-00404a9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __cdecl FUN_004047e3(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

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
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_00408d8c != 0x8000)))) {
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
      DAT_00408c04 = 0x16;
      DAT_00408c08 = 0;
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
      DAT_00408c04 = 0x16;
      DAT_00408c08 = 0;
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
      if (uVar2 == 0x200) goto LAB_00404901;
      if (uVar2 != 0x300) {
        DAT_00408c04 = 0x16;
        DAT_00408c08 = 0;
        return 0xffffffff;
      }
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_00404901:
        local_c = 5;
        goto LAB_00404911;
      }
      if (uVar2 != 0x700) {
        DAT_00408c04 = 0x16;
        DAT_00408c08 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_00404911:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_00408c0c & param_4 & 0x80) == 0)) {
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
  uVar3 = FUN_00404510();
  if (uVar3 == 0xffffffff) {
    DAT_00408c08 = 0;
    DAT_00408c04 = 0x18;
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
        FUN_004045a5(uVar3,hFile);
        iVar6 = (uVar3 & 0x1f) * 8;
        param_1._3_1_ = local_5 & 0x48;
        *(byte *)((&DAT_0040a020)[(int)uVar3 >> 5] + 4 + iVar6) = local_5 | 1;
        if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
          local_14 = FUN_004021bf(uVar3,-1,2);
          if (local_14 == 0xffffffff) {
            if (DAT_00408c08 != 0x83) {
LAB_00404a72:
              FUN_00401c41(uVar3);
              return 0xffffffff;
            }
          }
          else {
            param_3 = param_3 & 0xffffff;
            iVar5 = FUN_00402259(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
            if ((((iVar5 == 0) && (param_3._3_1_ == '\x1a')) &&
                (iVar5 = FUN_0040569e(uVar3,local_14), iVar5 == -1)) ||
               (DVar4 = FUN_004021bf(uVar3,0,0), DVar4 == 0xffffffff)) goto LAB_00404a72;
          }
        }
        if (param_1._3_1_ != 0) {
          return uVar3;
        }
        if ((param_2 & 8) != 0) {
          pbVar1 = (byte *)((&DAT_0040a020)[(int)uVar3 >> 5] + 4 + iVar6);
          *pbVar1 = *pbVar1 | 0x20;
          return uVar3;
        }
        return uVar3;
      }
      CloseHandle(hFile);
    }
    DVar4 = GetLastError();
    FUN_00402a47(DVar4);
  }
  return 0xffffffff;
}


/*
 * FUN_00404a9c at 00404a9c
 * undefined __cdecl FUN_00404a9c(undefined4 * param_1)
 * Address ranges: 00404a9c-00404adf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00404a9c(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_00408d74 = _DAT_00408d74 + 1;
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
 * FUN_00404ae0 at 00404ae0
 * byte __cdecl FUN_00404ae0(uint param_1)
 * Address ranges: 00404ae0-00404b05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


byte __cdecl FUN_00404ae0(uint param_1)

{
  if (DAT_0040a120 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}


/*
 * FUN_00404b10 at 00404b10
 * undefined4 * __cdecl FUN_00404b10(undefined4 * param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 00404b10-00404b6a;00404b6c-00404b72;00404b80-00404ba8;00404bac-00404bce;00404bd0-00404be8;00404c0c-00404c55;00404c68-00404c6e;00404c70-00404c7a;00404c7c-00404c8c;00404c90-00404ca6;00404ca8-00404ccd;00404cd0-00404cd8;00404cdc-00404cfa;00404d08-00404d24;00404d28-00404d4e;00404d50-00404d80;00404da4-00404ded;00404e00-00404e06;00404e08-00404e14;00404e18-00404e2a;00404e2c-00404e44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __cdecl FUN_00404b10(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_00404cc7_caseD_2;
        case 3:
          goto switchD_00404cc7_caseD_3;
        }
        goto switchD_00404cc7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00404cc7_caseD_0;
      case 1:
        goto switchD_00404cc7_caseD_1;
      case 2:
        goto switchD_00404cc7_caseD_2;
      case 3:
        goto switchD_00404cc7_caseD_3;
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
              goto switchD_00404cc7_caseD_2;
            case 3:
              goto switchD_00404cc7_caseD_3;
            }
            goto switchD_00404cc7_caseD_1;
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
              goto switchD_00404cc7_caseD_2;
            case 3:
              goto switchD_00404cc7_caseD_3;
            }
            goto switchD_00404cc7_caseD_1;
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
              goto switchD_00404cc7_caseD_2;
            case 3:
              goto switchD_00404cc7_caseD_3;
            }
            goto switchD_00404cc7_caseD_1;
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
switchD_00404cc7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_00404cc7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_00404cc7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_00404cc7_caseD_0:
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
        goto switchD_00404b45_caseD_2;
      case 3:
        goto switchD_00404b45_caseD_3;
      }
      goto switchD_00404b45_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00404b45_caseD_0;
    case 1:
      goto switchD_00404b45_caseD_1;
    case 2:
      goto switchD_00404b45_caseD_2;
    case 3:
      goto switchD_00404b45_caseD_3;
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
            goto switchD_00404b45_caseD_2;
          case 3:
            goto switchD_00404b45_caseD_3;
          }
          goto switchD_00404b45_caseD_1;
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
            goto switchD_00404b45_caseD_2;
          case 3:
            goto switchD_00404b45_caseD_3;
          }
          goto switchD_00404b45_caseD_1;
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
            goto switchD_00404b45_caseD_2;
          case 3:
            goto switchD_00404b45_caseD_3;
          }
          goto switchD_00404b45_caseD_1;
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
switchD_00404b45_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00404b45_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00404b45_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00404b45_caseD_0:
  return param_1;
}


/*
 * FUN_00404e45 at 00404e45
 * undefined4 __cdecl FUN_00404e45(int param_1)
 * Address ranges: 00404e45-00404fdd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00404e45(int param_1)

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
  
  CodePage = FUN_00404fde(param_1);
  if (CodePage == DAT_00408db8) {
    return 0;
  }
  if (CodePage != 0) {
    iVar11 = 0;
    pUVar5 = &DAT_00408778;
    do {
      if (*pUVar5 == CodePage) {
        puVar13 = &DAT_00408ee0;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
        local_8 = 0;
        iVar11 = iVar11 * 0x30;
        *(undefined1 *)puVar13 = 0;
        pbVar12 = (byte *)(iVar11 + 0x408788);
        do {
          bVar3 = *pbVar12;
          pbVar10 = pbVar12;
          while ((bVar3 != 0 && (bVar3 = pbVar10[1], bVar3 != 0))) {
            uVar7 = (uint)*pbVar10;
            if (uVar7 <= bVar3) {
              bVar4 = (&DAT_00408770)[local_8];
              do {
                pbVar2 = (byte *)((int)&DAT_00408ee0 + uVar7 + 1);
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
        DAT_00408dcc = 1;
        DAT_00408db8 = CodePage;
        DAT_00408fe4 = FUN_00405028(CodePage);
        DAT_00408dc0 = *(undefined4 *)(iVar11 + 0x40877c);
        DAT_00408dc4 = *(undefined4 *)(iVar11 + 0x408780);
        DAT_00408dc8 = *(undefined4 *)(iVar11 + 0x408784);
        goto LAB_00404fcd;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar11 = iVar11 + 1;
    } while ((int)pUVar5 < 0x408868);
    BVar6 = GetCPInfo(CodePage,&local_1c);
    if (BVar6 == 1) {
      puVar13 = &DAT_00408ee0;
      DAT_00408db8 = CodePage;
      for (iVar11 = 0x40; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      *(undefined1 *)puVar13 = 0;
      DAT_00408fe4 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_00408dcc = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar8 = local_1c.LeadByte + 1;
          do {
            bVar3 = *pBVar8;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar8[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              pbVar12 = (byte *)((int)&DAT_00408ee0 + uVar7 + 1);
              *pbVar12 = *pbVar12 | 4;
            }
            pBVar1 = pBVar8 + 1;
            pBVar8 = pBVar8 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          pbVar12 = (byte *)((int)&DAT_00408ee0 + uVar7 + 1);
          *pbVar12 = *pbVar12 | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_00408fe4 = FUN_00405028(CodePage);
        DAT_00408dcc = 1;
      }
      DAT_00408dc0 = 0;
      DAT_00408dc4 = 0;
      DAT_00408dc8 = 0;
      goto LAB_00404fcd;
    }
    if (DAT_00408d7c == 0) {
      return 0xffffffff;
    }
  }
  FUN_0040505b();
LAB_00404fcd:
  FUN_00405084();
  return 0;
}


/*
 * FUN_00404fde at 00404fde
 * int __cdecl FUN_00404fde(int param_1)
 * Address ranges: 00404fde-00405027
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00404fde(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00408d7c = 1;
                    /* WARNING: Could not recover jumptable at 0x00404ff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00408d7c = 1;
                    /* WARNING: Could not recover jumptable at 0x0040500d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00408da8;
  }
  DAT_00408d7c = (uint)bVar2;
  return param_1;
}


/*
 * FUN_00405028 at 00405028
 * undefined4 __cdecl FUN_00405028(int param_1)
 * Address ranges: 00405028-0040505a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00405028(int param_1)

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
 * FUN_0040505b at 0040505b
 * undefined __stdcall FUN_0040505b(void)
 * Address ranges: 0040505b-00405083
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040505b(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00408ee0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00408db8 = 0;
  DAT_00408dcc = 0;
  DAT_00408fe4 = 0;
  DAT_00408dc0 = 0;
  DAT_00408dc4 = 0;
  DAT_00408dc8 = 0;
  return;
}


/*
 * FUN_00405084 at 00405084
 * undefined __stdcall FUN_00405084(void)
 * Address ranges: 00405084-00405208
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00405084(void)

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
  
  BVar2 = GetCPInfo(DAT_00408db8,&local_18);
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
    FUN_00405a33(1,local_118,0x100,local_518,DAT_00408db8,DAT_00408fe4,0);
    FUN_004057e4(DAT_00408fe4,0x100,local_118,0x100,local_218,0x100,DAT_00408db8,0);
    FUN_004057e4(DAT_00408fe4,0x200,local_118,0x100,local_318,0x100,DAT_00408db8,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_00408ee0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_00405190;
        }
        (&DAT_00408de0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_00408ee0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_00405190:
        (&DAT_00408de0)[uVar3] = uVar8;
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
          pbVar1 = (byte *)((int)&DAT_00408ee0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_004051da;
        }
        (&DAT_00408de0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_00408ee0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_004051da:
        (&DAT_00408de0)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


/*
 * FUN_00405209 at 00405209
 * undefined __stdcall FUN_00405209(void)
 * Address ranges: 00405209-00405224
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00405209(void)

{
  if (DAT_0040a12c == 0) {
    FUN_00404e45(-3);
    DAT_0040a12c = 1;
  }
  return;
}


/*
 * _strlen at 00405230
 * size_t __cdecl _strlen(char * _Str)
 * Address ranges: 00405230-004052aa
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
    if (((uint)puVar2 & 3) == 0) goto LAB_00405250;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00405283:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00405250:
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
  goto LAB_00405283;
}


/*
 * FUN_004052ab at 004052ab
 * int __cdecl FUN_004052ab(LPSTR param_1, WCHAR param_2)
 * Address ranges: 004052ab-00405312
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_004052ab(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_00408d98 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_00408da8,0x220,&param_2,1,lpMultiByteStr,DAT_00408aa0,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  DAT_00408c04 = 0x2a;
  return -1;
}


/*
 * __aulldiv at 00405320
 * undefined8 __stdcall __aulldiv(uint param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00405320-00405387
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
 * __aullrem at 00405390
 * undefined8 __stdcall __aullrem(uint param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00405390-00405404
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
 * FUN_00405405 at 00405405
 * undefined __cdecl FUN_00405405(byte param_1)
 * Address ranges: 00405405-00405415
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00405405(byte param_1)

{
  FUN_00405416(param_1,0,4);
  return;
}


/*
 * FUN_00405416 at 00405416
 * undefined4 __cdecl FUN_00405416(byte param_1, uint param_2, byte param_3)
 * Address ranges: 00405416-00405446
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00405416(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((*(byte *)((int)&DAT_00408ee0 + param_1 + 1) & param_3) == 0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(&DAT_00408892 + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


/*
 * FUN_00405450 at 00405450
 * uint * __cdecl FUN_00405450(uint * param_1, uint * param_2)
 * Address ranges: 00405450-00405456
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_00405450(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_00405538;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00405538:
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
 * FUN_00405460 at 00405460
 * uint * __cdecl FUN_00405460(uint * param_1, uint * param_2)
 * Address ranges: 00405460-0040553f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * __cdecl FUN_00405460(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0040547c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_004054af;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x004054cb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0040547c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x004054cb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x004054cb;
    }
  }
LAB_004054af:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x004054cb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_00405538:
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
    if (bVar1 == 0) goto LAB_00405538;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


/*
 * FUN_00405540 at 00405540
 * int __cdecl FUN_00405540(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00405540-004055c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00405540(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00408d80 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00408d80 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00408d80 != (FARPROC)0x0) {
        DAT_00408d84 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_00408d88 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_0040558f;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_0040558f:
    if (DAT_00408d84 != (FARPROC)0x0) {
      iVar1 = (*DAT_00408d84)();
      if ((iVar1 != 0) && (DAT_00408d88 != (FARPROC)0x0)) {
        iVar1 = (*DAT_00408d88)(iVar1);
      }
    }
    iVar1 = (*DAT_00408d80)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


/*
 * FUN_004055c9 at 004055c9
 * int * __cdecl FUN_004055c9(int param_1, int param_2)
 * Address ranges: 004055c9-00405645
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * __cdecl FUN_004055c9(int param_1,int param_2)

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
      if ((_Size < DAT_004083bc || (int)_Size - (int)DAT_004083bc == 0) &&
         (piVar1 = FUN_00402e7e(_Size), piVar1 != (int *)0x0)) {
        _memset(piVar1,0,(size_t)_Size);
        return piVar1;
      }
      piVar1 = HeapAlloc(DAT_0040a01c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_00408c5c == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_00403333(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}


/*
 * FUN_0040569e at 0040569e
 * int __cdecl FUN_0040569e(uint param_1, int param_2)
 * Address ranges: 0040569e-004057e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_0040569e(uint param_1,int param_2)

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
  
  FUN_00405c60();
  iVar7 = 0;
  if ((param_1 < DAT_0040a120) &&
     ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    DVar1 = FUN_004021bf(param_1,0,1);
    if ((DVar1 != 0xffffffff) && (DVar2 = FUN_004021bf(param_1,0,2), DVar2 != 0xffffffff)) {
      uVar8 = param_2 - DVar2;
      if ((int)uVar8 < 1) {
        if ((int)uVar8 < 0) {
          FUN_004021bf(param_1,param_2,0);
          hFile = (HANDLE)FUN_00404696(param_1);
          BVar6 = SetEndOfFile(hFile);
          iVar7 = (BVar6 != 0) - 1;
          if (iVar7 == -1) {
            DAT_00408c04 = 0xd;
            DAT_00408c08 = GetLastError();
          }
        }
      }
      else {
        _memset(local_1004,0,0x1000);
        uStackY_28 = 0x40572e;
        iVar3 = FUN_00405be8(param_1,0x8000);
        do {
          uVar4 = 0x1000;
          if ((int)uVar8 < 0x1000) {
            uVar4 = uVar8;
          }
          iVar5 = FUN_0040289a(param_1,local_1004,uVar4);
          if (iVar5 == -1) {
            if (DAT_00408c08 == 5) {
              DAT_00408c04 = 0xd;
            }
            iVar7 = -1;
            break;
          }
          uVar8 = uVar8 - iVar5;
        } while (0 < (int)uVar8);
        FUN_00405be8(param_1,iVar3);
      }
      FUN_004021bf(param_1,DVar1,0);
      return iVar7;
    }
  }
  else {
    DAT_00408c04 = 9;
  }
  return -1;
}


/*
 * FUN_004057e4 at 004057e4
 * int __cdecl FUN_004057e4(LCID param_1, uint param_2, char * param_3, int param_4, LPWSTR param_5, int param_6, UINT param_7, int param_8)
 * Address ranges: 004057e4-004058f3;00405907-004059a7;004059ba-00405a07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl
FUN_004057e4(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004074e8;
  pcStack_10 = FUN_004042ac;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00408db0 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_00408db0 = 2;
    }
    else {
      DAT_00408db0 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_00405a08(param_3,param_4);
  }
  if (DAT_00408db0 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_00408db0 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_00408da8;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_00405c60();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_00405c60();
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
 * FUN_004058f4 at 004058f4
 * undefined FUN_004058f4(void)
 * Address ranges: 004058f4-004058f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004058f4(void)

{
  return 1;
}


/*
 * FUN_004059a8 at 004059a8
 * undefined FUN_004059a8(void)
 * Address ranges: 004059a8-004059ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004059a8(void)

{
  return 1;
}


/*
 * FUN_00405a08 at 00405a08
 * int __cdecl FUN_00405a08(char * param_1, int param_2)
 * Address ranges: 00405a08-00405a32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00405a08(char *param_1,int param_2)

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
 * FUN_00405a33 at 00405a33
 * BOOL __cdecl FUN_00405a33(DWORD param_1, LPCSTR param_2, int param_3, LPWORD param_4, UINT param_5, LCID param_6, int param_7)
 * Address ranges: 00405a33-00405b2b;00405b37-00405b7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


BOOL __cdecl
FUN_00405a33(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
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
  puStack_c = &DAT_00407500;
  pcStack_10 = FUN_004042ac;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_00408db4;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_00408db4 == 0) {
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
  DAT_00408db4 = iVar3;
  if (DAT_00408db4 != 2) {
    if (DAT_00408db4 == 1) {
      if (param_5 == 0) {
        param_5 = DAT_00408da8;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_00405c60();
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
    param_6 = DAT_00408d98;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}


/*
 * FUN_00405b2c at 00405b2c
 * undefined FUN_00405b2c(void)
 * Address ranges: 00405b2c-00405b2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00405b2c(void)

{
  return 1;
}


/*
 * FUN_00405b7c at 00405b7c
 * undefined __stdcall FUN_00405b7c(void)
 * Address ranges: 00405b7c-00405b84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00405b7c(void)

{
  __amsg_exit(2);
  return;
}


/*
 * _memset at 00405b90
 * void * __cdecl _memset(void * _Dst, int _Val, size_t _Size)
 * Address ranges: 00405b90-00405be7
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
 * FUN_00405be8 at 00405be8
 * int __cdecl FUN_00405be8(uint param_1, int param_2)
 * Address ranges: 00405be8-00405c5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __cdecl FUN_00405be8(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 < DAT_0040a120) {
    bVar1 = *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8);
    if ((bVar1 & 1) != 0) {
      if (param_2 == 0x8000) {
        bVar2 = bVar1 & 0x7f;
      }
      else {
        if (param_2 != 0x4000) {
          DAT_00408c04 = 0x16;
          return -1;
        }
        bVar2 = bVar1 | 0x80;
      }
      *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) = bVar2;
      return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  DAT_00408c04 = 9;
  return -1;
}


/*
 * FUN_00405c60 at 00405c60
 * undefined __stdcall FUN_00405c60(void)
 * Address ranges: 00405c60-00405c8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Unable to track spacebase fully for stack */

void FUN_00405c60(void)

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
 * KERNEL32.DLL::RtlUnwind at 00405c90
 * void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
 * Address ranges: 00405c90-00405c95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::RtlUnwind
 */


void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x00405c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}


/*
 * FUN_00405c96 at 00405c96
 * undefined __cdecl FUN_00405c96(int param_1, uint * param_2, undefined4 * param_3)
 * Address ranges: 00405c96-00405cac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00405c96(int param_1,uint *param_2,undefined4 *param_3)

{
  FUN_00405cad(param_1,param_2,param_3,(char *)0x0);
  return;
}


/*
 * FUN_00405cad at 00405cad
 * char * __cdecl FUN_00405cad(int param_1, uint * param_2, undefined4 * param_3, char * param_4)
 * Address ranges: 00405cad-00405df5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_00405cad(int param_1,uint *param_2,undefined4 *param_3,char *param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  size_t sVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  undefined **ppuVar7;
  char *local_c;
  
  pbVar1 = (byte *)FUN_00405efe((byte *)param_2,0x5c);
  pbVar2 = (byte *)FUN_00405efe((byte *)param_2,0x2f);
  puVar4 = param_2;
  if (pbVar2 == (byte *)0x0) {
    if ((pbVar1 != (byte *)0x0) ||
       (pbVar1 = FUN_00405e8b((byte *)param_2,0x3a), pbVar1 != (byte *)0x0)) goto LAB_00405d22;
    sVar3 = _strlen((char *)param_2);
    puVar4 = _malloc(sVar3 + 3);
    if (puVar4 != (uint *)0x0) {
      FUN_00405450(puVar4,(uint *)&DAT_0040752c);
      FUN_00405460(puVar4,param_2);
      pbVar1 = (byte *)((int)puVar4 + 2);
      goto LAB_00405d22;
    }
LAB_00405d7b:
    local_c = (char *)0xffffffff;
  }
  else {
    if ((pbVar1 == (byte *)0x0) || (pbVar1 < pbVar2)) {
      pbVar1 = pbVar2;
    }
LAB_00405d22:
    local_c = (char *)0xffffffff;
    iVar5 = FUN_00405efe(pbVar1,0x2e);
    if (iVar5 == 0) {
      sVar3 = _strlen((char *)puVar4);
      puVar6 = _malloc(sVar3 + 5);
      if (puVar6 == (uint *)0x0) goto LAB_00405d7b;
      FUN_00405450(puVar6,puVar4);
      sVar3 = _strlen((char *)puVar4);
      ppuVar7 = &PTR_DAT_00408abc;
      do {
        FUN_00405450((uint *)(sVar3 + (int)puVar6),(uint *)*ppuVar7);
        iVar5 = FUN_00405e47((LPCSTR)puVar6,0);
        if (iVar5 != -1) {
          local_c = FUN_00405df6(param_1,(LPCSTR)puVar6,param_3,param_4);
          break;
        }
        ppuVar7 = ppuVar7 + -1;
      } while (0x408aaf < (int)ppuVar7);
      FUN_00401779(puVar6);
    }
    else {
      iVar5 = FUN_00405e47((LPCSTR)puVar4,0);
      if (iVar5 != -1) {
        local_c = FUN_00405df6(param_1,(LPCSTR)puVar4,param_3,param_4);
      }
    }
    if (puVar4 != param_2) {
      FUN_00401779(puVar4);
    }
  }
  return local_c;
}


/*
 * FUN_00405df6 at 00405df6
 * char * __cdecl FUN_00405df6(int param_1, LPCSTR param_2, undefined4 * param_3, char * param_4)
 * Address ranges: 00405df6-00405e46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_00405df6(int param_1,LPCSTR param_2,undefined4 *param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_0040613d(param_3,(undefined4 *)param_4,&param_4,&param_3);
  if (iVar1 == -1) {
    return (char *)0xffffffff;
  }
  pcVar2 = FUN_00405f5e(param_1,param_2,param_4,param_3);
  FUN_00401779(param_4);
  FUN_00401779(param_3);
  return pcVar2;
}


/*
 * FUN_00405e47 at 00405e47
 * undefined4 __cdecl FUN_00405e47(LPCSTR param_1, byte param_2)
 * Address ranges: 00405e47-00405e8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl FUN_00405e47(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    FUN_00402a47(DVar1);
  }
  else {
    if (((DVar1 & 1) == 0) || ((param_2 & 2) == 0)) {
      return 0;
    }
    DAT_00408c04 = 0xd;
    DAT_00408c08 = 5;
  }
  return 0xffffffff;
}


/*
 * FUN_00405e8b at 00405e8b
 * byte * __cdecl FUN_00405e8b(byte * param_1, uint param_2)
 * Address ranges: 00405e8b-00405efd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


byte * __cdecl FUN_00405e8b(byte *param_1,uint param_2)

{
  ushort uVar1;
  byte *pbVar2;
  
  if (DAT_00408dcc == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
    return pbVar2;
  }
  while( true ) {
    uVar1 = (ushort)*param_1;
    if (uVar1 == 0) break;
    if ((*(byte *)((int)&DAT_00408ee0 + uVar1 + 1) & 4) == 0) {
      pbVar2 = param_1;
      if (param_2 == uVar1) break;
    }
    else {
      pbVar2 = param_1 + 1;
      if (param_1[1] == 0) {
        return (byte *)0x0;
      }
      if (param_2 == CONCAT11(*param_1,param_1[1])) {
        return param_1;
      }
    }
    param_1 = pbVar2 + 1;
  }
  return (byte *)(~-(uint)(param_2 != uVar1) & (uint)param_1);
}


/*
 * FUN_00405efe at 00405efe
 * undefined __cdecl FUN_00405efe(byte * param_1, uint param_2)
 * Address ranges: 00405efe-00405f5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_00405efe(byte *param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  bool bVar6;
  
  pbVar3 = (byte *)0x0;
  if (DAT_00408dcc == 0) {
    _strrchr((char *)param_1,param_2);
    return;
  }
  do {
    bVar5 = *param_1;
    if ((*(byte *)((int)&DAT_00408ee0 + bVar5 + 1) & 4) == 0) {
      bVar6 = param_2 == bVar5;
LAB_00405f51:
      pbVar4 = param_1;
      if (bVar6) {
        pbVar3 = param_1;
      }
    }
    else {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if (bVar1 == 0) {
        bVar6 = pbVar3 == (byte *)0x0;
        param_1 = pbVar4;
        bVar5 = bVar1;
        goto LAB_00405f51;
      }
      uVar2 = CONCAT11(bVar5,bVar1);
      bVar5 = bVar1;
      if (param_2 == uVar2) {
        pbVar3 = param_1;
      }
    }
    param_1 = pbVar4 + 1;
    if (bVar5 == 0) {
      return;
    }
  } while( true );
}


/*
 * FUN_00405f5e at 00405f5e
 * char * __cdecl FUN_00405f5e(int param_1, LPCSTR param_2, char * param_3, LPVOID param_4)
 * Address ranges: 00405f5e-0040613c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __cdecl FUN_00405f5e(int param_1,LPCSTR param_2,char *param_3,LPVOID param_4)

{
  undefined4 *puVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar5;
  undefined4 *puVar6;
  BOOL BVar7;
  DWORD DVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  _STARTUPINFOA local_64;
  _PROCESS_INFORMATION local_20;
  char *local_10;
  DWORD local_c;
  char local_5;
  char *pcVar4;
  
  local_5 = '\0';
  local_c = 0;
  if ((param_1 != 0) && (param_1 != 1)) {
    if (param_1 < 2) {
      DAT_00408c04 = 0x16;
      DAT_00408c08 = 0;
      return (char *)0xffffffff;
    }
    if (3 < param_1) {
      if (param_1 != 4) {
        DAT_00408c04 = 0x16;
        DAT_00408c08 = 0;
        return (char *)0xffffffff;
      }
      local_5 = '\x01';
    }
  }
  local_10 = param_3;
  pcVar3 = param_3;
  while (*pcVar3 != '\0') {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar3 != '\0');
    if (pcVar4[2] != '\0') {
      *pcVar3 = ' ';
      pcVar3 = pcVar4 + 2;
    }
  }
  _memset(&local_64,0,0x44);
  local_64.cb = 0x44;
  uVar11 = DAT_0040a120;
  uVar5 = DAT_0040a120;
  while ((uVar11 != 0 &&
         (uVar5 = uVar5 - 1,
         *(char *)((&DAT_0040a020)[(int)uVar5 >> 5] + 4 + (uVar5 & 0x1f) * 8) == '\0'))) {
    uVar11 = uVar11 - 1;
  }
  uVar5 = uVar11 * 5 + 4;
  local_64.cbReserved2 = (WORD)uVar5;
  local_64.lpReserved2 = (LPBYTE)FUN_004055c9(uVar5 & 0xffff,1);
  *(uint *)local_64.lpReserved2 = uVar11;
  uVar5 = 0;
  puVar9 = (uint *)((int)local_64.lpReserved2 + 4);
  puVar6 = (undefined4 *)((int)local_64.lpReserved2 + uVar11 + 4);
  if (0 < (int)uVar11) {
    do {
      puVar1 = (undefined4 *)((&DAT_0040a020)[(int)uVar5 >> 5] + (uVar5 & 0x1f) * 8);
      bVar2 = *(byte *)(puVar1 + 1);
      if ((bVar2 & 0x10) == 0) {
        *(byte *)puVar9 = bVar2;
        *puVar6 = *puVar1;
      }
      else {
        *(byte *)puVar9 = 0;
        *puVar6 = 0xffffffff;
      }
      uVar5 = uVar5 + 1;
      puVar9 = (uint *)((int)puVar9 + 1);
      puVar6 = puVar6 + 1;
    } while ((int)uVar5 < (int)uVar11);
  }
  if (local_5 != '\0') {
    puVar9 = (uint *)((int)local_64.lpReserved2 + 4);
    iVar10 = 0;
    puVar6 = (undefined4 *)((int)local_64.lpReserved2 + uVar11 + 4);
    while( true ) {
      uVar5 = uVar11;
      if (2 < (int)uVar11) {
        uVar5 = 3;
      }
      if ((int)uVar5 <= iVar10) break;
      *(undefined1 *)puVar9 = 0;
      *puVar6 = 0xffffffff;
      iVar10 = iVar10 + 1;
      puVar9 = (uint *)((int)puVar9 + 1);
      puVar6 = puVar6 + 1;
    }
    local_c = 8;
  }
  DAT_00408c04 = 0;
  DAT_00408c08 = 0;
  BVar7 = CreateProcessA(param_2,local_10,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,1,
                         local_c,param_4,(LPCSTR)0x0,&local_64,&local_20);
  DVar8 = GetLastError();
  FUN_00401779(local_64.lpReserved2);
  if (BVar7 != 0) {
    if (param_1 != 2) {
      if (param_1 == 0) {
        WaitForSingleObject(local_20.hProcess,0xffffffff);
        GetExitCodeProcess(local_20.hProcess,(LPDWORD)&param_3);
        CloseHandle(local_20.hProcess);
      }
      else if (param_1 == 4) {
        CloseHandle(local_20.hProcess);
        param_3 = (char *)0x0;
      }
      else {
        param_3 = local_20.hProcess;
      }
      CloseHandle(local_20.hThread);
      return param_3;
    }
                    /* WARNING: Subroutine does not return */
    __exit(0);
  }
  FUN_00402a47(DVar8);
  return (char *)0xffffffff;
}


/*
 * FUN_0040613d at 0040613d
 * undefined4 __cdecl FUN_0040613d(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 0040613d-00406340
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __cdecl
FUN_0040613d(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  char cVar6;
  undefined4 *puVar7;
  size_t sVar8;
  uint *puVar9;
  undefined4 *puVar10;
  
  sVar8 = 2;
  sVar3 = sVar8;
  for (puVar7 = param_1; (char *)*puVar7 != (char *)0x0; puVar7 = puVar7 + 1) {
    sVar1 = _strlen((char *)*puVar7);
    sVar3 = sVar3 + 1 + sVar1;
  }
  pvVar2 = _malloc(sVar3);
  *param_3 = pvVar2;
  if (pvVar2 == (void *)0x0) {
    *param_4 = 0;
LAB_0040625e:
    DAT_00408c04 = 0xc;
    DAT_00408c08 = 8;
LAB_00406272:
    uVar5 = 0xffffffff;
  }
  else {
    puVar7 = param_2;
    if (param_2 == (undefined4 *)0x0) {
      *param_4 = 0;
      puVar7 = param_4;
      puVar10 = param_4;
    }
    else {
      for (; (char *)*puVar7 != (char *)0x0; puVar7 = puVar7 + 1) {
        sVar3 = _strlen((char *)*puVar7);
        sVar8 = sVar8 + 1 + sVar3;
      }
      if (DAT_00408c50 == (char *)0x0) {
        DAT_00408c50 = FUN_00404082();
        if (DAT_00408c50 != (LPSTR)0x0) goto LAB_004061db;
        goto LAB_00406272;
      }
LAB_004061db:
      puVar7 = (undefined4 *)0x0;
      if (*DAT_00408c50 != '\0') {
        cVar6 = *DAT_00408c50;
        pcVar4 = DAT_00408c50;
        do {
          if (cVar6 == '=') break;
          sVar3 = _strlen(pcVar4);
          puVar7 = (undefined4 *)((int)puVar7 + sVar3 + 1);
          cVar6 = DAT_00408c50[(int)puVar7];
          pcVar4 = DAT_00408c50 + (int)puVar7;
        } while (cVar6 != '\0');
      }
      pcVar4 = DAT_00408c50 + (int)puVar7;
      puVar10 = puVar7;
      while ((((*pcVar4 == '=' && (pcVar4[1] != '\0')) && (pcVar4[2] == ':')) && (pcVar4[3] == '='))
            ) {
        sVar3 = _strlen(pcVar4 + 4);
        puVar10 = (undefined4 *)((int)puVar10 + sVar3 + 5);
        pcVar4 = DAT_00408c50 + (int)puVar10;
      }
      pvVar2 = _malloc((int)puVar10 + (sVar8 - (int)puVar7));
      *param_4 = pvVar2;
      if (pvVar2 == (void *)0x0) {
        FUN_00401779((LPVOID)*param_3);
        *param_3 = 0;
        goto LAB_0040625e;
      }
    }
    puVar9 = (uint *)*param_3;
    param_3 = param_1;
    if ((uint *)*param_1 != (uint *)0x0) {
      FUN_00405450(puVar9,(uint *)*param_1);
      param_3 = param_1 + 1;
      sVar3 = _strlen((char *)*param_1);
      puVar9 = (uint *)((int)puVar9 + sVar3 + 1);
      goto LAB_00406299;
    }
    while( true ) {
      puVar9 = (uint *)((int)puVar9 + 1);
LAB_00406299:
      if ((uint *)*param_3 == (uint *)0x0) break;
      FUN_00405450(puVar9,(uint *)*param_3);
      sVar3 = _strlen((char *)*param_3);
      puVar9 = (uint *)((int)puVar9 + sVar3);
      *(undefined1 *)puVar9 = 0x20;
      param_3 = param_3 + 1;
    }
    *(undefined1 *)((int)puVar9 + -1) = 0;
    *(undefined1 *)puVar9 = 0;
    puVar9 = (uint *)*param_4;
    if (param_2 != (undefined4 *)0x0) {
      FUN_00402450(puVar9,(undefined4 *)(DAT_00408c50 + (int)puVar7),(int)puVar10 - (int)puVar7);
      puVar9 = (uint *)((int)puVar9 + ((int)puVar10 - (int)puVar7));
      for (; (uint *)*param_2 != (uint *)0x0; param_2 = param_2 + 1) {
        FUN_00405450(puVar9,(uint *)*param_2);
        sVar3 = _strlen((char *)*param_2);
        puVar9 = (uint *)((int)puVar9 + sVar3 + 1);
      }
    }
    if (puVar9 != (uint *)0x0) {
      if (puVar9 == (uint *)*param_4) {
        *(undefined1 *)puVar9 = 0;
        puVar9 = (uint *)((int)puVar9 + 1);
      }
      *(undefined1 *)puVar9 = 0;
    }
    FUN_00401779(DAT_00408c50);
    DAT_00408c50 = (char *)0x0;
    uVar5 = 0;
  }
  return uVar5;
}


/*
 * _strchr at 00406360
 * char * __cdecl _strchr(char * _Str, int _Val)
 * Address ranges: 00406350-00406354;00406360-0040641b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _strchr  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */


/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}


/*
 * _strrchr at 00406420
 * char * __cdecl _strrchr(char * _Str, int _Ch)
 * Address ranges: 00406420-00406446
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


