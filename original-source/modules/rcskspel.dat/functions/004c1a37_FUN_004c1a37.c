/*
 * FUN_004c1a37 at 004c1a37
 * undefined FUN_004c1a37(void)
 * Address ranges: 004c1a37-004c1b14
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004c1a37(undefined8 *param_1,undefined1 *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  
  piVar1 = DAT_006b6764;
  if (DAT_006b6768 == '\0') {
    piVar1 = (int *)FUN_004c947d(*param_1);
    FUN_004c9406(param_2 + (*piVar1 == 0x2d),piVar1[1] + param_3,piVar1);
  }
  else if (DAT_006b676c == param_3) {
    iVar2 = (*DAT_006b6764 == 0x2d) + DAT_006b676c;
    param_2[iVar2] = 0x30;
    (param_2 + iVar2)[1] = 0;
  }
  puVar3 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = 0x2d;
    puVar3 = param_2 + 1;
  }
  if (piVar1[1] < 1) {
    FUN_004c1c4b(puVar3,1);
    *puVar3 = 0x30;
    puVar3 = puVar3 + 1;
  }
  else {
    puVar3 = puVar3 + piVar1[1];
  }
  if (0 < (int)param_3) {
    FUN_004c1c4b(puVar3,1);
    *puVar3 = DAT_00502f90;
    iVar2 = piVar1[1];
    if (iVar2 < 0) {
      if ((DAT_006b6768 != '\0') || (-iVar2 <= (int)param_3)) {
        param_3 = -iVar2;
      }
      FUN_004c1c4b(puVar3 + 1,param_3);
      _memset(puVar3 + 1,0x30,param_3);
    }
  }
  return param_2;
}

