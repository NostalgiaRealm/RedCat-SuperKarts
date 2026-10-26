/*
 * FUN_00443b70 at 00443b70
 * undefined FUN_00443b70(void)
 * Address ranges: 00443b70-00443ce9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00443b70(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  CHAR aCStack_154 [20];
  char local_140 [64];
  char acStack_100 [256];
  
  FUN_004b1d60(s_LANGUAGE_INI_004eed4c);
  _DAT_0053d4e4 = FUN_004b1ed0(s_SETTINGS_004eed68,s_language_004eed5c);
  if (_DAT_0053d4e4 == 0) {
    pcVar7 = s_NEDERLANDS_004eed74;
  }
  else if (_DAT_0053d4e4 == 1) {
    pcVar7 = s_ENGELS_004eed80;
  }
  else {
    if (_DAT_0053d4e4 != 2) {
      FUN_004afee0(s__s___d__Illegal_language_set_in_l_004eedb4,
                   s_D__work_rcsk_Code_game_lan_main__004eed90,0x51,_DAT_0053d4e4);
      goto LAB_00443bfb;
    }
    pcVar7 = s_DUITS_004eed88;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar8 + -uVar4;
  pcVar8 = local_140;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
LAB_00443bfb:
  iVar2 = FUN_004b1ed0(s_SETTINGS_004eee00,s_text_count_004eedf4);
  if ((iVar2 < 0) || (0x20 < iVar2)) {
    FUN_004afee0(s__s___d__Illegal_value_for_nr__of_004eee30,
                 s_D__work_rcsk_Code_game_lan_main__004eee0c,0x5a,iVar2);
  }
  iVar6 = 0;
  DAT_0053d4e8 = iVar2;
  if (0 < iVar2) {
    do {
      wsprintfA(aCStack_154,&DAT_004eee68,iVar6);
      FUN_004b1f10(local_140,aCStack_154,acStack_100,0xff);
      iVar3 = -1;
      pcVar7 = acStack_100;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (iVar3 == -2) {
        FUN_004afee0(s__s___d__Couldn_t_find_text_for_i_004eee90,
                     s_D__work_rcsk_Code_game_lan_main__004eee6c,0x6a,iVar6,local_140);
      }
      iVar3 = FUN_00443b40(iVar6);
      uVar4 = 0xffffffff;
      pcVar7 = acStack_100;
      do {
        pcVar8 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar8 + -uVar4;
      pcVar8 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      iVar6 = iVar6 + 1;
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
    } while (iVar6 < iVar2);
  }
  _DAT_0053d4e0 = 1;
  return;
}

