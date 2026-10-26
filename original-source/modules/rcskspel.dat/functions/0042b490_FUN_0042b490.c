/*
 * FUN_0042b490 at 0042b490
 * undefined FUN_0042b490(void)
 * Address ranges: 0042b490-0042b60b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b490(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_10c [12];
  char acStack_100 [256];
  
  FUN_004b1d60(s_SndGfx_INI_004e925c);
  if ((((DAT_0053b9ac != 0) && (DAT_0053b9ac != 1)) && (DAT_0053b9ac != 2)) && (DAT_0053b9ac != 3))
  {
    FUN_004afee0(s__s___d__Unknown_resolution__Reso_004e928c,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e9268,0x1fe,DAT_0053b9ac);
  }
  iVar6 = 0;
  if (0 < DAT_0053a6a0) {
    pcVar7 = (char *)&DAT_0050bd80;
    do {
      FUN_004bea92(local_10c,&DAT_004e92bc,iVar6);
      if (DAT_0053b9ac == 0) {
        pcVar2 = s_wait_lo_004ea19c;
      }
      else if ((DAT_0053b9ac < 1) || (3 < DAT_0053b9ac)) {
        FUN_004afee0(s__s__d____Unsupported_game_info_d_004ea1a4,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004ea1dc,0x1e9,DAT_0053b9ac);
        pcVar2 = (char *)0x0;
      }
      else {
        pcVar2 = s_wait_hi_004ea200;
      }
      FUN_004b1f10(pcVar2,local_10c,acStack_100,199);
      iVar3 = -1;
      pcVar2 = acStack_100;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (iVar3 == -2) {
        FUN_004afee0(s__s___d__No_fname_found_for_PCX__E_004e92e4,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e92c0,0x20f,iVar6,DAT_0053b9ac);
      }
      uVar4 = 0xffffffff;
      pcVar2 = acStack_100;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (0xc < (int)(~uVar4 - 1)) {
        uVar4 = 0xffffffff;
        pcVar2 = acStack_100;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        FUN_004afee0(s__s___d__Filename_too_long_in_ini_004e9344,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e9320,0x214,~uVar4 - 1);
      }
      uVar4 = 0xffffffff;
      pcVar2 = acStack_100;
      do {
        pcVar8 = pcVar2;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar2 = pcVar8 + -uVar4;
      pcVar8 = pcVar7;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar8 = pcVar8 + 1;
      }
      FUN_004afce0(s__s__d____Wait_screen_etappe__s_004e939c,
                   s_D__work_rcsk_Code_game_Gm_ini_cp_004e9378,0x21a,acStack_100);
      iVar6 = iVar6 + 1;
      pcVar7 = pcVar7 + 0xd;
    } while (iVar6 < DAT_0053a6a0);
  }
  return;
}

