/*
 * FUN_00426f04 at 00426f04
 * undefined4 __cdecl FUN_00426f04(int param_1)
 * Address ranges: 00426f04-00427030
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00426f04(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  
  iVar2 = param_1;
  if (param_1 == 2) {
    puVar3 = &DAT_0043e5a4;
    pcVar6 = DAT_0043e5a4;
  }
  else if (((param_1 == 4) || (param_1 == 8)) || (param_1 == 0xb)) {
    puVar3 = FUN_00427031(param_1);
    pcVar6 = (code *)puVar3[2];
    puVar3 = puVar3 + 2;
  }
  else if (param_1 == 0xf) {
    puVar3 = &DAT_0043e5b0;
    pcVar6 = DAT_0043e5b0;
  }
  else if (param_1 == 0x15) {
    puVar3 = &DAT_0043e5a8;
    pcVar6 = DAT_0043e5a8;
  }
  else {
    if (param_1 != 0x16) {
      return 0xffffffff;
    }
    puVar3 = &DAT_0043e5ac;
    pcVar6 = DAT_0043e5ac;
  }
  iVar1 = DAT_0043e330;
  iVar4 = DAT_004371b4;
  if (pcVar6 == (code *)0x1) {
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (iVar5 = param_1, param_1 == 4)) {
    DAT_0043e330 = 0;
    iVar5 = iVar1;
    if (param_1 == 8) {
      DAT_004371b4 = 0x8c;
      param_1 = iVar4;
      goto LAB_00426fc8;
    }
LAB_00426ff4:
    *puVar3 = 0;
    if (iVar2 != 8) {
      (*pcVar6)(iVar2);
      if ((iVar2 != 0xb) && (iVar2 != 4)) {
        return 0;
      }
      goto LAB_00427017;
    }
  }
  else {
LAB_00426fc8:
    if (iVar2 != 8) goto LAB_00426ff4;
    if (DAT_004371a8 < DAT_004371ac + DAT_004371a8) {
      iVar4 = (DAT_004371ac + DAT_004371a8) - DAT_004371a8;
      puVar3 = (undefined4 *)(DAT_004371a8 * 0xc + 0x437138);
      do {
        *puVar3 = 0;
        puVar3 = puVar3 + 3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  (*pcVar6)(8,DAT_004371b4);
LAB_00427017:
  if (iVar2 == 8) {
    DAT_004371b4 = param_1;
  }
  DAT_0043e330 = iVar5;
  return 0;
}

