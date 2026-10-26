/*
 * _SmackSoundUseMSS@4 at 00405dc0
 * undefined4 __stdcall _SmackSoundUseMSS@4(int param_1)
 * Address ranges: 00405dc0-00406043
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _SmackSoundUseMSS_4(int param_1)

{
  undefined3 uVar1;
  FARPROC pFVar2;
  UINT uMode;
  uint uVar3;
  
                    /* 0x5dc0  33  _SmackSoundUseMSS@4 */
  if (DAT_0040e84c != (code *)0x0) {
LAB_0040603b:
    return param_1 & 0xffffff00;
  }
  DAT_004104ac = param_1;
  uVar1 = 0;
  if (param_1 != 0) {
    if (DAT_0040e85c == (HMODULE)0x0) {
      uMode = SetErrorMode(0x8000);
      DAT_0040e85c = LoadLibraryA(s_WAIL32_DLL_0040e11c);
      param_1 = SetErrorMode(uMode);
    }
    if (DAT_0040e85c < (HMODULE)0x20) {
      DAT_0040e85c = (HMODULE)0x1;
      goto LAB_0040603b;
    }
    DAT_0041048c = GetProcAddress(DAT_0040e85c,s__AIL_minimum_sample_buffer_size__0040e128);
    DAT_004104a8 = GetProcAddress(DAT_0040e85c,s__AIL_allocate_sample_handle_4_0040e14c);
    DAT_004104b0 = GetProcAddress(DAT_0040e85c,s__AIL_init_sample_4_0040e16c);
    DAT_00410494 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_type_12_0040e180);
    DAT_00410484 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_playback_rate_8_0040e198);
    DAT_00410490 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_user_data_12_0040e1b8);
    DAT_00410488 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_volume_8_0040e1d8);
    DAT_004104c4 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_pan_8_0040e1f4);
    DAT_004104c0 = GetProcAddress(DAT_0040e85c,s__AIL_serve_0_0040e20c);
    DAT_004104b4 = GetProcAddress(DAT_0040e85c,s__AIL_sample_buffer_ready_4_0040e21c);
    DAT_004104b8 = GetProcAddress(DAT_0040e85c,s__AIL_load_sample_buffer_16_0040e238);
    DAT_004104a4 = GetProcAddress(DAT_0040e85c,s__AIL_end_sample_4_0040e254);
    DAT_004104bc = GetProcAddress(DAT_0040e85c,s__AIL_release_sample_handle_4_0040e268);
    _DAT_0041049c = GetProcAddress(DAT_0040e85c,s__AIL_sample_status_4_0040e288);
    DAT_004104a0 = GetProcAddress(DAT_0040e85c,s__AIL_sample_buffer_info_20_0040e2a0);
    DAT_00410498 = GetProcAddress(DAT_0040e85c,s__MEM_alloc_lock_4_0040e2bc);
    DAT_00410480 = GetProcAddress(DAT_0040e85c,s__MEM_free_lock_4_0040e2d0);
    DAT_00410478 = &DAT_004062f0;
    DAT_0040e854 = 0;
    uVar1 = 0x4063;
    DAT_0041047c = FUN_004060c0;
    DAT_00410470 = FUN_00406140;
    DAT_0040e850 = FUN_00406140;
    DAT_0040e858 = FUN_00406050;
    DAT_00410474 = FUN_00406330;
  }
  pFVar2 = DAT_004104a0;
  DAT_0040e84c = FUN_00406170;
  if (DAT_004104a0 == (FARPROC)0x0) {
    uVar3 = FreeLibrary(DAT_0040e85c);
    DAT_0040e85c = (HMODULE)pFVar2;
    return uVar3 & 0xffffff00;
  }
  return CONCAT31(uVar1,1);
}

