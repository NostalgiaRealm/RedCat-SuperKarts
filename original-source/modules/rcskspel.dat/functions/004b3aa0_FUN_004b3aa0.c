/*
 * FUN_004b3aa0 at 004b3aa0
 * undefined FUN_004b3aa0(void)
 * Address ranges: 004b3aa0-004b3bb9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3aa0(undefined4 *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  
  iVar2 = FUN_004b3a80();
  if (iVar2 == -1) {
    return 0;
  }
  FUN_004afce0(s__s___s_00500404,param_2,param_3);
  uVar5 = 0xffffffff;
  iVar7 = iVar2 * 0xd8;
  do {
    pcVar4 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar4 = pcVar4 + -uVar5;
  pcVar9 = (char *)(iVar7 + 0x10 + DAT_006ab794);
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar4 = param_3;
  do {
    pcVar9 = pcVar4;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar4 = pcVar9 + -uVar5;
  pcVar9 = (char *)(iVar7 + 0x74 + DAT_006ab794);
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar3 = __strcmpi(param_3,s_SB16_VXD_005003f8);
  if (iVar3 == 0) {
    FUN_004afce0(s_sb16_driver_found__d_005003e0,iVar2);
    DAT_00500160 = iVar2;
  }
  pcVar4 = _strrchr(param_3,0x2e);
  if (pcVar4 != (char *)0x0) {
    iVar3 = __strcmpi(pcVar4,&DAT_005003d8);
    if (iVar3 == 0) {
      FUN_004afce0(s_secondary_driver_found__d_005003bc,iVar2);
      DAT_00500164 = iVar2;
    }
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar8 = (undefined4 *)(iVar7 + DAT_006ab794);
    *puVar8 = *param_1;
    puVar8[1] = param_1[1];
    puVar8[2] = param_1[2];
    puVar8[3] = param_1[3];
  }
  return 1;
}

