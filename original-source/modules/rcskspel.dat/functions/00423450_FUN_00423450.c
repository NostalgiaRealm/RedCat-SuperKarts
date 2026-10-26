/*
 * FUN_00423450 at 00423450
 * undefined FUN_00423450(void)
 * Address ranges: 00423450-0042355a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423450(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int local_18;
  int local_14;
  
  local_14 = 0;
  pfVar4 = (float *)&DAT_005091c4;
  do {
    fVar1 = (float)local_14;
    local_14 = local_14 + 1;
    local_18 = 0;
    pfVar5 = pfVar4;
    do {
      fVar2 = (float)local_18;
      local_18 = local_18 + 1;
      pfVar4 = pfVar5 + 0x10;
      fVar3 = fVar2 * 12.5 - 100.0;
      pfVar5[-9] = fVar3;
      pfVar5[-8] = fVar1 * 15.0 - 75.0;
      pfVar5[-7] = 100.0;
      pfVar5[-5] = -NAN;
      pfVar5[-4] = 0.0;
      fVar2 = fVar2 * 0.06249997 * 0.0625 + 0.445313;
      pfVar5[-3] = fVar2;
      pfVar5[-2] = 0.046875 - fVar1 * 0.046875 * 0.1;
      pfVar5[-1] = fVar3;
      *pfVar5 = (float)local_14 * 15.0 - 75.0;
      pfVar5[1] = 100.0;
      pfVar5[3] = -NAN;
      pfVar5[4] = 0.0;
      pfVar5[5] = fVar2;
      pfVar5[6] = 0.046875 - (float)local_14 * 0.046875 * 0.1;
      pfVar5 = pfVar4;
    } while (local_18 < 0x11);
  } while ((int)pfVar4 < 0x50bc44);
  return;
}

