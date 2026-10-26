/*
 * FUN_00449520 at 00449520
 * undefined FUN_00449520(void)
 * Address ranges: 00449520-00449704
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00449520(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int local_14c;
  undefined4 uStack_148;
  char local_140 [64];
  CHAR local_100 [64];
  char acStack_c0 [64];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  FUN_004b1d60(param_1);
  iVar2 = FUN_004b1ed0(s_CONFIG_004efd5c,s_COUNT_004efd54);
  local_14c = 0;
  if (0 < iVar2) {
    do {
      wsprintfA(local_100,&DAT_004efd64,local_14c);
      FUN_004b1f10(s_CONFIG_004efd68,local_100,local_140,0x40);
      iVar3 = -1;
      pcVar6 = local_140;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (iVar3 == -2) {
        FUN_004afee0(s__s___d__Couldn_t_find_animation_n_004efd94,
                     s_D__work_rcsk_Code_game_anm_main__004efd70,0x6b,local_14c,param_1);
      }
      iVar3 = FUN_004b1ed0(local_140,s_COUNT_004efdd8);
      if (iVar3 != 0) {
        uStack_148 = FUN_004a5410(local_140,iVar3);
      }
      iVar5 = 0;
      if (0 < iVar3) {
        do {
          wsprintfA(local_100,&DAT_004efde0,iVar5);
          FUN_004b1f10(local_140,local_100,acStack_c0,0x40);
          iVar4 = -1;
          pcVar6 = acStack_c0;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          if (iVar4 == -2) {
            FUN_004afee0(s__s___d__Couldn_t_find_frame__d_f_004efe08,
                         s_D__work_rcsk_Code_game_anm_main__004efde4,0x7d,iVar5,local_140,param_1);
          }
          iVar4 = FUN_004b1f60(acStack_c0,0);
          if (iVar4 != 2) {
            FUN_004afee0(s__s___d__Illegal_number_of_argume_004efe68,
                         s_D__work_rcsk_Code_game_anm_main__004efe44,0x85,param_1,local_140,iVar5);
          }
          FUN_004b2110(0,auStack_40,0x40);
          FUN_004b2110(1,auStack_80,0x40);
          FUN_004afce0(s_File__s__Animation__s__Adding_fr_004efeb0,param_1,local_140,iVar5,
                       auStack_40,auStack_80);
          FUN_004a5800(uStack_148,auStack_40,auStack_80);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar3);
      }
      local_14c = local_14c + 1;
    } while (local_14c < iVar2);
  }
  return;
}

