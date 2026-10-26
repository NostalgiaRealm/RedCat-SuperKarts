/*
 * FUN_004089db at 004089db
 * undefined __stdcall FUN_004089db(void)
 * Address ranges: 004089db-004089fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004089db(void)

{
  if (DAT_0040ef40 != 0xffffffff) {
    TlsFree(DAT_0040ef40);
    DAT_0040ef40 = 0xffffffff;
  }
  return;
}

