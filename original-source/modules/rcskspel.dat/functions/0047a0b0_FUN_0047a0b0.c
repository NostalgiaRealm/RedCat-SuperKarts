/*
 * FUN_0047a0b0 at 0047a0b0
 * undefined FUN_0047a0b0(void)
 * Address ranges: 0047a0b0-0047a0f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047a0b0(void)

{
  char cVar1;
  
  if (DAT_00544e6c != 0) {
    cVar1 = *(char *)(DAT_00544e6c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544e6c + -1);
    }
    else {
      *(char *)(DAT_00544e6c + -1) = cVar1 + -1;
    }
  }
  DAT_00544e6c = 0;
  _DAT_00544e70 = 0;
  DAT_00544e74 = 0;
  return;
}

