/*
 * FUN_004ae8c0 at 004ae8c0
 * undefined FUN_004ae8c0(void)
 * Address ranges: 004ae8c0-004ae8fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004ae8c0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0x48);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 != 0) {
    return *(undefined4 *)(param_1 + 0xb0);
  }
  return *(undefined4 *)(param_1 + 0x17c);
}

