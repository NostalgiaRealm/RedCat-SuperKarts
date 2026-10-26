/*
 * FUN_004aec70 at 004aec70
 * undefined FUN_004aec70(void)
 * Address ranges: 004aec70-004aecc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_004aec70(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0xfa);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 8) != 0) {
      return *(uint *)(param_1 + 0xec) & 4;
    }
  }
  else if ((*(byte *)(param_1 + 4) & 8) != 0) {
    return *(uint *)(param_1 + 0x20) & 4;
  }
  return 0xffffffff;
}

