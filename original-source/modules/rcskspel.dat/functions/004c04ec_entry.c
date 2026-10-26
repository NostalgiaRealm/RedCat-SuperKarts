/*
 * entry at 004c04ec
 * undefined entry(void)
 * Address ranges: 004c04ec-004c05d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HMODULE pHVar5;
  undefined4 uVar6;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 *local_18;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004d3a90;
  pcStack_10 = FUN_004c2aa4;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_006b6700 = DVar1 >> 8 & 0xff;
  _DAT_006b66fc = DVar1 & 0xff;
  _DAT_006b66f8 = _DAT_006b66fc * 0x100 + _DAT_006b6700;
  _DAT_006b66f4 = DVar1 >> 0x10;
  iVar2 = FUN_004c62d6(0);
  if (iVar2 == 0) {
    FUN_004c0607(0x1c);
  }
  local_8 = 0;
  FUN_004c7b70();
  DAT_006b7dc4 = GetCommandLineA();
  DAT_006b6734 = FUN_004c7a3e();
  FUN_004c77f1();
  FUN_004c7738();
  FUN_004c022f();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  uVar3 = FUN_004c76e0();
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_60.wShowWindow;
  }
  uVar6 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  uVar3 = FUN_004432a0(pHVar5,uVar6,uVar3,uVar4);
  FUN_004c025c(uVar3);
  FUN_004c755c(*(undefined4 *)*local_18,local_18);
  return;
}

