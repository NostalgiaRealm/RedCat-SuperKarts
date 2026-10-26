/*
 * FUN_00433870 at 00433870
 * undefined FUN_00433870(void)
 * Address ranges: 00433870-00433cec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433870(float param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  DWORD DVar4;
  float10 fVar5;
  
  bVar3 = FUN_0042ee60();
  _DAT_0053bd88 = *(undefined4 *)((int)param_1 * 0xd0 + DAT_0067ee20 + 0xa4);
  DAT_0053bdf4 = ((int)(char)bVar3 & 0x20U) >> 5;
  if (((bVar3 & 0x10) != 0) && (DVar4 = GetTickCount(), 500 < DVar4 - _DAT_0053be1c)) {
    FUN_004513c0();
    FUN_004517f0();
    _DAT_0053be1c = GetTickCount();
  }
  fVar2 = DAT_0053bd74;
  if (DAT_0053ba34 == 1) {
    if ((bVar3 & 4) == 0) {
      if ((bVar3 & 8) == 0) {
        DAT_0053bd74 = 20.0;
        DAT_0053bd90 = 0;
        goto LAB_00433a6d;
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
    if ((bVar3 & 4) == 0) {
      DAT_0053bd74 = 0.0;
    }
    else {
      fVar5 = (float10)FUN_0048f4e0();
      fVar5 = fVar5 * (float10)70.0 + (float10)fVar2;
      DAT_0053bd74 = (float)fVar5;
      if ((float10)100.0 < fVar5) {
        DAT_0053bd74 = 100.0;
      }
    }
    if ((bVar3 & 8) == 0) {
      DAT_0053be04 = 0;
    }
    else {
      FUN_0048f4e0();
      DAT_0053be04 = __ftol();
      if (100 < DAT_0053be04) {
        DAT_0053be04 = 100;
      }
    }
    fVar2 = _DAT_0053bd70;
    if (DAT_0053ba34 != 1) {
      param_1 = _DAT_0053bd70;
      fVar1 = 1.0 - ABS(_DAT_0053bd70) * 0.01;
      fVar1 = fVar1 + fVar1;
      if ((((bVar3 & 1) != 0) && ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] != 1)) ||
         (((bVar3 & 2) != 0 && ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1)))) {
        if (0.0 < _DAT_0053bd70) {
          _DAT_0053bd70 = 0.0;
          return;
        }
        if (_DAT_0053bd70 == 0.0) {
          param_1 = -15.0;
        }
        fVar5 = (float10)FUN_0048f4e0();
        fVar5 = (float10)param_1 - fVar5 * (float10)fVar1 * (float10)200.0;
        _DAT_0053bd70 = (float)fVar5;
        if (fVar5 < (float10)-100.0) {
          _DAT_0053bd70 = -100.0;
          return;
        }
        return;
      }
      if ((((bVar3 & 2) == 0) || ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] == 1)) &&
         (((bVar3 & 1) == 0 || ((&DAT_0053a734)[DAT_0053b9b4 * 0x25] != 1)))) {
        if (0.0 < _DAT_0053bd70) {
          fVar5 = (float10)FUN_0048f4e0();
          fVar5 = (float10)fVar2 - fVar5 * (float10)400.0;
          _DAT_0053bd70 = (float)fVar5;
          if (fVar5 < (float10)0.0) {
            _DAT_0053bd70 = 0.0;
            return;
          }
          return;
        }
        if (_DAT_0053bd70 < 0.0) {
          fVar5 = (float10)FUN_0048f4e0();
          fVar5 = fVar5 * (float10)400.0 + (float10)fVar2;
          _DAT_0053bd70 = (float)fVar5;
          if ((float10)0.0 < fVar5) {
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
      fVar5 = (float10)FUN_0048f4e0();
      fVar5 = fVar5 * (float10)fVar1 * (float10)200.0 + (float10)param_1;
      _DAT_0053bd70 = (float)fVar5;
      if ((float10)100.0 < fVar5) {
        _DAT_0053bd70 = 100.0;
        return;
      }
      return;
    }
  }
LAB_00433a6d:
  if ((bVar3 & 1) == 0) {
    if ((bVar3 & 2) == 0) {
      _DAT_0053bd70 = 30.0;
      return;
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

