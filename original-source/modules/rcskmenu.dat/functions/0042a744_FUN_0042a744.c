/*
 * FUN_0042a744 at 0042a744
 * undefined __register FUN_0042a744(int param_1, char param_2)
 * Address ranges: 0042a744-0042a77d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a744(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x1f8)) {
    *(char *)(param_1 + 0x1f8) = param_2;
    if (param_2 == '\0') {
      FUN_0042a29c(*(int *)(param_1 + 0x1f0),0);
      FUN_0042a29c(*(int *)(param_1 + 500),0);
    }
    else {
      FUN_0042a720(param_1);
    }
  }
  return;
}

