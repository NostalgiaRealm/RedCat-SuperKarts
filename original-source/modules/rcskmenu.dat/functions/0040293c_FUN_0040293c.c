/*
 * FUN_0040293c at 0040293c
 * undefined __register FUN_0040293c(void)
 * Address ranges: 0040293c-00402976
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040293c(void)

{
  _SYSTEMTIME local_1c;
  
  GetSystemTime(&local_1c);
  DAT_0047d044 = (CONCAT22((short)((uint)local_1c.wHour * 0x3c >> 0x10),
                           (short)((uint)local_1c.wHour * 0x3c) + local_1c.wMinute) * 0x3c +
                 (uint)local_1c.wSecond) * 1000 + (uint)local_1c.wMilliseconds;
  return;
}

