/*
 * FUN_0043e140 at 0043e140
 * undefined __register FUN_0043e140(HDC param_1, int param_2, int param_3)
 * Address ranges: 0043e140-0043e16e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e140(HDC param_1,int param_2,int param_3)

{
  tagPOINT local_14;
  
  GetWindowOrgEx(param_1,&local_14);
  SetWindowOrgEx(param_1,local_14.x - param_2,local_14.y - param_3,(LPPOINT)0x0);
  return;
}

