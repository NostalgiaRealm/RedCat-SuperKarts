/*
 * FUN_00449d70 at 00449d70
 * undefined FUN_00449d70(void)
 * Address ranges: 00449d70-00449f2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00449d70(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char local_c0 [64];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  FUN_004b1d60(param_1);
  iVar2 = FUN_004b1ed0(s_General_004f0388,s_NrAnims_004f0380);
  FUN_00449c80(iVar2);
  iVar7 = 0;
  if (0 < iVar2) {
    do {
      FUN_004bea92(local_80,&DAT_004f0398,&DAT_004f0390,iVar7);
      FUN_004b1f10(local_80,s_AnimNames_004f03a0,local_c0,0x3f);
      iVar5 = -1;
      pcVar9 = local_c0;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      FUN_00492fe0(iVar5 != -2,s__s___d__AnimName_not_found_for_a_004f03d0,
                   s_D__work_rcsk_Code_game_anm_type__004f03ac,0x1a6,iVar7);
      FUN_00449970(local_c0);
      iVar5 = FUN_004b1ed0(local_80,s_NrFrames_004f03fc);
      FUN_00449b80(iVar5);
      iVar8 = 0;
      if (0 < iVar5) {
        do {
          FUN_004bea92(local_40,&DAT_004f0410,s_Frame_004f0408,iVar8);
          FUN_004b1f10(local_80,local_40,local_c0,0x3f);
          iVar6 = -1;
          pcVar9 = local_c0;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          FUN_00492fe0(iVar6 != -2,s__s___d__Value_not_found_for_anim_004f043c,
                       s_D__work_rcsk_Code_game_anm_type__004f0418,0x1b5,iVar7,iVar8);
          iVar6 = FUN_004b1f60(local_c0,0);
          FUN_00492fe0(iVar6 == 2,s__s___d__Incorrect_number_of_argu_004f0470,0x1ba,iVar7,iVar8);
          uVar3 = FUN_004b20c0(0);
          uVar4 = FUN_004b20c0(1);
          FUN_00449ae0(iVar8,uVar3,uVar4);
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar5);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  return;
}

