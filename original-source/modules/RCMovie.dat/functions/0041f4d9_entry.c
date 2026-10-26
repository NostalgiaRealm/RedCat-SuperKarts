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

