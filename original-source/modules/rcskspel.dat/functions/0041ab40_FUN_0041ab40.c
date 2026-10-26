/*
 * FUN_0041ab40 at 0041ab40
 * undefined FUN_0041ab40(void)
 * Address ranges: 0041ab40-0041ad99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ab40(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_0041aa20();
  FUN_004b1850(0,0,0x28,&DAT_004e23e4);
  iVar2 = FUN_004b3830(0x1b);
  while (iVar2 == 0) {
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = DAT_00508618 * 0x1f + iVar3;
      fVar1 = (float)(&DAT_00506918)[iVar2];
      (&DAT_00506918)[iVar2] = fVar1 + 1.0;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s_Max_speed_gear__d___f_004e23e8,iVar3 + 1,
                   (double)(fVar1 + 1.0));
      FUN_00419230(0x6b);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = DAT_00508618 * 0x1f + iVar3;
      fVar1 = (float)(&DAT_00506918)[iVar2];
      (&DAT_00506918)[iVar2] = fVar1 - 1.0;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s_Max_speed_gear__d___f_004e2400,iVar3 + 1,
                   (double)(fVar1 - 1.0));
      FUN_00419230(0x6d);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = DAT_00508618 * 0x1f + iVar3;
      fVar1 = (float)(&DAT_00506918)[iVar2];
      (&DAT_00506918)[iVar2] = fVar1 - 10.0;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s_Max_speed_gear__d___f_004e2418,iVar3 + 1,
                   (double)(fVar1 - 10.0));
      FUN_00419230(0x25);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = DAT_00508618 * 0x1f + iVar3;
      fVar1 = (float)(&DAT_00506918)[iVar2];
      (&DAT_00506918)[iVar2] = fVar1 + 10.0;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s_Max_speed_gear__d___f_004e2430,iVar3 + 1,
                   (double)(fVar1 + 10.0));
      FUN_00419230(0x27);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e2448);
      if (iVar3 == 0) {
        iVar3 = 5;
      }
      else {
        iVar3 = iVar3 + -1;
      }
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e244c);
      FUN_00419230(0x26);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e2450);
      if (iVar3 == 5) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + 1;
      }
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e2454);
      FUN_00419230(0x28);
    }
    iVar2 = FUN_004b3830();
  }
  FUN_00419230();
  return;
}

