/*
 * FUN_0040f523 at 0040f523
 * int __stdcall FUN_0040f523(void)
 * Address ranges: 0040f523-0040f550
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040f523(void)

{
  int iVar1;
  
  iVar1 = FUN_0040f1dc(0x14);
  if (iVar1 == 0) {
    DirectDrawEnumerateA(FUN_0040f310,0);
    iVar1 = 0;
  }
  return iVar1;
}

