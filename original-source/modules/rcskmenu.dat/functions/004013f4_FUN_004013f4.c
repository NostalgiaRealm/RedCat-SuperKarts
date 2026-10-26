/*
 * FUN_004013f4 at 004013f4
 * int * __register FUN_004013f4(void)
 * Address ranges: 004013f4-00401442
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004013f4(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  if (DAT_0047d454 == (int *)0x0) {
    puVar1 = LocalAlloc(0,0x644);
    if (puVar1 == (undefined4 *)0x0) {
      return (int *)0x0;
    }
    *puVar1 = DAT_0047d450;
    iVar3 = 0;
    DAT_0047d450 = puVar1;
    do {
      piVar2 = puVar1 + iVar3 * 4 + 1;
      *piVar2 = (int)DAT_0047d454;
      iVar3 = iVar3 + 1;
      DAT_0047d454 = piVar2;
    } while (iVar3 != 100);
  }
  piVar2 = DAT_0047d454;
  DAT_0047d454 = (int *)*DAT_0047d454;
  return piVar2;
}

