/*
 * FUN_0043eaa4 at 0043eaa4
 * undefined __register FUN_0043eaa4(int param_1, char param_2)
 * Address ranges: 0043eaa4-0043eac2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043eaa4(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x51)) {
    *(char *)(param_1 + 0x51) = param_2;
    FUN_0043ed90(param_1);
  }
  return;
}

