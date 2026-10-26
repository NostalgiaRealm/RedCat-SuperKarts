/*
 * FUN_0043b450 at 0043b450
 * undefined FUN_0043b450(void)
 * Address ranges: 0043b450-0043b556
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043b450(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  
  FUN_0049e240(1000,1000,0x3c);
  FUN_0049e940(s_SOUND_INI_004ec1f8);
  iVar2 = DAT_0053bf90;
  DAT_0053c1ec = DAT_0053bf90;
  if (DAT_0053bf90 != 0) {
    DAT_0053c1f0 = operator_new(DAT_0053bf90 * 0x44);
    if (DAT_0053c1f0 == (void *)0x0) {
      FUN_004afee0(s__s___d__Couldn_t_allocate_static_004ec228,
                   s_D__work_rcsk_Code_game_snd_main__004ec204,0x41,iVar2);
    }
    iVar7 = 0;
    if (0 < iVar2) {
      iVar8 = 0;
      do {
        iVar3 = FUN_0049ec00(iVar7);
        if (0x3f < *(uint *)(iVar3 + 0x30)) {
          FUN_004afee0(s__s___d__Sound_type_name_too_long_004ec29c,
                       s_D__work_rcsk_Code_game_snd_main__004ec278,0x4c,iVar7);
        }
        pcVar9 = "";
        if (*(char **)(iVar3 + 0x2c) != (char *)0x0) {
          pcVar9 = *(char **)(iVar3 + 0x2c);
        }
        uVar5 = 0xffffffff;
        do {
          pcVar10 = pcVar9;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar10 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar10;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar9 = pcVar10 + -uVar5;
        pcVar10 = (char *)((int)DAT_0053c1f0 + iVar8);
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar10 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar10 = pcVar10 + 1;
        }
        uVar4 = FUN_0049dec0(iVar7);
        iVar7 = iVar7 + 1;
        *(undefined4 *)((int)DAT_0053c1f0 + iVar8 + 0x40) = uVar4;
        iVar8 = iVar8 + 0x44;
      } while (iVar7 < iVar2);
    }
  }
  FUN_00437d50();
  return;
}

