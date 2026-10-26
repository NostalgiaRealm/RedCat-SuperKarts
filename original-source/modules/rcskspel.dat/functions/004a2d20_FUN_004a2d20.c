/*
 * FUN_004a2d20 at 004a2d20
 * undefined FUN_004a2d20(void)
 * Address ranges: 004a2d20-004a2d85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a2d20(float param_1)

{
  double local_8;
  
  if ((1.0 < param_1) && (param_1 <= 256.0)) {
    _DAT_004fc9d4 = param_1;
    return;
  }
  local_8 = (double)param_1;
  FUN_004afee0(s__s__d____illegal_texture_partion_004fca44,s_D__work_libs_DX3D_text_cpp_004fca28,
               0x4a,local_8);
  _DAT_004fc9d4 = param_1;
  return;
}

