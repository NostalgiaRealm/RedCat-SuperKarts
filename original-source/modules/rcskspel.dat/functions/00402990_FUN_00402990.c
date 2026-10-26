/*
 * FUN_00402990 at 00402990
 * undefined FUN_00402990(void)
 * Address ranges: 00402990-00402a57
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402990(void)

{
  DAT_00504fec = 0;
  _strncpy(&DAT_00504ff4,s_AI_Behaviors_004dda48,0x19);
  _strncpy(&DAT_0050500d,s_t_ai_behavior_004dda38,0x19);
  if (DAT_00504fec != 0) {
    if (DAT_00504fec == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_0050500d,&DAT_00504ff4,
                   DAT_00504fe4);
      FUN_004bc150(DAT_00504fe0);
    }
    if (DAT_00504fec != 0) {
      FUN_004bc150(DAT_00504ff0);
      DAT_00504fec = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_00504fe0 = 0;
  DAT_00504fe4 = 0;
  _DAT_00504fe8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_0050500d,&DAT_00504ff4,0);
  DAT_00504ff0 = 0;
  DAT_00504fec = 0;
  return;
}

