/*
 * FUN_004126b0 at 004126b0
 * undefined FUN_004126b0(void)
 * Address ranges: 004126b0-004126d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004126b0(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0xfc) != '\0') {
    FUN_00457730(param_1);
    FUN_00457ab0(param_1);
    *(undefined1 *)(param_2 + 0xfc) = 0;
  }
  return;
}

