/*
 * FUN_0047ed50 at 0047ed50
 * undefined FUN_0047ed50(void)
 * Address ranges: 0047ed50-0047f12b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0047ed50(int param_1,int param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  char *pcVar10;
  undefined1 local_134 [4];
  char *local_130;
  uint local_12c;
  int local_124;
  undefined4 local_120;
  char local_11c [4];
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d11b5;
  local_c = ExceptionList;
  pcVar3 = *(char **)(param_3 + 4);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = "";
  }
  ExceptionList = &local_c;
  local_124 = param_1;
  iVar4 = __strcmpi(pcVar3,s_background_004f8fe0);
  if (iVar4 == 0) {
    puVar9 = *(undefined1 **)(param_3 + 4);
    if (puVar9 == (undefined1 *)0x0) {
      puVar9 = &DAT_004d2404;
    }
    puVar5 = *(undefined1 **)(param_2 + 4);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_004d2404;
    }
    FUN_004b1f10(puVar5,puVar9,local_10c,0xff);
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar3 = local_10c;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    FUN_0040b540(local_10c,~uVar7 - 1);
    local_4 = 0;
    FUN_0047fce0(local_134);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    puVar9 = *(undefined1 **)(param_1 + 0x38);
    if (puVar9 == (undefined1 *)0x0) {
      puVar9 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____Background_image__s_004f9014,s_D__work_rcsk_Code_game_Requester_004f8fec
                 ,0x17f,puVar9);
  }
  else {
    pcVar3 = *(char **)(param_3 + 4);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "";
    }
    iVar4 = __strcmpi(pcVar3,s_palette_004f9034);
    if (iVar4 == 0) {
      puVar9 = *(undefined1 **)(param_3 + 4);
      if (puVar9 == (undefined1 *)0x0) {
        puVar9 = &DAT_004d2404;
      }
      puVar5 = *(undefined1 **)(param_2 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      FUN_004b1f10(puVar5,puVar9,local_10c,0xff);
      uVar7 = 0xffffffff;
      pcVar3 = local_10c;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      uVar7 = ~uVar7 - 1;
      cVar2 = FUN_0040b600(uVar7,1);
      if (cVar2 != '\0') {
        pcVar3 = local_10c;
        pcVar10 = *(char **)(param_1 + 0x28);
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar10 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar10 = pcVar10 + 1;
        }
        FUN_0040b5e0(uVar7);
      }
      puVar9 = *(undefined1 **)(param_1 + 0x28);
      if (puVar9 == (undefined1 *)0x0) {
        puVar9 = &DAT_004d2404;
      }
      FUN_004afce0(s__s__d____Palette_image__s_004f9064,s_D__work_rcsk_Code_game_Requester_004f903c,
                   0x18d,puVar9);
    }
    else {
      puVar9 = &DAT_004d2404;
      if (*(undefined1 **)(param_3 + 4) != (undefined1 *)0x0) {
        puVar9 = *(undefined1 **)(param_3 + 4);
      }
      puVar5 = *(undefined1 **)(param_2 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      FUN_004b1f10(puVar5,puVar9,local_10c,0xff);
      iVar4 = FUN_004b1f60(local_10c,&DAT_004f9080);
      if (iVar4 < 1) {
        puVar9 = *(undefined1 **)(param_3 + 4);
        if (puVar9 == (undefined1 *)0x0) {
          puVar9 = &DAT_004d2404;
        }
        FUN_004afce0(s__s__d____Not_enough_parameters_f_004f90ac,
                     s_D__work_rcsk_Code_game_Requester_004f9084,0x19a,puVar9);
      }
      else {
        local_120 = FUN_0047df70();
        FUN_004b2110(0,local_10c,0xff);
        iVar6 = __strcmpi(s_IMAGELIST_004f90d8,local_10c);
        if (iVar6 == 0) {
          FUN_0047e740(param_3,iVar4);
        }
        else {
          FUN_0040b4f0(0);
          uVar7 = 0xffffffff;
          pcVar3 = local_10c;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            cVar2 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar2 != '\0');
          uVar7 = ~uVar7 - 1;
          cVar2 = FUN_0040b600(uVar7,1);
          if (cVar2 != '\0') {
            pcVar3 = local_10c;
            pcVar10 = local_130;
            for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined4 *)pcVar10 = *(undefined4 *)pcVar3;
              pcVar3 = pcVar3 + 4;
              pcVar10 = pcVar10 + 4;
            }
            for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar10 = *pcVar3;
              pcVar3 = pcVar3 + 1;
              pcVar10 = pcVar10 + 1;
            }
            local_130[uVar7] = '\0';
            local_12c = uVar7;
          }
          local_4 = 1;
          cVar2 = FUN_0047dfd0(local_134);
          local_4 = 0xffffffff;
          FUN_0040b4f0(1);
          if (cVar2 == '\0') {
            puVar9 = *(undefined1 **)(param_3 + 4);
            if (puVar9 == (undefined1 *)0x0) {
              puVar9 = &DAT_004d2404;
            }
            puVar5 = *(undefined1 **)(param_2 + 4);
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_004d2404;
            }
            FUN_004afee0(s__s__d____Requester__s__item__s_h_004f910c,
                         s_D__work_rcsk_Code_game_Requester_004f90e4,0x1b1,puVar5,puVar9,local_10c);
          }
          else {
            uVar7 = 0xffffffff;
            pcVar3 = local_10c;
            do {
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              cVar1 = *pcVar3;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            local_118 = 0;
            local_114 = 0;
            local_110 = 0;
            local_11c[0] = cVar2;
            FUN_0040b540(local_10c,~uVar7 - 1);
            local_4 = 2;
            FUN_0047ea20(param_3,local_11c,iVar4);
            if (local_118 != 0) {
              cVar2 = *(char *)(local_118 + -1);
              if ((cVar2 == '\0') || (cVar2 == -1)) {
                FUN_004bc150((char *)(local_118 + -1));
              }
              else {
                *(char *)(local_118 + -1) = cVar2 + -1;
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_c;
  return;
}

