/*
 * FUN_004ae940 at 004ae940
 * undefined FUN_004ae940(void)
 * Address ranges: 004ae940-004ae995
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_004ae940(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0x5f);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 2) != 0) {
      return *(uint *)(param_1 + 0xd8) & 0x100;
    }
  }
  else if ((*(byte *)(param_1 + 4) & 2) != 0) {
    return *(uint *)(param_1 + 0xc) & 0x100;
  }
  return 0xffffffff;
}

