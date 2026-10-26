/*
 * FUN_004080a0 at 004080a0
 * undefined __register FUN_004080a0(HANDLE param_1, LONG param_2, DWORD param_3)
 * Address ranges: 004080a0-004080aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004080a0(HANDLE param_1,LONG param_2,DWORD param_3)

{
  SetFilePointer(param_1,param_2,(PLONG)0x0,param_3);
  return;
}

