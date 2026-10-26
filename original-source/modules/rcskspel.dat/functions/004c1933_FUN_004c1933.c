/*
 * FUN_004c1933 at 004c1933
 * undefined FUN_004c1933(void)
 * Address ranges: 004c1933-004c1a36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004c1933(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  
  piVar1 = DAT_006b6764;
  if (DAT_006b6768 == '\0') {
    piVar1 = (int *)FUN_004c947d(*param_1);
    FUN_004c9406(param_2 + (uint)(0 < param_3) + (uint)(*piVar1 == 0x2d),param_3 + 1,piVar1);
  }
  else {
    FUN_004c1c4b(param_2 + (*DAT_006b6764 == 0x2d));
  }
  puVar2 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = 0x2d;
    puVar2 = param_2 + 1;
  }
  if (0 < param_3) {
    *puVar2 = puVar2[1];
    puVar2[1] = DAT_00502f90;
  }
  puVar2 = (undefined1 *)FUN_004c51f0();
  if (param_4 != 0) {
    *puVar2 = 0x45;
  }
  if (*(char *)piVar1[3] != '0') {
    iVar3 = piVar1[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      puVar2[1] = 0x2d;
    }
    if (99 < iVar3) {
      puVar2[2] = puVar2[2] + (char)(iVar3 / 100);
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      puVar2[3] = puVar2[3] + (char)(iVar3 / 10);
      iVar3 = iVar3 % 10;
    }
    puVar2[4] = puVar2[4] + (char)iVar3;
  }
  return param_2;
}

