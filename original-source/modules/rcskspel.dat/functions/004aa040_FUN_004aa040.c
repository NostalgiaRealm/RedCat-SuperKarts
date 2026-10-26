/*
 * FUN_004aa040 at 004aa040
 * undefined FUN_004aa040(void)
 * Address ranges: 004aa040-004aa090
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004aa040(int *param_1)

{
  if (*param_1 == 0) {
    FUN_004afee0(s__s__d____error_unknown_mesh_type_004fd1cc,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x368);
  }
  if (*param_1 == 1) {
    FUN_004aa0c0(param_1[0x1e],param_1[0x1f]);
  }
  else if (*param_1 == 2) {
    FUN_004aa0c0(param_1[0x20],param_1[0x21]);
    return;
  }
  return;
}

