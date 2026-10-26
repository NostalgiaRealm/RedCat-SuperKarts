/*
 * FUN_004295f0 at 004295f0
 * undefined FUN_004295f0(void)
 * Address ranges: 004295f0-0042992e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004295f0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 local_400 [256];
  undefined1 local_300 [256];
  char local_200 [512];
  
  FUN_004b1d60(s_game_ini_004e8724);
  uVar2 = FUN_004b1ed0(s_HELPDESK_004e86fc,s_DEBUGON_004e8730);
  FUN_00429130(uVar2);
  iVar3 = FUN_00429190();
  FUN_004afcc0(0,iVar3 != 0);
  FUN_004b1d60(s_Race_INI_004e8738);
  uVar2 = FUN_004b1ed0(s_ETAPPE_004e871c,s_ETAPPE_004e8744);
  FUN_004b1d60(param_1);
  uVar4 = FUN_004b1ed0(s_PROGRAM_004e86ec,s_RESOLUTION_004e874c);
  FUN_00428db0(uVar4);
  FUN_004b1f10(s_PROGRAM_004e86ec,&DAT_004e8758,local_400,0x1f);
  FUN_00428e00(local_400);
  uVar4 = FUN_004b1ed0(s_MOUSE_004e8714,&DAT_004e8760);
  FUN_00428f10(uVar4);
  FUN_004b1d60(s_SndGfx_ini_004e8768);
  uVar4 = FUN_004b1ed0(s_PROGRAM_004e86ec,s_FOCUS_004e8774);
  FUN_004291a0(uVar4);
  uVar4 = FUN_004b1ed0(s_SOUND_004e86f4,s_BUFFERS_004e877c);
  FUN_00428fd0(uVar4);
  uVar4 = FUN_004b1ed0(s_SOUND_004e86f4,&DAT_004e8784);
  FUN_00428f80(uVar4);
  uVar4 = FUN_004b1ed0(s_SOUND_004e86f4,s_MUSICVOLUME_004e8788);
  FUN_00429020(uVar4);
  uVar4 = FUN_004b1ed0(s_SOUND_004e86f4,s_SFXVOLUME_004e8794);
  FUN_00429040(uVar4);
  FUN_004b1f10(&PTR_LAB_004e8710,s_RCSFILE_004e87a0,local_400,0xff);
  FUN_00428e50(local_400);
  FUN_004afce0(s__s__d___etapenr__d_004e87cc,s_D__work_rcsk_Code_game_gm_body_c_004e87a8,0x297,uVar2
              );
  FUN_004be8cb(local_300,0xff,s_etappe_d_004e87e0,uVar2);
  FUN_004b1f10(s_PALET_004e8708,local_300,local_200,0x1ff);
  iVar3 = FUN_004b1f60(local_200,0);
  if (iVar3 != 2) {
    FUN_004afee0(s__load_palette_info___s__d____Inv_004e8810,
                 s_D__work_rcsk_Code_game_gm_body_c_004e87ec,0x2a1);
  }
  FUN_004b2110(0,local_400,0xff);
  FUN_004b2110(1,local_300,0xff);
  FUN_00429060(local_400,local_300);
  FUN_004afce0(s_etappe_nummer_for_palet____d___s_004e8854,uVar2,local_400,local_300);
  uVar2 = FUN_004b1ed0(s_PALET_004e8708,&DAT_004e887c);
  FUN_004290c0(uVar2);
  FUN_004b1d60(s_SndGfx_ini_004e8884);
  DAT_004e7bfc = FUN_004b1ed0(s_DIRECTX_004e8898,s_INDEX_004e8890);
  FUN_004b1f10(s_DIRECTX_004e88a8,&DAT_004e88a0,&DAT_004e7c10,199);
  FUN_004b1f10(s_DIRECTX_004e88b8,&DAT_004e88b0,local_200,199);
  iVar3 = -1;
  pcVar5 = local_200;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    FUN_004b1f60(local_200,0);
    _DAT_004e7c00 = FUN_004b20c0(0);
    _DAT_004e7c04 = FUN_004b20c0(1);
    _DAT_004e7c06 = FUN_004b20c0(2);
    DAT_004e7c08 = FUN_004b20c0(3);
    DAT_004e7c09 = FUN_004b20c0(4);
    DAT_004e7c0a = FUN_004b20c0(5);
    DAT_004e7c0b = FUN_004b20c0(6);
    DAT_004e7c0c = FUN_004b20c0(7);
    DAT_004e7c0d = FUN_004b20c0(8);
    DAT_004e7c0e = FUN_004b20c0(9);
    DAT_004e7c0f = FUN_004b20c0(10);
  }
  return;
}

