/*
 * FUN_00423024 at 00423024
 * undefined FUN_00423024(void)
 * Address ranges: 00423024-00423073
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423024(int param_1,LPRECT param_2)

{
  LONG LVar1;
  
  FUN_00441acc();
  FUN_004188b4(*(int *)(param_1 + 0x1f0));
  LVar1 = FUN_00418810(*(int **)(param_1 + 0x1f0),&DAT_0042307c);
  param_2->top = param_2->top + LVar1;
  InflateRect(param_2,-1,-1);
  if (*(char *)(param_1 + 0x138) != '\0') {
    InflateRect(param_2,-1,-1);
  }
  return;
}

