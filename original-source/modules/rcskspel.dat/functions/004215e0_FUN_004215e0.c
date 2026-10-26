/*
 * FUN_004215e0 at 004215e0
 * undefined FUN_004215e0(void)
 * Address ranges: 004215e0-004216a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004215e0(void)

{
  DAT_005090dc = 0;
  _strncpy(&DAT_005090e4,s_g_3d_effect_object_004e41c4,0x19);
  _strncpy(&DAT_005090fd,s_________t_3d_effect_object_004e41a8 + 8,0x19);
  if (DAT_005090dc != 0) {
    if (DAT_005090dc == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_005090fd,&DAT_005090e4,
                   DAT_005090d4);
      FUN_004bc150(DAT_005090d0);
    }
    if (DAT_005090dc != 0) {
      FUN_004bc150(DAT_005090e0);
      DAT_005090dc = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_005090d0 = 0;
  DAT_005090d4 = 0;
  _DAT_005090d8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_005090fd,&DAT_005090e4,0);
  DAT_005090e0 = 0;
  DAT_005090dc = 0;
  return;
}

