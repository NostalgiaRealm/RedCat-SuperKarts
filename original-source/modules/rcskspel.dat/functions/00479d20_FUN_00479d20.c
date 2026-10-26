/*
 * FUN_00479d20 at 00479d20
 * undefined FUN_00479d20(void)
 * Address ranges: 00479d20-00479df7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00479d20(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544e88 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_Race_INI_004f7ee0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544e8c = (char *)0x0;
  _DAT_00544e90 = 0;
  DAT_00544e94 = 0;
  if ((((uVar2 < 0xfffffffe) || (FUN_004bc15b(), DAT_00544e8c == (char *)0x0)) ||
      (cVar1 = DAT_00544e8c[-1], cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_00544e94 < 0x20) && (uVar2 <= DAT_00544e94)) goto LAB_00479dcd;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    DAT_00544e8c[-1] = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_00479dcd:
  pcVar4 = s_Race_INI_004f7ee0;
  pcVar5 = DAT_00544e8c;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  _DAT_00544e90 = uVar2;
  DAT_00544e8c[uVar2] = '\0';
  return;
}

