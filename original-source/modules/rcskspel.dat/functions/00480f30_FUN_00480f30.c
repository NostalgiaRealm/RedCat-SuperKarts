/*
 * FUN_00480f30 at 00480f30
 * undefined FUN_00480f30(void)
 * Address ranges: 00480f30-00481007
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00480f30(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00545090 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_options_004f9774;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00545094 = (char *)0x0;
  _DAT_00545098 = 0;
  DAT_0054509c = 0;
  if (0xfffffffd < uVar2) {
    FUN_004bc15b();
  }
  if (((DAT_00545094 == (char *)0x0) || (cVar1 = DAT_00545094[-1], cVar1 == '\0')) || (cVar1 == -1))
  {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_0054509c < 0x20) && (uVar2 <= DAT_0054509c)) goto LAB_00480fdd;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    DAT_00545094[-1] = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_00480fdd:
  pcVar4 = s_options_004f9774;
  pcVar5 = DAT_00545094;
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
  _DAT_00545098 = uVar2;
  DAT_00545094[uVar2] = '\0';
  return;
}

