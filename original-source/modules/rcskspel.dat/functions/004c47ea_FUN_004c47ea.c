/*
 * FUN_004c47ea at 004c47ea
 * undefined FUN_004c47ea(void)
 * Address ranges: 004c47ea-004c4949
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004c47ea(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = param_1;
  if (*param_1 < 0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_004c9bcf();
    iVar2 = *piVar1;
    if ((iVar2 < 0x3f481) || (0x7ffc0b7e < iVar2)) {
      piVar1 = (int *)FUN_004ca12e(piVar1);
      iVar3 = FUN_004c9e42(piVar1);
      iVar2 = *piVar1;
      if (iVar3 != 0) {
        iVar2 = iVar2 - DAT_005036b8;
      }
      param_1 = (int *)(iVar2 - DAT_005036b0);
      iVar2 = (int)param_1 % 0x3c;
      *piVar1 = iVar2;
      if (iVar2 < 0) {
        *piVar1 = iVar2 + 0x3c;
        param_1 = (int *)((int)param_1 + -0x3c);
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar1[1]);
      iVar2 = (int)param_1 % 0x3c;
      piVar1[1] = iVar2;
      if (iVar2 < 0) {
        piVar1[1] = iVar2 + 0x3c;
        param_1 = (int *)((int)param_1 + -0x3c);
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar1[2]);
      iVar2 = (int)param_1 % 0x18;
      piVar1[2] = iVar2;
      if (iVar2 < 0) {
        piVar1[2] = iVar2 + 0x18;
        param_1 = (int *)((int)param_1 + -0x18);
      }
      iVar2 = (int)param_1 / 0x18;
      if (iVar2 < 1) {
        if (-1 < iVar2) {
          return piVar1;
        }
        piVar1[6] = (piVar1[6] + 7 + iVar2) % 7;
        piVar1[3] = piVar1[3] + iVar2;
        if (piVar1[3] < 1) {
          piVar1[5] = piVar1[5] + -1;
          piVar1[3] = piVar1[3] + 0x1f;
          piVar1[7] = 0x16c;
          piVar1[4] = 0xb;
          return piVar1;
        }
      }
      else {
        piVar1[6] = (piVar1[6] + iVar2) % 7;
        piVar1[3] = piVar1[3] + iVar2;
      }
      piVar1[7] = piVar1[7] + iVar2;
    }
    else {
      param_1 = (int *)(iVar2 - DAT_005036b0);
      piVar1 = (int *)FUN_004ca12e(&param_1);
      if ((DAT_005036b4 != 0) && (iVar2 = FUN_004c9e42(piVar1), iVar2 != 0)) {
        param_1 = (int *)((int)param_1 - DAT_005036b8);
        piVar1 = (int *)FUN_004ca12e(&param_1);
        piVar1[8] = 1;
      }
    }
  }
  return piVar1;
}

