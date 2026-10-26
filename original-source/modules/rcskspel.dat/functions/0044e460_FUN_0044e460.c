/*
 * FUN_0044e460 at 0044e460
 * undefined FUN_0044e460(void)
 * Address ranges: 0044e460-0044e830
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044e5f7) */
/* WARNING: Removing unreachable block (ram,0x0044e78b) */
/* WARNING: Removing unreachable block (ram,0x0044e7a6) */
/* WARNING: Removing unreachable block (ram,0x0044e7b5) */
/* WARNING: Removing unreachable block (ram,0x0044e7bc) */

void __thiscall FUN_0044e460(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int *piVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  int iStack_110;
  int local_10c;
  int iStack_108;
  int *local_104;
  char local_100 [256];
  
  local_104 = param_1;
  FUN_00412870(param_3,0,0xffffffff);
  FUN_00412870(param_4,0,0xffffffff);
  param_1[6] = 0;
  puVar4 = *(undefined1 **)(param_3 + 4);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_004d2404;
  }
  puVar9 = *(undefined1 **)(param_2 + 4);
  if (puVar9 == (undefined1 *)0x0) {
    puVar9 = &DAT_004d2404;
  }
  FUN_004b1f10(puVar9,puVar4,local_100,0x100);
  FUN_004b1f60(local_100,&DAT_004f0a34);
  FUN_004afce0(local_100);
  FUN_004b2110(0,local_100,0x100);
  uVar10 = 0xffffffff;
  pcVar13 = local_100;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar3 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar3 != '\0');
  uVar10 = ~uVar10 - 1;
  cVar3 = FUN_0040b600(uVar10,1);
  if (cVar3 != '\0') {
    pcVar13 = local_100;
    pcVar14 = (char *)param_1[0xd];
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar14 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar14 = pcVar14 + 4;
    }
    for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pcVar14 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar14 = pcVar14 + 1;
    }
    param_1[0xe] = uVar10;
    *(undefined1 *)(param_1[0xd] + uVar10) = 0;
  }
  iVar5 = FUN_004b20c0(1);
  *param_1 = iVar5;
  iVar5 = FUN_004b20c0(2);
  param_1[1] = iVar5;
  iVar5 = FUN_004b20c0(3);
  param_1[2] = iVar5;
  iVar5 = FUN_004b20c0(4);
  param_1[3] = iVar5;
  puVar4 = *(undefined1 **)(param_3 + 4);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_004d2404;
  }
  puVar9 = *(undefined1 **)(param_2 + 4);
  if (puVar9 == (undefined1 *)0x0) {
    puVar9 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__s__d__d__d__d_004f0a38,puVar9,puVar4,*param_1,param_1[1],param_1[2],iVar5);
  iVar5 = *param_1;
  bVar2 = param_1[1] <= iVar5;
  uVar10 = iVar5 - param_1[1];
  uVar11 = (int)uVar10 >> 0x1f;
  local_10c = iVar5;
  if ((uVar10 ^ uVar11) - uVar11 == -1) {
    puVar4 = (undefined1 *)param_1[9];
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    FUN_004afee0(s_No_frames_for_animation__s_defin_004f0a4c,puVar4);
  }
  iStack_108 = param_1[0x16];
  param_1[0x16] = param_1[0x15];
  piVar12 = param_1;
  do {
    while( true ) {
      puVar4 = (undefined1 *)piVar12[0xd];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      FUN_004be8cb(local_100,0x100,s__s_04d_d3d_004f0a70,puVar4,iVar5);
      iStack_110 = FUN_004a74b0(local_100);
      if ((iStack_110 < 0) && (iStack_110 = FUN_004a7680(2,local_100), iStack_110 < 0)) {
        FUN_004afee0(s__s__d____FILE__s_004f0aa4,s_D__work_rcsk_Code_game_msh_MshAn_004f0a7c,0x68,
                     local_100);
      }
      piVar8 = (int *)param_1[0x16];
      if (param_1[0x17] - (int)piVar8 >> 2 == 0) {
        if ((param_1[0x15] == 0) || (uVar10 = (int)piVar8 - param_1[0x15] >> 2, uVar10 < 2)) {
          uVar10 = 1;
        }
        iVar6 = FUN_0044ca80();
        iVar6 = iVar6 + uVar10;
        iVar5 = iVar6;
        if (iVar6 < 0) {
          iVar5 = 0;
        }
        pvVar7 = operator_new(iVar5 * 4);
        iStack_108 = FUN_00476950(param_1[0x15],piVar8,pvVar7);
        FUN_0044ec00(iStack_108,1,&iStack_110);
        FUN_00476950(piVar8,param_1[0x16],iStack_108 + 4);
        FUN_0048b600(param_1[0x15],param_1[0x16]);
        FUN_004bc150(param_1[0x15]);
        param_1[0x17] = (int)((int)pvVar7 + iVar6 * 4);
        iVar5 = FUN_0044ca80();
        param_1[0x15] = (int)pvVar7;
        param_1[0x16] = (int)pvVar7 + iVar5 * 4 + 4;
        piVar12 = local_104;
        iVar5 = local_10c;
      }
      else {
        FUN_00476950(piVar8,piVar8,piVar8 + 1);
        FUN_0044ec00(param_1[0x16],1 - (param_1[0x16] - (int)piVar8 >> 2),&iStack_110);
        piVar1 = (int *)param_1[0x16];
        for (; piVar8 != piVar1; piVar8 = piVar8 + 1) {
          *piVar8 = iStack_110;
        }
        param_1[0x16] = param_1[0x16] + 4;
      }
      FUN_004afce0(s_frame__d__d__004f0ab8,iVar5,iStack_110);
      if (bVar2) break;
      iVar5 = iVar5 + 1;
      local_10c = iVar5;
      if (piVar12[1] < iVar5) goto LAB_0044e809;
    }
    iVar5 = iVar5 + -1;
    local_10c = iVar5;
  } while (piVar12[1] <= iVar5);
LAB_0044e809:
  *(undefined1 *)(piVar12 + 7) = 1;
  FUN_004afce0(s___s_animation_loaded_at_line__d_004f0af0,
               s_D__work_rcsk_Code_game_msh_MshAn_004f0ac8,0x87);
  return;
}

