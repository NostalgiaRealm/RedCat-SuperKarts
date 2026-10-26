/*
 * FUN_004aec20 at 004aec20
 * undefined FUN_004aec20(void)
 * Address ranges: 004aec20-004aec6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004aec20(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0xea);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 8) != 0) {
      return *(undefined4 *)(param_1 + 0xf4);
    }
  }
  else if ((*(byte *)(param_1 + 4) & 8) != 0) {
    return *(undefined4 *)(param_1 + 0x28);
  }
  return 0xffffffff;
}

