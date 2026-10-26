/*
 * FUN_0049e490 at 0049e490
 * undefined FUN_0049e490(void)
 * Address ranges: 0049e490-0049e601
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049e490(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  int local_118;
  CHAR local_10c [12];
  char local_100 [256];
  
  *(undefined4 *)(param_1 + 0x220) = 0;
  iVar2 = FUN_004b1ed0(s_SndGroups_004fc3b0,s_count_004fba1c);
  FUN_0049f250(iVar2,0,0x1f,s_D__work_rcracer_oursoundlib_soun_004fc23c,0x140);
  local_118 = 0;
  if (0 < iVar2) {
    piVar6 = (int *)(param_1 + 0x24);
    do {
      wsprintfA(local_10c,&DAT_004fb9fc,local_118);
      FUN_004b1f10(s_SndGroups_004fc3b0,local_10c,local_100,0xff);
      iVar3 = -1;
      pcVar7 = local_100;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0049f2a0(iVar3 != -2,s__s__d__Can_t_find_sound_type__d_004fc390,
                   s_D__work_rcracer_oursoundlib_soun_004fc23c,0x149,local_118);
      uVar4 = 0xffffffff;
      pcVar7 = local_100;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4 - 1;
      if (0xfffffffd < uVar4) {
        FUN_004bc15b();
      }
      iVar3 = *piVar6;
      if (((iVar3 == 0) || (cVar1 = *(char *)(iVar3 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
        if (uVar4 != 0) {
          if ((0x1f < (uint)piVar6[2]) || ((uint)piVar6[2] < uVar4)) {
            FUN_0040b4f0(1);
            goto LAB_0049e5aa;
          }
          goto LAB_0049e5af;
        }
        FUN_0040b4f0(1);
      }
      else if (uVar4 == 0) {
        *(char *)(iVar3 + -1) = cVar1 + -1;
        *piVar6 = 0;
        piVar6[1] = 0;
        piVar6[2] = 0;
      }
      else {
LAB_0049e5aa:
        FUN_0040b720(uVar4);
LAB_0049e5af:
        pcVar7 = local_100;
        pcVar8 = (char *)*piVar6;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar8 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        }
        piVar6[1] = uVar4;
        *(undefined1 *)(*piVar6 + uVar4) = 0;
      }
      piVar6 = piVar6 + 4;
      local_118 = local_118 + 1;
      *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + 1;
    } while (local_118 < iVar2);
  }
  return;
}

