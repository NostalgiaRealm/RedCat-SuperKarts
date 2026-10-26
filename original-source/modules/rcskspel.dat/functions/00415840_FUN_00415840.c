/*
 * FUN_00415840 at 00415840
 * undefined FUN_00415840(void)
 * Address ranges: 00415840-00415983
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415840(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  
  DAT_00507298 = 0;
  iVar3 = (DAT_0053bf00 != 0) + 5;
  if (*(float *)(param_1 * 0xd0 + 0xa4 + DAT_0067ee20) < 0.0) {
    _DAT_00507290 = 800.0;
    DAT_00507298 = 0;
    return;
  }
  fVar2 = ((*(float *)(param_1 * 0xd0 + 0xa4 + DAT_0067ee20) * 3600.0 * 0.016666668) /
          (*(float *)(&DAT_00505b6c + DAT_0053be2c * 0xac) * 3.1415927 +
          *(float *)(&DAT_00505b6c + DAT_0053be2c * 0xac) * 3.1415927)) * 3.07;
  if (iVar3 != 0) {
    pfVar4 = (float *)&DAT_004e025c;
    fVar1 = _DAT_004e025c;
    do {
      _DAT_00507290 = fVar1 * fVar2 * 0.666;
      if (_DAT_00507290 <= *(float *)(&DAT_00505bcc + (DAT_0053bef0 + DAT_0053be2c * 0x2b) * 4)) {
        if (DAT_00507298 < iVar3) goto LAB_00415964;
        break;
      }
      pfVar4 = pfVar4 + 1;
      DAT_00507298 = DAT_00507298 + 1;
      fVar1 = *pfVar4;
    } while (DAT_00507298 < iVar3);
  }
  DAT_00507298 = (DAT_0053bf00 != 0) + 4;
  _DAT_00507290 = fVar2 * *(float *)(&DAT_004e0258 + iVar3 * 4) * 0.666;
LAB_00415964:
  if (_DAT_00507290 < 800.0) {
    _DAT_00507290 = 800.0;
  }
  return;
}

