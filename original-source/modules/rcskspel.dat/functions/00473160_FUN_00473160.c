/*
 * FUN_00473160 at 00473160
 * undefined FUN_00473160(void)
 * Address ranges: 00473160-004731a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473160(void)

{
  char cVar1;
  
  if (DAT_00544dbc != 0) {
    cVar1 = *(char *)(DAT_00544dbc + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544dbc + -1);
    }
    else {
      *(char *)(DAT_00544dbc + -1) = cVar1 + -1;
    }
  }
  DAT_00544dbc = 0;
  _DAT_00544dc0 = 0;
  DAT_00544dc4 = 0;
  return;
}

