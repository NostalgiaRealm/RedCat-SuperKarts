/*
 * FUN_00407892 at 00407892
 * undefined4 __fastcall FUN_00407892(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407892-004079b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00407892(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  HMODULE unaff_EBX;
  undefined8 uVar3;
  CHAR local_10c [260];
  
  DAT_004104e0 = in_EAX;
  uVar3 = FUN_004088ac(param_1,param_2);
  DAT_004104e4 = (int)uVar3;
  if (DAT_004104e4 == 0) {
    if (in_EAX == 0) {
                    /* WARNING: Subroutine does not return */
      ExitProcess(1);
    }
    uVar2 = 0;
  }
  else {
    FUN_00408708(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
    _DAT_0040f041 = GetEnvironmentStrings();
    GetModuleFileNameA((HMODULE)0x0,local_10c,0x104);
    uVar3 = FUN_00408b80(extraout_ECX_00,extraout_EDX);
    _DAT_0040f014 = (undefined4)uVar3;
    GetCommandLineA();
    uVar3 = FUN_00408b80(0,extraout_EDX_00);
    _DAT_0040f010 = (char *)uVar3;
    if (CONCAT31((int3)((uint)extraout_ECX_01 >> 8),*_DAT_0040f010) != 0x22) {
      do {
        if (((&DAT_0040e620)[(byte)(*_DAT_0040f010 + 1)] & 2) != 0) goto LAB_0040793e;
        if (*_DAT_0040f010 == '\0') goto LAB_0040793e;
        _DAT_0040f010 = _DAT_0040f010 + 1;
      } while( true );
    }
    do {
      _DAT_0040f010 = _DAT_0040f010 + 1;
      if (*_DAT_0040f010 == '\"') break;
    } while (*_DAT_0040f010 != '\0');
    if (*_DAT_0040f010 == '\0') goto LAB_0040793e;
    do {
      _DAT_0040f010 = _DAT_0040f010 + 1;
LAB_0040793e:
    } while (((&DAT_0040e620)[(byte)(*_DAT_0040f010 + 1)] & 2) != 0);
    if (in_EAX != 0) {
      GetModuleFileNameA(unaff_EBX,local_10c,0x104);
      uVar3 = FUN_00408b80(extraout_ECX_02,extraout_EDX_01);
      _DAT_0040f018 = (undefined4)uVar3;
    }
    DVar1 = GetVersion();
    DAT_0040f047 = (undefined1)(DVar1 >> 0x18);
    DAT_0040f049 = (undefined2)DVar1;
    DAT_0040f048 = (byte)(DVar1 >> 0x10) & 0xf;
    uVar2 = 1;
  }
  return uVar2;
}

