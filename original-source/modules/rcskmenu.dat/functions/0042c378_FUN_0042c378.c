/*
 * FUN_0042c378 at 0042c378
 * undefined __register FUN_0042c378(int param_1, char param_2)
 * Address ranges: 0042c378-0042c3ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c378(int param_1,char param_2)

{
  char cVar1;
  
  if (param_2 != *(char *)(param_1 + 0x211)) {
    *(char *)(param_1 + 0x211) = param_2;
    if ((param_2 == '\x02') || (param_2 == '\x05')) {
      cVar1 = '\x01';
    }
    else {
      cVar1 = '\0';
    }
    FUN_0042a744(param_1,cVar1);
    if ((*(byte *)(param_1 + 0x20) & 0x10) == 0) {
      FUN_00442cd4(param_1);
    }
  }
  return;
}

