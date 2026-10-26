/*
 * FUN_004358d0 at 004358d0
 * undefined FUN_004358d0(void)
 * Address ranges: 004358d0-0043599a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_004358d0(int param_1)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 local_4;
  
  fVar1 = *(float *)(param_1 + 0x98);
  if (fVar1 < 0.0) {
    _DAT_0053bd70 = 0.0;
    DAT_0053bdf4 = 0;
    return (uint)(ushort)((ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                         (ushort)(fVar1 == 0.0) << 0xe);
  }
  uVar2 = FUN_004be6c9();
  uVar2 = uVar2 & 0x80000001;
  bVar3 = uVar2 == 0;
  if ((int)uVar2 < 0) {
    bVar3 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
  }
  local_4 = -1.0;
  if (bVar3) {
    local_4 = 1.0;
  }
  fVar4 = (float10)FUN_0048f4e0();
  *(float *)(param_1 + 0x98) = (float)((float10)*(float *)(param_1 + 0x98) - fVar4);
  fVar4 = (float10)FUN_0048f4e0();
  fVar5 = fVar4 * (float10)local_4 * (float10)4000.0 + (float10)_DAT_0053bd70;
  _DAT_0053bd70 = (float)fVar5;
  fVar4 = (float10)100.0;
  if (fVar5 >= fVar4 && fVar5 != fVar4) {
    _DAT_0053bd70 = 100.0;
    return CONCAT31((uint3)(fVar5 < fVar4),1);
  }
  bVar3 = _DAT_0053bd70 < -100.0;
  if (bVar3) {
    _DAT_0053bd70 = -100.0;
  }
  return CONCAT31((uint3)bVar3,1);
}

