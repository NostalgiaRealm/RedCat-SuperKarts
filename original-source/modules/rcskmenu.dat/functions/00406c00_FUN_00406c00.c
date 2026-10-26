/*
 * FUN_00406c00 at 00406c00
 * undefined __register FUN_00406c00(LPCVOID param_1)
 * Address ranges: 00406c00-00406c12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406c00(LPCVOID param_1)

{
  HGLOBAL hMem;
  
  hMem = GlobalHandle(param_1);
  GlobalUnlock(hMem);
  GlobalFree(hMem);
  return;
}

