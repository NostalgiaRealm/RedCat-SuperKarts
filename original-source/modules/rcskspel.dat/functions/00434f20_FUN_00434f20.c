/*
 * FUN_00434f20 at 00434f20
 * undefined FUN_00434f20(void)
 * Address ranges: 00434f20-0043502a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00434f20(void)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar2 = __ftol();
  DVar3 = GetTickCount();
  if (DVar3 - _DAT_0053be20 < 300) {
    if ((17999 < iVar2) || (DAT_006a5b5c != 0)) goto LAB_00435021;
    FUN_004371f0();
    cVar1 = FUN_00437550();
    uVar5 = DAT_0053bad8;
    if (cVar1 == '\0') goto LAB_00435021;
  }
  else if (iVar2 < 18000) {
    FUN_004371f0();
    cVar1 = FUN_00437550();
    if (cVar1 == '\0') goto LAB_00435021;
    uVar4 = FUN_004be6c9();
    uVar4 = uVar4 & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    uVar5 = (&DAT_0053bac0)[uVar4];
  }
  else if (iVar2 < 25000) {
    FUN_004371f0();
    cVar1 = FUN_00437550();
    if (cVar1 == '\0') goto LAB_00435021;
    uVar4 = FUN_004be6c9();
    uVar4 = uVar4 & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    uVar5 = *(undefined4 *)(&DAT_0053bac8 + uVar4 * 4);
  }
  else {
    FUN_004371f0();
    cVar1 = FUN_00437550();
    if (cVar1 == '\0') goto LAB_00435021;
    uVar4 = FUN_004be6c9();
    uVar4 = uVar4 & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    uVar5 = *(undefined4 *)(&DAT_0053bad0 + uVar4 * 4);
  }
  uVar6 = 0;
  FUN_0049dd20(uVar5);
  FUN_0049d780(uVar6);
LAB_00435021:
  _DAT_0053be20 = GetTickCount();
  return;
}

