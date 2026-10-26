/*
 * FUN_004b5400 at 004b5400
 * undefined FUN_004b5400(void)
 * Address ranges: 004b5400-004b5448
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b5400(int param_1)

{
  if (DAT_006ab7b4 == 0) {
    return 0xffffffff;
  }
  if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
    FUN_004afee0(s__s__d____sound_buffer_index_ille_005008b8,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x683,param_1);
  }
  return *(undefined4 *)(DAT_006ab798 + 0x40 + param_1 * 0x44);
}

