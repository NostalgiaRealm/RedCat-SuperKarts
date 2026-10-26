/*
 * FUN_004bf879 at 004bf879
 * undefined FUN_004bf879(void)
 * Address ranges: 004bf879-004bf8ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bf879(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  _DAT_006b66e0 = lVar1 + (ulonglong)local_c.dwLowDateTime;
  return;
}

