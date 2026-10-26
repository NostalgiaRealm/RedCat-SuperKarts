/*
 * FUN_0043c880 at 0043c880
 * LRESULT __register FUN_0043c880(UINT param_1, WPARAM param_2, LPARAM param_3)
 * Address ranges: 0043c880-0043c8a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LRESULT FUN_0043c880(UINT param_1,WPARAM param_2,LPARAM param_3)

{
  LRESULT LVar1;
  
  if (*(HWND *)(*(int *)PTR_DAT_0047c86c + 0x24) != (HWND)0x0) {
    LVar1 = SendMessageA(*(HWND *)(*(int *)PTR_DAT_0047c86c + 0x24),param_1,param_2,param_3);
    return LVar1;
  }
  return 0;
}

