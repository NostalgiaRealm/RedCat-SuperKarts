/*
 * FUN_004071b3 at 004071b3
 * undefined4 __cdecl FUN_004071b3(int param_1, int param_2, int param_3)
 * Address ranges: 004071b3-004075e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004071b3(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_c;
  
  FUN_00405e1d();
  if (DAT_0043d43c != 0) {
    return 0;
  }
  if (DAT_0043d440 == 0) {
    if (DAT_0042ef70 == -1) {
      if (DAT_0042ef74 == -1) {
        FUN_004015a6((byte *)s_Using_default_driver_0042fb60);
        iVar1 = Ordinal_1(0,&DAT_0043d410,0);
        if (iVar1 != 0) {
          FUN_00405af0(iVar1);
          FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042fb84);
          return 0x2af9;
        }
        DAT_0043d440 = 1;
        FUN_004015a6((byte *)s_Default_driver_init_failure___No_0042fbb0);
      }
      else {
        FUN_004015a6((byte *)s_Attempting_to_use_secondary_driv_0042facc);
        iVar1 = Ordinal_1(DAT_0043d41c + DAT_0042ef74 * 0xd8,&DAT_0043d410,0);
        if (iVar1 != 0) {
          FUN_00405af0(iVar1);
          FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042fafc);
          return 0x2af9;
        }
        DAT_0043d440 = 1;
        FUN_004015a6((byte *)s_Attempting_to_use_secondary__unk_0042fb28);
      }
    }
    else {
      FUN_004015a6((byte *)s_Attempting_to_use_sb16_driver_0042fa48);
      iVar1 = Ordinal_1(DAT_0043d41c + DAT_0042ef70 * 0xd8,&DAT_0043d410,0);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_004015a6((byte *)s__s__d____error_creating_sound_ob_0042fa74);
        return 0x2af9;
      }
      DAT_0043d440 = 1;
      FUN_004015a6((byte *)s_Attempting_to_use_sb16_driver_su_0042faa0);
    }
  }
  if (DAT_0043d444 == 0) {
    iVar1 = (**(code **)(*DAT_0043d410 + 0x18))(DAT_0043d410,DAT_0043842c,3);
    if ((iVar1 != 0) != 0) {
      FUN_00405af0((uint)(iVar1 != 0));
      FUN_004015a6((byte *)s__s__d____error_setting_the_coop_l_0042fbe4);
      return 0x2af9;
    }
    DAT_0043d444 = 1;
  }
  if (DAT_0043d448 == 0) {
    DAT_0043d414 = param_1 + param_2;
    DAT_0043d420 = LocalAlloc(0x40,DAT_0043d414 * 0x44);
    if (DAT_0043d420 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____not_enough_memory_to_cr_0042fc20);
    }
    DAT_0043d448 = 1;
  }
  FUN_004015a6((byte *)s_sound_init_0042fc58);
  for (local_c = 0; local_c < DAT_0043d414; local_c = local_c + 1) {
    if (local_c < param_2) {
      *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x34) = 1;
    }
    else {
      *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x34) = 0;
    }
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x30) = 0;
    *(undefined4 *)((int)DAT_0043d420 + local_c * 0x44 + 0x38) = 0;
  }
  if ((param_3 < 0) || (0xd < param_3)) {
    FUN_0040187a((byte *)s__s__d____error_illegal_sound_mod_0042fc64);
  }
  if ((param_3 != 0xe) &&
     (FUN_004015a6((byte *)s_setting_3d_output_format_0042fc94), DAT_0043d44c == 0)) {
    iVar1 = FUN_00405fa9(*(int *)(&DAT_0042ee90 + param_3 * 0x10),
                         (short)*(undefined4 *)(&DAT_0042ee94 + param_3 * 0x10),
                         *(int *)(&DAT_0042ee9c + param_3 * 0x10),
                         *(int *)(&DAT_0042ee98 + param_3 * 0x10));
    if (iVar1 != 0) {
      return 0x2afa;
    }
    FUN_004015a6((byte *)s_setting_sound_format__dHz__dbits_0042fcc0);
    DAT_0043d44c = 1;
  }
  FUN_004015a6((byte *)s_query_interface_0042fce8);
  iVar1 = (**(code **)*DAT_0043d418)(DAT_0043d418,&DAT_004298b0,&DAT_0043d408);
  if (iVar1 != 0) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_query_interfa_0042fd08);
  }
  FUN_004015a6((byte *)s_done_0042fd44);
  DAT_0043d43c = 1;
  return 0;
}

