/*
 * FUN_0043c798 at 0043c798
 * undefined __register FUN_0043c798(char * param_1)
 * Address ranges: 0043c798-0043c7aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043c798(char *param_1)

{
  if (*param_1 == '\0') {
    *param_1 = '\x01';
    return;
  }
  if (*param_1 == '\x01') {
    *param_1 = '\0';
  }
  return;
}

