/*
 * FUN_00402aea at 00402aea
 * undefined4 __stdcall FUN_00402aea(void)
 * Address ranges: 00402aea-00402b27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402aea(void)

{
  DAT_0040a018 = HeapAlloc(DAT_0040a01c,0,0x140);
  if (DAT_0040a018 == (LPVOID)0x0) {
    return 0;
  }
  DAT_0040a010 = 0;
  DAT_0040a014 = 0;
  DAT_0040a00c = DAT_0040a018;
  DAT_0040a004 = 0x10;
  return 1;
}

