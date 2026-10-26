/*
 * FUN_004350d0 at 004350d0
 * undefined FUN_004350d0(void)
 * Address ranges: 004350d0-00435168
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004350d0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  
  if (DAT_0053b9f4 == 0) {
    fVar1 = 1.6;
    fVar2 = 1.15;
    fVar3 = 1.15;
  }
  else if (DAT_0053b9f4 == 1) {
    fVar1 = 1.7;
    fVar2 = 1.2;
    fVar3 = 1.2;
  }
  else if (DAT_0053b9f4 == 2) {
    fVar1 = 2.5;
    fVar2 = 1.5;
    fVar3 = 1.5;
  }
  else {
    fVar1 = 1.1;
    fVar2 = 1.1;
    fVar3 = 1.1;
  }
  pfVar5 = (float *)&DAT_00506948;
  do {
    iVar6 = 6;
    *pfVar5 = fVar1 * *pfVar5;
    pfVar4 = pfVar5 + -0x18;
    do {
      iVar6 = iVar6 + -1;
      pfVar4[0xc] = fVar2 * pfVar4[0xc];
      *pfVar4 = fVar3 * *pfVar4;
      pfVar4 = pfVar4 + 1;
    } while (iVar6 != 0);
    pfVar5 = pfVar5 + 0x1f;
  } while ((int)pfVar5 < 0x506e20);
  return;
}

