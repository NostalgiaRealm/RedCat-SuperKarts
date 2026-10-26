/*
 * FUN_00464150 at 00464150
 * undefined FUN_00464150(void)
 * Address ranges: 00464150-0046425e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00464150(undefined1 *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_85;
  char local_80 [128];
  
  puVar4 = &DAT_004d2404;
  if (*(undefined1 **)(param_3 + 4) != (undefined1 *)0x0) {
    puVar4 = *(undefined1 **)(param_3 + 4);
  }
  puVar3 = *(undefined1 **)(param_2 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b1f10(puVar3,puVar4,local_80,0x7f);
  uVar5 = 0xffffffff;
  *param_1 = local_85;
  *(undefined4 *)(param_1 + 4) = 0;
  pcVar7 = local_80;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (0xfffffffd < uVar5) {
    FUN_004bc15b();
  }
  iVar2 = *(int *)(param_1 + 4);
  if (((iVar2 == 0) || (cVar1 = *(char *)(iVar2 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar5 == 0) {
      FUN_0040b4f0(1);
      return param_1;
    }
    if ((*(uint *)(param_1 + 0xc) < 0x20) && (uVar5 <= *(uint *)(param_1 + 0xc))) goto LAB_00464231;
    FUN_0040b4f0(1);
  }
  else if (uVar5 == 0) {
    *(char *)(iVar2 + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return param_1;
  }
  FUN_0040b720(uVar5);
LAB_00464231:
  pcVar7 = local_80;
  pcVar8 = *(char **)(param_1 + 4);
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  *(uint *)(param_1 + 8) = uVar5;
  *(undefined1 *)(*(int *)(param_1 + 4) + uVar5) = 0;
  return param_1;
}

