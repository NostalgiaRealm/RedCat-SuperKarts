/*
 * FUN_00433cf0 at 00433cf0
 * undefined FUN_00433cf0(void)
 * Address ranges: 00433cf0-004341cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433cf0(float param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  float10 fVar7;
  
  uVar4 = FUN_0042ee60();
  uVar1 = *(undefined4 *)((int)param_1 * 0xd0 + DAT_0067ee20 + 0xa4);
  if (((uVar4 & 0x10) != 0) && (DVar5 = GetTickCount(), 500 < DVar5 - _DAT_0053be1c)) {
    FUN_004513c0();
    FUN_004517f0();
    _DAT_0053be1c = GetTickCount();
  }
  _DAT_0053bd88 = uVar1;
  if ((uVar4 & 0x20) == 0) {
    iVar6 = FUN_004b3830(0x20);
    DAT_0053bdf4 = 0;
    if (iVar6 != 0) goto LAB_00433d87;
  }
  else {
LAB_00433d87:
    DAT_0053bdf4 = 1;
  }
  fVar3 = DAT_0053bd74;
  if (DAT_0053ba34 == 1) {
    if ((uVar4 & 4) == 0) {
      if ((uVar4 & 8) == 0) {
        DAT_0053bd74 = 20.0;
        DAT_0053bd90 = 0;
        goto LAB_00433f02;
      }
      if (DAT_0053bd74 <= 20.0) {
        if (DAT_0053bd74 <= 0.0) {
          DAT_0053bd74 = 0.0;
        }
        else {
          DAT_0053bd74 = DAT_0053bd74 - 10.0;
        }
      }
      else {
        DAT_0053bd74 = 10.0;
      }
    }
    else if (DAT_0053bd74 < 40.0) {
      DAT_0053bd74 = DAT_0053bd74 + 5.0;
    }
    else {
      DAT_0053bd74 = 40.0;
    }
    if (DAT_0053bd90 == 1) {
      DAT_0053bd74 = 20.0;
    }
  }
  else {
    if ((uVar4 & 4) == 0) {
      DAT_0053bd74 = 0.0;
    }
    else {
      fVar7 = (float10)FUN_0048f4e0();
      fVar7 = fVar7 * (float10)70.0 + (float10)fVar3;
      DAT_0053bd74 = (float)fVar7;
      if ((float10)100.0 < fVar7) {
        DAT_0053bd74 = 100.0;
      }
    }
    if ((uVar4 & 8) == 0) {
      DAT_0053be04 = 0;
    }
    else {
      FUN_0048f4e0();
      DAT_0053be04 = __ftol();
      if (100 < DAT_0053be04) {
        DAT_0053be04 = 100;
      }
    }
    fVar3 = _DAT_0053bd70;
    if (DAT_0053ba34 != 1) {
      param_1 = _DAT_0053bd70;
      fVar2 = 1.0 - ABS(_DAT_0053bd70) * 0.01;
      fVar2 = fVar2 + fVar2;
      if ((((uVar4 & 1) != 0) && ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] != 1)) ||
         (((uVar4 & 2) != 0 && ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1)))) {
        if (0.0 < _DAT_0053bd70) {
          _DAT_0053bd70 = 0.0;
          return;
        }
        if (_DAT_0053bd70 == 0.0) {
          param_1 = -15.0;
        }
        fVar7 = (float10)FUN_0048f4e0();
        fVar7 = (float10)param_1 - fVar7 * (float10)fVar2 * (float10)200.0;
        _DAT_0053bd70 = (float)fVar7;
        if (fVar7 < (float10)-100.0) {
          _DAT_0053bd70 = -100.0;
          return;
        }
        return;
      }
      if ((((uVar4 & 2) == 0) || ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1)) &&
         (((uVar4 & 1) == 0 || ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] != 1)))) {
        if (0.0 < _DAT_0053bd70) {
          fVar7 = (float10)FUN_0048f4e0();
          fVar7 = (float10)fVar3 - fVar7 * (float10)400.0;
          _DAT_0053bd70 = (float)fVar7;
          if (fVar7 < (float10)0.0) {
            _DAT_0053bd70 = 0.0;
            return;
          }
          return;
        }
        if (_DAT_0053bd70 < 0.0) {
          fVar7 = (float10)FUN_0048f4e0();
          fVar7 = fVar7 * (float10)400.0 + (float10)fVar3;
          _DAT_0053bd70 = (float)fVar7;
          if ((float10)0.0 < fVar7) {
            _DAT_0053bd70 = 0.0;
            return;
          }
          return;
        }
        return;
      }
      if (_DAT_0053bd70 < 0.0) {
        _DAT_0053bd70 = 0.0;
        return;
      }
      if (_DAT_0053bd70 == 0.0) {
        param_1 = 15.0;
      }
      fVar7 = (float10)FUN_0048f4e0();
      fVar7 = fVar7 * (float10)fVar2 * (float10)200.0 + (float10)param_1;
      _DAT_0053bd70 = (float)fVar7;
      if ((float10)100.0 < fVar7) {
        _DAT_0053bd70 = 100.0;
        return;
      }
      return;
    }
  }
LAB_00433f02:
  if ((((uVar4 & 1) != 0) && ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] != 1)) ||
     (((uVar4 & 2) != 0 && ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1)))) {
    if (30.0 < _DAT_0053bd70) {
      _DAT_0053bd70 = 30.0;
      return;
    }
    if (_DAT_0053bd70 == 0.0) {
      _DAT_0053bd70 = 0.0;
      return;
    }
    _DAT_0053bd70 = _DAT_0053bd70 - 2.0;
    return;
  }
  if (((uVar4 & 2) == 0) || ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1)) {
    if ((uVar4 & 1) == 0) {
      _DAT_0053bd70 = 30.0;
      return;
    }
    if ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] != 1) {
      _DAT_0053bd70 = 30.0;
      return;
    }
  }
  if (_DAT_0053bd70 < 30.0) {
    _DAT_0053bd70 = 30.0;
    return;
  }
  if (_DAT_0053bd70 < 60.0) {
    _DAT_0053bd70 = _DAT_0053bd70 + 2.0;
    return;
  }
  return;
}

