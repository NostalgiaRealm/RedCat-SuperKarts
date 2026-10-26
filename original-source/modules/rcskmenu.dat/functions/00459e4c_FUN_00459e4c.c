/*
 * FUN_00459e4c at 00459e4c
 * undefined __register FUN_00459e4c(int param_1, byte param_2, int * param_3)
 * Address ranges: 00459e4c-00459e81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00459e4c(int param_1,byte param_2,int *param_3)

{
  byte bVar1;
  
  FUN_00403b50(param_3);
  bVar1 = 0;
  do {
    if (bVar1 == param_2) {
      FUN_00403ba4(param_3,*(undefined4 **)(param_1 + 0x150 + (uint)bVar1 * 4));
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 != 0x21);
  return;
}

