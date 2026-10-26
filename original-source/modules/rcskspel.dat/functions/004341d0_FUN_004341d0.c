/*
 * FUN_004341d0 at 004341d0
 * undefined FUN_004341d0(void)
 * Address ranges: 004341d0-00434355
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004341d0(void)

{
  uint uVar1;
  DWORD DVar2;
  bool bVar3;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_0053ba34 == 1) {
    uVar1 = FUN_0042ef90(0x3c,0x28,&local_c,&local_8);
    if (local_c < 0x1f) {
      local_4 = -*(int *)(&DAT_0053bb5c + local_c * -4);
    }
    else {
      local_4 = (&DAT_0053ba6c)[local_c];
    }
    local_4 = local_4 + 0x1e;
    _DAT_0053bd70 = (float)local_4;
    DAT_0053bd74 = (float)local_8;
    if (DAT_0053bd74 < 10.0) {
      DAT_0053bd74 = 0.0;
    }
  }
  else {
    uVar1 = FUN_0042ef90(100,100,&local_c,&local_8);
    if (local_8 < 0x32) {
      DAT_0053bd74 = 0.0;
      DAT_0053be04 = (0x32 - local_8) * 2;
    }
    else {
      DAT_0053be04 = 0;
      DAT_0053bd74 = (float)(local_8 * 2 + -100);
    }
    if ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1) {
      local_4 = (0x32 - local_c) * 2;
    }
    else {
      local_4 = local_c * 2 + -100;
    }
    _DAT_0053bd70 = (float)local_4;
  }
  bVar3 = (uVar1 & 0x20) != 0;
  if (bVar3) {
    DAT_00507288 = 0;
  }
  DAT_0053bdf4 = (uint)bVar3;
  if (((uVar1 & 0x10) != 0) && (DVar2 = GetTickCount(), 500 < DVar2 - _DAT_0053be1c)) {
    FUN_004513c0();
    FUN_004517f0();
    _DAT_0053be1c = GetTickCount();
  }
  return;
}

