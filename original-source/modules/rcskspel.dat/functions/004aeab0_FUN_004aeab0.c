/*
 * FUN_004aeab0 at 004aeab0
 * undefined FUN_004aeab0(void)
 * Address ranges: 004aeab0-004aeb05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004aeab0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0xb1);
  }
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0xd0) & 0x100) != 0) {
      return *(undefined4 *)(param_1 + 0x16c);
    }
  }
  else if ((*(uint *)(param_1 + 4) & 0x100) != 0) {
    return *(undefined4 *)(param_1 + 0xa0);
  }
  return 0xffffffff;
}

