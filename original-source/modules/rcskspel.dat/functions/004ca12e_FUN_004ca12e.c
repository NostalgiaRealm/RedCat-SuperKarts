/*
 * FUN_004ca12e at 004ca12e
 * undefined FUN_004ca12e(void)
 * Address ranges: 004ca12e-004ca226
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004ca12e(int *param_1)

{
  int iVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  bVar2 = false;
  iVar1 = *param_1;
  if (iVar1 < 0) {
    puVar3 = (undefined *)0x0;
  }
  else {
    iVar4 = iVar1 % 0x7861f80;
    iVar1 = (iVar1 / 0x7861f80) * 4;
    _DAT_006b69e4 = iVar1 + 0x46;
    iVar5 = iVar4;
    if (0x1e1337f < iVar4) {
      iVar5 = iVar4 + -0x1e13380;
      _DAT_006b69e4 = iVar1 + 0x47;
      if (0x1e1337f < iVar5) {
        iVar5 = iVar4 + -0x3c26700;
        _DAT_006b69e4 = iVar1 + 0x48;
        if (iVar5 < 0x1e28500) {
          bVar2 = true;
        }
        else {
          _DAT_006b69e4 = iVar1 + 0x49;
          iVar5 = iVar4 + -0x5a4ec00;
        }
      }
    }
    _DAT_006b69ec = iVar5 / 0x15180;
    piVar6 = (int *)&DAT_00503764;
    if (!bVar2) {
      piVar6 = (int *)&DAT_00503798;
    }
    _DAT_006b69e0 = 1;
    piVar7 = piVar6;
    while (piVar7 = piVar7 + 1, *piVar7 < _DAT_006b69ec) {
      _DAT_006b69e0 = _DAT_006b69e0 + 1;
    }
    _DAT_006b69e0 = _DAT_006b69e0 + -1;
    _DAT_006b69dc = _DAT_006b69ec - piVar6[_DAT_006b69e0];
    _DAT_006b69e8 = (*param_1 / 0x15180 + 4) % 7;
    _DAT_006b69d8 = (iVar5 % 0x15180) / 0xe10;
    _DAT_006b69d0 = (iVar5 % 0x15180) % 0xe10;
    _DAT_006b69d4 = _DAT_006b69d0 / 0x3c;
    _DAT_006b69d0 = _DAT_006b69d0 % 0x3c;
    _DAT_006b69f0 = 0;
    puVar3 = &DAT_006b69d0;
  }
  return puVar3;
}

