/*
 * FUN_00402ae0 at 00402ae0
 * undefined FUN_00402ae0(void)
 * Address ranges: 00402ae0-00402ba7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402ae0(void)

{
  DAT_00504fa4 = 0;
  _strncpy(&DAT_00504fac,s_AI_States_004dda64,0x19);
  _strncpy(&DAT_00504fc5,s_t_ai_state_004dda58,0x19);
  if (DAT_00504fa4 != 0) {
    if (DAT_00504fa4 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00504fc5,&DAT_00504fac,
                   DAT_00504f9c);
      FUN_004bc150(DAT_00504f98);
    }
    if (DAT_00504fa4 != 0) {
      FUN_004bc150(DAT_00504fa8);
      DAT_00504fa4 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_00504f98 = 0;
  DAT_00504f9c = 0;
  DAT_00504fa0 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_00504fc5,&DAT_00504fac,0);
  DAT_00504fa8 = 0;
  DAT_00504fa4 = 0;
  return;
}

