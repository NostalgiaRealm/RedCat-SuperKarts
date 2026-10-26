/*
 * FUN_004b9e40 at 004b9e40
 * undefined FUN_004b9e40(void)
 * Address ranges: 004b9e40-004b9e97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9e40(int param_1,int param_2)

{
  tagPOINT local_8;
  
  if (DAT_006ab95c == 0) {
    FUN_004afee0(s__s__d_____set_mouse_pos__Mouse_i_00501e10,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x1ad);
  }
  local_8.x = param_1;
  local_8.y = param_2;
  ClientToScreen(DAT_006a64b4,&local_8);
  SetCursorPos(local_8.x,local_8.y);
  return;
}

