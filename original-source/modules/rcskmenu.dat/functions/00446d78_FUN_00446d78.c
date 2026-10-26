/*
 * FUN_00446d78 at 00446d78
 * undefined __register FUN_00446d78(HWND param_1, int param_2, int param_3, int * param_4)
 * Address ranges: 00446d78-00446db7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446d78(HWND param_1,int param_2,int param_3,int *param_4)

{
  tagRECT local_1c;
  tagPOINT local_c;
  
  local_c.x = param_2;
  local_c.y = param_3;
  ClientToScreen(param_1,&local_c);
  GetWindowRect(param_1,&local_1c);
  *param_4 = local_c.x - local_1c.left;
  param_4[1] = local_c.y - local_1c.top;
  return;
}

