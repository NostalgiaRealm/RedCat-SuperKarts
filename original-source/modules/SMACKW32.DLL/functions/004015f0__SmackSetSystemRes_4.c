/*
 * _SmackSetSystemRes@4 at 004015f0
 * bool __stdcall _SmackSetSystemRes@4(uint param_1)
 * Address ranges: 004015f0-004016fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool _SmackSetSystemRes_4(uint param_1)

{
  HMODULE hModule;
  int iVar1;
  bool bVar2;
  undefined1 *puVar3;
  char *lpProcName;
  undefined1 local_a4 [36];
  undefined2 local_80;
  undefined4 local_7c;
  undefined4 local_38;
  undefined4 local_34;
  
                    /* 0x15f0  9  _SmackSetSystemRes@4 */
  if (param_1 < 5) {
    if (DAT_0040e838 == (FARPROC)0x0) {
      lpProcName = s_ChangeDisplaySettingsA_0040e104;
      hModule = GetModuleHandleA(s_user32_dll_0040e0f8);
      DAT_0040e838 = GetProcAddress(hModule,lpProcName);
      if (DAT_0040e838 == (FARPROC)0x0) {
        DAT_0040e838 = (FARPROC)0xffffffff;
      }
    }
    puVar3 = local_a4;
    if (DAT_0040e838 == (FARPROC)0xffffffff) {
      return false;
    }
    if (param_1 == 0) {
      puVar3 = (undefined1 *)0x0;
    }
    else {
      if (param_1 == 1) {
        local_38 = 0x280;
        local_34 = 400;
      }
      else if (param_1 == 2) {
        local_38 = 0x280;
        local_34 = 0x1e0;
      }
      else if (param_1 == 3) {
        local_38 = 800;
        local_34 = 600;
      }
      else if (param_1 == 4) {
        local_38 = 0x400;
        local_34 = 0x300;
      }
      local_7c = 0x180000;
      local_80 = 0x94;
    }
    iVar1 = (*DAT_0040e838)(puVar3,0);
    bVar2 = iVar1 == 0;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}

