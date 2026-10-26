/*
 * FUN_004b9080 at 004b9080
 * undefined FUN_004b9080(void)
 * Address ranges: 004b9080-004b909b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b9080(void)

{
  int iVar1;
  
  iVar1 = FUN_004b8d50(0x14);
  if (iVar1 == 0) {
    DirectDrawEnumerateA(FUN_004b8e90,0);
    iVar1 = 0;
  }
  return iVar1;
}

