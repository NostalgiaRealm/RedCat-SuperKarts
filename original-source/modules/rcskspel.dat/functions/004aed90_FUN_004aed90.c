/*
 * FUN_004aed90 at 004aed90
 * undefined FUN_004aed90(void)
 * Address ranges: 004aed90-004aede4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_004aed90(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0x12a);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 8) != 0) {
      return *(uint *)(param_1 + 0xec) & 2;
    }
  }
  else if ((*(byte *)(param_1 + 4) & 8) != 0) {
    return *(uint *)(param_1 + 0x20) & 2;
  }
  return 0xffffffff;
}

