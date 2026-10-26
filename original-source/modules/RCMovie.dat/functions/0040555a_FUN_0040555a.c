/*
 * FUN_0040555a at 0040555a
 * undefined __thiscall FUN_0040555a(void * this, int param_1)
 * Address ranges: 0040555a-00405613
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0040555a(void *this,int param_1)

{
  int iVar1;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__Mouse_is_n_0042ea3c);
  }
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__You_can_t_c_0042ea78);
  }
  if ((DAT_0042dfa4 == 2) && (DAT_00438490 == 0)) {
    FUN_0040187a((byte *)s__s__d_____draw_mouse__No_mouse_a_0042eac8);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043d858 + 8 + DAT_0042df9c * 0xc) + 4 + DAT_0042dfa0 * 8);
  FUN_00404ed3(param_1);
  FUN_004105ee(param_1,iVar1,DAT_00438480,DAT_00438484,3);
  return;
}

