/*
 * FUN_004b41b0 at 004b41b0
 * undefined FUN_004b41b0(void)
 * Address ranges: 004b41b0-004b4234
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b41b0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_006ab7b4 != 0) {
    if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
      FUN_004afee0(s__s__d____illegal_sound_buffer_in_00500544,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x241,param_1,DAT_006ab78c);
    }
    iVar2 = param_1 * 0x44;
    if (*(int *)(iVar2 + 0x30 + DAT_006ab798) != 0) {
      FUN_004b3fd0(param_1);
      piVar1 = *(int **)(iVar2 + 0x28 + DAT_006ab798);
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar2 + 0x30 + DAT_006ab798) = 0;
      *(undefined4 *)(iVar2 + 0x38 + DAT_006ab798) = 0;
    }
  }
  return 0;
}

