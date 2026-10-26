/*
 * FUN_004c7d54 at 004c7d54
 * undefined FUN_004c7d54(void)
 * Address ranges: 004c7d54-004c7ea6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c7d54(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  char acStackY_1e3 [7];
  undefined1 *puStackY_1dc;
  char *pcStackY_1d8;
  undefined4 uStackY_1d4;
  undefined1 *puStackY_1d0;
  undefined4 uStackY_1cc;
  undefined1 *puStackY_1c8;
  undefined *puStackY_1c4;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  CHAR local_1a8 [260];
  undefined1 local_a4 [160];
  
  iVar5 = 0;
  pDVar2 = &DAT_005034d8;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x503568);
  if (param_1 == (&DAT_005034d8)[iVar5 * 2]) {
    if ((DAT_006b673c == 1) || ((DAT_006b673c == 0 && (DAT_00502ae4 == 1)))) {
      lpNumberOfBytesWritten = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x5034dc);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      puStackY_1c4 = (undefined *)0x4c7e9d;
      hFile = GetStdHandle(0xfffffff4);
      puStackY_1c4 = (undefined *)0x4c7ea4;
      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_004c51f0();
      }
      sVar4 = _strlen(local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(local_1a8);
        puStackY_1c4 = (undefined *)0x4c7e1e;
        _strncpy(acStackY_1e3 + sVar4,"...",3);
      }
      FUN_004c51f0();
      puStackY_1c4 = (undefined *)0x4c7e3f;
      FUN_004c5200();
      puStackY_1c8 = local_a4;
      puStackY_1c4 = &DAT_004d3f14;
      uStackY_1cc = 0x4c7e50;
      FUN_004c5200();
      uStackY_1cc = *(undefined4 *)(iVar5 * 8 + 0x5034dc);
      puStackY_1d0 = local_a4;
      uStackY_1d4 = 0x4c7e62;
      FUN_004c5200();
      uStackY_1d4 = 0x12010;
      puStackY_1dc = local_a4;
      pcStackY_1d8 = "Microsoft Visual C++ Runtime Library";
      builtin_strncpy(acStackY_1e3 + 3,"x~L",4);
      FUN_004ca2fb();
    }
  }
  return;
}

