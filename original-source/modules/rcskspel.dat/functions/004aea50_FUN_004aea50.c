/*
 * FUN_004aea50 at 004aea50
 * undefined FUN_004aea50(void)
 * Address ranges: 004aea50-004aeaae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_004aea50(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0x9f);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 1) != 0) {
      return (uint)(*(int *)(param_1 + 0xd4) == 2);
    }
  }
  else if ((*(byte *)(param_1 + 4) & 1) != 0) {
    return (uint)(*(int *)(param_1 + 8) == 2);
  }
  return 0xffffffff;
}

