/*
 * FUN_0049b130 at 0049b130
 * undefined FUN_0049b130(void)
 * Address ranges: 0049b130-0049b177
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049b130(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 1000;
  puVar2 = &DAT_0068489c;
  do {
    puVar4 = puVar2 + -0x21;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar2[-1] = 0xffffffff;
    *puVar2 = 0xffffffff;
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + 0x22;
  } while (iVar3 != 0);
  FUN_004be654(&DAT_0049b180);
  return;
}

