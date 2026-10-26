/*
 * FUN_004b8e90 at 004b8e90
 * undefined FUN_004b8e90(void)
 * Address ranges: 004b8e90-004b907f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b8e90(undefined4 *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char acStack_40 [64];
  
  iVar2 = FUN_004b8db0();
  if (iVar2 == -1) {
    return 0;
  }
  _strncpy(acStack_40,param_3,0x3f);
  FUN_004bfcb1(acStack_40);
  FUN_004afce0(s__s___s_00500404,param_2,param_3);
  uVar5 = 0xffffffff;
  iVar7 = iVar2 * 0xd8;
  do {
    pcVar3 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar3 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar3;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar3 = pcVar3 + -uVar5;
  pcVar9 = (char *)(DAT_006ab8f4 + 0x10 + iVar7);
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar3 = param_3;
  do {
    pcVar9 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar3 = pcVar9 + -uVar5;
  pcVar9 = (char *)(DAT_006ab8f4 + 0x74 + iVar7);
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar9 = pcVar9 + 1;
  }
  pcVar3 = _strstr(acStack_40,&DAT_005016d0);
  if (pcVar3 != (char *)0x0) {
    FUN_004afce0(s_3dfx_driver_found__d_005016b8,iVar2);
    DAT_00501330 = iVar2;
  }
  iVar4 = FUN_004cc8f0(param_3,s_DD3Dfx_005016b0,6);
  if (iVar4 == 0) {
    FUN_004afce0(s_dd3ddfx_driver_found__d_00501694,iVar2);
    DAT_00501330 = iVar2;
  }
  iVar4 = FUN_004cc8f0(param_3,&DAT_00501690,3);
  if (iVar4 == 0) {
    FUN_004afce0(s_Righteous_dd3ddfx_driver_found___0050166c,iVar2);
    DAT_00501330 = iVar2;
  }
  iVar4 = FUN_004cc8f0(param_3,s_mnstr2_00501664,6);
  if (iVar4 == 0) {
    FUN_004afce0(s_Monster_2_driver_found__d_00501648,iVar2);
    DAT_00501330 = iVar2;
  }
  iVar4 = FUN_004cc8f0(param_3,s_display_00501640,6);
  if (iVar4 != 0) {
    iVar4 = __strcmpi(param_3,&DAT_005003d8);
    if (iVar4 == 0) {
      FUN_004afce0(s_secondary_driver_found__d_005003bc,iVar2);
      DAT_0050132c = iVar2;
    }
  }
  pcVar3 = _strrchr(param_3,0x2e);
  if (pcVar3 != (char *)0x0) {
    iVar4 = __strcmpi(param_3,&DAT_005003d8);
    if (iVar4 == 0) {
      FUN_004afce0(s_secondary_driver_found__d_005003bc,iVar2);
      DAT_0050132c = iVar2;
    }
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar8 = (undefined4 *)(iVar7 + DAT_006ab8f4);
    *puVar8 = *param_1;
    puVar8[1] = param_1[1];
    puVar8[2] = param_1[2];
    puVar8[3] = param_1[3];
  }
  return 1;
}

