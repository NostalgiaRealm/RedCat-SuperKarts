/*
 * FUN_004ab7b0 at 004ab7b0
 * undefined FUN_004ab7b0(void)
 * Address ranges: 004ab7b0-004ab877
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ab7b0(void)

{
  DAT_006a629c = 0;
  _strncpy(&DAT_006a62a4,s_material_ptr_004fda10,0x19);
  _strncpy(&DAT_006a62bd,s_material_t_004fda04,0x19);
  if (DAT_006a629c != 0) {
    if (DAT_006a629c == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a62bd,&DAT_006a62a4,
                   DAT_006a6294);
      FUN_004bc150(DAT_006a6290);
    }
    if (DAT_006a629c != 0) {
      FUN_004bc150(DAT_006a62a0);
      DAT_006a629c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a6290 = 0;
  DAT_006a6294 = 0;
  DAT_006a6298 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a62bd,&DAT_006a62a4,0);
  DAT_006a62a0 = 0;
  DAT_006a629c = 0;
  return;
}

