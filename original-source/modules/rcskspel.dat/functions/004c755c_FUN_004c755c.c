/*
 * FUN_004c755c at 004c755c
 * undefined FUN_004c755c(void)
 * Address ranges: 004c755c-004c769c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LONG FUN_004c755c(undefined4 param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = (int *)FUN_004c769d(param_1);
  uVar3 = DAT_006b67c8;
  if ((piVar4 == (int *)0x0) || (pcVar1 = (code *)piVar4[2], pcVar1 == (code *)0x0)) {
    LVar5 = UnhandledExceptionFilter(param_2);
  }
  else if (pcVar1 == (code *)0x5) {
    piVar4[2] = 0;
    LVar5 = 1;
  }
  else {
    if (pcVar1 != (code *)0x1) {
      DAT_006b67c8 = param_2;
      if (piVar4[1] == 8) {
        if (DAT_005034c0 < DAT_005034c4 + DAT_005034c0) {
          iVar6 = (DAT_005034c4 + DAT_005034c0) - DAT_005034c0;
          puVar7 = (undefined4 *)(DAT_005034c0 * 0xc + 0x503450);
          do {
            *puVar7 = 0;
            puVar7 = puVar7 + 3;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        uVar2 = DAT_005034cc;
        iVar6 = *piVar4;
        if (iVar6 == -0x3fffff72) {
          DAT_005034cc = 0x83;
        }
        else if (iVar6 == -0x3fffff70) {
          DAT_005034cc = 0x81;
        }
        else if (iVar6 == -0x3fffff6f) {
          DAT_005034cc = 0x84;
        }
        else if (iVar6 == -0x3fffff6d) {
          DAT_005034cc = 0x85;
        }
        else if (iVar6 == -0x3fffff73) {
          DAT_005034cc = 0x82;
        }
        else if (iVar6 == -0x3fffff71) {
          DAT_005034cc = 0x86;
        }
        else if (iVar6 == -0x3fffff6e) {
          DAT_005034cc = 0x8a;
        }
        (*pcVar1)(8,DAT_005034cc);
        DAT_005034cc = uVar2;
      }
      else {
        piVar4[2] = 0;
        (*pcVar1)(piVar4[1]);
      }
    }
    LVar5 = -1;
    DAT_006b67c8 = (_EXCEPTION_POINTERS *)uVar3;
  }
  return LVar5;
}

