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

