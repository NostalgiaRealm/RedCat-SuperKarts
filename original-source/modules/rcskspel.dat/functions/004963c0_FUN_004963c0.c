/*
 * FUN_004963c0 at 004963c0
 * undefined FUN_004963c0(void)
 * Address ranges: 004963c0-0049647f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004963c0(undefined4 *param_1)

{
  char *_Dest;
  char *_Dest_00;
  
  _Dest = (char *)(param_1 + 6);
  param_1[4] = 0;
  _strncpy(_Dest,s_m_chunks_004fb140,0x19);
  _Dest_00 = (char *)((int)param_1 + 0x31);
  _strncpy(_Dest_00,&DAT_004fb13c,0x19);
  if (param_1[4] != 0) {
    if (param_1[4] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,_Dest_00,_Dest,param_1[2]);
      FUN_004bc150(param_1[1]);
    }
    if (param_1[4] != 0) {
      FUN_004bc150(param_1[5]);
      param_1[4] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,_Dest_00,_Dest,0);
  param_1[5] = 0;
  param_1[4] = 0;
  *(undefined4 *)((int)param_1 + 0x4a) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x4e) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x52) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x56) = 0xffffffff;
  *param_1 = 0;
  *(undefined4 *)((int)param_1 + 0x9a) = 0;
  *(undefined4 *)((int)param_1 + 0x9e) = 0;
  *(undefined4 *)((int)param_1 + 0xa2) = 0;
  return param_1;
}

