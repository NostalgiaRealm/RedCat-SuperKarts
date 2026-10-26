/*
 * FUN_0048f780 at 0048f780
 * undefined FUN_0048f780(void)
 * Address ranges: 0048f780-0048f7a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f780(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0067ec88;
  for (iVar1 = 100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  _DAT_0067ee18 = 0;
  FUN_004be654(&DAT_0048f7b0);
  return;
}

