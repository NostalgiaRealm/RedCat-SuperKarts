/*
 * FUN_004b9ea0 at 004b9ea0
 * undefined FUN_004b9ea0(void)
 * Address ranges: 004b9ea0-004b9f28
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9ea0(LONG *param_1,LONG *param_2,int *param_3)

{
  int iVar1;
  tagPOINT local_8;
  
  if (DAT_006ab95c == 0) {
    FUN_004afee0(s__s__d_____get_mouse_pos__Mouse_i_00501e44,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x1d5);
  }
  GetCursorPos(&local_8);
  ScreenToClient(DAT_006a64b4,&local_8);
  *param_1 = local_8.x;
  *param_2 = local_8.y;
  *param_3 = 0;
  iVar1 = FUN_004b3830(1);
  if (iVar1 != 0) {
    *param_3 = 1;
  }
  iVar1 = FUN_004b3830(2);
  if (iVar1 != 0) {
    *param_3 = *param_3 + 2;
  }
  return;
}

