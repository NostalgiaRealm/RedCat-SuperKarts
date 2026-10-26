/*
 * FUN_004ae5e0 at 004ae5e0
 * undefined FUN_004ae5e0(void)
 * Address ranges: 004ae5e0-004ae660
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ae5e0(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    DAT_006a63de = DAT_006a63ce;
    FUN_004afce0(s_TXF_4BPP_RAMP_selected____d_004fe478,DAT_006a63ce);
    return;
  case 2:
    DAT_006a63de = DAT_006a63d2;
    FUN_004afce0(s_TXF_8BPP_RAMP_selected____d_004fe458,DAT_006a63d2);
    return;
  case 3:
    DAT_006a63de = DAT_006a63da;
    FUN_004afce0(s_TXF_16BPP_RGB_selected____d_004fe438,DAT_006a63da);
    return;
  case 4:
    DAT_006a63de = DAT_006a63d6;
    FUN_004afce0(s_TXF_16BPP_ALPHA_selected____d_004fe418,DAT_006a63d6);
    return;
  default:
    FUN_004afee0(s__s__d____Illegal_texture_format_t_004fe3f0);
    return;
  }
}

