/*
 * _SmackSoundUseDirectSound@4 at 00406640
 * undefined1 * __stdcall _SmackSoundUseDirectSound@4(uint param_1)
 * Address ranges: 00406640-0040670a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * _SmackSoundUseDirectSound_4(uint param_1)

{
  UINT uMode;
  uint uVar1;
  
                    /* 0x6640  36  _SmackSoundUseDirectSound@4 */
  DAT_0040e87c = param_1;
  uVar1 = param_1 & 0xffff0000;
  DAT_0040e880 = 0;
  if (DAT_0040e84c == (code *)0x0) {
    uMode = SetErrorMode(0x8000);
    DAT_0040e888 = LoadLibraryA(s_DSOUND_DLL_0040e2e4);
    uVar1 = SetErrorMode(uMode);
    if ((HMODULE)0x1f < DAT_0040e888) {
      DAT_004104d0 = GetProcAddress(DAT_0040e888,s_DirectSoundCreate_0040e2f0);
      DAT_0040e84c = FUN_004069b0;
      DAT_0040e850 = FUN_004067a0;
      DAT_0040e854 = FUN_00406790;
      DAT_0040e858 = FUN_00406710;
      DAT_00410470 = FUN_00406810;
      DAT_00410474 = &DAT_00406840;
      DAT_00410478 = FUN_00406960;
      DAT_0041047c = FUN_004067b0;
      return &LAB_00406901;
    }
  }
  return (undefined1 *)(uVar1 & 0xffffff00);
}

