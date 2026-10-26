/*
 * FUN_004b53b0 at 004b53b0
 * undefined FUN_004b53b0(void)
 * Address ranges: 004b53b0-004b53f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b53b0(int param_1,undefined4 param_2)

{
  if (DAT_006ab7b4 != 0) {
    if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
      FUN_004afee0(s__s__d____sound_buffer_index_ille_005008b8,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x66a,param_1);
    }
    *(undefined4 *)(DAT_006ab798 + 0x40 + param_1 * 0x44) = param_2;
  }
  return;
}

