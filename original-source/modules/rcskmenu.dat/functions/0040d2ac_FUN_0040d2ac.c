/*
 * FUN_0040d2ac at 0040d2ac
 * undefined __register FUN_0040d2ac(char * param_1, byte * param_2)
 * Address ranges: 0040d2ac-0040d2be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d2ac(char *param_1,byte *param_2)

{
  if (*param_1 == '\x01') {
    FUN_00407f90(param_2);
    return;
  }
  FUN_0040d260((int)param_1,(int)param_2);
  return;
}

