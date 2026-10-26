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

