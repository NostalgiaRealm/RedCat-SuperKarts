/*
 * FUN_00477b20 at 00477b20
 * undefined FUN_00477b20(void)
 * Address ranges: 00477b20-00477bf7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00477b20(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544e28 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f7d6c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544e2c = (undefined4 *)0x0;
  _DAT_00544e30 = 0;
  DAT_00544e34 = 0;
  if ((((uVar2 < 0xfffffffe) || (FUN_004bc15b(), DAT_00544e2c == (undefined4 *)0x0)) ||
      (cVar1 = *(char *)((int)DAT_00544e2c + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_00544e34 < 0x20) && (uVar2 <= DAT_00544e34)) goto LAB_00477bcd;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    *(char *)((int)DAT_00544e2c + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_00477bcd:
  puVar4 = &DAT_004f7d6c;
  puVar6 = DAT_00544e2c;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  _DAT_00544e30 = uVar2;
  *(undefined1 *)((int)DAT_00544e2c + uVar2) = 0;
  return;
}

