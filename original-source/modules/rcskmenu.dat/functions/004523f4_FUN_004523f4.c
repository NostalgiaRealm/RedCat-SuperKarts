/*
 * FUN_004523f4 at 004523f4
 * undefined FUN_004523f4(void)
 * Address ranges: 004523f4-0045243e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004523f4(int *param_1,int *param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x1c))();
  if (cVar1 == '\0') {
    if (*(char *)(param_1[9] + 0x42c) == '\0') {
      GdiFlush();
    }
    FUN_00411920(param_2,*(undefined4 *)(param_1[9] + 0xc),*(int *)(param_1[9] + 0x10));
    FUN_00411920(param_2,*(undefined4 *)(param_1[9] + 0x440),
                 *(int *)(*(int *)(param_1[9] + 0xc) + 0x14));
  }
  return;
}

