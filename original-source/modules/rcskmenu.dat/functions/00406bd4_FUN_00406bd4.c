/*
 * FUN_00406bd4 at 00406bd4
 * undefined __register FUN_00406bd4(UINT param_1, SIZE_T param_2)
 * Address ranges: 00406bd4-00406be1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406bd4(UINT param_1,SIZE_T param_2)

{
  HGLOBAL hMem;
  
  hMem = GlobalAlloc(param_1,param_2);
  GlobalLock(hMem);
  return;
}

