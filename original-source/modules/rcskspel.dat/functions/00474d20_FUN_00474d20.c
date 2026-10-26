/*
 * FUN_00474d20 at 00474d20
 * undefined FUN_00474d20(void)
 * Address ranges: 00474d20-00474d47
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00474d20(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544de0 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_car_ssr_ini_004f790c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544de4 = (char *)0x0;
  _DAT_00544de8 = 0;
  DAT_00544dec = 0;
  if ((((uVar2 < 0xfffffffe) || (FUN_004bc15b(), DAT_00544de4 == (char *)0x0)) ||
      (cVar1 = DAT_00544de4[-1], cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      FUN_0040b4f0(1);
      return;
    }
    if ((DAT_00544dec < 0x20) && (uVar2 <= DAT_00544dec)) goto LAB_00474dcd;
    FUN_0040b4f0(1);
  }
  else if (uVar2 == 0) {
    DAT_00544de4[-1] = cVar1 + -1;
    FUN_0040b4f0(0);
    return;
  }
  FUN_0040b720(uVar2);
LAB_00474dcd:
  pcVar4 = s_car_ssr_ini_004f790c;
  pcVar5 = DAT_00544de4;
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
  _DAT_00544de8 = uVar2;
  DAT_00544de4[uVar2] = '\0';
  return;
}

