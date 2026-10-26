/*
 * FUN_00404de4 at 00404de4
 * undefined __cdecl FUN_00404de4(LONG * param_1, LONG * param_2, int * param_3)
 * Address ranges: 00404de4-00404e62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00404de4(LONG *param_1,LONG *param_2,int *param_3)

{
  int iVar1;
  tagPOINT local_c;
  
  if (DAT_00438488 == 0) {
    FUN_0040187a((byte *)s__s__d_____get_mouse_pos__Mouse_i_0042e548);
  }
  GetCursorPos(&local_c);
  *param_1 = local_c.x;
  *param_2 = local_c.y;
  *param_3 = 0;
  iVar1 = FUN_004133f0(1);
  if (iVar1 != 0) {
    *param_3 = 1;
  }
  iVar1 = FUN_004133f0(2);
  if (iVar1 != 0) {
    *param_3 = *param_3 + 2;
  }
  return;
}

