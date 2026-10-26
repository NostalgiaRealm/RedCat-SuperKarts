/*
 * FUN_00420730 at 00420730
 * undefined FUN_00420730(void)
 * Address ranges: 00420730-0042083f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420730(void)

{
  float *pfVar1;
  undefined1 auStack_c [12];
  
  FUN_0041e280(1);
  FUN_004205f0();
  switch(DAT_004e3b10) {
  case 0:
  case 2:
    break;
  case 1:
    FUN_00430610(7);
    break;
  case 0xffffffff:
    FUN_004afee0(s__s___d__No_game_over_mode_set__004e3b3c,
                 s_D__work_rcsk_Code_game_ev_g_ovr__004e3b18,0xb6);
    break;
  default:
    FUN_004afee0(s__s___d__Illegal_game_over_mode_s_004e3b80,
                 s_D__work_rcsk_Code_game_ev_g_ovr__004e3b5c,0xc6,DAT_004e3b10);
  }
  FUN_0048f4e0();
  _DAT_00508ae0 = __ftol();
  _DAT_00508ae8 = 0;
  pfVar1 = (float *)FUN_00498a80(auStack_c);
  _DAT_00508af4 = *pfVar1;
  DAT_00508af8 = pfVar1[1];
  _DAT_00508afc = pfVar1[2];
  DAT_00508aec = 0xfffffc00;
  _DAT_00508ae4 = SQRT(_DAT_00508af4 * _DAT_00508af4 + _DAT_00508afc * _DAT_00508afc);
  DAT_00508af0 = __ftol();
  return;
}

