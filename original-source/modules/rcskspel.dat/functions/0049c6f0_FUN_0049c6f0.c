/*
 * FUN_0049c6f0 at 0049c6f0
 * undefined FUN_0049c6f0(void)
 * Address ranges: 0049c6f0-0049c715
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049c6f0(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_006a5b90;
  iVar2 = 2;
  do {
    *(undefined4 *)(puVar1 + -8) = 0;
    *(undefined4 *)(puVar1 + -4) = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_004be654(&DAT_0049c720);
  return;
}

