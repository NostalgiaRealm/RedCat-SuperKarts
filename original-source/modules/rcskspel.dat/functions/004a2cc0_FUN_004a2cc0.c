/*
 * FUN_004a2cc0 at 004a2cc0
 * undefined FUN_004a2cc0(void)
 * Address ranges: 004a2cc0-004a2cf9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2cc0(int param_1)

{
  if (param_1 == 0) {
    DAT_006a5edc = 0;
    return;
  }
  if (param_1 != 1) {
    FUN_004afee0(s__s__d____Unknown_texture_source_t_004fc9fc,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x35,param_1);
    return;
  }
  DAT_006a5edc = 1;
  return;
}

