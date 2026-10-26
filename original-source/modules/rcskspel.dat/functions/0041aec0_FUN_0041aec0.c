/*
 * FUN_0041aec0 at 0041aec0
 * undefined FUN_0041aec0(void)
 * Address ranges: 0041aec0-0041b061
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041aec0(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_0041ada0();
  FUN_004b1850(0,0,0x28,&DAT_004e2500);
  iVar2 = FUN_004b3830(0x1b);
  while (iVar2 == 0) {
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = DAT_00508618 * 0x1f + iVar3;
      fVar1 = (float)(&DAT_005068e8)[iVar2];
      (&DAT_005068e8)[iVar2] = fVar1 + 0.01;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s_Acceleration_gear__d___f_004e2504,iVar3 + 1,
                   (double)(fVar1 + 0.01));
      FUN_00419230(0x6b);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = DAT_00508618 * 0x1f + iVar3;
      fVar1 = (float)(&DAT_005068e8)[iVar2];
      (&DAT_005068e8)[iVar2] = fVar1 - 0.01;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s_Acceleration_gear__d___f_004e2520,iVar3 + 1,
                   (double)(fVar1 - 0.01));
      FUN_00419230(0x6d);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e253c);
      if (iVar3 == 0) {
        iVar3 = 5;
      }
      else {
        iVar3 = iVar3 + -1;
      }
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e2540);
      FUN_00419230(0x26);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e2544);
      if (iVar3 == 5) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + 1;
      }
      FUN_004b1850(0,0,(iVar3 * 5 + 10) * 4,&DAT_004e2548);
      FUN_00419230(0x28);
    }
    iVar2 = FUN_004b3830();
  }
  FUN_00419230();
  return;
}

