/*
 * FUN_0041485e at 0041485e
 * undefined4 __cdecl FUN_0041485e(int param_1, LPCSTR param_2)
 * Address ranges: 0041485e-00414a85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041485e(int param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  char local_398 [768];
  FILE *local_98;
  int local_94;
  int local_90;
  char local_8c [4];
  char local_88 [8];
  short local_80;
  short local_7e;
  short local_7c;
  undefined1 local_48;
  undefined1 local_47;
  short local_46;
  int local_8;
  
  local_8c[0] = '\f';
  if (DAT_0042c358 != 8) {
    FUN_0040187a((byte *)s__s__d____save_pcx_file____s___bi_00435154);
  }
  builtin_strncpy(local_88,"\n\x05\x01\b",5);
  local_7c = (short)DAT_0042c354;
  local_48 = 0;
  local_47 = 1;
  local_46 = (short)DAT_0042c350;
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_80 = (short)DAT_0042c350 + -1;
  local_7e = (short)DAT_0042c354 + -1;
  local_98 = (FILE *)FUN_0041f4c6(param_2,&DAT_004351a4);
  if (local_98 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_0041fe82(local_88,0x80,1,(int *)local_98);
    local_8 = FUN_00402531(param_1,&local_94);
    if (local_8 == 0) {
      FUN_0041f368(local_98);
      FUN_0040187a((byte *)s__s__d____Unable_to_lock_focus_fo_004351a8);
    }
    FUN_004147d7((int *)local_98,local_8,DAT_0042c350,DAT_0042c354,local_94);
    FUN_00402727(param_1,local_8);
    for (local_90 = 0; local_90 < 0x100; local_90 = local_90 + 1) {
      local_398[local_90 * 3] = *(char *)(DAT_0043d760 + local_90 * 4);
      local_398[local_90 * 3 + 1] = *(char *)(DAT_0043d760 + 1 + local_90 * 4);
      local_398[local_90 * 3 + 2] = *(char *)(DAT_0043d760 + 2 + local_90 * 4);
    }
    FUN_0041fe82(local_8c,1,1,(int *)local_98);
    FUN_0041fe82(local_398,1,0x300,(int *)local_98);
    FUN_0041f368(local_98);
    uVar1 = 0;
  }
  return uVar1;
}

