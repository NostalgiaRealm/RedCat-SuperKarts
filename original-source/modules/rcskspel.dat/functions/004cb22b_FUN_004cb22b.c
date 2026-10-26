/*
 * FUN_004cb22b at 004cb22b
 * undefined FUN_004cb22b(void)
 * Address ranges: 004cb22b-004cb357
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004cb22b(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  
  iVar2 = param_1;
  if (param_1 == 2) {
    puVar3 = &DAT_006b6a04;
    pcVar6 = DAT_006b6a04;
  }
  else if (((param_1 == 4) || (param_1 == 8)) || (param_1 == 0xb)) {
    iVar4 = FUN_004cb358(param_1);
    pcVar6 = *(code **)(iVar4 + 8);
    puVar3 = (undefined4 *)(iVar4 + 8);
  }
  else if (param_1 == 0xf) {
    puVar3 = &DAT_006b6a10;
    pcVar6 = DAT_006b6a10;
  }
  else if (param_1 == 0x15) {
    puVar3 = &DAT_006b6a08;
    pcVar6 = DAT_006b6a08;
  }
  else {
    if (param_1 != 0x16) {
      return 0xffffffff;
    }
    puVar3 = &DAT_006b6a0c;
    pcVar6 = DAT_006b6a0c;
  }
  iVar1 = DAT_006b67c8;
  iVar4 = DAT_005034cc;
  if (pcVar6 == (code *)0x1) {
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (iVar5 = param_1, param_1 == 4)) {
    DAT_006b67c8 = 0;
    iVar5 = iVar1;
    if (param_1 == 8) {
      DAT_005034cc = 0x8c;
      param_1 = iVar4;
      goto LAB_004cb2ef;
    }
LAB_004cb31b:
    *puVar3 = 0;
    if (iVar2 != 8) {
      (*pcVar6)(iVar2);
      if ((iVar2 != 0xb) && (iVar2 != 4)) {
        return 0;
      }
      goto LAB_004cb33e;
    }
  }
  else {
LAB_004cb2ef:
    if (iVar2 != 8) goto LAB_004cb31b;
    if (DAT_005034c0 < DAT_005034c4 + DAT_005034c0) {
      iVar4 = (DAT_005034c4 + DAT_005034c0) - DAT_005034c0;
      puVar3 = (undefined4 *)(DAT_005034c0 * 0xc + 0x503450);
      do {
        *puVar3 = 0;
        puVar3 = puVar3 + 3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  (*pcVar6)(8,DAT_005034cc);
LAB_004cb33e:
  if (iVar2 == 8) {
    DAT_005034cc = param_1;
  }
  DAT_006b67c8 = iVar5;
  return 0;
}

