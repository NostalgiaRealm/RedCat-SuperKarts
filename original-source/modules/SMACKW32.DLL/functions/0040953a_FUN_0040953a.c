/*
 * FUN_0040953a at 0040953a
 * undefined FUN_0040953a(void)
 * Address ranges: 0040953a-0040960d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD __fastcall FUN_0040953a(undefined4 param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBX;
  uint dwStackSize;
  undefined8 uVar1;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  char acStack_48 [24];
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  HANDLE pvStack_28;
  uint uStack_24;
  HANDLE pvStack_20;
  HANDLE *ppvStack_1c;
  HANDLE pvStack_18;
  DWORD DStack_14;
  
  if (DAT_0040ef40 == -1) {
    uVar1 = FUN_004088eb(param_1,0xffffffff);
    if ((int)uVar1 == 0) {
      return (int)((ulonglong)uVar1 >> 0x20);
    }
    FUN_004089fb();
    param_1 = extraout_ECX;
  }
  uStack_2c = param_1;
  pvStack_28 = GetCurrentThread();
  dwStackSize = unaff_EBX + 0xfffU & 0xfffff000;
  uStack_50 = DAT_0040e614;
  uStack_4c = DAT_0040e618;
  acStack_48[0] = DAT_0040e61c;
  uStack_24 = dwStackSize;
  GetCurrentThreadId();
  FUN_00409752(extraout_ECX_00,acStack_48);
  pvStack_20 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)&uStack_50);
  ppvStack_1c = &pvStack_18;
  pvStack_18 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,dwStackSize,FUN_0040948e,auStack_30,0,
                            &DStack_14);
  if (pvStack_18 == (HANDLE)0x0) {
    DStack_14 = 0xffffffff;
  }
  else {
    WaitForSingleObject(pvStack_20,0xffffffff);
  }
  CloseHandle(pvStack_20);
  return DStack_14;
}

