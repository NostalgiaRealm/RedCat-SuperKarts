/*
 * FUN_00404b6c at 00404b6c
 * undefined __cdecl FUN_00404b6c(int param_1, int param_2, undefined1 param_3)
 * Address ranges: 00404b6c-00404ced
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00404b6c(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  
  if (DAT_0042dfa4 == 1) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__You_ca_0042e1c8);
  }
  if ((param_1 < 0) || (DAT_00434c1c <= param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__illega_0042e21c);
  }
  if ((param_2 < 0) || (*(int *)(DAT_0043d858 + param_1 * 0xc) <= param_2)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__illega_0042e284);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043d858 + 8 + param_1 * 0xc) + 4 + param_2 * 8);
  if ((iVar1 < 0) || (DAT_00431b64 <= iVar1)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__image___0042e2ec);
  }
  if (*(int *)(DAT_0043d6e8 + iVar1 * 0x20) == 0) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__mouse_i_0042e33c);
  }
  if ((0x40 < *(int *)(DAT_0043d6e8 + 8 + iVar1 * 0x20)) ||
     (0x40 < *(int *)(DAT_0043d6e8 + 0xc + iVar1 * 0x20))) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_anim__mouse_a_0042e3a0);
  }
  DAT_0042df9c = param_1;
  DAT_0042dfa0 = param_2;
  DAT_004384a4 = param_3;
  DAT_00438490 = 1;
  return;
}

