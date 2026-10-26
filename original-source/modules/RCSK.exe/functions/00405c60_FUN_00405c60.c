/*
 * FUN_00405c60 at 00405c60
 * undefined __stdcall FUN_00405c60(void)
 * Address ranges: 00405c60-00405c8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_00405c60(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}

