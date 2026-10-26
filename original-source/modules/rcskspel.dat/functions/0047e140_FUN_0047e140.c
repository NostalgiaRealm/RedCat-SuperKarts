/*
 * FUN_0047e140 at 0047e140
 * undefined FUN_0047e140(void)
 * Address ranges: 0047e140-0047e217
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047e140(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00545028 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_dialogs_dat_004f8884;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_0054502c = (char *)0x0;
  _DAT_00545030 = 0;
  DAT_00545034 = 0;
  if ((((uVar2 < 0xfffffffe) || (FUN_004bc15b(), DAT_0054502c == (char *)0x0)) ||
      (cVar1 = DAT_0054502c[-1], cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_00545034 < 0x20) && (uVar2 <= DAT_00545034)) goto LAB_0047e1ed;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    DAT_0054502c[-1] = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_0047e1ed:
  pcVar4 = s_dialogs_dat_004f8884;
  pcVar5 = DAT_0054502c;
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
  _DAT_00545030 = uVar2;
  DAT_0054502c[uVar2] = '\0';
  return;
}

