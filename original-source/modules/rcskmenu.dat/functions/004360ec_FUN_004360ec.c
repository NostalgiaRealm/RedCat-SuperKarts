/*
 * FUN_004360ec at 004360ec
 * undefined FUN_004360ec(void)
 * Address ranges: 004360ec-00436109
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004360ec(int *param_1,short param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x38))();
  if (cVar1 != '\0') {
    FUN_004380b8((int *)param_1[6],param_2);
  }
  return;
}

