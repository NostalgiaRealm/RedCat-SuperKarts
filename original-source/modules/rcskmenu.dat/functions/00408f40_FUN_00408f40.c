/*
 * FUN_00408f40 at 00408f40
 * WORD __register FUN_00408f40(void)
 * Address ranges: 00408f40-00408f50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

WORD FUN_00408f40(void)

{
  _SYSTEMTIME local_10;
  
  GetLocalTime(&local_10);
  return local_10.wYear;
}

