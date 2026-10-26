/*
 * FUN_00432460 at 00432460
 * undefined FUN_00432460(void)
 * Address ranges: 00432460-004325ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432460(undefined4 param_1,int param_2)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    FUN_0049dd20(_DAT_004eb2d0);
    FUN_0049d7a0();
    _DAT_0053be14 = 0;
    DAT_0053bdf8 = 0;
    *(undefined4 *)(DAT_0053be2c * 300 + 0x4e0364) = _DAT_0053bae0;
  }
  else {
    DVar2 = GetTickCount();
    if (99 < (int)(DVar2 - _DAT_0053be18)) {
      _DAT_0053be18 = DVar2;
      if (0 < _DAT_0053be38) {
        FUN_0049dd20(_DAT_004eb2d0);
        iVar3 = FUN_0049d870();
        if ((iVar3 == 0) && (_DAT_0053be14 == 0)) {
          FUN_004371f0();
          cVar1 = FUN_00437550();
          if (cVar1 != '\0') {
            uVar4 = 0;
            FUN_0049dd20(_DAT_004eb2d0);
            FUN_0049d780(uVar4);
          }
          _DAT_0053be14 = 1;
        }
        _DAT_0053be38 = _DAT_0053be38 + -1;
        if (*(float *)(DAT_0053be2c * 300 + 0x4e0364) != 6.0) {
          _DAT_0053bae0 = *(undefined4 *)(DAT_0053be2c * 300 + 0x4e0364);
        }
        *(undefined4 *)(DAT_0053be2c * 300 + 0x4e0364) = 0x40c00000;
        DAT_0053bdf8 = 1;
        return;
      }
      DAT_0053bdf8 = 0;
      *(undefined4 *)(DAT_0053be2c * 300 + 0x4e0364) = _DAT_0053bae0;
      return;
    }
  }
  return;
}

