/*
 * FUN_004bf836 at 004bf836
 * undefined FUN_004bf836(void)
 * Address ranges: 004bf836-004bf878
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bf836(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  __aulldiv((lVar1 - CONCAT44(_DAT_006b66e4,_DAT_006b66e0)) + (ulonglong)local_c.dwLowDateTime,10000
            ,0);
  return;
}

