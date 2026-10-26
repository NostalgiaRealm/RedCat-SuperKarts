/*
 * FUN_00409213 at 00409213
 * int __stdcall FUN_00409213(void)
 * Address ranges: 00409213-0040921b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00409213(void)

{
  int in_EAX;
  
  return (*(uint *)(in_EAX + -4) & 0xfffffffe) - 4;
}

