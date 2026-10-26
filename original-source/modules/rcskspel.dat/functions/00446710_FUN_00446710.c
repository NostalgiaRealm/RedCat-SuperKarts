/*
 * FUN_00446710 at 00446710
 * undefined FUN_00446710(void)
 * Address ranges: 00446710-00446b07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446710(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  undefined1 local_b8 [4];
  char *local_b4;
  int local_a8;
  char local_a4 [20];
  undefined1 local_90 [8];
  undefined1 local_88 [4];
  int local_84;
  undefined **appuStack_5c [7];
  char local_40 [52];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd70e;
  local_c = ExceptionList;
  uVar10 = 0;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  puVar3 = *(undefined1 **)(param_1 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar3);
  puVar3 = *(undefined1 **)(param_3 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b1f10(s_PATH_OBJECTS_004ef654,puVar3,local_40,0x32);
  iVar6 = -1;
  pcVar5 = local_40;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  if (iVar6 == -2) {
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
  }
  else {
    iVar6 = FUN_004b1f60(local_40,&DAT_004ef950);
    if (iVar6 == 1) {
      uVar7 = 0xffffffff;
      pcVar5 = local_40;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      uVar7 = ~uVar7 - 1;
      cVar2 = FUN_0040b600(uVar7,1);
      if (cVar2 != '\0') {
        pcVar5 = local_40;
        pcVar11 = local_b4;
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar11 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar11 = pcVar11 + 1;
        }
        FUN_0040b5e0(uVar7);
      }
    }
    else {
      uVar4 = FUN_004312a0(local_a4,0);
      local_4._0_1_ = 1;
      FUN_00412870(uVar4,0,0xffffffff);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0040b4f0(1);
      uVar10 = FUN_004b20c0(1);
    }
    pcVar5 = local_b4;
    if (local_b4 == (char *)0x0) {
      pcVar5 = "";
    }
    FUN_004afce0(s__s__d____Current_mesh_name__s_004ef984,
                 s_D__work_rcsk_Code_game_pth_PathC_004ef954,0x1ed,pcVar5);
    puVar3 = *(undefined1 **)(param_2 + 4);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004b1d60(puVar3);
    iVar6 = FUN_004b1ed0(s_pathtypes_004ef640,s_COUNT_004ef64c);
    puVar3 = *(undefined1 **)(param_2 + 4);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____Trying_to_find_object_n_004ef9d4,
                 s_D__work_rcsk_Code_game_pth_PathC_004ef9a4,0x1f7,puVar3);
    uVar7 = 0;
    if (0 < iVar6) {
      do {
        FUN_004be8cb(local_90,5,&DAT_004efa00,uVar7);
        FUN_004b1f10(s_pathtypes_004ef640,local_90,local_a4,0x14);
        iVar9 = -1;
        pcVar5 = local_a4;
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        if (iVar9 != -2) {
          pcVar5 = *(char **)(param_3 + 4);
          if (pcVar5 == (char *)0x0) {
            pcVar5 = "";
          }
          iVar9 = __strcmpi(local_a4,pcVar5);
          if (iVar9 == 0) {
            if ((int)uVar7 < iVar6) {
              pcVar5 = local_b4;
              if (local_b4 == (char *)0x0) {
                pcVar5 = "";
              }
              puVar3 = *(undefined1 **)(param_3 + 4);
              if (puVar3 == (undefined1 *)0x0) {
                puVar3 = &DAT_004d2404;
              }
              FUN_004afce0(s__s__d____Adding__s___s___d_004efa34,
                           s_D__work_rcsk_Code_game_pth_PathC_004efa04,0x216,puVar3,pcVar5,uVar7);
              if ((0x7f < uVar7) &&
                 (FUN_004afee0(s__s__d____Enlarge_MAX_DYNAMIC_PAT_004efa80,
                               s_D__work_rcsk_Code_game_pth_PathC_004efa50,0x220), 0x7f < uVar7)) {
                FUN_0040b4f0(0);
                uVar10 = 0xffffffff;
                pcVar5 = s_invalid_bitset<N>_position_004efd00;
                goto code_r0x004469e8;
              }
              puVar1 = (uint *)(local_a8 + 0xc + (uVar7 >> 5) * 4);
              *puVar1 = *puVar1 | 1 << ((byte)uVar7 & 0x1f);
              FUN_00445c70(param_3,local_b8,uVar7);
              local_4._0_1_ = 3;
              FUN_00445dc0(CONCAT31((uint3)(uVar10 >> 9),(char)(uVar10 >> 1)) & 0xffffff01);
              FUN_00445dd0(uVar10 & 0xffffff01);
              FUN_00447a90(*(undefined4 *)(*(int *)(local_a8 + 4) + 8),1,local_88);
              local_4 = (uint)local_4._1_3_ << 8;
              FUN_0040b4f0(1);
              if (local_84 != 0) {
                cVar2 = *(char *)(local_84 + -1);
                if ((cVar2 == '\0') || (cVar2 == -1)) {
                  FUN_004bc150(local_84 + -1);
                }
                else {
                  *(char *)(local_84 + -1) = cVar2 + -1;
                }
              }
            }
            break;
          }
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < iVar6);
    }
    if (local_b4 != (char *)0x0) {
      cVar2 = local_b4[-1];
      if ((cVar2 == '\0') || (cVar2 == -1)) {
        FUN_004bc150(local_b4 + -1);
      }
      else {
        local_b4[-1] = cVar2 + -1;
      }
    }
  }
  ExceptionList = local_c;
  return;
  while( true ) {
    uVar10 = uVar10 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    if (cVar2 == '\0') break;
code_r0x004469e8:
    if (uVar10 == 0) break;
  }
  FUN_0040b540(s_invalid_bitset<N>_position_004efd00,~uVar10 - 1);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004472d0(local_a4);
  appuStack_5c[0] = &PTR_FUN_004d3504;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(appuStack_5c,&DAT_004d58b8);
}

