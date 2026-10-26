/*
 * FUN_0047d1a0 at 0047d1a0
 * undefined FUN_0047d1a0(void)
 * Address ranges: 0047d1a0-0047d277
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047d1a0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544fb8 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f86e4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544fbc = (undefined4 *)0x0;
  _DAT_00544fc0 = 0;
  DAT_00544fc4 = 0;
  if ((((uVar2 < 0xfffffffe) || (FUN_004bc15b(), DAT_00544fbc == (undefined4 *)0x0)) ||
      (cVar1 = *(char *)((int)DAT_00544fbc + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_00544fc4 < 0x20) && (uVar2 <= DAT_00544fc4)) goto LAB_0047d24d;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    *(char *)((int)DAT_00544fbc + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_0047d24d:
  puVar4 = &DAT_004f86e4;
  puVar6 = DAT_00544fbc;
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
  _DAT_00544fc0 = uVar2;
  *(undefined1 *)((int)DAT_00544fbc + uVar2) = 0;
  return;
}

