/*
 * FUN_00403ba0 at 00403ba0
 * LONG __cdecl FUN_00403ba0(int param_1, _EXCEPTION_POINTERS * param_2)
 * Address ranges: 00403ba0-00403ce0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LONG __cdecl FUN_00403ba0(int param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = FUN_00403ce1(param_1);
  uVar3 = DAT_00408c64;
  if ((piVar4 == (int *)0x0) || (pcVar1 = (code *)piVar4[2], pcVar1 == (code *)0x0)) {
    LVar5 = UnhandledExceptionFilter(param_2);
  }
  else if (pcVar1 == (code *)0x5) {
    piVar4[2] = 0;
    LVar5 = 1;
  }
  else {
    if (pcVar1 != (code *)0x1) {
      DAT_00408c64 = param_2;
      if (piVar4[1] == 8) {
        if (DAT_00408440 < DAT_00408444 + DAT_00408440) {
          iVar6 = (DAT_00408444 + DAT_00408440) - DAT_00408440;
          puVar7 = (undefined4 *)(DAT_00408440 * 0xc + 0x4083d0);
          do {
            *puVar7 = 0;
            puVar7 = puVar7 + 3;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        uVar2 = DAT_0040844c;
        iVar6 = *piVar4;
        if (iVar6 == -0x3fffff72) {
          DAT_0040844c = 0x83;
        }
        else if (iVar6 == -0x3fffff70) {
          DAT_0040844c = 0x81;
        }
        else if (iVar6 == -0x3fffff6f) {
          DAT_0040844c = 0x84;
        }
        else if (iVar6 == -0x3fffff6d) {
          DAT_0040844c = 0x85;
        }
        else if (iVar6 == -0x3fffff73) {
          DAT_0040844c = 0x82;
        }
        else if (iVar6 == -0x3fffff71) {
          DAT_0040844c = 0x86;
        }
        else if (iVar6 == -0x3fffff6e) {
          DAT_0040844c = 0x8a;
        }
        (*pcVar1)(8,DAT_0040844c);
        DAT_0040844c = uVar2;
      }
      else {
        piVar4[2] = 0;
        (*pcVar1)(piVar4[1]);
      }
    }
    LVar5 = -1;
    DAT_00408c64 = (_EXCEPTION_POINTERS *)uVar3;
  }
  return LVar5;
}

