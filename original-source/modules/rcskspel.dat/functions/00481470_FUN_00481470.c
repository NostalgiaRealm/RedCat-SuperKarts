/*
 * FUN_00481470 at 00481470
 * undefined FUN_00481470(void)
 * Address ranges: 00481470-00481547
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00481470(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00545050 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f9794;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00545054 = (undefined4 *)0x0;
  _DAT_00545058 = 0;
  DAT_0054505c = 0;
  if (0xfffffffd < uVar2) {
    FUN_004bc15b();
  }
  if (((DAT_00545054 == (undefined4 *)0x0) ||
      (cVar1 = *(char *)((int)DAT_00545054 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_0054505c < 0x20) && (uVar2 <= DAT_0054505c)) goto LAB_0048151d;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    *(char *)((int)DAT_00545054 + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_0048151d:
  puVar4 = &DAT_004f9794;
  puVar6 = DAT_00545054;
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
  _DAT_00545058 = uVar2;
  *(undefined1 *)((int)DAT_00545054 + uVar2) = 0;
  return;
}

