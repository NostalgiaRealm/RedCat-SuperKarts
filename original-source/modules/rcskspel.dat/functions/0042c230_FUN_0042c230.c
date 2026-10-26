/*
 * FUN_0042c230 at 0042c230
 * undefined FUN_0042c230(void)
 * Address ranges: 0042c230-0042c31a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c230(void)

{
  char cVar1;
  int iVar2;
  char *_Dest;
  int iVar3;
  char *pcVar4;
  undefined1 local_38 [4];
  char acStack_34 [52];
  
  FUN_004afce0(s_load_music_info_004e9e20);
  FUN_004b1d60(s_SndGfx_INI_004e9e34);
  DAT_0053b7fc = FUN_004b1ed0(s_MUSIC_004e9e48,s_COUNT_004e9e40);
  if ((DAT_0053b7fc < 1) || (0x1e < DAT_0053b7fc)) {
    FUN_004afee0(s__load_music_info___s__d____Inval_004e9e74,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e9e50,0x4b4,DAT_0053b7fc);
  }
  iVar3 = 0;
  if (0 < DAT_0053b7fc) {
    _Dest = &DAT_0053b800;
    do {
      FUN_004bea92(local_38,&DAT_004e9ea8,iVar3);
      FUN_004b1f10(s_MUSIC_004e9eac,local_38,acStack_34,0x31);
      iVar2 = -1;
      pcVar4 = acStack_34;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (iVar2 == -2) {
        FUN_004afee0(s__load_music_info___s__d____No_va_004e9ed8,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e9eb4,0x4c4,iVar3);
      }
      FUN_004bea92(_Dest,s__s_wav_004e9f18,acStack_34);
      _strncpy(_Dest,acStack_34,0xd);
      iVar3 = iVar3 + 1;
      _Dest = _Dest + 0xe;
    } while (iVar3 < DAT_0053b7fc);
  }
  return;
}

