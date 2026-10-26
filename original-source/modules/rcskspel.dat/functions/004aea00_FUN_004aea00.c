/*
 * FUN_004aea00 at 004aea00
 * undefined FUN_004aea00(void)
 * Address ranges: 004aea00-004aea4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004aea00(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0x7f);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 0x10) != 0) {
      return *(undefined4 *)(param_1 + 0xe4);
    }
  }
  else if ((*(byte *)(param_1 + 4) & 0x10) != 0) {
    return *(undefined4 *)(param_1 + 0x18);
  }
  return 0xffffffff;
}

