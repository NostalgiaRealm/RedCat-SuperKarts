/*
 * FUN_004054ad at 004054ad
 * undefined __thiscall FUN_004054ad(void * this, int param_1)
 * Address ranges: 004054ad-00405559
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004054ad(void *this,int param_1)

{
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__Mouse_is_n_0042e970);
  }
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__You_can_t_c_0042e9ac);
  }
  if ((DAT_0042dfa4 == 2) && (DAT_00438490 == 0)) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__No_mouse_a_0042e9fc);
  }
  if ((DAT_0042df80 != -1) && (DAT_0042df84 != -1)) {
    FUN_004051d7(param_1);
  }
  return;
}

