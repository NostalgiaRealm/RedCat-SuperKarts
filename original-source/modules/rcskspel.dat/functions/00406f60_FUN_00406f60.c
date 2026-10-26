/*
 * FUN_00406f60 at 00406f60
 * undefined FUN_00406f60(void)
 * Address ranges: 00406f60-0040712e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406f60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 local_4 [4];
  
  iVar2 = param_1;
  iVar1 = *(int *)(param_1 * 0xd0 + 0x1c + DAT_0067ee20);
  if (DAT_00508610 < 0xf) {
    piVar4 = &DAT_00503ef0 + DAT_00508610 * 0x47;
    do {
      if (*piVar4 == param_1) {
        return;
      }
      piVar4 = piVar4 + 0x47;
    } while ((int)piVar4 < 0x504f94);
  }
  iVar5 = 0;
  if (0 < DAT_00508610) {
    piVar4 = &DAT_00503ef0;
    do {
      iVar3 = *piVar4 * 0xd0 + DAT_0067ee20;
      if ((iVar1 == *(int *)(iVar3 + 0x1c)) && ((float)piVar4[0xc] <= *(float *)(iVar3 + 0xa4))) {
        FUN_00402620(param_1,(&DAT_00503ef0)[iVar5 * 0x47]);
        return;
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 0x47;
    } while (iVar5 < DAT_00508610);
  }
  if ((iVar1 == DAT_0053be40) && (FUN_004057f0(param_1,&param_1,local_4), param_1 != 0)) {
    switch(param_1) {
    case 4:
      if (DAT_0050504c < *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)) {
        FUN_00402620(iVar2,DAT_0053be28);
        return;
      }
      break;
    case 5:
      if (_DAT_00505050 < *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)) {
        FUN_00402620(iVar2,DAT_0053be28);
        return;
      }
      break;
    case 6:
      if (_DAT_00505054 < *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)) {
        FUN_00402620(iVar2,DAT_0053be28);
        return;
      }
      break;
    case 8:
      if (_DAT_00505058 < *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)) {
        FUN_00402620(iVar2,DAT_0053be28);
      }
    }
  }
  return;
}

