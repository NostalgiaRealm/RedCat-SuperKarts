/*
 * FUN_004606c4 at 004606c4
 * undefined FUN_004606c4(void)
 * Address ranges: 004606c4-004606ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004606c4(int *param_1,int *param_2)

{
  if (((*param_2 == 0x47) && (param_2[2] != 0)) && ((char)param_1[0x7e] != '\0')) {
    (**(code **)(*param_1 + 0x74))();
  }
  if (*(short *)((int)param_1 + 0x202) != 0) {
    (*(code *)param_1[0x80])(param_1[0x81],param_2);
  }
  return;
}

