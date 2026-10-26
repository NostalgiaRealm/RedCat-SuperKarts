/*
 * FUN_00432e1c at 00432e1c
 * undefined __register FUN_00432e1c(int param_1)
 * Address ranges: 00432e1c-00432e4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432e1c(int param_1)

{
  tagPOINT tStack_c;
  
  FUN_00432cf0(param_1);
  if (*(char *)(param_1 + 0x79) == '\0') {
    GetCursorPos(&tStack_c);
    FUN_0043306c(param_1,&tStack_c.x);
  }
  else if (*(char *)(param_1 + 0x79) == '\x01') {
    FUN_00432e50(param_1);
  }
  return;
}

