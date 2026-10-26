/*
 * FUN_004c0200 at 004c0200
 * undefined FUN_004c0200(void)
 * Address ranges: 004c0200-004c022e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_004c0200(void)

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

