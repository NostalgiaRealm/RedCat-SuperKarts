/*
 * FUN_00438600 at 00438600
 * undefined __register FUN_00438600(int * param_1, char param_2)
 * Address ranges: 00438600-00438628
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438600(int *param_1,char param_2)

{
  if (param_2 != *(char *)((int)param_1 + 0x31)) {
    *(char *)((int)param_1 + 0x31) = param_2;
    if (((char)param_1[0xb] != '\0') && (*(char *)((int)param_1 + 0x31) != '\0')) {
      FUN_00437f14((int)param_1);
    }
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return;
}

